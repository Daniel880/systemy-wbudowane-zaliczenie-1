# systemy-wbudowane-zaliczenie-1

## Przygotowanie środowiska (SSH i klonowanie repozytorium)
1. Sklonuj repozytorium z kluczem i skonfiguruj SSH:

```
git clone https://github.com/Daniel880/systemy-wbudowane-key.git   # pobranie repo z kluczem
cd systemy-wbudowane-key                                            # wejście do katalogu

chmod 600 systemy-wbudowane-1                                       # ustawienie praw do klucza
eval "$(ssh-agent -s)"                                              # uruchomienie ssh-agenta
ssh-add systemy-wbudowane-1                                         # dodanie klucza do agenta
```

2. Skonfiguruj dane użytkownika (wstaw swoje dane):

```
git config --global user.name "Imie Nazwisko"                       # ustawienie nazwy użytkownika
git config --global user.email "imie@nazwisko.com"                  # ustawienie adresu email
```

3. Sklonuj główne repozytorium:

```
cd ..                                                               # wyjście poziom wyżej
git clone git@github.com:Daniel880/systemy-wbudowane-zaliczenie-1.git          # klon repo projektu przez SSH
cd systemy-wbudowane-zaliczenie-1
```

## Opis zadania
Repozytorium zawiera prosty program w C++. W projekcie **brakuje jednego pliku `.cpp`**, który należy dodać oraz uwzględnić w konfiguracji CMake.

Zadanie polega na:
1. Dodaniu jednego pliku `.cpp`.
2. Uzupełnieniu [CMakeLists.txt](CMakeLists.txt) o dodany plik.
3. Dodaniu definicji funkcji `print_student_output()`.
4. Implementacji funkcji, która wypisuje odpowiednio sformatowany tekst, wykorzystując funkcje z [include/system_info.h](include/system_info.h).
5. Utworzeniu commita.
6. Utworzeniu brancha o odpowiedniej nazwie.
7. Wysłaniu kodu do repozytorium na GitHub.


## Wymagany format wyjścia
Program musi wypisać **dokładnie 5 linii** w następującym formacie (bez polskich znaków):

```
Hello World!
Imie i Nazwisko: DanielWyrwal
Nazwa Brancha: Zaliczenie-DanielWyrwal
IP: 62.21.2.116,
machine_ID: 1abf98f82f154f0fa16333d8aa6e5935
```

Wartości `IP`, `machine_ID` oraz nazwa brancha są zwracane przez przygotowane funkcje — należy je jedynie sformatować i wypisać.
Pole `Imie i Nazwisko` musi odpowiadać nazwie gałęzi bez prefiksu `Zaliczenie-` (bez spacji).

## Wymagania implementacyjne
1. Utworzyć plik [src/student_output.cpp](src/student_output.cpp).
2. Dodać plik do listy źródeł w [CMakeLists.txt](CMakeLists.txt).
3. Zaimplementować funkcję `print_student_output()` w pliku [src/student_output.cpp](src/student_output.cpp) zadeklarowaną w [include/student_output.h](include/student_output.h).
4. Skorzystać z funkcji z [include/system_info.h](include/system_info.h):
	- `get_branch_name()`
	- `get_ip_address()`
	- `get_machine_id()`

## Przykładowa struktura pliku student_output.cpp
```
#include "XYZ.h"


void print_student_output() {
	std::cout << "Hello World!" << std::endl;
	std::cout << "Imie i Nazwisko: " << ImieNazwisko << std::endl;
	std::cout << "Nazwa Brancha: " << FUNKCJA Z PLIKU system_info.h << std::endl;
	std::cout << "IP: " << FUNKCJA Z PLIKU system_info.h  << "," << std::endl;
	std::cout << "machine_ID: " << FUNKCJA Z PLIKU system_info.h  << std::endl;
}
```

## Wymagania dotyczące gałęzi
Nazwa gałęzi musi mieć format: `Zaliczenie-ImieNazwisko` (ASCII, bez polskich znaków i bez spacji).

## Wymagane pakiety (Alpine Linux)
Należy zainstalować: `cmake`, `make`, `g++`, `git`, `curl`.
Przykład: `apk add cmake make g++ git curl`

## Budowanie lokalne
```
mkdir -p build
cd build
cmake ..
make
./zaliczenie
```

## GitHub Actions
Workflow weryfikuje:
1. Generowanie CMake
2. Kompilację
3. Uruchomienie programu bez błędu
4. Poprawność formatu outputu
5. Poprawność nazwy gałęzi

W logach builda widoczny jest wynik każdego etapu.
