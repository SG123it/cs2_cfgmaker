#include <iostream>
#include <filesystem>
#include <map>

#include <Localization.hpp> //func from ./include

#pragma once


//Find the path to steam folder
std::map<std::string, std::string> steam_path(localization& language, bool with_account_id = false);