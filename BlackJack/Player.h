#pragma once
#include"Deck.h"

class Player {
public:
	Player();							// コンストラクタ
	void Show()const;					// 手札表示
	bool Play(Deck& deck);				// standするかバーストするまで繰り返す 
	bool CalcScore();					// 手札の点数を計算（バーストしたらfalse）
	void Draw(Deck& deck);				// カードを一枚引き手札に加える

private:
	Card _hand[HAND_SIZE];		// 手札の配列
	int _handIndex;				// 手札配列の要素番号（何枚ひいているか）
};