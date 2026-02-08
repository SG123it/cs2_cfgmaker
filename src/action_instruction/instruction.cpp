#include "instruction.hpp"
#include <filesystem>
#include <iostream>

#include <clearwindow.hpp> //func from ./include
#include <Localization.hpp> //func from ./include

void instruction(localization& language){ //1
    clearwindow();


    std::cout << language.getvalue(LOC_TYPES::INSTRUCTION_TEXT); //INSTRUCTION_TEXT

    std::cout << language.getvalue(LOC_TYPES::GENERAL_PAUSE); //SEARCH_PAUSE
    std::cin.ignore();
    std::cin.get();
}