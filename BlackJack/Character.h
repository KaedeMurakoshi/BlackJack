#pragma once
#include"Deck.h"

class Character {
public:
	void ShowAllHands(bool showAll)const;	// ��D�\��
	void Draw(Deck& deck);

protected:
	int CalcScore();
	Card _hand[HAND_SIZE];			// ��D�̔z��
	int _handIndex;					// ��D�z��̗v�f�ԍ��i���������Ă��邩�j
};