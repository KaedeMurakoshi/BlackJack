#pragma once
#include"Character.h"

class Player : public Character {
public:
	Player();							// �R���X�g���N�^
	bool Play(Deck& deck);				// stand���邩�o�[�X�g����܂ŌJ��Ԃ� 
};