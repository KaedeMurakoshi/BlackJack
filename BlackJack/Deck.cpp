#include"Deck.h"

// �R���X�g���N�^
Deck::Deck()
{
	// �R�D�̏�����
	for (int i = 0; i < CARD_RANGE; ++i)
	{
		// �O�`�P�Q�Ԗ�
		card[i].suit = SPADE;
		card[i].num = i + 1;

		// �P�R�`�Q�T�Ԗ�
		card[i + CARD_RANGE].suit = HEART;
		card[i + CARD_RANGE].num = i + 1;

		// �Q�U�`�R�W�Ԗ�
		card[i + CARD_RANGE * 2].suit = DIAMOND;
		card[i + CARD_RANGE * 2].num = i + 1;

		// �R�X�`�T�P�Ԗ�
		card[i + CARD_RANGE * 3].suit = CLUB;
		card[i + CARD_RANGE * 3].num = i + 1;
	}
}