#pragma once
#include <ecs/entities/entities.h>
#include <ecs/entities/entity_manager.h>
#include <ecs/components/component_manager.h>
#include <ecs/systems/system_manager.h>
#include <ecs/systems/render_system.h>
#include <ecs/systems/physics_system.h>
#include <ecs/systems/transform_system.h>

namespace Engine
{
	class ECS
	{
	public:
		ECS(Renderer* renderer)
		{
			em = new EntityManager();
			cm = new ComponentManager();
			sm = new SystemManager();

			cm->registerComponentArray(TRANSFORM_COMPONENT);
			cm->registerComponentArray(PHYSICS_COMPONENT);
			sm->registerSystem(new RenderSystem(cm->getComponentArray(TRANSFORM_COMPONENT), renderer));
			sm->registerSystem(new TransformSystem(cm->getComponentArray(TRANSFORM_COMPONENT), cm->getComponentArray(PHYSICS_COMPONENT)));
			sm->registerSystem(new PhysicsSystem(cm->getComponentArray(PHYSICS_COMPONENT)));
		}
		~ECS()
		{
			delete em;
			delete cm;
			//delete sm;
		}

		EntityID createEntity()
		{
			return em->createEntity();
		}
		void destroyEntity(EntityID id)
		{
			em->destroyEntity(id);
		}
		void addComponent(EntityID id, Component* c)
		{
			cm->addComponent(id, c);
		}
		Component* getComponent(EntityID id, ComponentType t)
		{
			return cm->getComponent(id, t);
		}
		void run(long double dt)
		{
			sm->run(dt);
		}
	private:
		EntityManager* em;
		ComponentManager* cm;
		SystemManager* sm;
	};
}