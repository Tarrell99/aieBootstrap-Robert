#pragma once
#include <memory>
#include "AnimatedSprite.h"
#include "Vector2D.h"

class FiniteStateMachine;

namespace aie {
	class Renderer2D;
}

class GameObject
{
public:
	GameObject(FiniteStateMachine* fsm);
	~GameObject();

	void addFrame(const std::shared_ptr<aie::Texture>& frame, float delay) { m_sprite.addFrame(frame, delay); }
	
	Vector2D getPosition() { return m_position; }
	float getRotation() { return m_rotation; }
	float getSpeed() { return m_speed; }

	void setPosition(const Vector2D& pos) { m_position = pos; }
	void setRotation(float rot) { m_rotation = rot; }
	void setSpeed(float speed) { m_speed = speed; }

	void update(float deltaTime);
	void draw(aie::Renderer2D* renderer);

	

private:
	FiniteStateMachine*		m_fsm;
	AnimatedSprite			m_sprite;
	Vector2D				m_position;
	float					m_rotation;
	float					m_speed;
};

void CDDS_FiniteStateMachine_StudentApp::update(float deltaTime) {
	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->update(deltaTime);

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}
void CDDS_FiniteStateMachine_StudentApp::draw() {
	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!
	m_player->draw(m_2dRenderer);

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}
