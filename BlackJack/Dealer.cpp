#include <iostream>
#include"Dealer.h"
using namespace std;

// BlackJack.cpp�̃O���[�o���ϐ����g��
extern const char* suitName[];

bool Dealer::Play(Deck& deck)
{
	while (CalcScore() < 17 && CalcScore() > 0)
	{
		Draw(deck);
	}

	return false;
}