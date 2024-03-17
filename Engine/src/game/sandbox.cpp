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
		camera->cameraMove = true;
		player = Global::ecs->createEntity();
		Global::ecs->addComponent(player, new TransformComponent({ 100,100 }, { 100,100 }));
		Global::ecs->addComponent(player, new PhysicsComponent({ 0,0 }, { 1,10 }, {0,1}));
	}

	Sandbox::~Sandbox()
	{

	}

	void Sandbox::input()
	{

	}

	void Sandbox::update(long double dt)
	{
		//std::cout << ((TransformComponent*)Global::ecs->getComponent(player, TRANSFORM_COMPONENT))->position.x<<"\n";
	}

	void Sandbox::render()
	{
		
	}
}