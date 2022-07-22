# pragma once

#include <raylib.h>

#include "rlights.h"

#include <string>

class Game {
public:
    Game(int screenWidth, int screenHeight, std::string title);
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    ~Game() noexcept;
    bool GameShouldClose() const;
    void Tick();
    
private:
    void Update();
    void Draw();
    void Draw( int x, int y ) const;

    // Define the camera to look into our 3d world
    Camera camera = { 0 };

    // Define plane model from a generated mesh    
    Model model;
    Model cube;
    Vector3 pos;
    bool up = true;

    // Define basic lighting shader
    Shader shader;
    
    Light lights[MAX_LIGHTS] = { 0 };
};