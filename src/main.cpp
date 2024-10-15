// AndroidRaylibGame.cpp : Defines the entry point for the application.
//

#include "AndroidRaylibGame.h"
#include "GameSettings.h"
#include "raylib.h"
#include "Colors.h"

int main(int argc, char** argv)
{
	InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Android Game Test");
	SetTargetFPS(60);
	InitAudioDevice();

	//game scene loop
	while (!WindowShouldClose())
	{
		BeginDrawing();

		ClearBackground(GAME_GRAY);
		// - (words count * font size) / 2
		DrawText("TEST IN RAYLIB!", WINDOW_WIDTH / 2 - 200, 20, 40, GAME_BLUE_PURPLE);
		DrawText("START GAME! ", WINDOW_WIDTH / 2 - 180, WINDOW_HEIGHT / 2 - 100, 20, GAME_YELLOW);
		DrawText(TextFormat("Last Highscore: %08i", 10000), 20, 90, 20, GAME_LIGHT_GREEN);

		EndDrawing();
	}

	CloseAudioDevice();
	CloseWindow();
	return 0;
}
