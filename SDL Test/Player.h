#pragma once
#include "ObjectBase.h"
class Player : public ObjectBase
{
public:
	Player();

	// Inherited via ObjectBase
	void Update() override;
	const char* GetName() override;
	void Render() override;
	static int coins;

private:
	

	// Inherited via ObjectBase
	void Execute() override;

};
