#pragma once
#include <iostream>
#include <map>
#include <string>

enum LOC_TYPES { //localization_types

        GENERAL_PAUSE,

        //-------------------------

        MAIN_WARNING_SELECT_ACTION,
        MAIN_STARTUP_UI,
        MAIN_WARNING_SOMEFUNC_UNAVAILABLE,
        MAIN_THANK_YOU_GITHUB,
        MAIN_THANK_YOU,
        MAIN_ERROR_WARNING,
        MAIN_UNKNOWN_ERROR_WARNING,

        //-------------------------

        START_STEP1,
        START_STEAM_NOT_FOUND,
        START_ENTER_PATH,
        START_STEP2,
        START_DO_NOT_CLOSE_PROGRAM,
        START_BIND_DETECTED,
        START_SETTINGS_DETECTED,
        START_STEP3,
        START_PATH_TO_CFG,
        START_END_THANK_YOU,

        //-------------------------

        INSTRUCTION_TEXT,

        //-------------------------

        SEARCH_IS_YOUR_ACCOUNT,
        SEARCH_STEAM_FOUND
};
extern std::map<LOC_TYPES, std::string> RU;
extern std::map<LOC_TYPES, std::string> EN;