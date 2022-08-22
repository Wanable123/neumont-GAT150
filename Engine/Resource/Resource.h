#pragma once
#include <string>

namespace livewire
{
	class Resource
	{
	public:
		virtual bool Create(std::string name, ...) = 0;
	};
}