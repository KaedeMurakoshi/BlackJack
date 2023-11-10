#include <iostream>
#include"Dealer.h"
using namespace std;

// BlackJack.cpp�̃O���[�o���ϐ����g��
extern const char* suitName[];

// �R���X�g���N�^
Dealer::Dealer()
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		_hand[i].num = 0;
		_hand[i].suit = SPADE;
	}
	_handIndex = 0;
}

// ��D��\���i�f�B�[���[�͈ꖇ�ڂ����J���j
void Dealer::ShowAllHands(bool showAll)const
{
	printf("===================\n");

	// ��D���O���̎�
	if (_handIndex <= 0)
	{
		printf("[�G���[]��D������܂���\n");
		return;
	}

	printf("(�f�B�[���[�̎�D)\n");

	// showAll��true�̎��͎�D�����ׂĕ\��
	if (showAll)
	{
		// ��D�����ׂĕ\��
		for (int i = 0; i < _handIndex; ++i)
		{
			printf("[%s��%d]\n", suitName[_hand[i].suit], _hand[i].num);
		}
	}
	// showAll��false�̎��͈ꖇ�����\��
	else
	{
		// �ꖇ�����\��
		printf("[%s��%d]\n", suitName[_hand[0].suit], _hand[0].num);

		for (int i = 1; i < _handIndex; ++i)
		{
			printf("[�H�́H]\n");
		}
	}

	printf("===================\n");
}

bool Dealer::Play(Deck& deck)
{
	while (CalcScore())
	{
		Draw(deck);
		ShowAllHands(false);
	}

	return false;
}

// �o�[�X�g����stand������false��Ԃ�
bool Dealer::CalcScore()
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

	// ���v�_���\��
	printf("\n�f�B�[���[�̍��v�_���F%d\n", sum);

	// 17�����Ȃ�true��Ԃ��Čp��
	if (sum < 17)
	{
		printf("17�����Bhit���܂�\n");
		return true;
	}
	// 17�ȏ�21�ȉ��Ȃ�false��Ԃ���stand
	else if (17 <= sum && sum <= VINGT_ET_UN)
	{
		printf("stand���܂�\n");
		return false;
	}
	// �Q�P�𒴂�����false
	else
	{
		printf("���������A�o�[�X�g�����܂�����\n");
		return false;
	}
}

// �J�[�h�������������璷�Ȃ̂Ŋ֐���
// �J�[�h���ꖇ������D�ɉ�����A�������J�[�h��\��
void Dealer::Draw(Deck& deck)
{
	// �R�D����ꖇ�����ĕۑ�
	Card nextCard = deck.GetDeckCard();

	// ��D�Ɉ������J�[�h�̏�����������
	_hand[_handIndex].suit = nextCard.suit;
	_hand[_handIndex].num = nextCard.num;

	//��D�̃C���f�b�N�X�X�V
	++_handIndex;
}