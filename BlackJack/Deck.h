#pragma once
#include"Card.h"

// 山札を管理するクラス
class Deck {
public:
	Deck();						// コンストラクタ	
	Card GetDeckCard();			// 山札から一枚引き、indexを更新
	int GetIndex()const			// 山札の何枚目まで引いたかを返す
	{
		return _deckIndex;
	}

private:
	void Shuffle();				// 山札をシャッフルする関数
	Card _deck[MAX_CARD_NUM];	// 山札
	int _deckIndex;				// どこまで山札を引いたか
};