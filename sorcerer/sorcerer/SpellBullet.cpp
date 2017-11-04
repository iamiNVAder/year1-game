#include "SpellBullet.h"
#include <iostream>
SpellBullet::SpellBullet(float speed)
{
	texture.loadFromFile("Sprite\\magic_bullet.png");
	body.setTexture(&texture);
	body.setSize(sf::Vector2f(10.0f, 10.0f));
	this->speed = speed;
	shot = true;
}

SpellBullet::~SpellBullet()
{
}


void SpellBullet::Update(float deltaTime) {
	// Set color for each player.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) || sf::Keyboard::isKeyPressed(sf::Keyboard::Numpad1)) {
		if (playerSkill == 1) {
			body.setFillColor(sf::Color::Red);
		} else if (playerSkill == 2) {
			body.setFillColor(sf::Color::Blue);
		} else if (playerSkill == 3) {
			body.setFillColor(sf::Color::Yellow);
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift)) {
		body.setFillColor(sf::Color::Green);
	}
	time = clock.getElapsedTime();
	if (direction.x == 0 && direction.y == 0) {
		movement.x = lastestDirection.x * speed * deltaTime;
		movement.y = lastestDirection.y * speed * deltaTime;
	} else {
		lastestDirection.x = direction.x;
		lastestDirection.y = direction.y;
		movement.x += direction.x * speed * deltaTime;
		movement.y += direction.y * speed * deltaTime;
	}
	body.move(movement);
	if (time.asSeconds() > lifetime.asSeconds()) shot = false;
}

void SpellBullet::Draw(sf::RenderWindow& window) {
	if(GetShot()) window.draw(body);
}

void SpellBullet::SetPosition(sf::Vector2f position) {
	body.setPosition(position);
}
