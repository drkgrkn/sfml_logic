#include "Gates/LED.h"

LED::LED(sf::RenderWindow* w, LogicElement* ePtr) :
	LogicElement(w, ePtr)
{
	logicType = Object::objectType::LED;
	pins = new Pin[1]{ Pin(window, Pin::pinType::INPUT),
	};
	numPins = 1;
	dataLength = 500;
	dIdx = 0;
	pinsPos = new sf::Vector2f[1]{ sf::Vector2f(8,40),
	};
	setSprite();
}

LED::~LED()
{
	delete[] pins;
}

void LED::setSprite()
{
	sprite.setTexture(*(textures->textures[8]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}


void LED::setSprite(int index) {
	
	sprite.setTexture(*(textures->textures[index+8]));
	sprite.scale(1.f, 1.f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0)));
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));

	}

void LED::simulate()
{
	//INPUT UPDATE
	if (pins[0].connectedTo[0] != nullptr)
	{
		pins[0].state = pins[0].connectedTo[0]->state;
	}
	else
	{
		setSprite(0);
		pins[0].state = Pin::pinState::HIGHZ;
	}

	//OUTPUT UPDATE
	if (pins[0].state == Pin::pinState::HIGH)
	{
		setSprite(1);
	}
	if (pins[0].state == Pin::pinState::LOW)
	{
		setSprite(0);
	}
}

void LED::reset()
{
	setSprite(0);
	delete[] data;
	dataLength = 500;
	data = new Pin::pinState[dataLength];
	for (int i = 0; i < dataLength; i++)
		data[i] = Pin::pinState::HIGHZ;
	for (int p = 0; p < numPins; p++)
	{
		pins[p].reset();
	}
}
