#pragma once
#include"Character.h"

class Player : public Character {
public:
	bool Play(Deck& deck);				// standするかバーストするまで繰り返す 
};