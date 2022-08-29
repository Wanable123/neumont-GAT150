#pragma once
#include "Framework/Game.h"


class TheGame : public livewire::Game
{
public:
	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(livewire::Renderer& renderer) override;

	
protected:



};