#pragma once
#include "RenderComponent.h"

namespace livewire
{
	class Model;

	class ModelComponent : public RenderComponent
	{
	public:
		ModelComponent() = default;

		CLASS_DECLARATION(ModelComponent)
	public:

		virtual void Update() override;
		virtual void Draw(Renderer& renderer) override;

		virtual bool Write(const rapidjson::Value& value) const override;
		virtual bool Read(const rapidjson::Value& value) override;

	public:
		std::shared_ptr<Model> m_model;

	};
}