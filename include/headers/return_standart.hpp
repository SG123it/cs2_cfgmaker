#pragma once
#include <iostream>

struct return_standart {

    int code = 0;
    std::string reason = "";
    std::string file = "";
    std::string additional_information = "";

    std::string print();
};