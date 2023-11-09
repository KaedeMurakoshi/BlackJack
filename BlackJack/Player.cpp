#include <iostream>
#include"Player.h"
using namespace std;

// BlackJack.cppのグローバル変数を使う
extern const char* suitName[];

// コンストラクタ
Player::Player()
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		_hand[i].num = 0;
		_hand[i].suit = SPADE;
	}
	_handIndex = 0;
}

void Player::Show()const
{
	printf("===================\n");

	// 手札が０枚の時
	if (_handIndex <= 0)
	{
		printf("手札がありません\n");
		return;
	}

	printf("(あなたの手札)\n");

	// 手札をすべて表示
	for (int i = 0; i < _handIndex; ++i)
	{
		printf("[%sの%d]\n", suitName[_hand[i].suit], _hand[i].num);
	}

	printf("===================\n");
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
		printf("\n");

		// hit
		if (select == 1)
		{
			Draw(deck);

			// 手札表示
			Show();
		}
		// standを選択
		else if (select == 2)
		{
			printf("～スタンドします～\n");
			return true;
		}
		else
		{
			printf("１～２を入力してください\n");
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
	for (int i = 0; i < _handIndex; ++i)
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
	printf("\nあなたの合計点数：%d\n\n", sum);

	// バーストしていなければtrueを返す
	return true;
}

// カードを引く部分が冗長なので関数化
// カードを一枚引き手札に加える、引いたカードを表示
void Player::Draw(Deck& deck)
{
	// 山札から一枚引いて保存
	Card nextCard = deck.GetDeckCard();

	// 手札に引いたカードの情報を書き込む
	_hand[_handIndex].suit = nextCard.suit;
	_hand[_handIndex].num = nextCard.num;

	//手札のインデックス更新
	++_handIndex;

	// 引いたカードを表示
	printf("引いたカード：%dの%d\n", nextCard.suit, nextCard.num);
}

