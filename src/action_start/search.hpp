#include <iostream>
#include <filesystem>
#include <map>

#include <Localization.hpp> //func from ./include
#include <return_standart.hpp> //func from ./include

#pragma once


/*Find the path to steam folder
add.information = return value
Return code 101: Unable to exists Program Files (x86)
Return code 102: Unable to exists steam directory
Return code 103: Unable to exists ./Steam/userdata
Return code 104: Steam account not selected or isn't exists
Return code 111: Unable to start search::steam_path : available only in windows
*/
return_standart steam_path(localization& language, bool with_account_id = false);