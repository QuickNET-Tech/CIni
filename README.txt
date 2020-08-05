[ ----- CIni Information ----- ]

A simple single-header INI class with inbuilt exception handling
Written by : QuickNET
Latest Version : 1.2.0
Release Date : 2020/08/05

[ ----- CIni Change Log ----- ]

Version 1.2.1
 - Added const char* overloads for all get/set functions excluding unsafe getters
 - Fixed usage of incorrect string to type functions on getters

Version 1.2.0
 - Added a second constructor taking a const char*
 - Added macro to customize buffer size
   - Define `CINI_BUFFER_SIZE` with the value of the desired buffer size before your inclusion of `CIni.h`
   - If you do not define `CINI_BUFFER_SIZE` it will be defined for you and will be set to 0xFF
 - Replaced static buffer size in call to `GetPrivateProfileStringA` with `sizeof(buf)`
 - A little less std::string
 - A fuck ton more const
 - Class instances can now be const
 - Removed tons of redundant code (particularly redundant try/catch statements)

Version 1.1.1
 - Moved CIni Information and CIni Change Log into a separate read me file

Version 1.1.0
 - Marked converting constructor as explicit
 - Converted usage of std::string to const std::string&
 - Fixed CIni::getBool mistakenly returning a float

Version 1.0.0
 - Initial release