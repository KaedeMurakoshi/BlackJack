#include <iostream>
#include"Player.h"
using namespace std;

// BlackJack.cpp�̃O���[�o���ϐ����g��

// �o�[�X�g���邩stand����܂Ńh���[���J��Ԃ�
bool Player::Play(Deck& deck)
{
	// �o�[�X�g������I��
	while (CalcScore())
	{
		int select = 0;	// ���͗p

		// �v���[���[�̃X�R�A��\��
		printf("\n���Ȃ��̃X�R�A�F%d\n\n", CalcScore());

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
		// stand��I��������true��Ԃ�
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
	// �o�[�X�g������false��Ԃ�
	return false;
}

