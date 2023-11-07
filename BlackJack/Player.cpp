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
	_sum = 0;
}

void Player::Show()const
{
	const char* suit[] = {"�X�y�[�h", "�n�[�g", "�_�C�������h", "�N���u"};

	printf("(���Ȃ��̎�D)\n");

	for (int i = 0; i <= _index; ++i)
	{
		printf("%s��%d\n", suit[_hand[i].suit], _hand[i].num);
	}
}

// �o�[�X�g���邩stand����܂Ńh���[���J��Ԃ�
bool Player::Draw(const Deck& deck)
{
	while (CalcScore())
	{
		int select = 0;
		printf("1.hit 2.stand > ");
		cin >> select;
		
		if (select == 1)
		{
			// ��D�Ɉ������J�[�h�̏�����������
			_hand[_index].suit = deck.GetDeck().suit;
			_hand[_index].num = deck.GetDeck().num;

			//��D�̃C���f�b�N�X�X�V
			++_index;

			// �f�b�L����P����������C���f�b�N�X���X�V
			deck.GetIndex();

			// ��D�\��
			Show();
		}
		else if (select == 2)
		{
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
	bool haveAce = false;		// A����D�ɂ��邩�ǂ���

	// ��D�̓_�����J�E���g
	// A�͐�ɂP�_�Ƃ��ăJ�E���g���A��ō��v�l�ɂ���ĂP�O�_���_���邱�ƂŁA�P�P�_�Ƃ���
	for (int i = 0; i <= _index; ++i)
	{
		if (_hand[i].num == 1)
		{
			haveAce = true;
		}

		if (_hand[i].num >= 10)
		{
			_sum += 10;
		}
		else 
		{
			_sum += _hand[i].num;
		}	
	}

	// A������A��D�̍��v�_���P�P�_�ȉ��Ȃ�P�O�_���Z
	if (haveAce && _sum <= 11)
	{
		_sum += 10;
	}

	// �o�[�X�g���Ă�����false��Ԃ�
	if (_sum > VINGT_ET_UN)
	{
		return false;
	}

	return true;
}