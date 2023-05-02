#include "Engine.h"

using namespace std;

Engine::Engine()
{
	m_Window.create(sf::VideoMode::getDesktopMode);
}

void Engine::run()
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

	//fix me
}

void Engine::input()
{
	Event event;
	while(m_Window.pollEvent(event))
	{
		if(event.type == Event::Closed)
		{
			m_Window.close();
		}
	}

	if(Keyboard::isKeyPressed(Keyboard::Escape))
	{
		m_Window.close();
	}

	//fix me
}

void Engine::update(float dtAsSeconds)
{
	//fix me
}

void Engine::draw()
{
	m_Window.clear();
	//fix me

	m_Window.display();
}
