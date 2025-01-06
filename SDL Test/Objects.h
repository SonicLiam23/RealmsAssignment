#pragma once
#include <vector>
class Enemy;
class Wall;
class Tower;
class Coin;
class Farm;

struct Objects
{
	static std::vector<Enemy*> Enemies;
	static std::vector<Wall*> Walls;
	static std::vector<Tower*> Towers;
};

