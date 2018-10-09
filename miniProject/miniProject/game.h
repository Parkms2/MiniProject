#pragma once
#include"header.h"

class Game {
public:
	Game() {};
	~Game() {};
	bool init(const char*title, int xpos, int ypos, int width, int height, bool flags);
	void render();
	void update();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning; }

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;	//true = 게임실행 false = 게임 종료

	/*
	void SdlDeltaTime() {
		Uint64 now = SDL_GetTicks();
		this->deltaTime = now - this->prevFrame;
		this->prevFrame = now;
	}
	static int getDeltaTime()
	{
		return deltaTime;
	}
private:
	static Uint64 prevFrame;
	static int deltaTime;
	*/
};