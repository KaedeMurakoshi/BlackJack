#pragma once
#include"Deck.h"

class Dealer {
public:
	Dealer();								// コンストラクタ
	void ShowAllHands(bool showAll)const;	// 手札表示
	bool Play(Deck& deck);					// １７点以下かつバーストするまでhit 
	bool CalcScore();						// 手札の点数を計算（バーストしたらfalseを返す）
	void Draw(Deck& deck);				// カードを一枚引き手札に加える

private:
	Card _hand[HAND_SIZE];			// 手札の配列
	int _handIndex;					// 手札配列の要素番号（何枚引いているか）
};