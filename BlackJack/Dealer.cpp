#include <iostream>
#include"Dealer.h"
using namespace std;

// BlackJack.cppのグローバル変数を使う
extern const char* suitName[];

// コンストラクタ
Dealer::Dealer()
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		_hand[i].num = 0;
		_hand[i].suit = SPADE;
	}
	_handIndex = 0;
}


bool Dealer::Play(Deck& deck)
{
	while (CalcScore() < 17 && CalcScore() > 0)
	{
		Draw(deck);
	}

	return false;
}