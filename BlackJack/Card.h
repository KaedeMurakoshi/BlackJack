#pragma once

// ここにカードの情報をまとめる

const int MAX_CARD_NUM = 52;	// 山札の枚数
const int CARD_RANGE = 13;		// カードの数字の範囲（A～K）
const int HAND_SIZE = 20;		// 手札の最大枚数
const int VINGT_ET_UN = 21;		// ヴァンテアン（バーストするライン）

// 絵柄
enum Suit {
	SPADE,		// スペード
	HEART,		// ハート
	DIAMOND,	//ダイヤモンド
	CLUB		// クラブ
};

// カードが持つ情報
struct Card {
	Suit suit;	// 絵柄
	int num;	// 数字
};