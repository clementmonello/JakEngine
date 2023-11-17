#pragma once
#include <SFML/Graphics.hpp>
#include "AComponent.h"
#include <vector>

namespace JakEngine {

	class AEntity:public sf::Transformable, public sf::Drawable
	{
	protected:
		static int nbID;
	public:
		std::string name;
		std::vector<AComponent*> listComponent;
		sf::Sprite Sprite;
		sf::Texture Texture;
		int ID;

		AEntity();
		AEntity(std::string n);
		~AEntity();

		virtual void Awake();
		virtual void Start();
		virtual void Update(sf::Time t);
		virtual void LateUpdate(sf::Time t);
		virtual void FixedUpdate(sf::Time t);
		virtual void AttachComponent(AComponent *c);
		virtual void RemoveComponent(int id);
		virtual void MoveTo(float x, float y);
		virtual void Push(float x, float y);

		int GetID();

		virtual float* OnCollisionEnter();

		template<typename T>
		T* CreateAComponent(std::string n)
		{
			T* comp = new T(n);
			listComponent.push_back(comp);
			return comp;
		}

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states)const;
	};
}

