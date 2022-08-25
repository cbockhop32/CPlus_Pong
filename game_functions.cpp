

#include "raylib.h"
#include "ball.hpp"
#include "paddle.hpp"




#include "game_functions.hpp"

void DrawGame(Ball& ball, Paddle& leftPaddle, Paddle& rightPaddle, char* winnerText)
{
    BeginDrawing();
            ClearBackground(BLACK);
            ball.Draw();
            leftPaddle.Draw();
            rightPaddle.Draw();


            if(winnerText)
            {
                int textWidth = MeasureText(winnerText, 60);
                DrawText(winnerText, GetScreenWidth() / 2 - textWidth / 2, GetScreenHeight()/2 -30, 60, YELLOW);
            }

            
            DrawFPS(5, 5);
        EndDrawing();
}



