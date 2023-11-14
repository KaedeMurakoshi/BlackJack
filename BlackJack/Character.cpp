#include <iostream>
#include"Character.h"

// BlackJack.cppのグローバル変数を使う
extern const char* suitName[];

// コンストラクタ
Character::Character()
{
	for (int i = 0; i < HAND_SIZE; ++i)
	{
		_hand[i].num = 0;
		_hand[i].suit = SPADE;
	}
	_handIndex = 0;
}

// 手札を表示（ディーラーは一枚目だけ開示）
void Character::ShowAllHands(bool showAll)const
{
	printf("===================\n");

	// 手札が０枚の時
	if (_handIndex <= 0)
	{
		printf("[エラー]手札がありません\n");
		return;
	}

	// showAllがtrueの時は手札をすべて表示
	if (showAll)
	{
		// 手札をすべて表示
		for (int i = 0; i < _handIndex; ++i)
		{
			printf("[%sの%d]\n", suitName[_hand[i].suit], _hand[i].num);
		}
	}
	// showAllがfalseの時は一枚だけ表示
	else
	{
		// 一枚だけ表示
		printf("[%sの%d]\n", suitName[_hand[0].suit], _hand[0].num);

		for (int i = 1; i < _handIndex; ++i)
		{
			printf("[？の？]\n");
		}
	}

	printf("===================\n");
}

// バーストしたら０を返す
int Character::CalcScore()
{
	int score = 0;				// 合計点数
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
			score += 10;
		}
		// それ以外はそのままの点数
		else
		{
			score += _hand[i].num;
		}
	}

	// Aがあり、手札の合計点が１１点以下なら１０点加算
	if (haveAce && score <= 11)
	{
		score += 10;
	}

	//バーストである場合は0を返す
	if (score > 21) {
		//スコアに0を代入
		score = 0;
	}

	return score;
}

// カードを引く部分が冗長なので関数化
// カードを一枚引き手札に加える、引いたカードを表示
void Character::Draw(Deck& deck)
{
	// 山札から一枚引いて保存
	Card nextCard = deck.GetDeckCard();

	// 手札に引いたカードの情報を書き込む
	_hand[_handIndex].suit = nextCard.suit;
	_hand[_handIndex].num = nextCard.num;

	//手札のインデックス更新
	++_handIndex;
}