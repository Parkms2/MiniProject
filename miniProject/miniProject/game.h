#pragma once
#include"header.h"

class Game {
public:
	Game() {};
	~Game() {};
	bool init(const char*title, int xpos, int ypos, int width, int height, bool flags);
	void render();
	void update();
	void habdleEvents();
	void clean();
	bool running() { return m_bRunning; }
protected:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;

	SDL_Texture* m_pTextureFloor;
	SDL_Rect m_sourceRectangleFloor;
	SDL_Rect m_destinationRectangleFloor;
	SDL_Texture* m_pTextureFloor2;
	SDL_Rect m_sourceRectangleFloor2;
	SDL_Rect m_destinationRectangleFloor2;

	SDL_Texture* m_pTextureStage1Back;
	SDL_Rect m_sourceRectangleStage1Back;
	SDL_Rect m_destinationRectangleStage1Back;
	SDL_Texture* m_pTextureStage1Back2;
	SDL_Rect m_sourceRectangleStage1Back2;
	SDL_Rect m_destinationRectangleStage1Back2;

	bool m_bRunning;
};