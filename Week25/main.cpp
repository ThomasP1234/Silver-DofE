#include "raylib.h"
#include "iostream"
#include "ctime"
#include "cmath"
// Requires Raylib which can be found here: https://www.raylib.com/

class Clock {
    protected:
        const std::size_t MYTZ = 0;
        const std::size_t HOURS_PER_DAY = 24;

        const double DEG_PER_RAD = 57.2958;

        const std::size_t SECONDS_PER_MINUTE = 60;
        const std::size_t SECONDS_PER_HOUR = SECONDS_PER_MINUTE * 60;
        const std::size_t SECONDS_PER_DAY = SECONDS_PER_HOUR * HOURS_PER_DAY;

        const int screenWidth = 800;
        const int screenHeight = 800;

        const Vector2 screenCentre = {(float)(screenWidth+1)/2, (float)(screenHeight+1)/2};
        
        const int radius = std::min(screenCentre.x, screenCentre.y)-1;
        
        Font defaultFont = GetFontDefault();

    public:
        Clock() {
            InitWindow(screenWidth, screenHeight, "Game");
            SetTargetFPS(60); // Set game to run at 60 frames-per-second
        }

        ~Clock() {
            CloseWindow();
        }

        void GameLoop() {
            while (!WindowShouldClose()) {
                Frame();
            }
        }

        void Frame() {
            Draw();
        }

        void Draw() {
            std::time_t currentTime;
            struct tm* localTime;
            time(&currentTime);
            localTime = localtime(&currentTime);
            localTime->tm_hour = (localTime->tm_hour + MYTZ) % HOURS_PER_DAY;

            const auto hours = localTime->tm_hour;
            const auto minutes = localTime->tm_min;
            const auto seconds = localTime->tm_sec;

            float x2, y2, x3, y3;
            double angle;

            BeginDrawing();
                ClearBackground(DARKGRAY);

                DrawCircleLines(screenCentre.x, screenCentre.y, radius, RAYWHITE);
                DrawCircleLines(screenCentre.x, screenCentre.y, 1, RAYWHITE);

                for (int z = 0; z < 360; z += 30) {
                    angle = z;
                    angle = angle / DEG_PER_RAD;
                    x2 = (screenCentre.x + (sin(angle) * radius));
                    y2 = (screenCentre.y - (cos(angle) * radius));
                    x3 = (screenCentre.x + (sin(angle) * (radius-50)));
                    y3 = (screenCentre.y - (cos(angle) * (radius-50)));

                    DrawLine(x2, y2, x3, y3, YELLOW);
                }

                angle = seconds * 6;
                angle = angle / DEG_PER_RAD;
                x3 = (screenCentre.x + (sin(angle) * (radius-25)));
                y3 = (screenCentre.y - (cos(angle) * (radius-25)));
                DrawLineEx({screenCentre.x, screenCentre.y}, {x3, y3}, 2, RED);

                angle = minutes * 6;
                angle = angle / DEG_PER_RAD;
                x3 = (screenCentre.x + (sin(angle) * (radius-100)));
                y3 = (screenCentre.y - (cos(angle) * (radius-100)));
                DrawLineEx({screenCentre.x, screenCentre.y}, {x3, y3}, 3, GREEN);

                angle = (hours * 30 + int((minutes/12) * 6));
                angle = angle / DEG_PER_RAD;
                x3 = (screenCentre.x + (sin(angle) * (radius-225)));
                y3 = (screenCentre.y - (cos(angle) * (radius-225)));
                DrawLineEx({screenCentre.x, screenCentre.y}, {x3, y3}, 5, BLUE);

            EndDrawing();
        }
};

int main(void) {
    Clock objClock;
    objClock.GameLoop();
    return 0;
}