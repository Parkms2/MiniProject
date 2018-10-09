#pragma once
#include"header.h"
#include"game.h"

class MapFloor {
public:
	SDL_Texture* m_pTextureFloor;
	SDL_Rect m_sourceRectangleFloor;
	SDL_Rect m_destinationRectangleFloor;
	SDL_Texture* m_pTextureFloor2;
	SDL_Rect m_sourceRectangleFloor2;
	SDL_Rect m_destinationRectangleFloor2;

	bool mapFloorInit(SDL_Renderer* m_pRenderer) {
		SDL_Surface* pTempSurface = IMG_Load("assets/floors/level1Floor.png");
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
		return true;
	}
	void mapFloorRender(SDL_Renderer* m_pRenderer) {
		SDL_RenderCopy(m_pRenderer, m_pTextureFloor, &m_sourceRectangleFloor, &m_destinationRectangleFloor);
		SDL_RenderCopy(m_pRenderer, m_pTextureFloor2, &m_sourceRectangleFloor2, &m_destinationRectangleFloor2);
	}
	void mapFloorUpdate(int tick) {
		if (m_destinationRectangleFloor.x <= -m_sourceRectangleFloor.w) {
			m_destinationRectangleFloor.x = m_sourceRectangleFloor.w;
		}
		if (m_destinationRectangleFloor2.x <= -m_sourceRectangleFloor2.w) {
			m_destinationRectangleFloor2.x = m_sourceRectangleFloor2.w;
		}
		if (tick % 10 == 0) {
			m_destinationRectangleFloor.x -= 4;
			m_destinationRectangleFloor2.x -= 4;
		}
	}
};