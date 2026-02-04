#include <iostream>
#include <filesystem>
#include <fstream>
#include <clocale>

#include "action_start/start.hpp"
#include "action_instruction/instruction.hpp"

#include <clearwindow.hpp> //func from ./include
#include <Localization.hpp> //func from ./include
#include <return_standart.hpp> //func from ./include
#include <browser.hpp> //func from ./include

//checking OS
//--------------
#if !(defined _WIN32 || defined _WIN64 || defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__) || defined (__APPLE__))
    return 1;
#endif

int main() {

    std::string main_comment = ""; //для комментариев на главном экране
    localization language;
    while (true){
        int lang_choice = 0;
        std::cout << R"(

                            ------------------------------------ 
                            |       Localization system        |
                            ------------------------------------
                            |      Please select language      |
                            |----------------|-----------------|
                            | [1] - Russian  |  [2] - English  |
                            ------------------------------------
            )";

            std::cout << std::endl << main_comment << std::endl;

            std::cout << "\nChoice action: ";
            std::cout << ">>> ";

            std::cin >> lang_choice;

            //From AI
            //-------------------
            if (std::cin.fail()) { 
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                continue;
            }
            //-------------------
            else if (lang_choice < 1 || lang_choice > 2) {
                main_comment = "Please select action from the list!";
                continue;
            }

            if (lang_choice == 1) {
                language.set_language(localization::languages::RUSSIAN);
                setlocale(LC_ALL, "ru-RU.UTF8");
            }
            if (lang_choice == 2) language.set_language(localization::languages::ENGLISH);
            break;
    }



    main_comment = ""; //clear comment
    while(true) {
        clearwindow();

        std::cout << language.getvalue(localization_data::TYPES::MAIN_STARTUP_UI); //Print general UI
        //Output a warning if OS != windows
        #if !defined _WIN32 || !defined _WIN64
            std::cout << language.getvalue(localization_data::TYPES::MAIN_WARNING_SOMEFUNC_UNAVAILABLE); //MAIN_WARNING_SOMEFUNC_UNAVAILABLE
        #endif

        std::cout << std::endl << main_comment << std::endl;

        int choice = 0;
        std::cout << "Choice action: ";
        std::cout << ">>> ";
        std::cin >> choice;
        std::cout << std::endl;
        //From AI
        //-------------------
        if (std::cin.fail()) { 
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            main_comment = language.getvalue(localization_data::TYPES::MAIN_WARNING_SELECT_ACTION); //MAIN_WARNING_SELECT_ACTION
            continue;
        }
        //-------------------
        else if (choice < 1 || choice > 4) {
            main_comment = language.getvalue(localization_data::TYPES::MAIN_WARNING_SELECT_ACTION); //MAIN_WARNING_SELECT_ACTION
            continue;
        }


        if (choice == 1) instruction(language);

        else if (choice == 2) {

            browser::openlink("https://github.com/SG123it");
            main_comment = language.getvalue(localization_data::TYPES::MAIN_THANK_YOU_GITHUB); //MAIN_THANK_YOU_GITHUB

        }

        else if (choice == 3) {
            
            try{ //Try-Catch: 1

                return_standart return_code = start(language);
                if (return_code.code != 0) {
                    main_comment = language.getvalue(localization_data::TYPES::MAIN_ERROR_WARNING) + return_code.print(); //MAIN_ERROR_WARNING
                }
                else main_comment = language.getvalue(localization_data::TYPES::MAIN_THANK_YOU);//MAIN_THANK_YOU

            }
            catch (...) {

                main_comment = language.getvalue(localization_data::TYPES::MAIN_UNKNOWN_ERROR_WARNING); //MAIN_UNKNOWN_ERROR_WARNING
                continue;
            } 
        }
        else if (choice == 4) return 0;

        clearwindow();

    }
    
    

}