#pragma once
#include"Deck.h"

class Player {
public:
	Player();							// コンストラクタ
	void Show()const;					// 手札表示
	bool Draw(const Deck& deck);		// standするかバーストするまで繰り返す 
	bool CalcScore();					// 手札の点数を計算（バーストしたらfalse）

private:
	Card _hand[HAND_SIZE];	// 手札の配列
	int _index;					// 手札配列の要素番号（何番目まで使っているか）
	int _sum;					// 手札の合計値
};