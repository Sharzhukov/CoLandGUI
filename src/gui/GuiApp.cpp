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

//class coland::DataApp;
namespace coland{
    #ifdef __APPLE__
        #include <mach-o/dyld.h>
    #endif

    std::string getResourcePath() {
        #ifdef _WIN32
            return "./resources/";
        #elif __APPLE__
            // Проверяем, запущено ли приложение как .app или как бинарник
            char path[1024];
            uint32_t size = sizeof(path);
            if (_NSGetExecutablePath(path, &size) == 0) {
                std::string exePath(path);
                if (exePath.find(".app/") != std::string::npos) {
                    // .app бандл
                    return exePath.substr(0, exePath.find(".app/") + 5) + "Contents/Resources/";
                }
            }
            return ".Contents/MacOS/resources/";
        #else
            return "./resources/";
        #endif
    }
    class ColonistList {
        static int idTotal;
        int id;
        int positionX;
        int positionY;
        Color color;
    public: 
        ColonistList(int positionXnull, int positionYnull, Color color) {
            positionX = positionXnull;
            positionY = positionYnull;
            this->color = color;
            id = idTotal++;
        }
        int GetID() { return id; }
        int GetPositionX() { return positionX; }
        int GetPositionY() { return positionY; }
        Color GetColor() { return color; }

        int& PositionX_Ref() { return positionX; }
        int& PositionY_Ref() { return positionY; }
        Color& Color_Ref() { return color; }

        void SetPositionX(int positionX) { this->positionX = positionX; }
        void SetPositionY(int positionY) { this->positionY = positionY; }
        void SetColor(Color color) { this->color = color; }

        Vector2 Position() { return {(float)positionX, (float)positionY}; }
    };
    int ColonistList::idTotal = 0;

    void runApplication() {
        //f_initWindow();
        std::vector<ColonistList> colonistList;
        DataApp dApp;
        
        // [ initWindow 1 ]
        int currentMonitorMain = GetCurrentMonitor();
        InitWindow(0, 0, "CoLand ※ colony survival simulator.");

        Image iconApp = LoadImage("resources/img/appIcon.png");
        SetWindowIcon(iconApp);
        UnloadImage(iconApp);

        int m_WidthWindow = GetScreenWidth();
        int m_HeightWindow = GetScreenHeight();

        m_WidthWindow /= 2;
        m_HeightWindow /= 2;

        SetWindowSize(m_WidthWindow, m_HeightWindow);
        //ToggleBorderlessWindowed();
        SetWindowPosition((m_WidthWindow / 2), (m_HeightWindow / 2));   
        // [ initWindow 0 ]



        // [ colonist 1 ]
        const int SizeColonist = 50;
        
        const int ColonistPosXmax = m_WidthWindow - SizeColonist;
        const int ColonistPosXmin = 0;
        const int ColonistPosYmax = m_HeightWindow - SizeColonist - 30;
        const int ColonistPosYmin = 0;

        int ColonistPosX = m_WidthWindow / 2;
        int ColonistPosY = m_HeightWindow / 2;

        int ColonistPosXnull = m_WidthWindow / 2;
        int ColonistPosYnull = m_HeightWindow / 2;
        colonistList.emplace_back(ColonistPosXnull, ColonistPosYnull, BROWN);
        // [ colonist 0 ]


        
        // [ position border 1 ]
        int positionXhead = 0;
        int positionXend = m_WidthWindow;
        int positionYhead = 0;
        int positionYend = m_HeightWindow;

        int sizeYfooter = 30;
        int positionYendFoot = m_HeightWindow - sizeYfooter;
        // [ position border 0 ]



        Rectangle btnBounds = { positionXend - 200.0f, positionYendFoot - 40.0f, 200, 40 };
        Color btnColor = GRAY; // Начальный цвет кнопки
        bool btnClicked = false;




        int idColonistCurrent = 0;
        


        int deleteCount = 0;
        
        if (IsWindowReady())
        {
            SetTargetFPS(60);

            //Texture2D iconStar = LoadTexture((getResourcePath() + "img/star.png").c_str());
            Texture2D iconStar = LoadTexture("resources/img/star.png");
            //Image iconStar = LoadImage("resources/img/health.png");

            while (!WindowShouldClose()) { 
                ColonistList& colonistCurrent = colonistList[idColonistCurrent];


                if (IsKeyPressed(KEY_R))
                {
                    if (idColonistCurrent == (colonistList.size() - 1)) {
                        idColonistCurrent = 0;
                    }
                    else {
                        idColonistCurrent++;
                    }
                    std::cout << "Current id Colonist: " << idColonistCurrent << std::endl;
                    //std::this_thread::sleep_for(std::chrono::milliseconds(250));
                }
                if (IsKeyPressed(KEY_DELETE) && (colonistList.size() != 1))
                {
                    std::vector<ColonistList>::iterator it = colonistList.begin();
                    std::advance(it, idColonistCurrent);
                    std::cout << colonistList.back().GetID() << std::endl;
                    idColonistCurrent = 0;
                    colonistList.erase(it);
                    deleteCount++;
                }
                
                
                int runColonist = (IsKeyDown(KEY_LEFT_SHIFT)) ? (3) : (0);
                
                if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && colonistCurrent.PositionY_Ref() >= ColonistPosYmin)
                {
                    std::cout << "Colonist id " << colonistCurrent.GetID() << " pos Y: " << colonistCurrent.PositionY_Ref() << std::endl;
                    colonistCurrent.PositionY_Ref() -= (3 + runColonist); //ColonistPosY-=3
                }
                if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) && colonistCurrent.PositionY_Ref() <= ColonistPosYmax)
                {
                    std::cout << "Colonist id " << colonistCurrent.GetID() << " pos Y: " << colonistCurrent.PositionY_Ref() << std::endl;
                    colonistCurrent.PositionY_Ref() += (3 + runColonist);
                }
                if ((IsKeyDown(KEY_A) || IsKeyDown(KEY_LEFT)) && colonistCurrent.PositionX_Ref() >= ColonistPosXmin)
                {
                    std::cout << "Colonist id " << colonistCurrent.GetID() << " pos X: " << colonistCurrent.PositionX_Ref() << std::endl;
                    colonistCurrent.PositionX_Ref() -= (3 + runColonist);
                }
                if ((IsKeyDown(KEY_D) || IsKeyDown(KEY_RIGHT)) && colonistCurrent.PositionX_Ref() <= ColonistPosXmax)
                {
                    std::cout << "Colonist id " << colonistCurrent.GetID() << " pos X: " << colonistCurrent.PositionX_Ref() << std::endl;
                    colonistCurrent.PositionX_Ref() += (3 + runColonist);
                }


