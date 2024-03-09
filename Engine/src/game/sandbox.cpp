#include "sandbox.h"
#include <vector>
#include <collision/Quad.h>
#include "collision/CollisionFinder.h"


using namespace std;
using namespace Engine;
using namespace Global;

namespace Game
{
	EntityID player;
	Sandbox::Sandbox()
	{
		camera->cameraMove = false;
		player = Global::ecs->createEntity();
		Global::ecs->addComponent(player, new TransformComponent({ 0,0 }, { 100,100 }));
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