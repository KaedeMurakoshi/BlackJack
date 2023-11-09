#include <iostream>
#include <utility> // swap関数
#include <cstdlib>
#include"Deck.h"
using namespace std;

//#define DEBUG

// コンストラクタ
Deck::Deck()
{
	_deckIndex = -1;

	// 山札の初期化
	for (int i = 0; i < CARD_RANGE; ++i)
	{
		// ０～１２番目
		_deck[i].suit = SPADE;
		_deck[i].num = i + 1;

		// １３～２５番目
		_deck[i + CARD_RANGE].suit = HEART;
		_deck[i + CARD_RANGE].num = i + 1;

		// ２６～３８番目
		_deck[i + CARD_RANGE * 2].suit = DIAMOND;
		_deck[i + CARD_RANGE * 2].num = i + 1;

		// ３９～５１番目
		_deck[i + CARD_RANGE * 3].suit = CLUB;
		_deck[i + CARD_RANGE * 3].num = i + 1;
	}
}

// 山札シャッフル(FIsher Yates)
void Deck::Shuffle()
{
	for (int i = MAX_CARD_NUM - 1; i >= 1; --i)
	{
		int randNum = rand() % i;
		swap(_deck[i], _deck[randNum]);
	}

#ifdef DEBUG
	// シャッフル後表示
	printf("[デバッグ]山札表示\n");
	for (int k = 0; k < MAX_CARD_NUM; ++k)
	{
		printf("%dの%d\n", _deck[k].suit, _deck[k].num);
	}
#endif // DEBUG
}

// 山札の一番上のカードを返す
Card Deck::GetDeckCard()
{
	// デッキのインデックス更新
	++_deckIndex;

	// インデックスが無効な場合
	if (_deckIndex < 0 || _deckIndex > MAX_CARD_NUM - 1)
	{
		printf("インデックスが無効です\n");

		// _deckIndexを有効な値に変更
		_deckIndex = 0;
	}

	return _deck[_deckIndex];	
}
