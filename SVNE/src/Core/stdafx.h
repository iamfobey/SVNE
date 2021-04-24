#pragma once

#define SVNE_VERSION v0.0.0.1

#ifdef _DEBUG
#pragma comment ( lib, "sfml-main-d.lib")
#pragma comment ( lib, "sfml-window-d.lib")
#pragma comment ( lib, "sfml-system-d.lib")
#pragma comment ( lib, "sfml-graphics-d.lib")
#pragma comment ( lib, "sfml-audio-d.lib" )
#elif NDEBUG
#pragma comment ( lib, "sfml-main.lib")
#pragma comment ( lib, "sfml-window.lib")
#pragma comment ( lib, "sfml-system.lib")
#pragma comment ( lib, "sfml-graphics.lib")
#pragma comment ( lib, "sfml-audio.lib" )
#endif

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "SFML/Window.hpp"

#include <iostream>
#include <fstream>
#include <string>