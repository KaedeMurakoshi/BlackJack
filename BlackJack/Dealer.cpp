#include <iostream>
#include"Dealer.h"
using namespace std;

// BlackJack.cpp�̃O���[�o���ϐ����g��

bool Dealer::Play(Deck& deck)
{
	// �X�R�A���P�V�ȏ�ɂȂ�܂�hit
	while (CalcScore() < 17 && CalcScore() > 0)
	{
		printf("�f�B�[���[�F�u hit���܂��B�v\n");
		Draw(deck);
	}
	if (CalcScore() <= 0) return false;
	return true;
}