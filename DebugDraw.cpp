#include "DebugDraw.h"
#include <SFML/Graphics.hpp>
JakEngine::DebugDraw::DebugDraw(sf::RenderWindow& w):window(w)
{
}

void JakEngine::DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	sf::ConvexShape polygon(vertexCount);
	for (int i = 0; i < vertexCount; i++)
	{
		polygon.setPoint(i, sf::Vector2f(vertices[i].x, vertices[i].y)); 
	}																								  
	polygon.setOutlineThickness(0.02f);
	polygon.setFillColor(sf::Color::Transparent);
	polygon.setOutlineColor(sf::Color(color.r * 255, color.g * 255, color.b * 255, color.a * 255));

	window.draw(polygon);
}
void JakEngine::DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
{
	sf::ConvexShape polygon(vertexCount);
	for (int i = 0; i < vertexCount; i++)
	{
		polygon.setPoint(i, sf::Vector2f(vertices[i].x, vertices[i].y));
	}
	polygon.setFillColor(sf::Color(color.r * 255, color.g * 255, color.b * 255, color.a * 255));

	window.draw(polygon);
}
void JakEngine::DebugDraw::DrawCircle(const b2Vec2& center, float radius, const b2Color& color)
{
	sf::CircleShape circle(radius);
	circle.setPosition(center.x, center.y);
	circle.setOrigin(radius, radius);
	circle.setFillColor(sf::Color::Transparent);
	circle.setOutlineColor(sf::Color(color.r * 255, color.g * 255, color.b * 255, color.a * 255));
	circle.setOutlineThickness(0.02f);
	window.draw(circle);

}
void JakEngine::DebugDraw::DrawSolidCircle(const b2Vec2& center, float radius, const b2Vec2& axis, const b2Color& color)
{
	sf::CircleShape circle(radius);
	circle.setPosition(center.x, center.y);
	circle.setOrigin(radius, radius);
	circle.setFillColor(sf::Color(color.r * 255, color.g * 255, color.b * 255, color.a * 80));
	window.draw(circle);

	b2Vec2 p = center + (radius * axis);
	DrawSegment(center, p, color);
}
void JakEngine::DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
{
	sf::VertexArray line(sf::Lines, 2);
	sf::Color c=sf::Color(color.r * 255, color.g * 255, color.b * 255, color.a * 255);

	line[0].position = sf::Vector2f(p1.x, p1.y);
	line[0].color = c;
	line[1].position = sf::Vector2f(p2.x, p2.y);
	line[1].color = c;

	window.draw(line);
}
void JakEngine::DebugDraw::DrawTransform(const b2Transform& xf)
{
	float lineLength = 0.4;

	b2Vec2 p = xf.p;
	b2Vec2 px = p + (0.5f * xf.q.GetXAxis());
	b2Vec2 py = p + (0.5f * xf.q.GetYAxis());

	DrawSegment(p, px, b2Color(1.f, 0.f, 0.f));
	DrawSegment(p, py, b2Color(0.f, 1.f, 0.f));
}

void JakEngine::DebugDraw::DrawPoint(const b2Vec2& p, float size, const b2Color& color)
{
	sf::CircleShape circle(size);
	circle.setPosition(p.x,p.y);
	circle.setOrigin(size / 2.0f, size / 2.0f);
	circle.setFillColor(sf::Color(color.r*255, color.g * 255, color.b * 255,color.a * 255));
	window.draw(circle);
}
