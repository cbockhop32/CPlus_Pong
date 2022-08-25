#pragma once

struct Paddle
{
    float x, y;
    float speed;
    float width, height;


    Rectangle GetRect()
    {
        return Rectangle {x - width/2, y - height / 2, 10,100};
    }

    void Draw()
    {
        DrawRectangleRec(GetRect(), WHITE);
    }

    void MoveUp()
    {
        if ((y-height/2)>0){
            y -= speed * GetFrameTime();

        }

    }

    void MoveDown()
    {
        if ((y + height/2) < GetScreenHeight())
        {
            y += speed * GetFrameTime();

        }

    }

};