#include <iostream>
#include"Dealer.h"
using namespace std;

// BlackJack.cpp�̃O���[�o���ϐ����g��
extern const char* suitName[];

// �R���X�g���N�^
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
	while (CalcScore())
	{
		Draw(deck);
		ShowAllHands(false);
	}

	return false;
}