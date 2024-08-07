#pragma once
#include <string>
#include <Window.h>
#include <MyGui.h>

#ifdef _WIN32
extern std::string resPath;
extern std::string shadersPath;
extern std::string texturesPath;
#else 
extern std::string resPath;
extern std::string shadersPath;
extern std::string texturesPath;
#endif

