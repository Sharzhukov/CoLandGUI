//  Colonist.cpp
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

#include "../include/core/Colonist.hpp"

unsigned Colonist::idTotal = 0;

Colonist::Colonist(std::string name, unsigned age, Gender gender, Profession profession, Colony* colony) {
    idColonist = idTotal++;
    this->name = name;
    this->age = age;
    this->profession = profession;
    
    health = hunger = mood = 100;
    aliveStatus = true;
    daysLived = 0;
    
    this->colony = colony;
    this->idColony = colony->GetIdColony();
    wedding = nullptr;
    this->gender = gender;
    disease = Disease::Healthy;
    
    pathColonist = (name + "_" + std::to_string(idColonist) + "_" + std::to_string(colony->GetIdColony()) + ".txt");
}
Colonist::~Colonist() {}


// [ Friend ]
std::ostream& operator << (std::ostream& out, Colonist& colonist) {
    out << YELC << "========== [ START INFO COLONIST: " << colonist.GetIdColonist() << " ] ==========\n" << RESETC;
    out << "Colonist Name: " <<  YELC << colonist.GetName() << RESETC << "\n";
    out << "Colonist Age: " << YELC << colonist.GetAge() << " o.y." << RESETC << "\n";
    out << "Colonist Health: " << YELC << colonist.GetHealth() << "%" << RESETC << "\n";
    out << "Colonist Hunger: " << YELC << colonist.GetHunger() << "%" << RESETC << "\n";
    out << "Colonist Mood: " << YELC << colonist.GetMood() << "%" << RESETC << "\n";
    out << "Colonist Profession: " << YELC << colonist.GetProfessionName() << RESETC << "\n";
    out << "Colonist Gender: " << YELC << colonist.GetGenderName() << RESETC << "\n";
    out << "Colonist Disease: " << YELC << colonist.GetDiseaseName() << RESETC << "\n";
    out << "Colonist Wedding: " << YELC << ((colonist.wedding != nullptr) ? (colonist.wedding->name) : ("No Wedding")) << RESETC << "\n";
    out << "Colonist Colony: " << YELC << colonist.colony->GetName() << RESETC << "\n";
    out << "Colonist Alive Status: " << colonist.GetAliveStatusName() << "\n";
    out << "Colonist Days is Lived: " << YELC << colonist.GetDaysLived() << " days" << RESETC << "\n";
    out << YELC << "========== [ END INFO COLONIST: " << colonist.GetIdColonist() << " ] ==========\n" << RESETC;
    
    return out;
}

// [ Foon ]
// #Private
// [ Status day ]
void Colonist::UpdateDay() {
    CheckState(StateColonist::Hunger, MathSymbol::Minus, 2);
    CheckState(StateColonist::Mood, MathSymbol::Add, 10);
    CheckState(StateColonist::Health, MathSymbol::Add, 5);
    CheckState(StateColonist::Age, MathSymbol::Add, 1);
    
    CheckState();
    daysLived++;
}

// [ Foon to health ]
void Colonist::takeHunger(int value) { CheckState(StateColonist::Hunger, MathSymbol::Minus, value); };
void Colonist::takeDamage(int value) { CheckState(StateColonist::Health, MathSymbol::Minus, value); };
void Colonist::takeMood(int value) { CheckState(StateColonist::Mood, MathSymbol::Minus, value); };

void Colonist::recHunger(int value) { CheckState(StateColonist::Hunger, MathSymbol::Add, value); };
void Colonist::recHealth(int value) { CheckState(StateColonist::Health, MathSymbol::Add, value); };
void Colonist::recMood(int value) { CheckState(StateColonist::Mood, MathSymbol::Add, value); };


// #Public

void Colonist::CheckState(StateColonist stateColonist, MathSymbol mathSymbol, unsigned value) {
    switch (stateColonist) {
        case StateColonist::Health:
            if (mathSymbol == MathSymbol::Add) {
                health = (health + value > MAX_VALUE_STATUS) ? (MAX_VALUE_STATUS) : (health + value);
            }
            if (mathSymbol == MathSymbol::Minus) {
                health = (health - value < MIN_VALUE_STATUS) ? (MIN_VALUE_STATUS) : (health - value);
                if (!health) { aliveStatus = false; }
            }
            break;
            
        case StateColonist::Hunger:
            if (mathSymbol == MathSymbol::Add) {
                hunger = (hunger + value > MAX_VALUE_STATUS) ? (MAX_VALUE_STATUS) : (hunger + value);
            }
            if (mathSymbol == MathSymbol::Minus) {
                hunger = (hunger - value < MIN_VALUE_STATUS) ? (MIN_VALUE_STATUS) : (hunger - value);
                if (!hunger) { aliveStatus = false; }
            }
            break;
            
        case StateColonist::Mood:
            if (mathSymbol == MathSymbol::Add) {
                mood = (mood + value > MAX_VALUE_STATUS) ? (MAX_VALUE_STATUS) : (mood + value);
            }
            if (mathSymbol == MathSymbol::Minus) {
                mood = (mood - value < MIN_VALUE_STATUS) ? (MIN_VALUE_STATUS) : (mood - value);
                if (!mood) { aliveStatus = false; }
            }
            break;
            
        case StateColonist::Age:
            if (mathSymbol == MathSymbol::Add) {
                age = (age + value > MAX_VALUE_AGE) ? (MAX_VALUE_AGE) : (age + value);
            }
            if (mathSymbol == MathSymbol::Minus) {
                age = (age - value < MIN_VALUE_STATUS) ? (MIN_VALUE_STATUS) : (age - value);
                if (age == MAX_VALUE_AGE) { aliveStatus = false; }
            }
            break;
            
        default:
            break;
    }
}
void Colonist::CheckState() {
    if (disease != Disease::Healthy) { health -= 2; }
    if (!mood || !hunger || !health || age >= MAX_VALUE_AGE) {
        aliveStatus = false;
        return;
    }
}
//Foon Data
unsigned Colonist::GetID() { return idTotal; }

