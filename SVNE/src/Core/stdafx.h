#pragma once

#ifdef _DEBUG
#pragma comment ( lib, "sfml-main-d.lib")
#pragma comment ( lib, "sfml-window-d.lib")
#pragma comment ( lib, "sfml-system-d.lib")
#pragma comment ( lib, "sfml-graphics-d.lib")
#elif NDEBUG
#pragma comment ( lib, "sfml-main.lib")
#pragma comment ( lib, "sfml-window.lib")
#pragma comment ( lib, "sfml-system.lib")
#pragma comment ( lib, "sfml-graphics.lib")
#endif

#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "../Tools/Tools.h"

#include <iostream>
#include <fstream>