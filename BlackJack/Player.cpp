#include <iostream>
#include"Player.h"
using namespace std;

// BlackJack.cpp�̃O���[�o���ϐ����g��
extern const char* suitName[];

// �o�[�X�g���邩stand����܂Ńh���[���J��Ԃ�
bool Player::Play(Deck& deck)
{
	while (CalcScore())
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

