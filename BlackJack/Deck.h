#pragma once
#include"Card.h"

// �R�D���Ǘ�����N���X
class Deck {
public:
	Deck();						// �R���X�g���N�^
	void Shuffle();				// �R�D���V���b�t������֐�
	Card GetDeckCard();			// �R�D����ꖇ�����Aindex���X�V
	int GetIndex()const			// �R�D�̉����ڂ܂ň���������Ԃ�
	{
		return _deckIndex;
	}

private:
	Card _deck[MAX_CARD_NUM];	// �R�D
	int _deckIndex;				// �ǂ��܂ŎR�D����������
};