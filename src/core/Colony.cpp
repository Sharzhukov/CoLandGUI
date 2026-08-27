//  Colony.cpp
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

#include "../include/Colony.hpp"

unsigned Colony::idTotal = 0;

Colony::Colony(std::string name) {
    idColony = idTotal++;
    this->name = name;
    
    if (name == std::string()) {
        this->name = RandName::nameColonyList[rand() % RandName::nameColonyList.size()];
    }
    
    day = food = materials = shelterStrength = 0;
    isAliveColony = true;
    
    const int MIN_AGE_CREATE = 20;
    const int MAX_AGE_CREATE = 40;
    int ageCreate = MIN_AGE_CREATE + rand() % (MAX_AGE_CREATE - MIN_AGE_CREATE + 1);
    
    citizens.emplace_back(RandName::nameMaleColonistList[rand() % RandName::nameMaleColonistList.size()], ageCreate, Gender::Male,
                          Profession(rand() % (static_cast<int>(Profession::COUNT))), this);
    
    ageCreate = MIN_AGE_CREATE + rand() % (MAX_AGE_CREATE - MIN_AGE_CREATE + 1);
    
    citizens.emplace_back(RandName::nameFemaleColonistList[rand() % RandName::nameFemaleColonistList.size()], ageCreate, Gender::Female,
                          Profession(rand() % (static_cast<int>(Profession::COUNT))), this);

    citizens[0].wedding = &citizens[1];
    citizens[1].wedding = &citizens[0];
    
    pathColony = (name + "_" + std::to_string(idColony) + ".txt");
}

std::string Colony::GetPathColony() const {
    return pathColony;
}

void Colony::MarkDeadColonist() {
    for (int i = 0; i < citizens.size(); citizens[i++].CheckState());
}

Colonist* Colony::AddColonist(std::string name, unsigned int age, Gender gender, Profession profession) {
    citizens.emplace_back(name, age, gender, profession, this);
    
    return &citizens.back();
}

int Colony::GetPopulationCount() const { return (unsigned int)citizens.size(); }

int Colony::GetAliveCount() const {
    int sizeAlive{};
    for (int i = 0; i < citizens.size(); i++) { if (citizens[i].aliveStatus) { sizeAlive++;} }
    
    return sizeAlive;
}

bool Colony::IsAliveColony() {
    int sizeAlive{};
    for (int i = 0; i < citizens.size(); i++) { if (citizens[i].aliveStatus) { sizeAlive++;} }
    
    if (!sizeAlive) { isAliveColony = false; }
    return isAliveColony;
}

bool Colony::GetAliveStatus() { return isAliveColony; }

std::string Colony::GetAliveStatusName() {
    return (GetAliveStatus()) ? ("\x1B[32m Alive \x1B[0m") : ("\x1B[31m Dead \x1B[0m");
}


//TODO: std::left, std::setfill('~'), std::setw(10)
std::ostream& operator << (std::ostream& out, Colony& colony) {
    out << YELC << "========== [ LAUNCH INFO COLONY: " << colony.idColony << " ] ==========\n" << RESETC;
    out << "Colony Name: " <<  YELC << colony.name << RESETC << "\n";
    out << "Colony Alive: " <<  YELC << colony.GetAliveStatusName() << RESETC << "\n";
    out << "Colony Day: " << YELC <<  colony.day << RESETC << "\n";
    out << "Colony Food: " << YELC << colony.food << RESETC << "\n";
    out << "Colony Materials: " << YELC << colony.materials << RESETC << "\n";
    out << "Colony Shelter Strength: " << YELC << colony.shelterStrength << RESETC << "\n";
    out << MAGC << "===" << " Colony population ==> " << RESETC << "\n";
    
    out << YELC;
    for (int i = 0; i < colony.citizens.size(); i++) {
        out << MAGC << "Colonist " << (i + 1) << YELC << " [ID " << colony.citizens[i].GetIdColonist() << "]" << "\n";
        out << "\tname: " << colony.citizens[i].GetName() << "\n";
        out << "\tage: " << colony.citizens[i].GetAge() << "\n";
        out << "\tgender: " << colony.citizens[i].GetGenderName() << "\n";
        out << "\tprofession: " << colony.citizens[i].GetProfessionName() << "\n";
        out << "\tdisease: " << colony.citizens[i].GetDiseaseName() << "\n";
        if (colony.citizens[i].GetWedding()) { out << "\tWedding: for " << colony.citizens[i].GetWedding()->GetName() << " (" << "id Cly: " << colony.citizens[i].colony->GetIdColony() << ", " << "id Clt: " << colony.citizens[i].GetIdColonist() << ")" << "\n"; }
        out << "\tColony: " << colony.citizens[i].GetColony()->GetName() << "\n";
    }
    out << RESETC;
    
    out << YELC << "========== [ END INFO COLONY: " << colony.idColony << " ] ==========\n" << RESETC;
    
    return out;
}

unsigned Colony::GetID() const { return idTotal; }

unsigned Colony::GetIdColony() const { return idColony; }

Colonist& Colony::GetColonist(int index) {
    return citizens[index];
}

std::string& Colony::GetName() { return name; }


//TODO: postponed. The complete change and creation of the bottom list will take place after the final result is created.

//TODO: maybe разделение по первичным и вторичным группам
/*void Colony::save(std::ofstream& filename) {
    std::ofstream outColonist;
    FileManager fm;
    
    filename << "id_m" << "::" << name << "\n";
    filename << "id_a" << "::" << idColony << "\n";
    filename << "id_g" << "::" << idTotal << "\n";
    filename << "info" << "::" << citizens.size() << "\n";

    //var ...
    
    
    for (int i = 0; i < citizens.size(); i++) {
        try {
            outColonist.open(fm.GetColonistDIR(citizens[i].GetPathColonist()));
            
            citizens[i].SaveColonist(outColonist);
            
            outColonist.close();
            
        } catch (const std::exception& ex) {
            std::cout << "Error open: " << ex.what() << std::endl;
        }
    }
}

void Colony::load(const std::string& filename) {
    
}*/

//TODO: data + time, VAR -- std::vector<std::string> eventLog;
//TODO: ColonyStats getStats() const — возвращает структуру со статистикой

/*
//TODO: void DayReport();
 DayReport dailyUpdate(EventPool& eventPool) — выполняет один день:
 
 Каждый поселенец работает (work())
 Каждый поселенец ест (eat(1)) — тратится еда
 Каждый поселенец обновляет состояние (dailyUpdate())
 Происходит случайное событие (EventPool::getRandomEvent(day))
 Применяются эффекты события
 Удаляются мёртвые
 */
