#include"baslicCharaterCookie.h"

bool init() {
	SDL_Surface* pTempSurface = IMG_Load("assets/character/basicsCookie/basicRun.png");
	if (pTempSurface == NULL) m_bRunning = false; //이미지 불러오기 실패하면 실행
	m_pTexture = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	m_sourceRectangle.x = 0;
	m_sourceRectangle.y = 0;
	m_sourceRectangle.w = 150;
	m_sourceRectangle.h = 100;
	m_destinationRectangle.x = 300;
	m_destinationRectangle.y = 400;
	m_destinationRectangle.w = m_sourceRectangle.w;
	m_destinationRectangle.h = m_sourceRectangle.h;
}


/*
update -> 	m_sourceRectangle.x = 150 * int(((SDL_GetTicks() / 100) % 4));
*/