#include"Player.h"

void Player::Show()const
{

}

// バーストするかstandするまでドローを繰り返す
void Player::Draw(Deck& deck)
{
	while (CalcScore())
	{
		_hand[_index].suit = deck.GetDeck().suit;
		_hand[_index].num = deck.GetDeck().num;
		++_index;
	}
}

// バーストしたらfalseを返す
bool Player::CalcScore()
{
	for (int i = 0; i <= _index; ++i)
	{
		_sum += _hand[i].num;
	}

	if (_sum > VINGT_ET_UN)
	{
		return false;
	}

	return true;
}