/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "Game.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 510;
    int screenHeight = 610;

    char title[] = "Brick Breaker 1976";
    char subtitle[] = "Arcade Edition";
    char startGame[] = "Press Space To Begin";
    
    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Game game;
    game.Initialize();
    bool gameRunning = false;

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        BeginDrawing();
        DrawText(title, GetScreenWidth() / 9, (GetScreenHeight() / 2) - 50, 40, WHITE);
        DrawText(subtitle, GetScreenWidth() / 3.5f, GetScreenHeight() / 2, 30, WHITE);
        DrawText(startGame, GetScreenWidth() / 3.85f, (GetScreenHeight() / 2) + 60, 20, WHITE);
        
        ClearBackground(BLACK);

        if (IsKeyPressed(KEY_SPACE)) 
        {
            gameRunning = true;
            game.Initialize();
        }

        
        while (gameRunning) {
            game.Update();
            // Draw
            //----------------------------------------------------------------------------------
            BeginDrawing();

            game.Draw();

            gameRunning = game.CheckIfRunning();

            ClearBackground(BLACK);


            
            EndDrawing();
        }

        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


