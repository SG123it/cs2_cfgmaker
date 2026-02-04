#include "start.hpp"

#include <filesystem>
#include <iostream>
#include <map>
#include <fstream>

#include <clearwindow.hpp> //func from ./include
#include "search.hpp"
#include <Localization.hpp> //func from ./include
#include <return_standart.hpp> //func from ./include
#include <browser.hpp> //func from ./include

return_standart start(localization& language) {
    return_standart return_value;

    //Step 1: Filling variables
    //--------------------------------------
    std::cout << "Step 1 - Filling variables..." << std::endl; //START_STEP1

    std::string steam_cfgpath = ""; //Var with path to ./Steam/userdata/userid/730/local/cfg folder
    bool steam_account_selected = false;

    //--------------------
    
    /*add.information = return value
    Return code 101: Unable to exists Program Files (x86)
    Return code 102: Unable to exists steam directory
    Return code 103: Unable to exists ./Steam/userdata
    Return code 104: Steam account not selected or isn't exists
    Return code 111: Unable to start search::steam_path : available only in windows
    */
    try{ //Try-Catch: 2

        return_standart temp = steam_path(language, true);
        if (temp.code != 0) {
            while (true) {
                int choice = 0;
                std::cout << language.getvalue(localization_data::TYPES::START_STEAM_NOT_FOUND); //START_STEAM_NOT_FOUND
                std::cin >> choice;
                
                if (choice < 1 || choice > 2) continue;
                //From AI
                //-------------------
                if (std::cin.fail()) { 
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                    continue;
                }
                //-------------------

                if (choice == 2) {
                    return_value.code = 104;
                    return_value.reason = "Steam account not selected";
                    return_value.file = "src/action_start/start.cpp";
                    return return_value;
                }
                if (choice == 1) {
                    std::string path = "";
                    std::cout << language.getvalue(localization_data::TYPES::START_ENTER_PATH); //START_ENTER_PATH
                    std::cin.ignore();
                    std::getline(std::cin, path);
                    if (!std::filesystem::exists(path)) continue;

                    if (path[path.length() - 1] != '\\') path.append("\\");
                    
                    steam_cfgpath = path;
                    break;
                }
            }
        }

        else steam_cfgpath = temp.additional_information; //add.information = return value
        
    } 
    catch(std::exception& err) {

        return_value.code = -1;
        return_value.reason = std::string(err.what());
        return_value.file = "src/action_start/start.cpp";
        return_value.additional_information = "Critical error: try-catch 2";
        return return_value;

    }
    
    //------------------------------

    steam_cfgpath += "730\\";
    if (!std::filesystem::exists(steam_cfgpath)) {
        //Return code 105: folder "730"(CS2 settings) isn't exists in user_folder(steam)

        return_value.code = 105;
        return_value.reason = "folder 730(CS2 settings) isn't exists in user_folder(steam)";
        return_value.file = "src/action_start/start.cpp";
        return return_value;
        
    }

    steam_cfgpath += "local\\cfg\\";
    if (!std::filesystem::exists(steam_cfgpath)) {
        //Return code 106: folder "730/local/cfg"(CS2 cfg path) isn't exists

        return_value.code = 106;
        return_value.reason = "folder 730/local/cfg(CS2 cfg path) isn't exists";
        return_value.file = "src/action_start/start.cpp";
        return return_value;

    }

    //Step 2: read and build CFG
    //--------------------------------------
    std::cout << "Step 2 - Writing to CFG..." << std::endl; //START_STEP2

    std::fstream user_keys(steam_cfgpath + "cs2_user_keys_0_slot0.vcfg", std::ios::in);
    if (!user_keys.is_open()) {
        //Return code 107: Unable to open "cs2_user_keys_0_slot0.vcfg" file

        return_value.code = 107;
        return_value.reason = "Unable to open cs2_user_keys_0_slot0.vcfg file";
        return_value.file = "src/action_start/start.cpp";
        return return_value;

    }

    std::fstream machine_convars(steam_cfgpath + "cs2_machine_convars.vcfg", std::ios::in);
    if (!machine_convars.is_open()) {
        //Return code 108: Unable to open "cs2_machine_convars.vcfg" file

        return_value.code = 108;
        return_value.reason = "Unable to open cs2_machine_convars.vcfg file";
        return_value.file = "src/action_start/start.cpp";
        return return_value;

    }

    std::fstream user_convars(steam_cfgpath + "cs2_user_convars_0_slot0.vcfg", std::ios::in);
    if (!user_convars.is_open()) {
        //Return code 109: Unable to open "cs2_user_convars_0_slot0.vcfg" file

        
        return_value.code = 109;
        return_value.reason = "Unable to open cs2_user_convars_0_slot0.vcfg file";
        return_value.file = "src/action_start/start.cpp";
        return return_value;

    }

    std::cout << "All files are open. Please do not close the program..." << std::endl; //START_DO_NOT_CLOSE_PROGRAM

    std::string download_path = std::getenv("USERPROFILE");
    download_path += "\\Downloads\\";
    std::string configuration_file_path = download_path += "\\configuration_CS.cfg";


    std::ofstream finish_cfg(configuration_file_path);
    if (!finish_cfg.is_open()) {
        //Return code 110: Unable to open new "configuration_CS.cfg" file at downloads

        return_value.code = 110;
        return_value.reason = "Unable to open new configuration_CS.cfg file at downloads";
        return_value.file = "src/action_start/start.cpp";
        return return_value;

    }

    std::string line;

    finish_cfg << "echo cs2_user_keys_0_slot0.vcfg" << std::endl << std::endl;

    //Write user_keys to CFG
    //----------------------
    while (std::getline(user_keys, line)) {

        for (int i = 0; i < line.size() - 1; i++) {

            if (i <= 1 && line[i] == '\t') {
                line = line.erase(i, i + 1);
                i--;
            }
            else if (i > 1 && line[i] == '\t') line[i] = ' ';

        }

        //RULES
        //---------
        if (line.empty()) continue;
        if (line == "\"config\"" || line == "\t\"bindings\"" || line == "\t\"analogbindings\"" || line == "\"config\"" || line == "\"bindings\"" || line == "\"analogbindings\"" || line == "\t{" || line == "\t}" || line == "{" || line == "}") continue;
        //---------

        line = "bind " + line;
        std::cout << language.getvalue(localization_data::TYPES::START_BIND_DETECTED) << line << std::endl; //START_BIND_DETECTED

        finish_cfg << line << std::endl;


    }
    user_keys.close();

    finish_cfg << std::endl << std::endl << "echo cs2_user_convars_0_slot0.vcfg" << std::endl << std::endl;
    line = "";


    //Write machine_convars to CFG
    //----------------------
    while (std::getline(machine_convars, line)) {

        for (int i = 0; i < line.size() - 1; i++) {

            if (i <= 1 && line[i] == '\t') {
                line = line.erase(i, i + 1);
                i--;
            }
            else if (i > 1 && line[i] == '\t') line[i] = ' ';

        }

        //RULES
        //---------

        if (line.empty()) continue;
        if (line == "\"config\"" || line == "\"convars\"" || line == "\t\"convars\"" || line == "\t{" || line == "\t}" || line == "{" || line == "}") continue;

        if (line.find("$") != std::string::npos) {
            std::string first_part = line.substr(0, line.find("  "));
            std::string second_part = line.substr(line.find("  "), line.size() - 1);

            first_part = first_part.substr(0, first_part.find("$")) + "\"";
            
            line = first_part + second_part;
        }

        //---------

        std::cout << language.getvalue(localization_data::TYPES::START_SETTINGS_DETECTED) << line << std::endl; //START_SETTINGS_DETECTED

        finish_cfg << line << std::endl;


    }
    machine_convars.close();

    finish_cfg << std::endl << std::endl << "echo cs2_user_convars_0_slot0.vcfg" << std::endl << std::endl;
    line = "";

    //Write user_convars to CFG
    //----------------------
    while (std::getline(user_convars, line)) {

        for (int i = 0; i < line.size() - 1; i++) {

            if (i <= 1 && line[i] == '\t') {
                line = line.erase(i, i + 1);
                i--;
            }
            else if (i > 1 && line[i] == '\t') line[i] = ' ';

        }

        //RULES
        //---------

        if (line.empty()) continue;
        if (line == "\"config\"" || line == "\"convars\"" || line == "\t\"convars\"" || line == "\t{" || line == "\t}" || line == "{" || line == "}") continue;

        if (line.find("$") != std::string::npos) {
            std::string first_part = line.substr(0, line.find("  "));
            std::string second_part = line.substr(line.find("  "), line.size() - 1);

            first_part = first_part.substr(0, first_part.find("$")) + "\"";
            
            line = first_part + "  " + second_part;
        }

        //---------

        std::cout << language.getvalue(localization_data::TYPES::START_SETTINGS_DETECTED) << line << std::endl; //START_SETTINGS_DETECTED

        finish_cfg << line << std::endl;
    }
    user_convars.close();
    line = "";

    std::cout << language.getvalue(localization_data::TYPES::START_STEP3) << std::endl << std::endl; //START_STEP3


    finish_cfg << "echo + | - -------------------------------------" << std::endl;
    finish_cfg << "echo --|--|  Config created with CS2_cfgmaker   |" << std::endl;
    finish_cfg << "echo - | + -------------------------------------" << std::endl;
    finish_cfg << "echo Learn more: github.com/SG123it/cs2_cfgmaker" << std::endl;
    
    finish_cfg.close();

    std::cout << language.getvalue(localization_data::TYPES::START_PATH_TO_CFG) << configuration_file_path; //START_PATH_TO_CFG
    std::cout << language.getvalue(localization_data::TYPES::START_END_THANK_YOU); //START_END_THANK_YOU

    std::cout << language.getvalue(localization_data::TYPES::GENERAL_PAUSE); //SEARCH_PAUSE
    std::cin.ignore();
    std::cin.get();
    clearwindow();

    return_value.code = 0;
    return return_value;

}