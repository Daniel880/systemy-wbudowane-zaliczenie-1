#include <system_info.h>
#include <iostream>
#include<student_output.h>

void print_student_output(){
	std::cout<<"Hello World!" <<std::endl;
	std::cout<<"Imie i Nazwisko: " << "PiotrKrzyzaniak" <<std::endl;
	std::cout<<"Nazwa Brancha: "<<get_branch_name() <<std::endl;
	std::cout<<"IP: " <<get_ip_address() <<","  <<std::endl;
	std::cout<<"machine_ID: " <<get_machine_id() <<std::endl;
}
