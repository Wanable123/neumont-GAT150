#include "TheGame.h"
#include "Engine.h"

void TheGame::Initialize()
{
	m_scene = std::make_unique<livewire::Scene>();
	rapidjson::Document document;
	std::vector<std::string> sceneNames = { "Scenes/prefabs.txt","Scenes/Tilemap.txt","Scenes/level.txt"};

	for (auto sceneName : sceneNames) {

		bool success = livewire::json::Load(sceneName, document);
		if (!success) {
			LOG("Could not load scene &s", sceneName.c_str());
			continue;
		}

		m_scene->Read(document);
		
	}
	m_scene->Initialize();




	for (int i = 0; i < 10; i++)
	{
		auto actor = livewire::Factory::Instance().Create<livewire::Actor>("Coin");
		actor->m_transform.position = { livewire::randomf(0, 800), 100.0f };
		
		actor->Initialize();
		m_scene->Add(std::move(actor));
		

	}
}


 void TheGame::Shutdown() 
{
	m_scene->RemoveAll();
}


 void TheGame::Update() 
{
	m_scene->Update();

}


 void TheGame::Draw(livewire::Renderer& renderer) 
{
	m_scene->Draw(renderer);

}