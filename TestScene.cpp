#include "TestScene.h"
#include "Player.h"
#include "Ground.h"
#include "Engine/Camera.h"
#include "Engine/Text.h"


namespace {
	int myScore = 0;
}

//コンストラクタ
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//初期化
void TestScene::Initialize()
{	
	//pWp = Instantiate<Weapon>(this);
	Player* pPlayer = Instantiate <Player>(this);
	Ground* pGround = Instantiate <Ground>(this);
	pPlayer->SetGround(pGround);

	Camera::SetPosition({ 0,20,-20 });
	Camera::SetTarget({ 0,0,0 });

	pText_ = new Text;//文字の宣言
	pText_->Initialize();//初期化する
}

//更新
void TestScene::Update()
{
}

//餌を数えて　餌数を出す
//スコアを出す


//描画
void TestScene::Draw()
{
	std::string scrText;
	scrText = "SCORE:" + std::to_string(myScore);
	pText_->Draw(20, 20, scrText.c_str());//画面に文字を...""にscrText.c_str

}

//開放
void TestScene::Release()
{
	pText_->Release();//解放
}

void TestScene::AddScore(int score_)
{
	myScore += score_;
}
