#pragma once
#include <SFML/Graphics.hpp>

namespace JakEngine {
	class Input
	{
	public:
		sf::Keyboard keyboard;

		Input();
		~Input();

		virtual void Update(sf::Event e);
	};
}


