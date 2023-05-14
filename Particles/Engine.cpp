#include "Engine.h"

using namespace std;

Engine::Engine()
{
	m_Window.create(VideoMode::getDesktopMode);
}

void Engine::run()
{
	Clock clock;
	cout << "Starting Particle unit tests..." << endl;
	Particle p(m_Window, 4, { (int)m_Window.getSize().x / 2,
				  (int)m_Window.getSize().y / 2 });
	p.unitTests();
	cout << "Unit tests complete. Starting engine..." << endl;

	while(m_Window.isOpen())
	{
		Time dt = clock.restart();
		float dtAsSeconds = dt.asSeconds();
		input();
		update(dtAsSeconds);
		draw();
	}
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

	if(Mouse::isButtonPressed(Mouse::Left))
	{
		Vector2i clickPosition;
		for(int i = 0; i < 5; i++)
		{
			int points = rand() % 26 + 25;
			Particle p(m_Window, points, clickPosition);
			m_particles.push_back(p);
		}
	}
}

void Engine::update(float dtAsSeconds)
{
	//fix me
}

void Engine::draw()
{
	m_Window.clear();

	for(int i = 0; i < m_particles.size(); i++)
	{
		m_Window.draw(m_particles.at(i));
	}

	m_Window.display();
}
