#pragma once
#include"Deck.h"

class Player {
public:
	Player();							// �R���X�g���N�^
	void Show()const;					// ��D�\��
	bool Draw(const Deck& deck);		// stand���邩�o�[�X�g����܂ŌJ��Ԃ� 
	bool CalcScore();					// ��D�̓_�����v�Z�i�o�[�X�g������false�j

private:
	Card _hand[HAND_SIZE];	// ��D�̔z��
	int _index;					// ��D�z��̗v�f�ԍ��i���Ԗڂ܂Ŏg���Ă��邩�j
	int _sum;					// ��D�̍��v�l
};