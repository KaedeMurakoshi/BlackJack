#pragma once
#include"Card.h"

// 山札を管理するクラス
class Deck {
public:
	Deck();						// コンストラクタ
	void Shuffle();				// 山札をシャッフルする関数
	Card GetDeckCard();			// 山札から一枚引き、indexを更新
	int GetIndex()const			// 山札の何枚目まで引いたかを返す
	{
		return _deckIndex;
	}

private:
	Card _deck[MAX_CARD_NUM];	// 山札
	int _deckIndex;				// どこまで山札を引いたか
};