#pragma once
#include"Deck.h"

class Player {
public:
	Player();							// �R���X�g���N�^
	void Show()const;					// ��D�\��
	bool Play(Deck& deck);				// stand���邩�o�[�X�g����܂ŌJ��Ԃ� 
	bool CalcScore();					// ��D�̓_�����v�Z�i�o�[�X�g������false�j
	void Draw(Deck& deck);				// �J�[�h���ꖇ������D�ɉ�����

private:
	Card _hand[HAND_SIZE];		// ��D�̔z��
	int _handIndex;				// ��D�z��̗v�f�ԍ��i�����Ђ��Ă��邩�j
};