                Vector2 mousePos = GetMousePosition();
                // Проверяем, находится ли курсор мыши над кнопкой
                if (CheckCollisionPointRec(mousePos, btnBounds)) {
                    if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
                        btnColor = DARKGRAY; // Цвет при зажатии
                    } else {
                        btnColor = LIGHTGRAY; // Цвет при наведении
                    }

                    // Фиксируем клик после того, как кнопку отпустили
                    if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
                        btnClicked = !btnClicked; // Переключаем состояние
                    }
                } else {
                    btnColor = GRAY; // Обычный цвет, когда мышь далеко
                }


                BeginDrawing();
                ClearBackground(RAYWHITE);

                DrawRectangle(0, 0, positionXend, positionYend, GREEN);
                DrawRectangle(0, 0, 75, 25, WHITE);
                DrawFPS(0, 0);

                //dApp.initDA();

                for (size_t i = 0; i < colonistList.size(); i++)
                {
                    if (i == idColonistCurrent) { continue; }
                    DrawRectangle(colonistList[i].GetPositionX(), colonistList[i].GetPositionY(), SizeColonist, SizeColonist, BLACK);
                    DrawText(std::to_string(colonistList[i].GetID()).c_str(), colonistList[i].GetPositionX() + 10, colonistList[i].GetPositionY() + 10, 30, WHITE);
                }
                
                DrawRectangle(colonistCurrent.PositionX_Ref(), colonistCurrent.PositionY_Ref(), SizeColonist, SizeColonist, colonistCurrent.GetColor());
                DrawText(std::to_string(colonistCurrent.GetID()).c_str(), colonistCurrent.PositionX_Ref() + 10, colonistCurrent.PositionY_Ref() + 10, 30, WHITE);

                
                
        
                // Рисуем тело кнопки
                DrawRectangleRec(btnBounds, btnColor);
                // Рисуем рамку кнопки, чтобы она выглядела аккуратнее
                DrawRectangleLinesEx(btnBounds, 2, BLACK);
                // Текст на кнопке (центрируем вручную)
                DrawText("ADD Colonist", btnBounds.x + 35, btnBounds.y + 10, 20, BLACK);

                // Выводим результат клика на экран
                if (btnClicked) {
                    colonistList.emplace_back(ColonistPosXnull, ColonistPosYnull, BROWN);
                    idColonistCurrent = 0;
                    btnClicked = !btnClicked;
                    std::cout << "New Colonist id: " << (colonistList.size() - 1) << std::endl;
                }

                

                DrawTexture(iconStar, (10 + (iconStar.height * 1)), (positionYendFoot - iconStar.width), WHITE);
                DrawTexture(iconStar, (20 + (iconStar.height * 2)), (positionYendFoot - iconStar.width), WHITE);
                DrawTexture(iconStar, (30 + (iconStar.height * 3)), (positionYendFoot - iconStar.width), WHITE);
                DrawTexture(iconStar, (40 + (iconStar.height * 4)), (positionYendFoot - iconStar.width), WHITE);


                

                // [ Footer copiryght 1 ]
                {
                    DrawRectangle(0, positionYend-sizeYfooter, positionXend, sizeYfooter, WHITE);
                    DrawText("CoLand Copyright (C) 2026 by Sharzhukov.", 10, (positionYend - 23), 15, BLACK);
                }
                // [ Footer copiryght 0 ]
                EndDrawing();
            }

            UnloadTexture(iconStar);
        }

        CloseWindow();
    }
}