#include "raylib.h"

int main(void)
{
    InitWindow(800, 450, "beginner");

    struct rectangle {
        double x;
        double y;
        double speed;
        int width;
        int height;
    };

    struct rectangle rectangle;
    rectangle.x = 100;
    rectangle.y = 100;
    rectangle.speed = 300;
    rectangle.width = 100;
    rectangle.height = 100;

    float sliderValue = 300.0f;
    float speedRangeMin = 50.0f;
    float speedRangeMax = 500.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {   
        float deltaTime = GetFrameTime();
        BeginDrawing();
        // Correct use of GuiSlider
        DrawText("The mouse distance from the left side impacts speed.", 50, 50, 20, BLUE);
        rectangle.speed = GetMousePosition().x;

        if (IsKeyDown(KEY_LEFT) && rectangle.x > 0) rectangle.x -= rectangle.speed * deltaTime;
        if (IsKeyDown(KEY_RIGHT) && rectangle.x < 800 - rectangle.width) rectangle.x += rectangle.speed * deltaTime;
        if (IsKeyDown(KEY_UP) && rectangle.y > 0) rectangle.y -= rectangle.speed * deltaTime;
        if (IsKeyDown(KEY_DOWN) && rectangle.y < 450 - rectangle.height) rectangle.y += rectangle.speed * deltaTime;

        ClearBackground(YELLOW);

        DrawRectangle(rectangle.x, rectangle.y, rectangle.width, rectangle.height, BLUE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
