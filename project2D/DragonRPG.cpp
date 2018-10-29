#include "DragonRPG.h"
#include <imgui.h>
#include <iostream>
#include "Texture.h"
#include "Font.h"
#include "Input.h"

DragonRPG_Application::DragonRPG_Application()
{
}

DragonRPG_Application::~DragonRPG_Application()
{
}

bool DragonRPG_Application::startup()
{
	m_2dRenderer = new aie::Renderer2D();

	m_texture = new aie::Texture("./textures/dragon thing sprite.png");
	m_shipTexture = new aie::Texture();
	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;
	return true;
}

void DragonRPG_Application::shutdown()
{
	delete m_font;
	delete m_texture;
	delete m_shipTexture;
	delete m_2dRenderer;
}

void DragonRPG_Application::update(float deltTime)
{
	m_timer += deltTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// use arrow keys to move camera
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltTime;

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void DragonRPG_Application::draw()
{
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	// demonstrate animation
	m_2dRenderer->setUVRect(int(m_timer*2 ) % 5/ 5.0f, 0, 2.f / 10, 2.f / 8);
	m_2dRenderer->drawSprite(m_texture, 250, 250, 150, 150);

	
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}
