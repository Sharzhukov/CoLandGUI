//  Event.hpp
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
#include "../include/Enum.hpp"

#ifndef Event_hpp
#define Event_hpp

class Event {
    std::string name;
    std::string description;
    Events type;
    int footChange;
    int materialsChange;
    int healthChange;
    int moodChange;
    int shelterChange;
    
    //TODO: logic in type events for constructor;
    
public:
    Event(std::string name = std::string(), std::string description = std::string(), Events type = Events()) {
        this->name = name;
        this->description = description;
        this->type = type;
    }
    
    std::string GetName() { return  name; }
    std::string GetDesription() { return description; }
    std::string GetTypeName() {
        switch (type) {
            case Events::Positive:
                return "Positive";
            case Events::Neutral:
                return "Neutral";
            case Events::Negative:
                return "Negative";
            default:
                return "Neutral";
        }
    }
    Events GetType() { return type; }
    int GetFoot() { return footChange; }
    int GetMaterials() { return materialsChange; }
    int GetHealth() { return healthChange; }
    int GetMood() { return moodChange; }
    int GetShelter() { return shelterChange; }
    
};

#endif /* Event_hpp */
