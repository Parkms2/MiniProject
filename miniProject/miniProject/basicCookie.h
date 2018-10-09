#pragma once
#include"header.h"
#include"game.h"
#include"cookieAction.h"

class BasicCookie : public CookieAction {
public:
	SDL_Texture* m_pTexture;
	SDL_Rect m_sourceRectangle;
	SDL_Rect m_destinationRectangle;


	bool basicCookieRun(SDL_Renderer* m_pRenderer) {
		SDL_Surface* pTempSurface = IMG_Load("assets/characters/basicsCookie/basicRun.png");
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

		CookieAction::basicJumpInit(m_pRenderer);
		CookieAction::basicSlideInit(m_pRenderer);

		return true;
	}

	void basicCookieRender(SDL_Renderer* m_pRenderer){
		CookieAction::basicJumpRender(m_pRenderer, m_pTexture, &m_sourceRectangle, m_destinationRectangle);
	}

	void basicCookieUpdate(int tick) {
		CookieAction::basicJumpUpdate(tick, &m_sourceRectangle);
	}
};
