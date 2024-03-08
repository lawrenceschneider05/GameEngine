#include "sandbox.h"
#include <vector>
#include <collision/Quad.h>
#include "collision/CollisionFinder.h"
#include <components/entity_type_component.h>
#include <components/transform_component.h>

using namespace std;
using namespace Engine;
using namespace Global;

namespace Game
{
	EntityID player;
	Sandbox::Sandbox()
	{
		player = entity_manager->createEntity();
		component_manager->addComponent(player, new EntityTypeComponent(ENTITY_PLAYER));
		component_manager->addComponent(player, new TransformComponent({ 0,0 }, { 100,100 }));
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
		
		renderer->drawQuad(*(TransformComponent*)component_manager->getComponent(player, TRANSFORM_COMPONENT), Colors::RED);
	}
}