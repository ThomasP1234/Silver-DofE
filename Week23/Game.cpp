#include <raylib.h>
#include <raymath.h>
#include <assert.h>
#include "Game.h"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION            330
#else   // PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION            100
#endif

#define RLIGHTS_IMPLEMENTATION
#include "rlights.h"

Game::Game(int screenWidth, int screenHeight, std::string title) {
    assert(!GetWindowHandle()); // window is already open
	SetConfigFlags(FLAG_MSAA_4X_HINT); 
    InitWindow(screenWidth, screenHeight, title.c_str());

	camera.position = (Vector3){ 2.0f, 4.0f, 6.0f };    // Camera position
    camera.target = (Vector3){ 0.0f, 0.5f, 0.0f };      // Camera looking at point
    camera.up = (Vector3){ 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 60.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE; 

	SetCameraMode(camera, CAMERA_FREE);

	// Load plane model from a generated mesh
	model = LoadModelFromMesh(GenMeshPlane(10.0f, 10.0f, 3, 3));
    cube = LoadModelFromMesh(GenMeshCube(2.0f, 2.0f, 2.0f));
	pos = {0.0f, 0.0f, 0.0f};

	// Load basic lighting shader
	shader = LoadShader(TextFormat("resources/shaders/glsl%i/base_lighting.vs", GLSL_VERSION),
                        TextFormat("resources/shaders/glsl%i/lighting.fs", GLSL_VERSION));

	// Get some required shader locations
    shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(shader, "viewPos");
	
	// Ambient light level (some basic lighting)
    int ambientLoc = GetShaderLocation(shader, "ambient");
	// static const float f4[4] = { 0.1f, 0.1f, 0.1f, 1.0f };
    // SetShaderValue(shader, ambientLoc, &f4[0], SHADER_UNIFORM_VEC4);
	
	static const float f5[5] = { 0.1f, 0.1f, 0.1f, 1.0f, 1.0f };
    SetShaderValue(shader, ambientLoc, &f5[0], SHADER_UNIFORM_VEC4);

	int numberOfLightsLoc = GetShaderLocation(shader, "numberOfLights");
	static const int numberOfLights = 5;
	SetShaderValue(shader, numberOfLightsLoc, &numberOfLights, SHADER_UNIFORM_INT);
	
    // Assign out lighting shader to model
    model.materials[0].shader = shader;
    cube.materials[0].shader = shader;

	// Create lights    
    lights[0] = CreateLight(LIGHT_POINT, (Vector3){ -2, 3, -2 }, Vector3Zero(), YELLOW, shader);
    lights[1] = CreateLight(LIGHT_POINT, (Vector3){ 2, 3, 2 }, Vector3Zero(), RED, shader);
    lights[2] = CreateLight(LIGHT_POINT, (Vector3){ -2, 3, 2 }, Vector3Zero(), GREEN, shader);
    lights[3] = CreateLight(LIGHT_POINT, (Vector3){ 2, 3, -2 }, Vector3Zero(), BLUE, shader);

    SetCameraMode(camera, CAMERA_FIRST_PERSON);  // Set an orbital camera mode
	
    SetTargetFPS(60); 
}
Game::~Game() noexcept {
    assert(GetWindowHandle()); // window is already closed

	// De-Initialization
    //--------------------------------------------------------------------------------------
    UnloadModel(model);     // Unload the model
    UnloadModel(cube);      // Unload the model
    UnloadShader(shader);   // Unload shader
    
    CloseWindow();
}

bool Game::GameShouldClose() const{
    return WindowShouldClose();
}

void Game::Tick() {
    BeginDrawing();    
	Update();
    Draw();
    EndDrawing();
}

void Game::Update() {
	if (up == true) {
		pos.y += 0.1;
	}
	else {
		pos.y -= 0.1;
	}
	if (pos.y > 10 ) {
		up = false;
	}
	else if (pos.y < 1) {
		up = true;
	}

	UpdateCamera(&camera); 

	if (IsKeyDown('Z')) camera.target = (Vector3){ 0.0f, 0.0f, 0.0f };

	// Update the shader with the camera view vector (points towards { 0.0f, 0.0f, 0.0f })
    float cameraPos[3] = { camera.position.x, camera.position.y, camera.position.z };
    SetShaderValue(shader, shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);

	// Check key inputs to enable/disable lights
	if (IsKeyPressed(KEY_Y)) { lights[0].enabled = !lights[0].enabled; }
	if (IsKeyPressed(KEY_R)) { lights[1].enabled = !lights[1].enabled; }
	if (IsKeyPressed(KEY_G)) { lights[2].enabled = !lights[2].enabled; }
	if (IsKeyPressed(KEY_B)) { lights[3].enabled = !lights[3].enabled; }     

	// Update light values (actually, only enable/disable them)
    for (int i = 0; i < MAX_LIGHTS; i++) UpdateLightValues(shader, lights[i]);
}

void Game::Draw() {
    ClearBackground(BLACK);
    
	BeginMode3D(camera);

		DrawModel(model, Vector3Zero(), 1.0f, WHITE);
		DrawModel(cube, pos, 1.0f, WHITE);

		// Draw spheres to show where the lights are
		for (int i = 0; i < MAX_LIGHTS; i++)
		{
			if (lights[i].enabled) DrawSphereEx(lights[i].position, 0.2f, 8, 8, lights[i].color);
			else DrawSphereWires(lights[i].position, 0.2f, 8, 8, ColorAlpha(lights[i].color, 0.3f));
		}

		DrawGrid(10, 1.0f);

	EndMode3D();

	// DrawFPS(10, 10);
	// DrawText("Use keys [Y][R][G][B] to toggle lights", 10, 40, 40, DARKGRAY);

	DrawRectangle( 10, 10, 440, 140, Fade(SKYBLUE, 0.5f));
	DrawRectangleLines( 10, 10, 440, 140, BLUE);

	DrawText("Controls:", 20, 20, 20, BLACK);
	DrawText("- Move with keys: W, A, S, D", 40, 50, 20, BLACK);
	DrawText("- Move mouse to look around", 40, 80, 20, BLACK);
	DrawText("- Use keys [Y][R][G][B] to toggle lights", 40, 110, 20, BLACK);
}