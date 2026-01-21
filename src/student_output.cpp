#include "system_info.h"
#include <iostream>
using namespace std;
void print_student_output(){
string ImieNazwisko = get_branch_name();
ImieNazwisko = ImieNazwisko.erase(0,11);
cout << "Hello World!" << endl;
cout << "Imie i Nazwisko: " <<ImieNazwisko<< endl;
cout << "Nazwa Brancha: "<< get_branch_name() << endl;
cout << "IP: " << get_ip_address() << endl;
cout << "machine_ID: " << get_machine_id() << endl;
}

