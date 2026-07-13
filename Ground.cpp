#include "Ground.h"
#include "Engine/Model.h"


namespace
{
	using std::vector;
	int model_t = -1;
	vector< vector<int>> mapData =
	{
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, // 0行目 (外壁)
	{1, 0, 0, 0, 1, 0, 0, 0, 0, 1}, // 1行目 (左上がスタート)
	{1, 0, 1, 0, 1, 0, 1, 1, 0, 1}, // 2行目
	{1, 0, 1, 0, 0, 0, 1, 0, 0, 1}, // 3行目
	{1, 1, 1, 1, 1, 0, 1, 0, 1, 1}, // 4行目
	{1, 0, 0, 0, 1, 0, 0, 0, 1, 1}, // 5行目
	{1, 0, 1, 0, 1, 1, 1, 0, 0, 1}, // 6行目
	{1, 0, 1, 0, 0, 0, 1, 1, 0, 1}, // 7行目
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 1}, // 8行目 (右下がゴール)
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  // 9行目 (外壁)
	};
}



Ground::Ground(GameObject* parent)
	:GameObject(parent,"Ground"), hModel_(-1)
{
	mapData_ = mapData;//ファイルグローバルのmapdataをコピーしてメンバ関数mapdata
}

void Ground::Initialize()
{
	hModel_ = Model::Load("jimen3.fbx");
	hModel_t = Model::Load("block.fbx");

	Model::SetAnimFrame(hModel_, 0, 59, 1.0);
	Model::SetAnimFrame(hModel_t, 0, 59, 1.0);
}

void Ground::Update()
{
}

void Ground::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);

	for (int j = 0;j < 10;j++)
	{
		for (int i = 0; i < 10;i++)
		{
			if (mapData_[j][i] == 1) {
				Transform tr;
				tr.position_ = {-9.0f + i * 2.0f, 0.0f, 9.0f - j * 2.0f};
				Model::SetTransform(hModel_t, tr);
				Model::Draw(hModel_t);
			}
			
		}

	}
}

void Ground::Release()
{
}
