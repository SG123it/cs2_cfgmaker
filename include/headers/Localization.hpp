#pragma once
#include <iostream>
#include <map>
#include <string>

#include "Localization_data.hpp"
//-----------------------

class localization : public localization_data {

public:
    enum class languages {
        RUSSIAN,
        ENGLISH
    };

    void set_language(languages language);
    std::string getvalue(TYPES key);

private:
    languages selected_language = languages::ENGLISH;
};
