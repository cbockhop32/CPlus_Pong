#pragma once


struct Ball 
{
    float x, y;
    float speedX, speedY;
    float radius;

    void Draw() 
    {
        DrawCircle((int) x, (int) y, radius, WHITE);
    }


    void MoveBall()
    {
        x += speedX* GetFrameTime();
        y += speedY * GetFrameTime();

        if(y < 0)
        {
            y = 0;
            speedY *= -1;
        }
        if(y > GetScreenHeight())
        {
            y = GetScreenHeight();
            speedY *= -1;
        }
    }



};