#include <iostream>
#include"Character.h"

// BlackJack.cpp�̃O���[�o���ϐ����g��
extern const char* suitName[];

// �R���X�g���N�^
Character::Character()
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		_hand[i].num = 0;
		_hand[i].suit = SPADE;
	}
	_handIndex = 0;
}

// ��D��\���i�f�B�[���[�͈ꖇ�ڂ����J���j
void Character::ShowAllHands(bool showAll)const
{
	printf("===================\n");

	// ��D���O���̎�
	if (_handIndex <= 0)
	{
		printf("[�G���[]��D������܂���\n");
		return;
	}

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

// �o�[�X�g������O��Ԃ�
int Character::CalcScore()
{
	int score = 0;				// ���v�_��
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
			score += 10;
		}
		// ����ȊO�͂��̂܂܂̓_��
		else
		{
			score += _hand[i].num;
		}
	}

	// A������A��D�̍��v�_���P�P�_�ȉ��Ȃ�P�O�_���Z
	if (haveAce && score <= 11)
	{
		score += 10;
	}

	//�o�[�X�g�ł���ꍇ��0��Ԃ�
	if (score > 21) {
		//�X�R�A��0����
		score = 0;
	}

	return score;
}

// �J�[�h�������������璷�Ȃ̂Ŋ֐���
// �J�[�h���ꖇ������D�ɉ�����A�������J�[�h��\��
void Character::Draw(Deck& deck)
{
	// �R�D����ꖇ�����ĕۑ�
	Card nextCard = deck.GetDeckCard();

	// ��D�Ɉ������J�[�h�̏�����������
	_hand[_handIndex].suit = nextCard.suit;
	_hand[_handIndex].num = nextCard.num;

	//��D�̃C���f�b�N�X�X�V
	++_handIndex;
}