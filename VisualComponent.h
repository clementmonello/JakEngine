#pragma once
#include "AComponent.h"
#include "structure.h"
namespace JakEngine {
	class VisualComponent :public JakEngine::AComponent
	{
	public:
		position forme;

		VisualComponent();
		VisualComponent(std::string n);
		~VisualComponent();

		virtual void setDefaultParameters(sf::Shape* s, sf::Color c, float i, float j);
		virtual void setShape(sf::Shape* s);
		virtual void setPosition(sf::Vector2f p);


		virtual void Awake();
		virtual void Start();
		virtual void Update(sf::Time t);
		virtual void LateUpdate(sf::Time t);
		virtual void FixedUpdate(sf::Time t);
		virtual float* OnCollisionEnter();
		virtual int GetID();
	};
}