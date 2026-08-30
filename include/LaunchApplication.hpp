//  LaunchApplication.hpp
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
#include "common/common.hpp"
#include "core/Colonist.hpp"
#include "core/Colony.hpp"
#include "core/Enum.hpp"
#include "core/Event.hpp"
#include "core/Wedding.hpp"
namespace coland {
    void runApplication();
}

#ifndef LaunchApplication_hpp
#define LaunchApplication_hpp

class DayReport {
    /*
     day — номер дня
     productionLog — массив строк (что произвели)
     consumptionLog — массив строк (что съели/потратили)
     stateLog — массив строк (изменения здоровья, голода и т.д.)
     eventDescription — описание события
     deathLog — массив строк (кто умер и почему)
     summary — итоговая строка (изменение населения, ресурсов и т.д.)
     */
    
    
};

class ColonySimulator {
    
};

class ColonyLog {
    
};

#endif /* LaunchApplication_hpp */
