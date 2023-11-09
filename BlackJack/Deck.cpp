#include <iostream>
#include <utility> // swap�֐�
#include <cstdlib>
#include"Deck.h"
using namespace std;

//#define DEBUG

// �R���X�g���N�^
Deck::Deck()
{
	_deckIndex = -1;

	// �R�D�̏�����
	for (int i = 0; i < CARD_RANGE; ++i)
	{
		// �O�`�P�Q�Ԗ�
		_deck[i].suit = SPADE;
		_deck[i].num = i + 1;

		// �P�R�`�Q�T�Ԗ�
		_deck[i + CARD_RANGE].suit = HEART;
		_deck[i + CARD_RANGE].num = i + 1;

		// �Q�U�`�R�W�Ԗ�
		_deck[i + CARD_RANGE * 2].suit = DIAMOND;
		_deck[i + CARD_RANGE * 2].num = i + 1;

		// �R�X�`�T�P�Ԗ�
		_deck[i + CARD_RANGE * 3].suit = CLUB;
		_deck[i + CARD_RANGE * 3].num = i + 1;
	}
}

// �R�D�V���b�t��(FIsher Yates)
void Deck::Shuffle()
{
	for (int i = MAX_CARD_NUM - 1; i >= 1; --i)
	{
		int randNum = rand() % i;
		swap(_deck[i], _deck[randNum]);
	}

#ifdef DEBUG
	// �V���b�t����\��
	printf("[�f�o�b�O]�R�D�\��\n");
	for (int k = 0; k < MAX_CARD_NUM; ++k)
	{
		printf("%d��%d\n", _deck[k].suit, _deck[k].num);
	}
#endif // DEBUG
}

// �R�D�̈�ԏ�̃J�[�h��Ԃ�
Card Deck::GetDeckCard()
{
	// �f�b�L�̃C���f�b�N�X�X�V
	++_deckIndex;

	// �C���f�b�N�X�������ȏꍇ
	if (_deckIndex < 0 || _deckIndex > MAX_CARD_NUM - 1)
	{
		printf("�C���f�b�N�X�������ł�\n");

		// _deckIndex��L���Ȓl�ɕύX
		_deckIndex = 0;
	}

	return _deck[_deckIndex];	
}
