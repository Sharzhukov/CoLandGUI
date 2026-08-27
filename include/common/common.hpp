//  common.hpp
//  CoLand
//
//  Copyright (C) 2026 Alexander Sharzhukov
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.

#pragma once

#ifndef stdafx_hpp
#define stdafx_hpp

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <fstream>
#include <filesystem>
#include <cstdlib>
#include <stdio.h>
#include <ostream>
#include <ctime>
#include <memory>
#include <thread>
#include <chrono>
#include <vector>

#endif /* stdafx_hpp */


#ifndef ConsoleColor
#define ConsoleColor

namespace ConsoleColor {
#define BLKC "\x1B[30m"
#define REDC "\x1B[31m"
#define GRNC "\x1B[32m"
#define YELC "\x1B[33m"
#define BLUC "\x1B[34m"
#define MAGC "\x1B[35m"
#define CYNC "\x1B[36m"
#define WHTC "\x1B[37m"

#define RESETC "\x1B[0m"
}

#endif /* ConsoleColor */



#ifndef meNamespace
#define meNamespace
namespace coland {
    // [ CL Utils ]
    inline namespace CLUtil {
        void clear();
        void sleep(int ms);
        void getch();
        std::time_t GetTimeNow();
    }

    // [ types | (enums) ]
    namespace types {
        
    }

    // [ component | (components) ]
    namespace component {

    }
    
    // [ entities | (classes) ]
    namespace entities {
        class Wedding;
    }
}

#endif /* meNamespace */