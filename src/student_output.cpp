#include <iostream>
#include "system_info.h"


void print_student_output()
{
std::cout << "HelloWordl!" << std::endl;
std::cout << "Imie i Nazwisko: "<<"KacperWesolowski"<< std::endl;
std::cout << "Nazwa Bruncha: " << get_branch_name()<<std::endl;
std::cout << "IP: " << get_ip_address() <<","<< std::endl;
std::cout << "machine_ID: " << get_machine_id()<< std::endl;
}
