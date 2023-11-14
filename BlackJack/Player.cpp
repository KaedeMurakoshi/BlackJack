#include <iostream>
#include"Player.h"
using namespace std;

// BlackJack.cpp�̃O���[�o���ϐ����g��
extern const char* suitName[];

// �R���X�g���N�^
Player::Player()
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		_hand[i].num = 0;
		_hand[i].suit = SPADE;
	}
	_handIndex = 0;
}

// �o�[�X�g���邩stand����܂Ńh���[���J��Ԃ�
bool Player::Play(Deck& deck)
{
	while (CalcScore() != 0)
	{
		int select = 0;	// ���͗p

		// �I�����\��
		printf("1.hit 2.stand > ");
		cin >> select;
		printf("\n");

		// hit
		if (select == 1)
		{
			Draw(deck);

			// ��D�\��
			ShowAllHands(true);
		}
		// stand��I��
		else if (select == 2)
		{
			printf("�X�^���h\n");
			return true;
		}
		else
		{
			printf("�P�`�Q����͂��Ă�������\n");
		}
	}
	return false;
}

