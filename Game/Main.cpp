
#include "Engine.h"
#include<iostream>
#include <vector>

int main() {

	std::cout << "Hello World" << std::endl;
	std::cout << "Hello World" << std::endl;

	livewire::InitializeMemory();
	livewire::SetFilePath("../Assets");

	livewire::g_audio.Initialize();
	livewire::g_inputSystem.Initialize();
	livewire::g_renderer.Initialize();
	livewire::g_time.Reset();

	livewire::g_renderer.CreateWindow("Game", 1000, 800);
	livewire::g_renderer.setClearColor(livewire::Color{ 0,0,0,255 });

	std::shared_ptr<livewire::Texture> texture = std::make_shared<livewire::Texture>();
	texture->Create(livewire::g_renderer, "sf2.bmp");

	bool quit = false;
	while (!quit) {
		livewire::g_time.Tick();


		livewire::g_inputSystem.Update();
		livewire::g_audio.Update();

		if (livewire::g_inputSystem.GetKeyDown(livewire::key_escape)) quit = true;

		livewire::g_renderer.BeginFrame();

		livewire::g_renderer.Draw(texture, { 400, 300 }, 0);
		livewire::g_renderer.EndFrame();


	}
	livewire::g_inputSystem.Shutdown();
	livewire::g_renderer.Shutdown();
	livewire::g_audio.Shutdown();
	


}