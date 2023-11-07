#pragma once
#include"Card.h"

// 山札を管理するクラス
class Deck {
public:
	Deck();						// コンストラクタ
	void Shuffle();				// 山札をシャッフルする関数
	Card GetDeck()const
	{
		return _deck[deckIndex];
	}
	int GetIndex()const
	{
		return deckIndex;
	}
	void SetIndex()
	{
		++deckIndex;
	}

private:
	Card _deck[MAX_CARD_NUM];	// 山札
	int deckIndex;
};