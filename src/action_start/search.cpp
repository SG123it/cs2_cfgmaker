#include <iostream>
#include <filesystem>
#include <map>

#include "search.hpp"
#include <Localization.hpp> //func from ./include

std::map<std::string, std::string> steam_path(localization& language, bool with_account_id) {
    std::map<std::string, std::string> return_value = {
        {"return_code", "0"},
        {"return_value", ""}
    };

    #if !defined(_WIN32) || defined(_WIN64) //Return code 111: Unable to start search::steam_path : available only in windows
        return_value["return_code"] = "111";
        return return_value;
    #endif

    std::string steampath = getenv("windir"); //Var with path to steam folder

    steampath = steampath.substr(0,2) + "\\"; //template: c:/
    
    steampath += "Program Files (x86)\\"; //template: c:/Program Files (x86)
    if (!std::filesystem::exists(steampath)) {
        //Return code 101: Unable to exists Program Files (x86)
        return_value["return_code"] = "101";
        return return_value;
    }

    steampath += "Steam\\"; //template: c:/Program Files (x86)/steam
    if (!std::filesystem::exists(steampath)) {
        //Return code 102: Unable to exists steam directory
        return_value["return_code"] = "102";
        return return_value;
    }
    
    std::cout << language.getvalue(localization_data::TYPES::SEARCH_STEAM_FOUND) << steampath << std::endl; //SEARCH_STEAM_FOUND

    return_value["return_value"] = steampath;
    if (!with_account_id) return return_value;

    //--------------------
    bool steam_account_selected = false;

    steampath += "userdata\\"; //template: c:/Program Files (x86)/steam/userdata
    if (!std::filesystem::exists(steampath)) {
        //Return code 103: Unable to exists ./Steam/userdata
        return_value["return_code"] = "103";
        return return_value;
    }

    for (const std::filesystem::path iterator : std::filesystem::directory_iterator(steampath)) {
        std::string account_id = "";

        if (!std::filesystem::is_directory(iterator)) continue;
        account_id = iterator.filename().string();
                
        while (!steam_account_selected) {

            int choice = 0;
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

                return_value["return_value"] = steampath;
                return return_value;
            }

            else if (choice == 2) break;

            else if (choice == 3) {
                std::cout << language.getvalue(localization_data::TYPES::SEARCH_CHECKIN_BROWSER) << account_id << std::endl; //SEARCH_CHECKIN_BROWSER
                
                std::cout << language.getvalue(localization_data::TYPES::GENERAL_PAUSE); //SEARCH_PAUSE
                std::cin.ignore();
                std::cin.get();

            }
        }

    }


    if (!steam_account_selected) {
        //Return code 104: Steam account not selected or isn't exists
        return_value["return_code"] = "104";
        }
        return return_value;


}