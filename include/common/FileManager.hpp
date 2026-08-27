//  FileManager.hpp
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
#include "common.hpp"

#ifndef FileManager_hpp
#define FileManager_hpp

class FileManager {
    // [main dir]
    std::filesystem::path dataFolder = "data"; //root DIR
    std::filesystem::path savesFolder = dataFolder / "saves";
    
    // [col* dir]
    std::filesystem::path colonistFolder = savesFolder / "colonist";
    std::filesystem::path colonyFolder = savesFolder / "colony";
    
    // [fons fir]
    std::filesystem::path logsFolder = dataFolder / "logs";
    std::filesystem::path eventsFolder = dataFolder / "events";
    
    /*std::ifstream LoadlistFile;
    std::vector<std::string> listDIR;*/
public:
    /*void LoadListDIR() {
        for (int i = 0; i < 3; i++) {
            try {
                LoadlistFile.open("dataFolder/listFile.txt", std::fstream::in);
                break;
            } catch (const std::exception& ex) {
                std::cout << ex.what() << std::endl;
            }
        }
        
        std::string getList;
        while (std::getline(LoadlistFile, getList)) {
            listDIR.emplace_back(getList);
        }
    }*/
    void launchDIR() {
        std::filesystem::create_directories(colonyFolder);
        std::filesystem::create_directories(colonistFolder);
        std::filesystem::create_directories(logsFolder);
        std::filesystem::create_directories(eventsFolder);
    }
    
    bool checkCorrectDIR() {
        /*for (auto list : listDIR) {
            if (!std::filesystem::is_directory(list)) {
                return false;
            }
        }*/
        
        if (!std::filesystem::is_directory(colonyFolder)) {
            return false;
        }
        if (!std::filesystem::is_directory(colonistFolder)) {
            return false;
        }
        if (!std::filesystem::is_directory(logsFolder)) {
            return false;
        }
        if (!std::filesystem::is_directory(eventsFolder)) {
            return false;
        }
        
        return true;
    }
    
    const std::string GetColonyDIR(const std::string& path) {
        std::filesystem::path tmpF = colonyFolder / path;
        return (tmpF);
    }
    const std::string GetColonistDIR(const std::string& path) {
        std::filesystem::path tmpF = colonistFolder / path;
        return (tmpF);
    }
};

#endif /* FileManager_hpp */
