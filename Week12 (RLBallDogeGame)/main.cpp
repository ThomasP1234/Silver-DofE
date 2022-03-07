#include "raylib.h"
#include <math.h>

int main(void) {
    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Game");
    
    InitAudioDevice();
    Sound level = LoadSound("Resources/sfx_sounds_powerup17.wav");
    SetSoundVolume(level, 0.5f);
    Sound death = LoadSound("Resources/sfx_damage_hit1.wav");
    SetSoundVolume(death, 1.0f);

    const int ballSize = 30;
    Color ballColour = LIME;
    Vector2 ballPosition = { (float)screenWidth/2, (float)screenHeight/2 }; // Defult Position As Centre

    const int dodgeSize = 20;
    Color dodgeColour = RED;
    Vector2 dodgePosition = { (float)screenWidth + dodgeSize + 10, (float)GetRandomValue(dodgeSize*2, screenHeight-(dodgeSize*2)) }; // Defult Position
    float dodgeSpeed = 2.0;
    Vector2 dodge2Position = { (float)screenWidth + dodgeSize + 10, (float)GetRandomValue(dodgeSize*2, screenHeight-(dodgeSize*2)) }; // Defult Position

    SetTargetFPS(60); // Set game to run at 60 frames-per-second
    
    int score = 0;

    int currentScreen = 0;

    Font defaultFont = GetFontDefault();

    bool end = false;

    while (!WindowShouldClose()) { // Detect window close button or ESC key
        switch (currentScreen){
            case 0: {
                // Update
                //----------------------------------------------------------------------------------
                if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) {
                    end = true;
                    break;
                }
                if (IsKeyPressed(KEY_ENTER) or IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)) {
                    currentScreen = 1;
                }

                //----------------------------------------------------------------------------------
                
                // Draw
                //----------------------------------------------------------------------------------
                BeginDrawing();
                
                ClearBackground(RAYWHITE);

                DrawRectangle(0, 0, screenWidth, screenHeight, GREEN);
                DrawText("Welcome To My Game", 20, 20, 40, DARKGREEN);
                DrawText("PRESS ENTER or X to Start Game", (screenWidth/2) - (MeasureTextEx(defaultFont, "PRESS ENTER or X to Start Game", 20, 2.0).x/2), 220, 20, DARKGREEN);
                DrawText("PRESS Esc or Circle to Quit", (screenWidth/2) - (MeasureTextEx(defaultFont, "PRESS Esc or Circle to Quit", 20, 2.0).x/2), 260, 20, DARKGREEN);

                EndDrawing();
                //----------------------------------------------------------------------------------
            } break;
            case 1: {
                // Update
                //----------------------------------------------------------------------------------
                float movementSpeed = 4.0;

                dodgePosition.x -= dodgeSpeed;
                dodge2Position.x -= dodgeSpeed;

                if (dodgePosition.x < dodgeSize or dodge2Position.x < dodgeSize) {
                    PlaySound(level);

                    score += 1;

                    dodgePosition.x = (float)screenWidth + dodgeSize + 10;
                    dodge2Position.x = (float)screenWidth + dodgeSize + 10;

                    dodgePosition.y = (float)GetRandomValue(dodgeSize*2, screenHeight-(dodgeSize*2));
                    dodge2Position.y = (float)GetRandomValue(dodgeSize*2, screenHeight-(dodgeSize*2));

                    dodgeSpeed += 0.5;
                }
                // Keyboard Movement
                if (IsKeyDown(KEY_A) 
                        or IsKeyDown(KEY_D) 
                        or IsKeyDown(KEY_W) 
                        or IsKeyDown(KEY_S)) { // if..elif..elif.else use to make sure only 1 input is being used else a speed boost can be gained
                    if (IsKeyDown(KEY_A)) ballPosition.x -= movementSpeed; // Left
                    if (IsKeyDown(KEY_D)) ballPosition.x += movementSpeed; // Right
                    if (IsKeyDown(KEY_W)) ballPosition.y -= movementSpeed; // Up
                    if (IsKeyDown(KEY_S)) ballPosition.y += movementSpeed; // Down
                }
                else if (IsKeyDown(KEY_LEFT) 
                        or IsKeyDown(KEY_RIGHT) 
                        or IsKeyDown(KEY_UP) 
                        or IsKeyDown(KEY_DOWN)) {
                    if (IsKeyDown(KEY_LEFT)) ballPosition.x -= movementSpeed;
                    if (IsKeyDown(KEY_RIGHT)) ballPosition.x += movementSpeed;
                    if (IsKeyDown(KEY_UP)) ballPosition.y -= movementSpeed;
                    if (IsKeyDown(KEY_DOWN)) ballPosition.y += movementSpeed;   
                }
                // Controller Movement
                else if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT) 
                        or IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT) 
                        or IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP) 
                        or IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) {
                    // D-Pad
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_LEFT)) ballPosition.x -= movementSpeed;
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_RIGHT)) ballPosition.x += movementSpeed;
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_UP)) ballPosition.y -= movementSpeed;
                    if (IsGamepadButtonDown(0, GAMEPAD_BUTTON_LEFT_FACE_DOWN)) ballPosition.y += movementSpeed;
                }
                else {
                    // Left Joystick
                    if (GetGamepadAxisMovement(0, 0) < 0) ballPosition.x -= movementSpeed; // Left
                    if (GetGamepadAxisMovement(0, 0) > 0) ballPosition.x += movementSpeed; // Right
                    if (GetGamepadAxisMovement(0, 1) < 0) ballPosition.y -= movementSpeed; // Up
                    if (GetGamepadAxisMovement(0, 1) > 0) ballPosition.y += movementSpeed; // Down
                }

                // Collition With Window Boarder
                if (ballPosition.x < ballSize) ballPosition.x = ballSize;
                if (ballPosition.x > screenWidth-ballSize) ballPosition.x = screenWidth-ballSize;
                if (ballPosition.y < ballSize) ballPosition.y = ballSize;
                if (ballPosition.y > screenHeight-ballSize) ballPosition.y = screenHeight-ballSize;

                // Collition With Dodge
                if (CheckCollisionCircles(ballPosition, ballSize, dodgePosition, dodgeSize) or CheckCollisionCircles(ballPosition, ballSize, dodge2Position, dodgeSize)) {
                    PlaySound(death);
                    currentScreen = 2;
                }
                //----------------------------------------------------------------------------------

                // Draw
                //----------------------------------------------------------------------------------
                BeginDrawing();

                    ClearBackground(RAYWHITE);
                    
                    DrawCircleV(ballPosition, ballSize, ballColour);

                    DrawCircleV(dodgePosition, dodgeSize, dodgeColour);
                    DrawCircleV(dodge2Position, dodgeSize, dodgeColour);

                    if (GetTime() < 30) DrawText("Move the ball with WASD, Arrow Keys, D-PAD or Left Joystick \nAnd dodge the small circles", 10, 10, 20, DARKGRAY);
                    DrawText(TextFormat("Score: %i", score), 10, screenHeight-20, 20, DARKGRAY);

                EndDrawing();
                //----------------------------------------------------------------------------------
            } break;
            case 2: {
                // Update
                //----------------------------------------------------------------------------------
                if (IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_RIGHT)) {
                    end = true;
                    break;
                }
                if (IsKeyPressed(KEY_ENTER) or IsGamepadButtonPressed(0, GAMEPAD_BUTTON_RIGHT_FACE_DOWN)){                    
                    // Reset variables
                    score = 0;
                    dodgeSpeed = 2.0;
                    dodgePosition = { (float)screenWidth + dodgeSize + 10, (float)GetRandomValue(dodgeSize*2, screenHeight-(dodgeSize*2)) };
                    dodge2Position = { (float)screenWidth + dodgeSize + 10, (float)GetRandomValue(dodgeSize*2, screenHeight-(dodgeSize*2)) };
                    ballPosition = { (float)screenWidth/2, (float)screenHeight/2 };

                    currentScreen = 1;
                }
                //----------------------------------------------------------------------------------

                // Draw
                //----------------------------------------------------------------------------------
                BeginDrawing();
                DrawRectangle(0, 0, screenWidth, screenHeight, BLUE);
                DrawText(TextFormat("End Score: %i", score), 20, 20, 40, DARKBLUE);
                DrawText("PRESS ENTER or X to restart Game", (screenWidth/2) - (MeasureTextEx(defaultFont, "PRESS ENTER or X to restart Game", 20, 2.0).x/2), 220, 20, DARKBLUE);
                DrawText("PRESS Esc or Circle to Quit", (screenWidth/2) - (MeasureTextEx(defaultFont, "PRESS Esc or Circle to Quit", 20, 2.0).x/2), 260, 20, DARKBLUE);
                EndDrawing();
                //----------------------------------------------------------------------------------
            }
            default: break;
        }
        if (end == true) {
            break;
        }
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadSound(level);
    UnloadSound(death);
    void CloseAudioDevice(void);
    CloseWindow(); // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}