#include "Engine.h"
#include <iostream>

int main()
{
	livewire::InitializeMemory();
	livewire::SetFilePath("../Assets");

	livewire::g_renderer.Initialize();
	livewire::g_inputSystem.Initialize();
	livewire::g_audioSystem.Initialize();
	livewire::g_resourceManager.Initialize();

	livewire::Engine::Instance().Register();

	int width = 800; 
	int height = 600; 
	livewire::g_renderer.CreateWindow("TheGame", width, height);
	livewire::g_renderer.SetClearColor(livewire::Color::black); 

	std::shared_ptr<livewire::Texture> texture = livewire::g_resourceManager.Get<livewire::Texture>("Textures/spaceShip.png", &livewire::g_renderer);

	livewire::g_audioSystem.AddAudio("laser", "Audio/laser.wav");

	livewire::Scene scene;

	rapidjson::Document document;
	bool success = livewire::json::Load("level.txt", document);
	//assert(success);
	scene.Read(document);

	float angle = 0;

	bool gaming = true;
	while (gaming)
	{
		//update (engine)
		livewire::g_time.Tick();
		livewire::g_inputSystem.Update();
		//audio
		livewire::g_audioSystem.Update();

		if (livewire::g_inputSystem.GetKeyDown(livewire::key_escape)) gaming = false;

		//update scene
		angle += 360.0f * livewire::g_time.deltaTime; //rotation
		scene.Update();

		//render
		livewire::g_renderer.BeginFrame();

		scene.Draw(livewire::g_renderer);

		livewire::g_renderer.EndFrame();
	}

	//shut
	livewire::g_inputSystem.Shutdown();
	livewire::g_resourceManager.Shutdown();
	livewire::g_audioSystem.Shutdown();
	livewire::g_renderer.Shutdown();
}