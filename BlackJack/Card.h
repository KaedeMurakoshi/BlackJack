#pragma once

// �J�[�h�̏����܂Ƃ߂��N���X

const int MAX_CARD_NUM = 52;	// �R�D�̖���
const int CARD_RANGE = 13;		// �J�[�h�̐����͈̔́iA�`K�j
const int MAX_HAND_NUM = 10;	// ��D�̍ő喇��
const int VINGT_ET_UN = 21;		// ���@���e�A���i�o�[�X�g���郉�C���j

// �G��
enum Suit {
	SPADE,		// �X�y�[�h
	HEART,		// �n�[�g
	DIAMOND,	//�_�C�������h
	CLUB		// �N���u
};

// �J�[�h�������
struct Card {
	Suit suit;	// �G��
	int num;	// ����
};