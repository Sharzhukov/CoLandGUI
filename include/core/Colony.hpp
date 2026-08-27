//  Colony.hpp
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
#include "Colonist.hpp"
#include "../common/common.hpp"
#include "Enum.hpp"
#include "../common/FileManager.hpp"

#ifndef Colony_hpp
#define Colony_hpp

class Colonist;
class FileManager;
class Wedding;
class Colony {
    friend std::ostream& operator << (std::ostream& out, Colony& colony);
    friend class Colonist;
    friend class coland::entities::Wedding;
private:
    std::string pathColony;
    
    static unsigned idTotal;
    
    std::string name;
    unsigned day;
    unsigned food;
    unsigned materials;
    unsigned shelterStrength;
    unsigned idColony;
    bool isAliveColony;
    std::vector<Colonist> citizens;
    std::vector<std::string> eventLog;
    
public:
    Colony(std::string name = std::string());
    Colonist* AddColonist(std::string name, unsigned age, Gender gender, Profession profession);
    int GetPopulationCount() const;
    std::string& GetName();
    unsigned GetID() const;
    unsigned GetIdColony() const;
    int GetAliveCount() const;
    bool IsAliveColony();
    void MarkDeadColonist();
    void DayReport();
    Colonist& GetColonist(int index);
    
    std::string GetAliveStatusName();
    bool GetAliveStatus();
    std::string GetPathColony() const;
    
    
    /*
     //TODO: postponed
     void save(std::ofstream& filename);
    void load(const std::string& filename);*/
    //TODO: create full setter and getter
    //TODO: create event log, but create save load log. Save log - analitic code. Time out!
};

std::ostream& operator << (std::ostream& out, Colony& colony);
#endif /* Colony_hpp */
