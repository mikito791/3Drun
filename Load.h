#pragma once
#include "Engine/GameObject.h"
class Load :
    public GameObject
{
	int hModel_;
public:
	Load(GameObject* parent);
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

