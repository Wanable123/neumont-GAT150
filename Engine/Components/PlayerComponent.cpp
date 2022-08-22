#include "PlayerComponent.h"
#include "Engine.h"
#include <iostream>

namespace livewire
{
	void PlayerComponent::Update()
	{
		Vector2 direction = Vector2::zero;

		float p_speed = 100;
		//input
		auto left1 = livewire::g_inputSystem.GetKeyState(livewire::key_left) == livewire::InputSystem::KeyState::Held;
		auto left2 = livewire::g_inputSystem.GetKeyState(livewire::key_a) == livewire::InputSystem::KeyState::Held;
		if (left1 || left2)
		{
			m_owner->m_transform.rotation -= 180 * livewire::g_time.deltaTime;
		}

		auto right1 = livewire::g_inputSystem.GetKeyState(livewire::key_right) == livewire::InputSystem::KeyState::Held;
		auto right2 = livewire::g_inputSystem.GetKeyState(livewire::key_d) == livewire::InputSystem::KeyState::Held;
		if (right1 || right2)
		{
			m_owner->m_transform.rotation += 180 * livewire::g_time.deltaTime;
		}

		auto up1 = livewire::g_inputSystem.GetKeyState(livewire::key_up) == livewire::InputSystem::KeyState::Held;
		auto up2 = livewire::g_inputSystem.GetKeyState(livewire::key_w) == livewire::InputSystem::KeyState::Held;
		//set speed move
		float thrust = 0;
		if (up1 || up2)
		{
			thrust = 500;

		}

		auto component = m_owner->GetComponent<PhysicsComponent>();
		if (component)
		{
			//thrust force
			Vector2 force = Vector2::Rotate({ 1, 0 }, math::DegToRad(m_owner->m_transform.rotation)) * thrust;
			component->ApplyForce(force);
		}

		m_owner->m_transform.position += direction * 300 * g_time.deltaTime;

		auto down1 = livewire::g_inputSystem.GetKeyState(livewire::key_down) == livewire::InputSystem::KeyState::Held;
		auto down2 = livewire::g_inputSystem.GetKeyState(livewire::key_s) == livewire::InputSystem::KeyState::Held;
		if (down1 || down2)
		{
			//m_owner->m_transform.position.y += p_speed * livewire::g_time.deltaTime;
			//direction += Vector2::down * 100;
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
}