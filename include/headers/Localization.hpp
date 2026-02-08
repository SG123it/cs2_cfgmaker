#pragma once
#include <iostream>
#include <map>
#include <string>

#include "Localization_data.hpp"
//-----------------------

class localization {
public:
    enum class languages { //supported_languages
        RUSSIAN,
        ENGLISH
    };

    void set_language(languages language);
    std::string getvalue(LOC_TYPES key);
    languages get_selected_language();

private:
    languages selected_language = languages::ENGLISH;
};
