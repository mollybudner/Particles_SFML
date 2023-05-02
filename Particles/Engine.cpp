#include "Engine.h"

using namespace Engine;
using namespace std;

Engine()
{
	m_Window.create(VideoMode::getDesktopMode);
}

void run()
{
	sf::Clock clock;
	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2,
				  (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete. Starting engine..." << endl;

	while(m_Window.isOpen())
	{
		clock.restart();
		float time = clock.getElapsedTime().asSeconds();
}

void input()
{

}

void update(float dtAsSeconds)
{

}

void draw()
{

}
