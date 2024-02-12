#include "sandbox.h"
#include <vector>
#include "entities/player.h"
#include "entities/wall.h"
#include <collision/Quad.h>
#include "collision/CollisionFinder.h"

using namespace std;
using namespace Engine;
using namespace Global;

namespace Game
{
	Sandbox::Sandbox()
	{
		IEntity* p = new Player({ 0,0 }, { 100,100 }, Colors::BLUE, PLAYER);
		IEntity* w = new Wall({ 0,0 }, { 25,400 }, Colors::BLACK, WALL);
		entityManager->addEntity(p);
		entityManager->addEntity(w);
	}

	Sandbox::~Sandbox()
	{

	}

	void Sandbox::input()
	{

	}

	void Sandbox::update(long double dt)
	{
		
	}

	void Sandbox::render()
	{

	}
}