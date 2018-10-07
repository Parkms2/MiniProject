#pragma once
#include"header.h"
#include"cookieControl.h"

class BasicCharaterCookie {
private:
	CookieControl* basicCookie = nullptr;
public:
	bool init();
};