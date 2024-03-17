#pragma once
#include <vector>
#include <ecs/systems/isystem.h>
namespace Engine
{
	class SystemManager
	{
	public:
		~SystemManager()
		{

		}
		void registerSystem(ISystem* s)
		{
			system_array.push_back(s);
		}

		void run(long double dt)
		{
			for (ISystem* s : system_array)
			{
				s->run(dt);
			}
		}
	private:
		std::vector<ISystem*> system_array;
	};
}