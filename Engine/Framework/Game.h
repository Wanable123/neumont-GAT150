#pragma once
#include "../Engine.h"
namespace livewire {
	class Game {
	public:

		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void Update() = 0;
		virtual void Draw(livewire::Renderer& renderer) = 0;


	protected:
		int m_score = 0;
		std::unique_ptr<Scene> m_scene;

	};
}
