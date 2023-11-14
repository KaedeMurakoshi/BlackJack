#pragma once
#include"Deck.h"

class Character {
public:
	void ShowAllHands(bool showAll)const;	// 手札表示
	void Draw(Deck& deck);
	int CalcScore();

protected:
	Card _hand[HAND_SIZE];			// 手札の配列
	int _handIndex;					// 手札配列の要素番号（何枚引いているか）
};