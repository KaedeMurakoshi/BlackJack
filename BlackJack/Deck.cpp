#include"Deck.h"

// ƒRƒ“ƒXƒgƒ‰ƒNƒ^
Deck::Deck()
{
	// RD‚Ì‰Šú‰»
	for (int i = 0; i < CARD_RANGE; ++i)
	{
		// ‚O`‚P‚Q”Ô–Ú
		card[i].suit = SPADE;
		card[i].num = i + 1;

		// ‚P‚R`‚Q‚T”Ô–Ú
		card[i + CARD_RANGE].suit = HEART;
		card[i + CARD_RANGE].num = i + 1;

		// ‚Q‚U`‚R‚W”Ô–Ú
		card[i + CARD_RANGE * 2].suit = DIAMOND;
		card[i + CARD_RANGE * 2].num = i + 1;

		// ‚R‚X`‚T‚P”Ô–Ú
		card[i + CARD_RANGE * 3].suit = CLUB;
		card[i + CARD_RANGE * 3].num = i + 1;
	}
}