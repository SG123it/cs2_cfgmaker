#include <iostream>
#include <filesystem>
#include <map>

#include "search.hpp"
#include <Localization.hpp> //func from ./include
#include <return_standart.hpp> //func from ./include
#include <browser.hpp> //func from ./include

return_standart steam_path(localization& language, bool with_account_id) {
    return_standart return_var;

    #if !defined(_WIN32) || !defined(_WIN64) //Return code 111: Unable to start search::steam_path : available only in windows
        return_value["return_code"] = "111";
        return return_value;
    #endif

    std::string steampath = getenv("windir"); //Var with path to steam folder

    steampath = steampath.substr(0,2) + "\\"; //template: c:/
    
    steampath += "Program Files (x86)\\"; //template: c:/Program Files (x86)
    if (!std::filesystem::exists(steampath)) {
        //Return code 101: Unable to exists Program Files (x86)
        return_var.code = 101;
        return_var.reason = "Unable to exists Program Files (x86)";
        return_var.file = "src/action_start/search.cpp";
        return return_var;
    }

    steampath += "Steam\\"; //template: c:/Program Files (x86)/steam
    if (!std::filesystem::exists(steampath)) {
        //Return code 102: Unable to exists steam directory
        return_var.code = 102;
        return_var.reason = "Unable to exists steam directory";
        return_var.file = "src/action_start/search.cpp";
        return return_var;
    }
    
    std::cout << language.getvalue(localization_data::TYPES::SEARCH_STEAM_FOUND) << steampath << std::endl; //SEARCH_STEAM_FOUND

    //add.information = return_value
    return_var.additional_information = steampath;
    if (!with_account_id) return return_var;

    //--------------------
    bool steam_account_selected = false;

    steampath += "userdata\\"; //template: c:/Program Files (x86)/steam/userdata
    if (!std::filesystem::exists(steampath)) {
        //Return code 103: Unable to exists ./Steam/userdata
        return_var.code = 103;
        return_var.reason = "Unable to exists ./Steam/userdata";
        return_var.file = "src/action_start/search.cpp";
        return return_var;
    }

    for (const std::filesystem::path iterator : std::filesystem::directory_iterator(steampath)) {
        std::string account_id = "";

        if (!std::filesystem::is_directory(iterator)) continue;
        account_id = iterator.filename().string();
                
        while (!steam_account_selected) {

            int choice = 0;
            //account_id : is your account? yes, no, check in browser
            std::cout << account_id << language.getvalue(localization_data::TYPES::SEARCH_IS_YOUR_ACCOUNT);

            std::cin >> choice;
            //From AI
            //-------------------
            if (std::cin.fail()) { 
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                continue;
            }
            //-------------------
            else if (choice > 3 || choice < 1) continue;

            if (choice == 1) {
                steam_account_selected = true;
                steampath += account_id + "\\";

                return_var.additional_information = steampath;
                return return_var;
            }

            else if (choice == 2) break;

            else if (choice == 3) { browser::openlink("https://steamdb.info/calculator/?player=" + std::string(account_id) + "&cc=ru");
        }

    }


    if (!steam_account_selected) {
        //Return code 104: Steam account not selected or isn't exists
        return_var.code = 104;
        return_var.reason = "Steam account not selected or isn't exists";
        return_var.file = "src/action_start/search.cpp";
        return return_var;
    }

    return return_var; //to dissaper "return-statement with no value, in function returning 'return_standart' [-fpermissive]"
}