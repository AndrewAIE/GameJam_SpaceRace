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
    char startGame[] = "Press Any Key To Begin";
    char escGame[] = "Press Escape to Exit the Game";





    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");
    Game game;
    game.Initialize();
    bool gameRunning = false;

    SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        
        DrawText(title, GetScreenWidth() / 2, (GetScreenHeight() / 2) - 30, 40, WHITE);
        DrawText(subtitle, GetScreenWidth() / 2, (GetScreenHeight() / 2) + 10, 30, WHITE);
        


        while(gameRunning)

        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------
        game.Update();
        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        
        game.Draw();
        
        gameRunning = game.CheckIfRunning();

        ClearBackground(BLACK);

        

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}


