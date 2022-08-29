#include "RBPhysicsComponents.h"
#include "Physics/PhysicsSystem.h"
#include "Engine.h"

namespace livewire {
	RBPhysicsComponent::~RBPhysicsComponent()
	{
		if (m_body) {
			g_physicsSystem.DestroyBody(m_body);
		}

	}
	void RBPhysicsComponent::Initialize()
	{
		m_body = g_physicsSystem.CreateBody(m_owner->m_transform.position, m_owner->m_transform.rotation, data);
		m_body->SetGravityScale(data.gravity_scale);
		m_body->SetLinearDamping(damping);
	}
	void RBPhysicsComponent::Update()
	{
		Vector2 position = B2VEC2_TO_VECTOR2(m_body->GetPosition());
		m_owner->m_transform.position = PhysicsSystem::WorldToScreen(position);
		m_owner->m_transform.rotation = m_body->GetAngle();
	}
	void RBPhysicsComponent::ApplyForce(const Vector2& force)
	{
		const b2Vec2 v{ force.y,force.x };
		m_body->ApplyForceToCenter(v, true);
	}
	bool RBPhysicsComponent::Write(const rapidjson::Value& value) const
	{
		return false;
	}
	bool RBPhysicsComponent::Read(const rapidjson::Value& value)
	{
		PhysicsComponent::Read(value);

		READ_DATA(value, data.gravity_scale);
		READ_DATA(value, data.constraints_angle);
		READ_DATA(value, data.is_dynamic);
		return true;
	}
}

