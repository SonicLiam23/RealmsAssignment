#pragma once
class Mix_Chunk; class GameStateMachine; class MenuState; class GameState; class GameOverState;
class Realms
{

private:
	Mix_Chunk* sound;
	GameStateMachine* FSM;

	MenuState* menu;
	GameState* game;
	GameOverState* dead;

public:
	void init();
	void Start();
	void Update();
	void Quit();
};

