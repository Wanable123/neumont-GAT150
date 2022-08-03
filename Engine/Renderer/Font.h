#pragma once
#include "Renderer.h"


struct _TTF_Font;

namespace livewire
{

	class Font
	{
	public:
		Font() = default;
		Font(const std::string& filename, int fontSize);
		~Font();

		void Load(const std::string& filename, int fontSize);

		friend class Text;

	private:
		_TTF_Font* m_ttfFont = nullptr;
	};
}
