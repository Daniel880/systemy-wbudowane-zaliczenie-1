
#include <iostream>
#include "system_info.h"

	void print_student_output() {
		std::cout<< "Hello World!" << std::endl;
		std::cout<< "Imie i Nazwisko: " << "Natan Szymanski" << std::endl;
		std::cout<<"Nazwa brancha: " << get_branch_name() << std::endl;
		std::cout<< "IP: " << get_ip_address() << std::endl;
		std::cout<< "Machine_ID: " << get_machine_id() << std::endl;

		

}

