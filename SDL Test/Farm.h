#pragma once
#include "ObjectBase.h"

class Farm : public ObjectBase
{
public:
	Farm();

private:

	void Update() override;
	const char* GetName() override;

	// Inherited via ObjectBase
	void Execute() override;
};

