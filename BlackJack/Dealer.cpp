#include <iostream>
#include"Dealer.h"
using namespace std;

// BlackJack.cppのグローバル変数を使う

bool Dealer::Play(Deck& deck)
{
	// スコアが１７以上になるまでhit
	while (CalcScore() < 17 && CalcScore() > 0)
	{
		printf("ディーラー：「 hitします。」\n");
		Draw(deck);
	}
	if (CalcScore() <= 0) return false;
	return true;
}