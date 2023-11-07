#include <iostream>
#include <utility> // swapŠÖ”
#include <cstdlib>
#include"Deck.h"
using namespace std;

#define DEBUG

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
Deck::Deck()
{
	deckIndex = 0;

	// RD‚Ì‰Šú‰»
	for (int i = 0; i < CARD_RANGE; ++i)
	{
		// ‚O`‚P‚Q”Ô–Ú
		_deck[i].suit = SPADE;
		_deck[i].num = i + 1;

		// ‚P‚R`‚Q‚T”Ô–Ú
		_deck[i + CARD_RANGE].suit = HEART;
		_deck[i + CARD_RANGE].num = i + 1;

		// ‚Q‚U`‚R‚W”Ô–Ú
		_deck[i + CARD_RANGE * 2].suit = DIAMOND;
		_deck[i + CARD_RANGE * 2].num = i + 1;

		// ‚R‚X`‚T‚P”Ô–Ú
		_deck[i + CARD_RANGE * 3].suit = CLUB;
		_deck[i + CARD_RANGE * 3].num = i + 1;
	}
}

// RDƒVƒƒƒbƒtƒ‹(FIsher Yates)
void Deck::Shuffle()
{
	for (int i = MAX_CARD_NUM - 1; i >= 1; --i)
	{
		int randNum = rand() % i;
		swap(_deck[i], _deck[randNum]);
	}

#ifdef DEBUG
	// ƒVƒƒƒbƒtƒ‹Œã•\¦
	printf("RD«\n");
	for (int k = 0; k < MAX_CARD_NUM; ++k)
	{
		printf("%d‚Ì%d\n", _deck[k].suit, _deck[k].num);
	}
#endif // DEBUG
}
