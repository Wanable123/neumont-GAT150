#include "TheGame.h"
#include "Engine.h"
#include <iostream>

int main()
{
	livewire::InitializeMemory();
	livewire::SetFilePath("../Assets");

	//initilize engine
	livewire::g_renderer.Initialize();
	livewire::g_inputSystem.Initialize();
	livewire::g_audioSystem.Initialize();
	livewire::g_physicsSystem.Initialize();
	livewire::g_resourceManager.Initialize();

	livewire::Engine::Instance().Register();

	//create window
	int width = 800; //800
	int height = 600; //600
	livewire::g_renderer.CreateWindow("Gaming", width, height);
	livewire::g_renderer.SetClearColor(livewire::Color::black); //old color: livewire::Color{ 21, 130, 173, 255 }

	std::shared_ptr<livewire::Texture> texture = livewire::g_resourceManager.Get<livewire::Texture>("textures/spaceShip.png", &livewire::g_renderer);

	//audio
	livewire::g_audioSystem.AddAudio("laser", "Audio/laser.wav");




	//Create game
	std::unique_ptr<TheGame> game = std::make_unique<TheGame>();
	game->Initialize();

	


	bool gaming = true;
	while (gaming)
	{
		//update (engine)
		livewire::g_time.Tick();
		livewire::g_inputSystem.Update();
		//audio
		livewire::g_audioSystem.Update();

		//physics
		livewire::g_physicsSystem.Update();

		if (livewire::g_inputSystem.GetKeyDown(livewire::key_escape)) gaming = false;

		//update scene
		game->Update();

		//render
		livewire::g_renderer.BeginFrame();

		game->Draw(livewire::g_renderer);

		livewire::g_renderer.EndFrame();
	}
	game->Shutdown();
	
	livewire::Factory::Instance().Shutdown();
	//shut
	livewire::g_resourceManager.Shutdown();
	livewire::g_physicsSystem.Shutdown();
	livewire::g_audioSystem.Shutdown();
	livewire::g_inputSystem.Shutdown();
	livewire::g_renderer.Shutdown();
}