#pragma once
#include "Application2D.h"
#include <Renderer2D.h>

class DragonRPG_Application : public aie::Application
{
public:
	DragonRPG_Application();
	virtual ~DragonRPG_Application();
	bool startup() override;
	void shutdown() override;
	void update(float deltTime) override;
	void draw()override;

	aie::Renderer2D* renderer;
protected:
//
	aie::Renderer2D*   m_2dRenderer;
	aie::Texture*      m_texture;
	aie::Texture*      m_shipTexture;
	aie::Font*         m_font;
//
	float m_cameraX, m_cameraY;
	float m_timer;
};

