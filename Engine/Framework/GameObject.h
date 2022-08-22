#pragma once
#include "Serialization/Serializable.h"

#define REGISTER_CLASS(class) Factory::Instance().Register<class>(#class)
namespace livewire
{
	class GameObject
	{
	public:
		GameObject() = default;
		virtual void Update() = 0;
	};
}