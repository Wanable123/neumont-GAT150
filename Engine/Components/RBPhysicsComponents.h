#pragma once
#include "Components/PhysicsComponent.h"
#include "Physics/PhysicsSystem.h"
namespace livewire
{
	class RBPhysicsComponent : public PhysicsComponent
	{

	public:
		RBPhysicsComponent() = default;
		~RBPhysicsComponent();

		void Initialize() override;
		void Update() override;

		CLASS_DECLARATION(RBPhysicsComponent)

		virtual void ApplyForce(const Vector2& force);

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

		friend class CollisionComponent;

	private:
		PhysicsSystem::RigidBodyData data;
		b2Body* m_body = nullptr;

	};



}