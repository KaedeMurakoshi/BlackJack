#pragma once
#include"Card.h"

// �R�D���Ǘ�����N���X
class Deck {
public:
	Deck();						// �R���X�g���N�^
	void Shuffle();				// �R�D���V���b�t������֐�
	Card GetDeck()const
	{
		return _deck[deckIndex];
	}
	int GetIndex()const
	{
		return deckIndex;
	}
	void SetIndex()
	{
		++deckIndex;
	}

private:
	Card _deck[MAX_CARD_NUM];	// �R�D
	int deckIndex;
};