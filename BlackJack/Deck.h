#pragma once

const int MAX_CARD_NUM = 52;
const int CARD_RANGE = 13;

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

// �R�D���Ǘ�����N���X
class Deck {
public:
	Deck();						// �R���X�g���N�^
	void Shuffle();				// �R�D���V���b�t������֐�

private:
	Card card[MAX_CARD_NUM];	// �R�D	
};