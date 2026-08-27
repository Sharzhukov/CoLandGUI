//  GuiApp.cpp
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

#include "../include/gui/GuiApp.hpp"
#include <raylib.h>

namespace coland{
    void runApplication() {
        int m_WidthWindow = 800;
        int m_HeightWindow = 600;

        const int SizeColonist = 50;
        
        const int ColonistPosXmax = m_WidthWindow - SizeColonist;
        const int ColonistPosXmin = 0;
        const int ColonistPosYmax = m_HeightWindow - SizeColonist;
        const int ColonistPosYmin = 0;


        int ColonistPosX = m_WidthWindow / 2;
        int ColonistPosY = m_HeightWindow / 2;


        InitWindow(m_WidthWindow, m_HeightWindow, "CoLand ※ colony survival simulator.");
        
        if (IsWindowReady())
        {
            SetTargetFPS(60);

            Image iconApp = LoadImage("resources/img/icon.png");
            SetWindowIcon(iconApp);
            UnloadImage(iconApp);

            while (!WindowShouldClose()) { 
                BeginDrawing();
                DrawRectangle(0, 0, m_WidthWindow, m_HeightWindow, GREEN);
                DrawRectangle(0, 0, 75, 25, WHITE);
                DrawFPS(0, 0);


                DrawRectangle(ColonistPosX, ColonistPosY, SizeColonist, SizeColonist, BROWN);

                if (IsKeyDown(KEY_W) && ColonistPosY >= ColonistPosYmin)
                {
                    std::cout << ColonistPosY << std::endl;
                    ColonistPosY-=3;
                }
                if (IsKeyDown(KEY_S) && ColonistPosY <= ColonistPosYmax)
                {
                    std::cout << ColonistPosY << std::endl;
                    ColonistPosY+=3;
                }
                if (IsKeyDown(KEY_A) && ColonistPosX >= ColonistPosXmin)
                {
                    std::cout << ColonistPosX << std::endl;
                    ColonistPosX-=3;
                }
                if (IsKeyDown(KEY_D) && ColonistPosX <= ColonistPosXmax)
                {
                    std::cout << ColonistPosX << std::endl;
                    ColonistPosX+=3;
                }


                //ClearBackground(RAYWHITE);
                
                //DrawText("CoLand GUI", 10, 10, 30, BLACK);



                EndDrawing();
            }
        }

        CloseWindow();
    }
}