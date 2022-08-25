#include <iostream>
#include <vector>
#include <string>
#include "raylib.h"



#include "ball.hpp"
#include "paddle.hpp"
#include "game_functions.hpp"

using namespace std;


wstring tetromino[7];


int main( ) {

    InitWindow(800,600, "Pong");
    SetWindowState(FLAG_VSYNC_HINT);


    // Initialize ball
    Ball ball;
    ball.x = GetScreenWidth() /2.0f;
    ball.y = GetScreenHeight() / 2.0f;
    ball.radius = 5;
    ball.speedX = 200;
    ball.speedY = 200;

    // Initialize left paddle
    Paddle leftPaddle;
    leftPaddle.x = 50;
    leftPaddle.y = GetScreenHeight()/2;
    leftPaddle.width = 10;
    leftPaddle.height = 100;
    leftPaddle.speed = 500;

    // Initialize right paddle
    Paddle rightPaddle;
    rightPaddle.x = GetScreenWidth()- 50;
    rightPaddle.y = GetScreenHeight() / 2;
    rightPaddle.width = 10;
    rightPaddle.height = 100;
    rightPaddle.speed = 500;


    char* winnerText = nullptr;



    while(!WindowShouldClose()) 
    {

        ball.MoveBall();

        // Control movement of left paddle
        if(IsKeyDown(KEY_W)) leftPaddle.MoveUp();
        if(IsKeyDown(KEY_S)) leftPaddle.MoveDown();

        // Contols movement of right paddle
        if(IsKeyDown(KEY_UP)) rightPaddle.MoveUp();
        if(IsKeyDown(KEY_DOWN)) rightPaddle.MoveDown();
        


        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, 
        leftPaddle.GetRect()))
        {
            if(ball.speedX < 0)
            {
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - leftPaddle.y) / (leftPaddle.height / 2) * ball.speedX;
            }

        }

        if(CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, 
        rightPaddle.GetRect()))
        {
            if(ball.speedX > 0)
            {
                ball.speedX *= -1.1f;
                ball.speedY = (ball.y - rightPaddle.y) / (leftPaddle.height / 2) * -ball.speedX;

            }

        }

        // Checking to see if either play was won
        if(ball.x < 0) winnerText = "Right Player Wins!";
        if(ball.x > GetScreenWidth()) winnerText = "Left Player Wins!";
        



        if(winnerText && IsKeyPressed(KEY_SPACE))
        {
            ball.x = GetScreenWidth() / 2;
            ball.y = GetScreenHeight() / 2;
            ball.speedX = 300;
            ball.speedY = 300;
            winnerText = nullptr;
        }


        DrawGame(ball, leftPaddle, rightPaddle, winnerText);
    }






  
    CloseWindow();

    return 0;
}