#include"Player.h"

void Player::Show()const
{

}

// �o�[�X�g���邩stand����܂Ńh���[���J��Ԃ�
void Player::Draw(Deck& deck)
{
	while (CalcScore())
	{
		_hand[_index].suit = deck.GetDeck().suit;
		_hand[_index].num = deck.GetDeck().num;
		++_index;
	}
}

// �o�[�X�g������false��Ԃ�
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