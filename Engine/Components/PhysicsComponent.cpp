#include "PhysicsComponent.h"
#include "../Engine.h"

namespace livewire 
	{
		void PhysicsComponent::Update()
		{
			velocity += acceleration * livewire::g_time.deltaTime;
			m_owner->m_transform.position += velocity * livewire::g_time.deltaTime;
			velocity *= damping;

			acceleration = Vector2::zero;
		}

		bool PhysicsComponent::Write(const rapidjson::Value & value) const
		{
			return false;
		}

		bool PhysicsComponent::Read(const rapidjson::Value & value)
		{
			READ_DATA(value, damping);
			READ_DATA(value, velocity);
			READ_DATA(value, acceleration);

			return true;
		}

	}
