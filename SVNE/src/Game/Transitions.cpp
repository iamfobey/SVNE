#include "Transitions.h"

#ifdef _DEBUG
#define TimerSeconds 700
#elif NDEBUG
#define TimerSeconds 3000
#endif

void dissolve(sf::RenderWindow& window, sf::Sprite image)
{
	sf::Time timer = sf::Time::Zero;

	int i = 0;

	while (true)
	{
		timer += sf::microseconds(1);

		if (timer.asMilliseconds() > TimerSeconds)
		{
			i += 15;

			image.setColor(sf::Color(255, 255, 255, i));
			window.draw(image);
			window.display();

			timer = sf::Time::Zero;

			if (i == 255)
			{
				return;
			}
		}
	}
}