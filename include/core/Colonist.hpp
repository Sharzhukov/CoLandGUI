//  Colonist.hpp
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
#include "Colony.hpp"
#include "../common/common.hpp"
#include "Enum.hpp"
#include "Wedding.hpp"

#ifndef Colonist_hpp
#define Colonist_hpp

class Colony;
class Wedding;
class Colonist {
    friend std::ostream& operator << (std::ostream& out, Colonist& colonist);
    friend std::ostream& operator << (std::ostream& out, Colony& colony);
    friend class Colony;
    friend class coland::entities::Wedding;
    
    const int MIN_VALUE_STATUS = 0;
    const int MAX_VALUE_STATUS = 100;
    const int MAX_VALUE_AGE = 120;

    
    /*
     //TODO: postponed
     void LoadColonist(std::ifstream& inF);
    void SaveColonist(std::ofstream& outF) const;*/
private:
    std::string pathColonist;
    
    //Variable data
    static unsigned idTotal;
    unsigned idColonist;
    unsigned idColony;
    std::string name;
    unsigned age;
    
    //Variable health
    unsigned health;
    unsigned hunger;
    unsigned mood;
    
    //Variable Individual
    Profession profession;
    bool aliveStatus;
    unsigned daysLived;
    
    //Addon
    Gender gender;
    Colonist* wedding;
    //coland::entities::Wedding m_wedding;
    Colony* colony;
    Disease disease;

    void AutoBirthColonist();
    bool CheckGender(Colonist& colonist);
    void CheckState(StateColonist stateColonist, MathSymbol mathSymbol, unsigned value);
    void CheckState();
public:
    Colonist(std::string name, unsigned age, Gender gender, Profession profession, Colony* colony = nullptr);
    Colonist() : Colonist(std::string(), unsigned(), Gender(), Profession()) {};
    ~Colonist();
    
    void takeHunger(int value);
    void takeDamage(int value);
    void takeMood(int value);
    
    void recHunger(int value);
    void recHealth(int value);
    void recMood(int value);
    
    //Foon data
    static unsigned GetID();
    const unsigned& GetIdColonist() const;
    const std::string& GetName() const;
    void SetName(std::string& name);
    const unsigned& GetAge() const;
    
    //Foon health
    const unsigned& GetHealth() const;
    const unsigned& GetHunger() const;
    const unsigned& GetMood() const;
    
    //Foon Individual
    const Profession& GetProfession() const;
    const Gender& GetGender() const;
    
    const std::string GetProfessionName() const;
    const std::string GetGenderName() const;
    const std::string GetAliveStatusName() const;
    
    const bool& GetAliveStatus() const;
    const unsigned& GetDaysLived() const;
    
    Colonist* GetWedding();
    Colony* GetColony();
    unsigned GetIdColony() const;
    Disease& GetDisease();
    
    void weddingColonist(Colonist& colonist);
    void UpdateDay();
    void workColonist();
    std::string GetDiseaseName() const;
    std::string GetPathColonist();
};
std::ostream& operator << (std::ostream& out, Colonist& colonist);

class colFramer : Colonist {
    //TODO: postponed
};

class colBuilder : Colonist {
    //TODO: postponed
};

#endif /* Colonist_hpp */
