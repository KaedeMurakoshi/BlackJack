#include <iostream>
#include"Player.h"
using namespace std;

// コンストラクタ
Player::Player()
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		_hand[i].num = 0;
		_hand[i].suit = SPADE;
	}
	_index = 0;
}

void Player::Show()const
{
	const char* suit[] = {"スペード", "ハート", "ダイヤモンド", "クラブ"};

	if (_index <= 0)
	{
		printf("手札がありません");
		return;
	}

	printf("(あなたの手札)\n");

	// 手札をすべて表示
	for (int i = 0; i < _index; ++i)
	{
		printf("%sの%d\n", suit[_hand[i].suit], _hand[i].num);
	}
}

// バーストするかstandするまでドローを繰り返す
bool Player::Play(Deck& deck)
{
	while (CalcScore())
	{
		int select = 0;	// 入力用

		// 選択肢表示
		printf("1.hit 2.stand > ");
		cin >> select;
		
		// hit
		if (select == 1)
		{
			//printf("[デバッグ]ドロー前の山札のインデックス>%d\n", deck.GetIndex());
			Card drawCard = deck.GetDeckCard();
			//("[デバッグ]ドロー後の山札のインデックス>%d\n", deck.GetIndex());

			// 手札に引いたカードの情報を書き込む
			_hand[_index].suit = drawCard.suit;
			_hand[_index].num = drawCard.num;

			// 引いたカード
			printf("引いたカード：%dの%d", drawCard.suit, drawCard.num);

			//手札のインデックス更新
			++_index;

			// 手札表示
			Show();
		}
		// stand
		else if (select == 2)
		{
			printf("スタンドします");
			return true;
		}
		else
		{
			printf("１～２を入力してください");
		}
	}

	return false;
}

// バーストしたらfalseを返す
bool Player::CalcScore()
{
	int sum = 0;				// 合計点数
	bool haveAce = false;		// Aが手札にあるかどうか

	// 手札の点数をカウント
	// Aは先に１点としてカウントし、後で合計値によって１０点加点することで、１１点とする
	for (int i = 0; i < _index; ++i)
	{
		// 手札にAがあれば
		if (_hand[i].num == 1)
		{
			haveAce = true;
		}

		// １０以上の数は１０点で計算
		if (_hand[i].num >= 10)
		{
			sum += 10;
		}
		// それ以外はそのままの点数
		else 
		{
			sum += _hand[i].num;
		}	
	}

	// Aがあり、手札の合計点が１１点以下なら１０点加算
	if (haveAce && sum <= 11)
	{
		sum += 10;
	}

	// バーストしていたらfalseを返す
	if (sum > VINGT_ET_UN)
	{
		printf("バーストしちゃったよん\n");
		return false;
	}

	// 合計点数表示
	printf("現在の合計点数：%d\n", sum);

	// バーストしていなければtrueを返す
	return true;
}