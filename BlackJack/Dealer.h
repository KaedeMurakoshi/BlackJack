#pragma once
#include"Character.h"

class Dealer : public Character{
public:
	Dealer();								// �R���X�g���N�^
	bool Play(Deck& deck);					// �P�V�_�ȉ����o�[�X�g����܂�hit 
};
