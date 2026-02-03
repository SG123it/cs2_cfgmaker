#include "headers/return_standart.hpp"

std::string return_standart::print() {
    std::string message = "";
    message += "\n--------------\n\n";
    message += "CODE: " + std::to_string(code) + "\n";
    message += "REASON: " + reason + "\n";
    message += "FILE: " + file + "\n";
    message += "Add.Information: " + additional_information + "\n";
    message += "\n--------------\n";

    std::cout << message;
    return message;
}