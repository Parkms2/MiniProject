#include"game.h"

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool flags) {
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0) {
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (m_pWindow != 0) {
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);	

			SDL_Surface* pTempSurface = IMG_Load("assets/characters/basicsCookie/basicRun.png");
			if (pTempSurface == NULL) m_bRunning = false; //이미지 불러오기 실패하면 실행
			m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
			SDL_FreeSurface(pTempSurface);
			m_sourceRectangle.x = 0;
			m_sourceRectangle.y = 0;
			m_sourceRectangle.w = 150;
			m_sourceRectangle.h = 100;
			m_destinationRectangle.x = 300;
			m_destinationRectangle.y = 508;
			m_destinationRectangle.w = m_sourceRectangle.w;
			m_destinationRectangle.h = m_sourceRectangle.h;

			pTempSurface = IMG_Load("assets/floors/level1Floor.png");
			if (pTempSurface == NULL) m_bRunning = false; //이미지 불러오기 실패하면 실행
			m_pTextureFloor = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
			m_pTextureFloor2 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
			SDL_FreeSurface(pTempSurface);
			m_sourceRectangleFloor.x = 0;
			m_sourceRectangleFloor.y = 0;
			m_sourceRectangleFloor.w = 1368;
			m_sourceRectangleFloor.h = 112;
			m_destinationRectangleFloor.x = 0;
			m_destinationRectangleFloor.y = 608;
			m_destinationRectangleFloor.w = m_sourceRectangleFloor.w;
			m_destinationRectangleFloor.h = m_sourceRectangleFloor.h;
			m_sourceRectangleFloor2.x = 0;
			m_sourceRectangleFloor2.y = 0;
			m_sourceRectangleFloor2.w = 1368;
			m_sourceRectangleFloor2.h = 112;
			m_destinationRectangleFloor2.x = 1368;
			m_destinationRectangleFloor2.y = 608;
			m_destinationRectangleFloor2.w = m_sourceRectangleFloor2.w;
			m_destinationRectangleFloor2.h = m_sourceRectangleFloor2.h;

			pTempSurface = IMG_Load("assets/BackGround/stage1Back.jpg");
			if (pTempSurface == NULL) m_bRunning = false; //이미지 불러오기 실패하면 실행
			m_pTextureStage1Back = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
			m_pTextureStage1Back2 = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
			SDL_FreeSurface(pTempSurface);
			m_sourceRectangleStage1Back.x = m_sourceRectangleStage1Back.y = 0;
			m_sourceRectangleStage1Back.w = 1136;
			m_sourceRectangleStage1Back.h = 640;
			m_destinationRectangleStage1Back.x = 0;
			m_destinationRectangleStage1Back.y = 0;
			m_destinationRectangleStage1Back.w = 1480;
			m_destinationRectangleStage1Back.h = 720;
			m_sourceRectangleStage1Back2.x = m_sourceRectangleStage1Back2.y = 0;
			m_sourceRectangleStage1Back2.w = 1136;
			m_sourceRectangleStage1Back2.h = 640;
			m_destinationRectangleStage1Back2.x = 1480;
			m_destinationRectangleStage1Back2.y = 0;
			m_destinationRectangleStage1Back2.w = 1480;
			m_destinationRectangleStage1Back2.h = 720;
			SDL_SetTextureAlphaMod(m_pTextureStage1Back, 90);			//반투명 정도 0~255
			SDL_SetTextureBlendMode(m_pTextureStage1Back, SDL_BLENDMODE_BLEND);
			SDL_SetTextureAlphaMod(m_pTextureStage1Back2, 90);
			SDL_SetTextureBlendMode(m_pTextureStage1Back2, SDL_BLENDMODE_BLEND);
		}
		else return false;
	}
	else return true;
}
void Game::render() {
	
	SDL_RenderClear(m_pRenderer);

	SDL_RenderCopy(m_pRenderer, m_pTextureStage1Back, &m_sourceRectangleStage1Back, &m_destinationRectangleStage1Back);
	SDL_RenderCopy(m_pRenderer, m_pTextureStage1Back2, &m_sourceRectangleStage1Back2, &m_destinationRectangleStage1Back2);

	SDL_RenderCopy(m_pRenderer, m_pTexture, &m_sourceRectangle, &m_destinationRectangle);
	SDL_RenderCopy(m_pRenderer, m_pTextureFloor, &m_sourceRectangleFloor, &m_destinationRectangleFloor);
	SDL_RenderCopy(m_pRenderer, m_pTextureFloor2, &m_sourceRectangleFloor2, &m_destinationRectangleFloor2);

	SDL_RenderPresent(m_pRenderer);

	// 만약 스페이스입력을 받으면 
}
void Game::update() {
	int tick = SDL_GetTicks();

	m_sourceRectangle.x = 150 * int(((tick / 70) % 4));		//캐릭터

	// 바닥 움직임시작
	if (m_destinationRectangleFloor.x <= -m_sourceRectangleFloor.w)	{
		m_destinationRectangleFloor.x = m_sourceRectangleFloor.w;
	}
	if (m_destinationRectangleFloor2.x <= -m_sourceRectangleFloor2.w)	{
		m_destinationRectangleFloor2.x = m_sourceRectangleFloor2.w;
	}
	if (tick % 10 == 0)	{
		m_destinationRectangleFloor.x -= 4;
		m_destinationRectangleFloor2.x -= 4; 
	}
	// 바닥 움직임끝
	//배경 움직임 시작
	if (m_destinationRectangleStage1Back.x <= -1480) {
		m_destinationRectangleStage1Back.x = m_sourceRectangleStage1Back2.x+1480;	//화면밖으로넘어가면 두번째이미지의 끝에서 부터 이어나옴
	}
	if (m_destinationRectangleStage1Back2.x <= -1480) {
		m_destinationRectangleStage1Back2.x = m_sourceRectangleStage1Back.x+1480;
	}
	if (tick % 15 == 0) {
		m_destinationRectangleStage1Back.x -= 1;
		m_destinationRectangleStage1Back2.x -= 1;
	}
	//배경 움직임 끝
}
void Game::habdleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
			case SDL_QUIT:
				m_bRunning = false;
				break;
			default:
				break;
		}
	}
}
void Game::clean() {
	std::cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}