#pragma once
#include"header.h"
#include"game.h"

class CookieAction {
public:
	//기본 점프1 시작
	bool jump1 = false; //true이면 점프실행
	bool peeked = false;	//꼭지점을 찍으면
	int floorHeight = 508;	//바닥지점

	SDL_Texture* m_pTextureJump;
	SDL_Rect m_sourceRectangleJump;
	SDL_Rect m_destinationRectangleJump;
	//기본 점프1 끝

	//슬라이딩 시작
	bool slide = false;
	SDL_Texture* m_pTextureSlide;
	SDL_Rect m_sourceRectangleSlide;
	SDL_Rect m_destinationRectangleSlide;
	//슬라이딩 끝


	virtual bool basicJumpInit(SDL_Renderer* m_pRenderer) {
		SDL_Surface* pTempSurface = IMG_Load("assets/characters/basicsCookie/jump1-1.png");
		m_pTextureJump = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);
		m_sourceRectangleJump.x = 0;
		m_sourceRectangleJump.y = 0;
		m_sourceRectangleJump.w = 150;
		m_sourceRectangleJump.h = 100;
		m_destinationRectangleJump.x = 300;
		m_destinationRectangleJump.y = 508;
		m_destinationRectangleJump.w = m_sourceRectangleJump.w;
		m_destinationRectangleJump.h = m_sourceRectangleJump.h;
		return true;
	}
	virtual bool basicSlideInit(SDL_Renderer* m_pRenderer) {
		SDL_Surface* pTempSurface = IMG_Load("assets/characters/basicsCookie/slide.png");
		m_pTextureSlide = SDL_CreateTextureFromSurface(m_pRenderer, pTempSurface);
		SDL_FreeSurface(pTempSurface);
		m_sourceRectangleSlide.x = 0;
		m_sourceRectangleSlide.y = 0;
		m_sourceRectangleSlide.w = 150;
		m_sourceRectangleSlide.h = 100;
		m_destinationRectangleSlide.x = 300;
		m_destinationRectangleSlide.y = 560;
		m_destinationRectangleSlide.w = m_sourceRectangleSlide.w;
		m_destinationRectangleSlide.h = m_sourceRectangleSlide.h;
		return true;
	}
	virtual void basicJumpRender(SDL_Renderer* m_pRenderer, SDL_Texture* m_pTexture, SDL_Rect* m_sourceRectangle, SDL_Rect m_destinationRectangle) {
		if (jump1 != true && slide != true) {
			SDL_RenderCopy(m_pRenderer, m_pTexture, m_sourceRectangle, &m_destinationRectangle);
		}
		else if (jump1 == true) {
			SDL_RenderCopy(m_pRenderer, m_pTextureJump, &m_sourceRectangleJump, &m_destinationRectangleJump);
		}
		else if (slide = true) {
			SDL_RenderCopy(m_pRenderer, m_pTextureSlide, &m_sourceRectangleSlide, &m_destinationRectangleSlide);
		}
	}

	virtual void basicJumpUpdate(int tick, SDL_Rect *m_sourceRectangle) {
		if (jump1 == true) {
			if (tick % 8 == 0) {
				if (m_destinationRectangleJump.y < 368) {
					peeked = true;
				}
				if (peeked) {
					m_destinationRectangleJump.y += 2;
				}
				else {
					m_destinationRectangleJump.y -= 2;
				}
				m_sourceRectangleJump.x = 150 * int(tick / 50 % 3);
			}
			if (m_destinationRectangleJump.y > floorHeight) {
				m_destinationRectangleJump.y = floorHeight;
				jump1 = false;
			}
		}
		else if (slide == true && jump1 == false) {
			m_sourceRectangleSlide.x = 150 * int(tick / 70 % 2);
			if (tick % 2000 == 0) slide = false;
		}
		else m_sourceRectangle->x = 150 * int(tick / 70 % 4);		//캐릭터
	}
	void sdlKeyUp() {
		if (jump1 == false) {
			jump1 = true;
			peeked = false;
			slide = false;
		}
	}
	void sdlKeyDown() {
		if(jump1 == false) slide = true;
	}
			// if 키다운 끝나면 slide = false;
};