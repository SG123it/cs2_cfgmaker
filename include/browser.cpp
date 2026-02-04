#include "headers/browser.hpp"
#include <iostream>

void browser::openlink(std::string link){

    #if defined _WIN32 || defined _WIN64
        std::string command = "start " + link;
        std::system(command.c_str());
    #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
        std::string command = "xdg-open " + link;
        std::system(command.c_str());
    #elif defined (__APPLE__)
        std::string command = "open " + link;
        std::system(command.c_str());
    #endif

}