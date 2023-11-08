#include <iostream>
#include"Player.h"
using namespace std;

// �R���X�g���N�^
Player::Player()
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		_hand[i].num = 0;
		_hand[i].suit = SPADE;
	}
	_index = 0;
}

void Player::Show()const
{
	const char* suit[] = {"�X�y�[�h", "�n�[�g", "�_�C�������h", "�N���u"};

	if (_index <= 0)
	{
		printf("��D������܂���");
		return;
	}

	printf("(���Ȃ��̎�D)\n");

	// ��D�����ׂĕ\��
	for (int i = 0; i < _index; ++i)
	{
		printf("%s��%d\n", suit[_hand[i].suit], _hand[i].num);
	}
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
		
		// hit
		if (select == 1)
		{
			//printf("[�f�o�b�O]�h���[�O�̎R�D�̃C���f�b�N�X>%d\n", deck.GetIndex());
			Card drawCard = deck.GetDeckCard();
			//("[�f�o�b�O]�h���[��̎R�D�̃C���f�b�N�X>%d\n", deck.GetIndex());

			// ��D�Ɉ������J�[�h�̏�����������
			_hand[_index].suit = drawCard.suit;
			_hand[_index].num = drawCard.num;

			// �������J�[�h
			printf("�������J�[�h�F%d��%d", drawCard.suit, drawCard.num);

			//��D�̃C���f�b�N�X�X�V
			++_index;

			// ��D�\��
			Show();
		}
		// stand
		else if (select == 2)
		{
			printf("�X�^���h���܂�");
			return true;
		}
		else
		{
			printf("�P�`�Q����͂��Ă�������");
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
	for (int i = 0; i < _index; ++i)
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
	printf("���݂̍��v�_���F%d\n", sum);

	// �o�[�X�g���Ă��Ȃ����true��Ԃ�
	return true;
}