//  wedding.hpp
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
#include "../include/Colonist.hpp"

#ifndef Wedding_hpp
#define Wedding_hpp

class Colonist;

namespace coland::entities {
    class Wedding {
        int dayWedding;
        Colonist* male;
        Colonist* female;
        std::vector<Colonist*> children;
    public:
        bool Empty();
        //TODO: GET male female;
        int GetDay();
        void SetMale(Colonist* male);
        void SetFemale(Colonist* female);
        void AddChildren(Colonist* children);
    };
}


#endif /* Wedding_hpp */
