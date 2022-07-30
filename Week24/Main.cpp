#include "raylib.h"
#include "raymath.h"

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game");

    Camera camera = {0};
    camera.position = (Vector3){0.0f, 50.0f, -120.0f};
    camera.target = (Vector3){0.0f, 0.0f, 0.0f};
    camera.up = (Vector3){0.0f, 1.0f, 0.0f};
    camera.fovy = 30.0f;
    camera.projection = CAMERA_FREE;

    Model model = LoadModel("resources/model.obj");

    float pitch = 0.0f;
    float roll = 0.0f;
    float yaw = 0.0f;

    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        if (IsKeyDown(KEY_DOWN)) pitch += 0.6f;
        else if (IsKeyDown(KEY_UP)) pitch -= 0.6f;
        
        if (IsKeyDown(KEY_D)) yaw += 0.6f;
        else if (IsKeyDown(KEY_A)) yaw -= 0.6f;

        if (IsKeyDown(KEY_LEFT)) roll += 0.6f;
        else if (IsKeyDown(KEY_RIGHT)) roll -= 0.6f;

        model.transform = MatrixRotateXYZ((Vector3){DEG2RAD*pitch, DEG2RAD*yaw, DEG2RAD*roll});

        BeginDrawing();
            ClearBackground(RAYWHITE);

            BeginMode3D(camera);

                DrawModel(model, (Vector3){0.0f, -3.0f, 0.0f}, 25.0f, RED);

            EndMode3D();

            DrawRectangle(30, 370, 260, 70, Fade(GREEN, 0.5f));
            DrawRectangleLines(30, 370, 260, 70, Fade(DARKGREEN, 0.5f));
            DrawText("Pitch controlled with: KEY_UP / KEY_DOWN", 40, 380, 10, DARKGRAY);
            DrawText("Roll controlled with: KEY_LEFT / KEY_RIGHT", 40, 400, 10, DARKGRAY);
            DrawText("Yaw controlled with: KEY_A / KEY_S", 40, 420, 10, DARKGRAY);

        EndDrawing();
    }
    UnloadModel(model);

    CloseWindow();

    return 0;
}