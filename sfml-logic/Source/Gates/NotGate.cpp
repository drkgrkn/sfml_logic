#include "Gates/NotGate.h"

NotGate::NotGate(sf::RenderWindow* w, LogicElement* ePtr) : //Constructor of NotGate which initializes number of pins, types and position of the pins relative to NotGate sprite
	LogicElement(w, ePtr)
{
	logicType = Object::objectType::NotGate;
	pins = new Pin[2]{ Pin(window, Pin::pinType::INPUT),
						Pin(window, Pin::pinType::OUTPUT) };
	numPins = 2;
	dataLength = 500;
	dIdx = 0;
	pinsPos = new sf::Vector2f[2]{ sf::Vector2f(-3,13),
								sf::Vector2f(53,13),
	};
	setSprite();
}

NotGate::~NotGate()  //Delete NotGate object and pins
{
	delete[] pins;
}

void NotGate::setSprite()
{
	sprite.setTexture(*(textures->textures[3]));
	sprite.scale(0.6f, 0.6f);

	float x_size = sprite.getTexture()->getSize().x * sprite.getScale().x;  // Resize OrGate sprite to 0.6 times by itself
	float y_size = sprite.getTexture()->getSize().y * sprite.getScale().y;

	selectionIndicator.setOutlineColor(sf::Color::Red);
	selectionIndicator.setFillColor((sf::Color(255, 255, 255, 0))); //Initiate the selection box proporties
	selectionIndicator.setOutlineThickness(4);
	selectionIndicator.setSize(sf::Vector2f(x_size, y_size));
}

void NotGate::simulate() {

	//INPUT UPDATE
	if (pins[0].connectedTo[0] == nullptr)
	{
		pins[0].state = Pin::pinState::HIGHZ;
	}
	else
	{
		pins[0].state = pins[0].connectedTo[0]->state;
	}

	//OUTPUT UPDATE
	if (pins[0].state == Pin::pinState::HIGHZ)
	{
		pins[1].state = Pin::pinState::HIGHZ;
	}
	else if (pins[0].state == Pin::pinState::HIGH)
	{
		pins[1].state = Pin::pinState::LOW;
	}

	else if (pins[0].state == Pin::pinState::LOW)
	{
		pins[1].state = Pin::pinState::HIGH;
	}


}