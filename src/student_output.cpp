# include <iostream>
# include "../include/system_info.h"

void print_student_output(){
    std::string branch=get_branch_name();
    std:: string ip = get_ip_address();
    std::string machine=get_machine_id();

    std::cout<<"Hello World!"<<std::endl;
    std::cout<<"Imie i Nazwisko: "<<"MariaSzulc"<<std::endl;
    std::cout<<"Nazwa Brancha: "<<branch<<std::endl;
    std::cout<<"IP: "<<ip<<std::endl;
    std::cout<<"machine_ID: "<<machine<<std::endl;
}
