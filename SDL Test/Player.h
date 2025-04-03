#pragma once
#include "ObjectBase.h"

class Mix_Chunk; class GameStateMachine;
class Player : public ObjectBase
{
public:
	Player();

	// Inherited via ObjectBase
	void Update() override;
	const char* GetName() override;
	void Render() override;
	static int coins;
	void SetGameStateMachine(GameStateMachine* machine);
	

private:
	GameStateMachine* FSM;
	Mix_Chunk* sound;
	// Inherited via ObjectBase
	void Execute() override;

};
