#pragma once
#include"Deck.h"

class Player {
public:
	void Show()const;					// ��D�\��
	void Draw(Deck& deck);		// stand���邩�o�[�X�g����܂ŌJ��Ԃ� 
	bool CalcScore();					// ��D�̓_�����v�Z�i�o�[�X�g������false�j

private:
	Card _hand[MAX_HAND_NUM];	// ��D�̔z��
	int _index;					// ��D�z��̗v�f�ԍ��i���Ԗڂ܂Ŏg���Ă��邩�j
	int _sum;					// ��D�̍��v�l
};