#include "Timer.h"
#include <Window.h>
#include <string>

#ifdef _WIN32
std::string resPath = "..\\res\\";
std::string shadersPath(resPath + "shaders\\");
std::string texturesPath(resPath + "tex\\");
#else 
std::string resPath = "../res/";
std::string shadersPath(resPath+"shaders/");
std::string texturesPath(resPath+"tex/");
#endif

