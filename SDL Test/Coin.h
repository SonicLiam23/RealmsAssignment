#pragma once
#include "ObjectBase.h"
class Coin : public ObjectBase
{
public:
	void Update() override;
	const char* GetName() override;

private:


	// Inherited via ObjectBase
	void Execute() override;

};
