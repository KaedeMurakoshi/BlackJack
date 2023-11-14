#include <iostream>
#include"Player.h"
using namespace std;

// BlackJack.cppのグローバル変数を使う

// バーストするかstandするまでドローを繰り返す
bool Player::Play(Deck& deck)
{
	// バーストしたら終了
	while (CalcScore())
	{
		int select = 0;	// 入力用

		// プレーヤーのスコアを表示
		printf("\nあなたのスコア：%d\n\n", CalcScore());

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
		// standを選択したらtrueを返す
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
	// バーストしたらfalseを返す
	return false;
}

