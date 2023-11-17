#pragma once
#include <string>
#include <SFML/Graphics.hpp>


namespace JakEngine {
	

	class AComponent
	{
	protected:
		static int nbID;
	public:
		std::string name;
		int ID;
		AComponent();
		AComponent(std::string n);
		~AComponent();

		virtual void Awake();
		virtual void Start();
		virtual void Update(sf::Time t);
		virtual void LateUpdate(sf::Time t);
		virtual void FixedUpdate(sf::Time t);
		virtual float* OnCollisionEnter();
		virtual int GetID();
	};
}


