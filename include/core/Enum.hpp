//  Enum.hpp
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
#include "../include/common.hpp"

#ifndef Enum_hpp
#define Enum_hpp

enum class Profession { Idle, Farmer, Builder, Medic, Scout, Guard, COUNT };
enum class Events { Positive, Neutral, Negative, COUNT };
enum class Gender { Male, Female, COUNT };
enum class StateColonist { Health, Hunger, Age, Mood, COUNT };
enum class MathSymbol { Add, Minus };
enum class Disease { Healthy };

struct RandName {
    static std::vector<std::string> nameColonyList;
    static std::vector<std::string> nameMaleColonistList;
    static std::vector<std::string> nameFemaleColonistList;
private:
    //TODO: LOAD name;
};
/*std::vector<std::string> nameColonyList{"Franki", "Regini", "Avanger", "Avrora"};
std::vector<std::string> nameMaleColonistList{"Denis", "Moki", "Huritan", "Kodzim"};
std::vector<std::string> nameFemaleColonistList{"Lora", "Jenis", "Veta", "Loki"};*/
//TODO: load names is file data, namecolst, ...

#endif /* Enum_hpp */
