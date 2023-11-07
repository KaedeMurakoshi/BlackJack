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
	_sum = 0;
}

void Player::Show()const
{
	const char* suit[] = {"スペード", "ハート", "ダイヤモンド", "クラブ"};

	printf("(あなたの手札)\n");

	for (int i = 0; i <= _index; ++i)
	{
		printf("%sの%d\n", suit[_hand[i].suit], _hand[i].num);
	}
}

// バーストするかstandするまでドローを繰り返す
bool Player::Draw(const Deck& deck)
{
	while (CalcScore())
	{
		int select = 0;
		printf("1.hit 2.stand > ");
		cin >> select;
		
		if (select == 1)
		{
			// 手札に引いたカードの情報を書き込む
			_hand[_index].suit = deck.GetDeck().suit;
			_hand[_index].num = deck.GetDeck().num;

			//手札のインデックス更新
			++_index;

			// デッキから１枚引いたらインデックスを更新
			deck.GetIndex();

			// 手札表示
			Show();
		}
		else if (select == 2)
		{
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
	bool haveAce = false;		// Aが手札にあるかどうか

	// 手札の点数をカウント
	// Aは先に１点としてカウントし、後で合計値によって１０点加点することで、１１点とする
	for (int i = 0; i <= _index; ++i)
	{
		if (_hand[i].num == 1)
		{
			haveAce = true;
		}

		if (_hand[i].num >= 10)
		{
			_sum += 10;
		}
		else 
		{
			_sum += _hand[i].num;
		}	
	}

	// Aがあり、手札の合計点が１１点以下なら１０点加算
	if (haveAce && _sum <= 11)
	{
		_sum += 10;
	}

	// バーストしていたらfalseを返す
	if (_sum > VINGT_ET_UN)
	{
		return false;
	}

	return true;
}