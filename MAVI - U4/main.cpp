#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

#define FONT_PATH "C:\\Windows\\Fonts\\arial.ttf"

using namespace sf;

int main()
{
	int sizeX = 800;
	int sizeY = 600;

	/////Creamos la ventana//////
	sf::RenderWindow App(sf::VideoMode(sizeX, sizeY, 32), "Que ventana horrible");

	/////Loop principal//////
	while (App.isOpen())
	{
		App.setFramerateLimit(60);

		Event evt;
		while (App.pollEvent(evt)) {
			/////Procesar eventos//////
			switch (evt.type)
			{
				/////Si se cerro la ventana//////
			case sf::Event::Closed:
				App.close();
				break;	
			}

			if (Keyboard::isKeyPressed(Keyboard::Escape) == true)
				App.close();

			

			if (Keyboard::isKeyPressed(Keyboard::Up) == true && sizeY >= 100) {
				sizeY -= 1;
				App.setSize(sf::Vector2u(sizeX, sizeY));
			}
			if (Keyboard::isKeyPressed(Keyboard::Down) == true && sizeY <= 1000) {
				sizeY += 1;
				App.setSize(sf::Vector2u(sizeX, sizeY));
			}
			if (Keyboard::isKeyPressed(Keyboard::Left) == true && sizeX >= 100) {
				sizeX -= 1;
				App.setSize(sf::Vector2u(sizeX, sizeY));
			}
			if (Keyboard::isKeyPressed(Keyboard::Right) == true && sizeX <= 1000) {
				sizeX += 1;
				App.setSize(sf::Vector2u(sizeX, sizeY));
			}
		}

		App.clear();

		App.display();
	}
	return 0;
}

