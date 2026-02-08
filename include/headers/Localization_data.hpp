#pragma once
#include <iostream>
#include <map>
#include <string>

#include <Localization.hpp>

    std::map<LOC_TYPES, std::string> RU {
        {GENERAL_PAUSE, "\nНажмите на любую кнопку чтобы продолжить...\n"},

        //-------------------------

        {MAIN_WARNING_SELECT_ACTION, "Пожалуйста выберите действие из списка"},
        {MAIN_STARTUP_UI, R"(
                _______ ___ ___       __                 _
               / / / __/ __|_  )  __ / _|__ _ _ __  __ _| |_____ _ _
              / / / (__\__ \/ /  / _|  _/ _` | '  \/ _` | / / -_) '_|
             /_/_/ \___|___/___|_\__|_| \__, |_|_|_\__,_|_\_\___|_|
                                     |___|     |___/
                   
                        --------------------------------------
                        |CS2_cfgmaker - настройка CFG для CS2|
                        |Создатель:https://github.com/SG123it|
                        --------------------------------------
                        |  Выберите действие и нажмите       |
                        |  enter для продолжения      :)     |
                        -|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
                        |   [1] - Как начать                 |
                        |       [2] - Посетить github        |
                        |           [3] - Начать             |
                        |               [4] - Выйти          |
                        --------------------------------------
    )"},
        {MAIN_WARNING_SOMEFUNC_UNAVAILABLE, R"(
    --------------------------------------------------------------------------------------------------------
    | Некоторые функции недоступны. за доп. информацией пожалуйста прочтите readme.md на github репозитории|
    |                                       Спасибо за понимание!                                          |
    --------------------------------------------------------------------------------------------------------
            )"},
        {MAIN_THANK_YOU_GITHUB, "Спасибо за посещение моей страницы github :)"},
        {MAIN_THANK_YOU, "Спасибо что используйте эту программу"},
        {MAIN_ERROR_WARNING, "Что то пошло не так\nПожалуйста попробуйте снова или прочтите readme.md: https://github.com/SG123it/cs2_cfgmaker"},
        {MAIN_UNKNOWN_ERROR_WARNING, "Неизвестная ошибка!\nПожалуйста сообщите о ней на мой репозиторий github: https://github.com/SG123it/cs2_cfgmaker"},

        //-------------------------

        {START_STEP1, "Шаг 1 - Заполнение переменных..."},
        {START_STEAM_NOT_FOUND, "Путь до стима не найден!\nХотите ли вы указать его вручную?\n[1] - ДА\n[2] - НЕТ\n>>> "},
        {START_ENTER_PATH, "Пожалуйста введите полный путь до steam/userdata/<your_account_id>\n >>> "},
        {START_STEP2, "Шаг 2 - Запись в конфигурационный файл..."},
        {START_DO_NOT_CLOSE_PROGRAM, "Все файлы открыты. Пожалуйста не закрывайте эту программу..."},
        {START_BIND_DETECTED, "Обнаружен бинд:  "},
        {START_SETTINGS_DETECTED, "Обнаруженна настройка: "},
        {START_STEP3, "Шаг 3 - Последние шаги..."},
        {START_PATH_TO_CFG, "Путь до конфигурационного файла: "},
        {START_END_THANK_YOU, R"(

                             ------------ 
                             | ХИХИХИХА |  
            ----------------------------------------------
            | Спасибо за использование CS2_cfgmaker      |
            | Если вы хотели бы о чём либо сообщите      |
            | пожалуйста свяжитесь со мной через github  |
            |                                            |
            | Если моя программа Вам помогла пожалуйста  |
            | Оцените её                                 |
            | https://github.com/SG123it/cs2_cfgmaker    |
            ----------------------------------------------


        )"},

        //-------------------------

        {INSTRUCTION_TEXT, R"(
                        --------------
                        | Как начать |
            --------------------------------------------
            |                                          |
            | 1. Запустите CS2                         |
            | 2. Откройте консоль                      |
            | 3. Введите "host_writeconfig"            |
            | 4. Закройте игру                         |
            | 5. Теперь вы можете запускать программу  |
            |                                          |
            --------------------------------------------


        )"},

        //-------------------------

        {SEARCH_IS_YOUR_ACCOUNT, " : Ваш аккаунт?\n[1] - ДА\n[2] - НЕТ\n[3] - Проверить в браузере \n>>> "},
        {SEARCH_STEAM_FOUND, "Steam найден - "}

};
std::map<LOC_TYPES, std::string> EN {
        {GENERAL_PAUSE, "\nPress any key to continue...\n"},

        //-------------------------

        {MAIN_WARNING_SELECT_ACTION, "Please select action from the list!"},
        {MAIN_STARTUP_UI, R"(
                _______ ___ ___       __                 _
               / / / __/ __|_  )  __ / _|__ _ _ __  __ _| |_____ _ _
              / / / (__\__ \/ /  / _|  _/ _` | '  \/ _` | / / -_) '_|
             /_/_/ \___|___/___|_\__|_| \__, |_|_|_\__,_|_\_\___|_|
                                     |___|     |___/
                   
                        ------------------------------------ 
                        |CS2_cfgmaker                      |
                        |Creator:https://github.com/SG123it|
                        ------------------------------------
                        |  Choise a action and press enter |
                        |  to continue      :)             |
                        -|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|-|
                        |   [1] - How to start             |
                        |       [2] - Visit my github      |
                        |           [3] - Start            |
                        |               [4] - Quit         |
                        ------------------------------------
        )"},
        {MAIN_WARNING_SOMEFUNC_UNAVAILABLE, R"(
    ----------------------------------------------------------------------------------------------
    | Some functions unavailable. For more information please read readme.md in github repository|
    |                           Thank you for understanding!                                     |
    ----------------------------------------------------------------------------------------------
            )"},
        {MAIN_THANK_YOU_GITHUB, "Thank you for visit my github page :)"},
        {MAIN_THANK_YOU, "Thank you for using my program"},
        {MAIN_ERROR_WARNING, "Something went wrong\nPlease try again or read readme.md here: https://github.com/SG123it/cs2_cfgmaker"},
        {MAIN_UNKNOWN_ERROR_WARNING, "Unknown error!\nPlease report this to our repository on github: https://github.com/SG123it/cs2_cfgmaker"},

        //-------------------------

        {START_STEP1, "Step 1 - Filling variables..."},
        {START_STEAM_NOT_FOUND, "Path to steam not found!\nDo you want to write a path manually?\n[1] - YES\n[2] - NO\n>>> "},
        {START_ENTER_PATH, "Please enter full path to steam/userdata/<your_account_id>\n >>> "},
        {START_STEP2, "Step 2 - Writing to CFG..."},
        {START_DO_NOT_CLOSE_PROGRAM, "All files are open. Please do not close the program..."},
        {START_BIND_DETECTED, "Detected bind:  "},
        {START_SETTINGS_DETECTED, "Detected settings: "},
        {START_STEP3, "Step 3 - Final step..."},
        {START_PATH_TO_CFG, "Path to configuration file: "},
        {START_END_THANK_YOU, R"(

                             ------------ 
                             | HEHEHEHA |  
            ----------------------------------------------
            | Thank you for using CS2_cfgmaker           |
            | If you want to tell something to me please |
            | Contact me at my github profile            |
            |                                            |
            | If i helped you please rate my github repo |
            | https://github.com/SG123it/cs2_cfgmaker    |
            ----------------------------------------------


        )"},

        //-------------------------

        {INSTRUCTION_TEXT, R"(
                        ----------------
                        | How to start |
            --------------------------------------------
            |                                          |
            | 1. Launch CS2                            |
            | 2. Open console                          |
            | 3. Write "host_writeconfig"              |
            | 4. Close the game                        |
            | 5. Now you can run the program           |
            |                                          |
            --------------------------------------------


        )"},

        //-------------------------

        {SEARCH_IS_YOUR_ACCOUNT, " : Is your account?\n[1] - YES\n[2] - NO\n[3] - Check in browser \n>>> "},
        {SEARCH_STEAM_FOUND, "Steam found - "}
};