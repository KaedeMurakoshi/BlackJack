#include <iostream>
#include"Player.h"
using namespace std;

// BlackJack.cppのグローバル変数を使う
extern const char* suitName[];

// バーストするかstandするまでドローを繰り返す
bool Player::Play(Deck& deck)
{
	while (CalcScore())
	{
		int select = 0;	// 入力用

		// 選択肢表示
		printf("1.hit 2.stand > ");
		cin >> select;
		printf("\n");

		// hit
		if (select == 1)
		{
			Draw(deck);

			// 手札表示
			ShowAllHands(true);
		}
		// standを選択
		else if (select == 2)
		{
			printf("スタンド\n");
			return true;
		}
		else
		{
			printf("１～２を入力してください\n");
		}
	}
	return false;
}

