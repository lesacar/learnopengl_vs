#pragma once
#include <string>
#include "Timer.h"
#include <Window.h>

#ifdef _WIN32
extern std::string resPath;
extern std::string shadersPath;
extern std::string texturesPath;
#else 
extern std::string resPath;
extern std::string shadersPath;
extern std::string texturesPath;
#endif

