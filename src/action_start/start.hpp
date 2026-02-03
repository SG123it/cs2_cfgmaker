#pragma once
#include <iostream>
#include <Localization.hpp>
#include <map>

//Start keys: return_code, error_reason, error_file
std::map<std::string, std::string> start(localization& language);