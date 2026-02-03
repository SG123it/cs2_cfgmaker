<!------------------------------>
<h2>Feedback: </h2>
<h3>
<b>
If you find a bug please report here: https://github.com/SG123it/cs2_cfgmaker/discussions <br>
Thank you for your feedback in advance
</b>
<h3>

<!------------------------------>
<h1>About program: </h1>
<h3>
cfgmaker for cs2 - pet project for build your personal configuration file in cs2
<b>
Supported languages: Russian, English<br></b>
<br><br>
<b>
Supported OS: windows<br>
Note: You can build program in linux and MacOS<br>but some functions will be unavailable
</b>
<h3>
<!------------------------------>
<h1>Launching program: </h1>

<h2>Download from github:</h2>
<b>

1) Go to https://github.com/SG123it/cs2_cfgmaker/releases <br>
2) Download latest version <br>
3) Open program
   
</b>

<hr>

<br><br><br>
<!------------------------------>
<h1>Build using CMAKE: </h1>

<b>

! Before building make sure that you have installed:<br>
Cmake: https://cmake.org/ <br>
G++/GCC or another compiler: https://www.msys2.org/<br>
<hr>

1) open console <br>
2) Write cd "Path to project" <br>
3) Write cmake -B build -G "MinGW Makefiles" <br>
4) Write cmake --build build <br>
   
</b>

<hr>

<br><br><br>
<!------------------------------>
<h1>Return codes: </h1>

<h3>
<b>
Return code 101: Unable to exists Program Files (x86)<br><br>
Return code 102: Unable to exists steam directory<br><br>
Return code 103: Unable to exists ./Steam/userdata<br><br>
Return code 104: Steam account not selected or isn't exists<br><br>
Return code 105: folder "730"(CS2 settings) isn't exists in user_folder(steam)<br><br>
Return code 106: folder "730/local/cfg"(CS2 cfg path) isn't exists<br><br>
Return code 107: Unable to open "cs2_user_keys_0_slot0.vcfg" file<br><br>
Return code 108: Unable to open "cs2_machine_convars.vcfg" file<br><br>
Return code 109: Unable to open "cs2_user_convars_0_slot0.vcfg" file<br><br>
Return code 110: Unable to open new "configuration_CS.cfg" file at downloads<br><br>
Return code 111: Unable to start search::steam_path : available only in windows<br><br>

Return code -1: Critical error<br><br><br>
<br><br>
</b>
</h3>
<!------------------------------>
<h1>Localization keys: </h1>

<h3><b>GENERAL_PAUSE</b></h3>

<h3>
<b>
<h2>src/main.cpp </h2>
MAIN_WARNING_SELECT_ACTION<br>
MAIN_STARTUP_UI<br>
MAIN_WARNING_SOMEFUNC_UNAVAILABLE<br>
MAIN_WARNING_SELECT_ACTION<br>
MAIN_THANK_YOU_GITHUB<br>
MAIN_THANK_YOU<br>
MAIN_ERROR_WARNING<br>
MAIN_CRITICAL_ERROR_WARNING<br>
MAIN_UNKNOWN_ERROR_WARNING<br><br>

<h2>src/action_start/start.cpp </h2>
START_STEP1<br>
START_STEAM_NOT_FOUND<br>
START_ENTER_PATH<br>
START_STEP2<br>
START_DO_NOT_CLOSE_PROGRAM<br>
START_BIND_DETECTED<br>
START_SETTINGS_DETECTED<br>
START_STEP3<br>
START_PATH_TO_CFG<br>
START_END_THANK_YOU<br><br>

<h2>src/action_instruction/instruction.cpp </h2>
INSTRUCTION_TEXT<br><br>

<h2>include/search.cpp </h2>
SEARCH_IS_YOUR_ACCOUNT<br>
SEARCH_STEAM_FOUND<br>
SEARCH_CHECKIN_BROWSER<br>
<br>
</b>
</h3>

<hr>
<!------------------------------>