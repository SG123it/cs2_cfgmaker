#include <iostream>
#include <map>
#include <string>

#include "headers/Localization.hpp"



std::string localization::getvalue(LOC_TYPES key) {

    if (selected_language == languages::RUSSIAN) return RU[key];
    else if (selected_language == languages::ENGLISH) return EN[key];
    return ""; //to dissaper "return-statement with no value, in function returning 'return_standart' [-fpermissive]"

}

void localization::set_language(localization::languages language) {

    selected_language = language;

}

localization::languages localization::get_selected_language(){

    return selected_language;

}