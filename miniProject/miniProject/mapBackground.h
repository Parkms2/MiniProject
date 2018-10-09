#pragma once
#include"header.h"
#include"game.h"

class MapBackground {
public:
	SDL_Texture* m_pTextureStage1Back;
	SDL_Rect m_sourceRectangleStage1Back;
	SDL_Rect m_destinationRectangleStage1Back;
	SDL_Texture* m_pTextureStage1Back2;
	SDL_Rect m_sourceRectangleStage1Back2;
	SDL_Rect m_destinationRectangleStage1Back2;

	bool mapBackgroundInit(SDL_Renderer* m_pRenderer) {
		SDL_Surface* pTempSurface = IMG_Load("assets/BackGround/stage1Back.jpg");
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
		return true;
	}
	void mapBackgroundRender(SDL_Renderer* m_pRenderer) {
		SDL_RenderCopy(m_pRenderer, m_pTextureStage1Back, &m_sourceRectangleStage1Back, &m_destinationRectangleStage1Back);
		SDL_RenderCopy(m_pRenderer, m_pTextureStage1Back2, &m_sourceRectangleStage1Back2, &m_destinationRectangleStage1Back2);
	}
	void mapBackgroundUpdate(int tick) {
		if (m_destinationRectangleStage1Back.x <= -1480) {
			m_destinationRectangleStage1Back.x = m_sourceRectangleStage1Back2.x + 1480;	//화면밖으로넘어가면 두번째이미지의 끝에서 부터 이어나옴
		}
		if (m_destinationRectangleStage1Back2.x <= -1480) {
			m_destinationRectangleStage1Back2.x = m_sourceRectangleStage1Back.x + 1480;
		}
		if (tick % 15 == 0) {
			m_destinationRectangleStage1Back.x -= 1;
			m_destinationRectangleStage1Back2.x -= 1;
		}
	}
};