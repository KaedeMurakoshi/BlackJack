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

void Player::Show()const
{
	printf("===================\n");

	// ��D���O���̎�
	if (_handIndex <= 0)
	{
		printf("��D������܂���\n");
		return;
	}

	printf("(���Ȃ��̎�D)\n");

	// ��D�����ׂĕ\��
	for (int i = 0; i < _handIndex; ++i)
	{
		printf("[%s��%d]\n", suitName[_hand[i].suit], _hand[i].num);
	}

	printf("===================\n");
}

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
			Show();
		}
		// stand��I��
		else if (select == 2)
		{
			printf("�`�X�^���h���܂��`\n");
			return true;
		}
		else
		{
			printf("�P�`�Q����͂��Ă�������\n");
		}
	}

	return false;
}

// �o�[�X�g������false��Ԃ�
bool Player::CalcScore()
{
	int sum = 0;				// ���v�_��
	bool haveAce = false;		// A����D�ɂ��邩�ǂ���

	// ��D�̓_�����J�E���g
	// A�͐�ɂP�_�Ƃ��ăJ�E���g���A��ō��v�l�ɂ���ĂP�O�_���_���邱�ƂŁA�P�P�_�Ƃ���
	for (int i = 0; i < _handIndex; ++i)
	{
		// ��D��A�������
		if (_hand[i].num == 1)
		{
			haveAce = true;
		}

		// �P�O�ȏ�̐��͂P�O�_�Ōv�Z
		if (_hand[i].num >= 10)
		{
			sum += 10;
		}
		// ����ȊO�͂��̂܂܂̓_��
		else 
		{
			sum += _hand[i].num;
		}	
	}

	// A������A��D�̍��v�_���P�P�_�ȉ��Ȃ�P�O�_���Z
	if (haveAce && sum <= 11)
	{
		sum += 10;
	}

	// �o�[�X�g���Ă�����false��Ԃ�
	if (sum > VINGT_ET_UN)
	{
		printf("�o�[�X�g������������\n");
		return false;
	}

	// ���v�_���\��
	printf("\n���Ȃ��̍��v�_���F%d\n\n", sum);

	// �o�[�X�g���Ă��Ȃ����true��Ԃ�
	return true;
}

// �J�[�h�������������璷�Ȃ̂Ŋ֐���
// �J�[�h���ꖇ������D�ɉ�����A�������J�[�h��\��
void Player::Draw(Deck& deck)
{
	// �R�D����ꖇ�����ĕۑ�
	Card nextCard = deck.GetDeckCard();

	// ��D�Ɉ������J�[�h�̏�����������
	_hand[_handIndex].suit = nextCard.suit;
	_hand[_handIndex].num = nextCard.num;

	//��D�̃C���f�b�N�X�X�V
	++_handIndex;

	// �������J�[�h��\��
	printf("�������J�[�h�F%d��%d\n", nextCard.suit, nextCard.num);
}

