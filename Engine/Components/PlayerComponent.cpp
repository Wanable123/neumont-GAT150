#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace livewire
{
	void PlayerComponent::Initialize()
	{
		auto component = m_owner->GetComponent<CollisionComponent>();
		if (component)
		{
			component->SetCollisionEnter(std::bind(&PlayerComponent::OnCollisionEnter, this, std::placeholders::_1));
			component->SetCollisionExit(std::bind(&PlayerComponent::OnCollisionExit, this, std::placeholders::_1));
		}
	}

	void PlayerComponent::Update()
	{
		Vector2 direction = Vector2::zero;

		float p_speed = 100;
		//input
		auto left1 = livewire::g_inputSystem.GetKeyState(livewire::key_left) == livewire::InputSystem::KeyState::Held;
		auto left2 = livewire::g_inputSystem.GetKeyState(livewire::key_a) == livewire::InputSystem::KeyState::Held;
		if (left1 || left2)
		{
			//m_owner->m_transform.rotation -= 180 * livewire::g_time.deltaTime;
			direction = Vector2::left;
		}

		auto right1 = livewire::g_inputSystem.GetKeyState(livewire::key_right) == livewire::InputSystem::KeyState::Held;
		auto right2 = livewire::g_inputSystem.GetKeyState(livewire::key_d) == livewire::InputSystem::KeyState::Held;
		if (right1 || right2)
		{
			//m_owner->m_transform.rotation += 180 * livewire::g_time.deltaTime;
			direction = Vector2::right;
		}

		auto up1 = livewire::g_inputSystem.GetKeyState(livewire::key_up) == livewire::InputSystem::KeyState::Held;
		auto up2 = livewire::g_inputSystem.GetKeyState(livewire::key_w) == livewire::InputSystem::KeyState::Held;
		if (up1 || up2)
		{
			auto component = m_owner->GetComponent<PhysicsComponent>();
			if (component)
			{
				component->ApplyForce(Vector2::up * speed);
			}

		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			component->ApplyForce(direction * speed);
		}

		m_owner->m_transform.position += direction * 300 * g_time.deltaTime;

		auto down1 = livewire::g_inputSystem.GetKeyState(livewire::key_down) == livewire::InputSystem::KeyState::Held;
		auto down2 = livewire::g_inputSystem.GetKeyState(livewire::key_s) == livewire::InputSystem::KeyState::Held;
		//set speed (move)
		if (down1 || down2)
		{

		}

		if (livewire::g_inputSystem.GetKeyState(key_space) == livewire::InputSystem::KeyState::Pressed)
		{
			auto component = m_owner->GetComponent<AudioComponent>();
			if (component)
			{
				component->Play();
			}
		}

		//rotating
		bool rReset = livewire::g_inputSystem.GetButtonState(livewire::button_middle) == livewire::InputSystem::KeyState::Held;
		if (rReset)
		{
			m_owner->m_transform.rotation = 0;
		}


	}
	bool PlayerComponent::Write(const rapidjson::Value& value) const
	{
		return true;
	}

	bool PlayerComponent::Read(const rapidjson::Value& value)
	{
		READ_DATA(value, speed);
		return true;
	}

	void PlayerComponent::OnCollisionEnter(Actor* other)
	{
		std::cout << "Player enter\n";
	}
	void PlayerComponent::OnCollisionExit(Actor* other)
	{
		std::cout << "Player exit\n";
	}
}