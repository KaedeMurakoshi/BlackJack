#pragma once
#include"Deck.h"

class Player {
public:
	void Show()const;					// 手札表示
	void Draw(Deck& deck);		// standするかバーストするまで繰り返す 
	bool CalcScore();					// 手札の点数を計算（バーストしたらfalse）

private:
	Card _hand[MAX_HAND_NUM];	// 手札の配列
	int _index;					// 手札配列の要素番号（何番目まで使っているか）
	int _sum;					// 手札の合計値
};