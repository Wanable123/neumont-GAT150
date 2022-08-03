#pragma once
#include "Renderer.h"
#include <string>
#include <vector>


namespace livewire
{
	class Model
	{
	public:
		Model() = default;
		Model(const std::vector<livewire::Vector2>& points, const livewire::Color& color) :
			m_points{ points },
			m_color{ color }
		{
		}
		Model(const std::string& filename);

		void Draw(Renderer& renderer, const Vector2& position, float angle, float scale = 1);

		void Load(const std::string& filename);
		float CalculateRadius();

		float GetRadius() { return m_radius; }

	private:
		std::vector<livewire::Vector2> m_points;
		livewire::Color m_color{ 0,0,0,0 };
		float m_radius = 0;
	};
}