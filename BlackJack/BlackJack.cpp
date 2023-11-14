// BlackJack.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include"Player.h"
#include"Dealer.h"

using namespace std;

// 表示用
const char* suitName[] = { "スペード", "ハート", "ダイヤ", "クラブ" };

// リザルト
static void ShowResult(Player& player, Dealer& dealer)
{
    printf("\n～Result～\n\n");
    // 手札をすべて表示
    printf("[あなたの手札]\n");
    player.ShowAllHands(true);
    printf("\n[ディーラーの手札]\n");
    dealer.ShowAllHands(true);

    // スコアが同じのとき
    if (player.CalcScore() == dealer.CalcScore())
    {
        printf("引き分けです");
    }
    else
    {
        cout << "勝者は " << ((player.CalcScore() > dealer.CalcScore()) ? "あなた" : "ディーラー") << " です。" << endl;
    }
}

int main()
{
    // 乱数準備
    time_t t;
    srand(time(&t) % RAND_MAX);

    // クラスの実体を宣言
    Deck deck;
    Player player;
    Dealer dealer;

    // 最初に二枚引く
    player.Draw(deck);
    player.Draw(deck);

    dealer.Draw(deck);
    dealer.Draw(deck);

    // プレーヤーの手札表示
    printf("[あなたの手札]\n");
    player.ShowAllHands(true);

    // ディーラーの手札を一枚目だけ表示
    printf("\n\n[ディーラーの手札]\n");
    dealer.ShowAllHands(false);

    // standするかバーストするまで繰り返す
    if (!player.Play(deck))
    {
        // バーストしたら終了
        printf("バーストしました、あなたの負けです\n");
        return 0;
    }

    // ディーラーの自動処理
    if (!dealer.Play(deck))
    {
        // バーストしたら
        printf("バーストしました、あなたの勝ちです\n");
    }

    // リザルト
    ShowResult(player, dealer);
}

// プログラムの実行: Ctrl + F5 または [デバッグ] > [デバッグなしで開始] メニュー
// プログラムのデバッグ: F5 または [デバッグ] > [デバッグの開始] メニュー

// 作業を開始するためのヒント: 
//    1. ソリューション エクスプローラー ウィンドウを使用してファイルを追加/管理します 
//   2. チーム エクスプローラー ウィンドウを使用してソース管理に接続します
//   3. 出力ウィンドウを使用して、ビルド出力とその他のメッセージを表示します
//   4. エラー一覧ウィンドウを使用してエラーを表示します
//   5. [プロジェクト] > [新しい項目の追加] と移動して新しいコード ファイルを作成するか、[プロジェクト] > [既存の項目の追加] と移動して既存のコード ファイルをプロジェクトに追加します
//   6. 後ほどこのプロジェクトを再び開く場合、[ファイル] > [開く] > [プロジェクト] と移動して .sln ファイルを選択します
