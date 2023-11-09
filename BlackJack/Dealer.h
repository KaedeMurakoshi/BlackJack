#pragma once
#include"Deck.h"

class Dealer {
public:
	Dealer();								// �R���X�g���N�^
	void ShowAllHands(bool showAll)const;	// ��D�\��
	bool Play(Deck& deck);					// �P�V�_�ȉ����o�[�X�g����܂�hit 
	bool CalcScore();						// ��D�̓_�����v�Z�i�o�[�X�g������false��Ԃ��j
	void Draw(Deck& deck);				// �J�[�h���ꖇ������D�ɉ�����

private:
	Card _hand[HAND_SIZE];			// ��D�̔z��
	int _handIndex;					// ��D�z��̗v�f�ԍ��i���������Ă��邩�j
};