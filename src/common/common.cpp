//  common.cpp
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

#include "../include/common.hpp"

void coland::CLUtil::clear() {
    std::cout << "\033[2J\033[H";
}

void coland::CLUtil::sleep(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void coland::CLUtil::getch() {
    std::cin.get();
}

std::time_t coland::CLUtil::GetTimeNow()  {
    auto timeNow = std::chrono::system_clock::now();
    return std::chrono::system_clock::to_time_t(timeNow);
}
