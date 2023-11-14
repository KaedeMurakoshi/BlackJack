#pragma once
#include"Character.h"

class Dealer : public Character{
public:
	bool Play(Deck& deck);					// １７点以下かつバーストするまでhit 
};
