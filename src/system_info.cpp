#include "system_info.h"

#include <arpa/inet.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>

#include <array>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>

namespace {
std::string trim(const std::string &value) {
  size_t start = 0;
  while (start < value.size() &&
         std::isspace(static_cast<unsigned char>(value[start]))) {
    ++start;
  }

  size_t end = value.size();
  while (end > start &&
         std::isspace(static_cast<unsigned char>(value[end - 1]))) {
    --end;
  }

  return value.substr(start, end - start);
}

std::string read_file_first_line(const std::string &path) {
  std::ifstream file(path);
  if (!file.is_open()) {
    return "";
  }
  std::string line;
  std::getline(file, line);
  return trim(line);
}

std::string run_command(const char *cmd) {
  std::array<char, 256> buffer{};
  std::string result;
  FILE *pipe = popen(cmd, "r");
  if (!pipe) {
    return "";
  }

  while (fgets(buffer.data(), static_cast<int>(buffer.size()), pipe) !=
         nullptr) {
    result += buffer.data();
  }
  pclose(pipe);
  return trim(result);
}

std::string get_env_value(const char *key) {
  const char *value = std::getenv(key);
  if (!value) {
    return "";
  }
  return trim(value);
}
} // namespace

std::string get_branch_name() {
  std::string branch = get_env_value("GITHUB_REF_NAME");
  if (!branch.empty()) {
    return branch;
  }

  branch = get_env_value("BRANCH_NAME");
  if (!branch.empty()) {
    return branch;
  }

  branch = run_command("git rev-parse --abbrev-ref HEAD 2>/dev/null");
  if (!branch.empty()) {
    return branch;
  }

  return "UNKNOWN";
}

std::string get_ip_address() {
  std::string ip = run_command("curl -s https://api.ipify.org");
  if (!ip.empty()) {
    return ip;
  }

  struct ifaddrs *ifaddr = nullptr;
  if (getifaddrs(&ifaddr) == -1) {
    return "127.0.0.1";
  }

  ip = "";
  for (struct ifaddrs *ifa = ifaddr; ifa != nullptr; ifa = ifa->ifa_next) {
    if (!ifa->ifa_addr) {
      continue;
    }
    if (ifa->ifa_addr->sa_family != AF_INET) {
      continue;
    }
    if (ifa->ifa_flags & IFF_LOOPBACK) {
      continue;
    }

    char host[NI_MAXHOST];
    const auto *sa =
        reinterpret_cast<const struct sockaddr_in *>(ifa->ifa_addr);
    if (inet_ntop(AF_INET, &sa->sin_addr, host, sizeof(host)) != nullptr) {
      ip = host;
      break;
    }
  }

  freeifaddrs(ifaddr);

  if (ip.empty()) {
    return "127.0.0.1";
  }

  return ip;
}

std::string get_machine_id() {
  std::string id = read_file_first_line("/etc/machine-id");
  if (!id.empty()) {
    return id;
  }

  id = read_file_first_line("/var/lib/dbus/machine-id");
  if (!id.empty()) {
    return id;
  }

  return "UNKNOWN";
}
