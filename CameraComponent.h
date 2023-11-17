#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"

namespace JakEngine {
	class CameraComponent :public AComponent
	{
	public:
		sf::View view;
		sf::RenderWindow* window;

		CameraComponent();
		CameraComponent(std::string n,sf::RenderWindow* w);
		~CameraComponent();

		virtual void Awake();
		virtual void Start();
		virtual void Update(sf::Time t);
		virtual void LateUpdate(sf::Time t);
		virtual void FixedUpdate(sf::Time t);
		virtual float* OnCollisionEnter();
		virtual int GetID();
		virtual void SetWindow(sf::RenderWindow* w);
	};
}