const unsigned& Colonist::GetIdColonist() const { return idColonist; }
const std::string& Colonist::GetName() const { return name; }
void Colonist::SetName(std::string& name) {
    if (name.size() < 2) {
        throw std::length_error("Your new name is too short (minimum length 2 characters). Your entered name: \"" + name + "\"");
    }
    else if (name.size() > 20) {
        throw std::length_error("Your new name is too long (maximum length 20 characters). Your entered name: \"" + name + "\"");
    }
    else {
        for (std::string::iterator i = name.begin(); i != name.end(); i++) {
            unsigned char ch = (*i);
            if (!(std::isalpha(ch) || ch == '`' || ch == '-')) {
                throw std::invalid_argument("Your new name contains invalid characters. Invalid symbol: \"" + std::string(1, ch) + "\"");
            }
        }
    }
    
    this->name = name;
}
const unsigned& Colonist::GetAge() const { return age; }

//Foon health
const unsigned& Colonist::GetHealth() const { return health;}
const unsigned& Colonist::GetHunger() const {return hunger;}
const unsigned& Colonist::GetMood() const {return mood;}

//Foon Individual
const Profession& Colonist::GetProfession() const { return profession; }
const Gender& Colonist::GetGender() const { return gender; }

const std::string Colonist::GetProfessionName() const {
    switch (profession) {
        case Profession::Farmer: return "Farmer";
        case Profession::Builder: return "Builer";
        case Profession::Medic: return "Medic";
        case Profession::Scout: return "Scout";
        case Profession::Guard: return "Guard";
        default: return "Idle";
    }
}
const std::string Colonist::GetGenderName() const {
    switch (gender) {
        case Gender::Male: return "Male";
        case Gender::Female: return "Female";
        default: return "Male";
    }
}
const std::string Colonist::GetAliveStatusName() const {
    return (aliveStatus) ? ("\x1B[32m Alive \x1B[0m") : ("\x1B[31m Dead \x1B[0m");
}

const bool& Colonist::GetAliveStatus() const {return aliveStatus;}
const unsigned& Colonist::GetDaysLived() const {return daysLived;}

bool Colonist::CheckGender(Colonist& colonist) { return this->gender != colonist.gender; }
void Colonist::weddingColonist(Colonist& colonist) {
    if (!aliveStatus || !colonist.aliveStatus) {
        throw std::logic_error("the settlers you chose are already dead");
    }
    
    if (wedding != nullptr || colonist.wedding != nullptr) {
        throw std::logic_error("One of the colonists is already engaged");
    }

    wedding = (CheckGender(colonist)) ? (&colonist) : (throw std::logic_error("same-sex weddings are prohibited"));
    colonist.wedding = this;
}

Colonist* Colonist::GetWedding() { return wedding; }

Colony* Colonist::GetColony() { return colony; }

void Colonist::workColonist() {
    switch (profession) {
            //TODO: All colonist full work
        case Profession::Farmer:
            colony->food += 2;
            break;
        case Profession::Builder:
            colony->shelterStrength += 1;
            break;
        case Profession::Medic:
            //TODO: Logic Disease % full coloist in Colony
            break;
        case Profession::Scout:
            //TODO: colony->materials += 10% find rescourse; Scout — +10% к шансу найти ресурсы
            break;
        case Profession::Guard:
            //TODO: Guard — защита от угроз
            
            break;
        default:
            //TODO: idle minimal work
            break;
    }
}

//TODO: AutoBirth
/*void Colonist::AutoBirthColonist() {
    if (wedding1->GetDay() == 20) {
        if (rand() % 2 == 1) {
            colony->citizens.emplace_back(RandName::nameMaleColonistList[rand() % RandName::nameMaleColonistList.size()], 0, Gender::Male,
                                          Profession(rand() % (static_cast<int>(Profession::COUNT))), colony);
            wedding1->AddChildren(&colony->citizens.back());
        }
        else {
            colony->citizens.emplace_back(RandName::nameFemaleColonistList[rand() % RandName::nameFemaleColonistList.size()], 0, Gender::Female,
                                          Profession(rand() % (static_cast<int>(Profession::COUNT))), colony);
            wedding1->AddChildren(&colony->citizens.back());
        }
    }
}*/

Disease& Colonist::GetDisease() { return disease; }
std::string Colonist::GetDiseaseName() const {
    switch (disease) {
        case Disease::Healthy:
            return "Full healthy";
        default:
            break;
    }
}

unsigned Colonist::GetIdColony() const { return idColony; }

std::string Colonist::GetPathColonist() {
    return pathColonist;
}

/*
//TODO: postponed
 void Colonist::LoadColonist(std::ifstream& inF) {
    
}

void Colonist::SaveColonist(std::ofstream& outF) const {
    outF << idTotal << "|";
    outF << idColonist << "|";
    outF << name << "|";
    outF << age << "|";
    outF << health << "|";
    outF << hunger << "|";
    outF << mood << "|";
    outF << GetProfessionName() << "|";
    outF << aliveStatus << "|";
    outF << daysLived << "|";
    outF << GetGenderName() << "|";
    //TODO: don`t work wedding->Getidcolony
    if (wedding != nullptr) {
        outF << wedding->idColonist << ":" << wedding->idColony << "|";
    }
    outF << colony->idColony << "|";
    outF << GetDiseaseName() << "|";
}*/
