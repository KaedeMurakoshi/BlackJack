#pragma once

const int MAX_CARD_NUM = 52;
const int CARD_RANGE = 13;

// 絵柄
enum Suit {
	SPADE,		// スペード
	HEART,		// ハート
	DIAMOND,	//ダイヤモンド
	CLUB		// クラブ
};

// カードが持つ情報
struct Card {
	Suit suit;	// 絵柄
	int num;	// 数字
};

// 山札を管理するクラス
class Deck {
public:
	Deck();						// コンストラクタ
	void Shuffle();				// 山札をシャッフルする関数

private:
	Card card[MAX_CARD_NUM];	// 山札	
};