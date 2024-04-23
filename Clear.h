#pragma once
#include "Engine/GameObject.h"
class Clear :
    public GameObject
{
	int hPict;
public:

	Clear(GameObject* parent);
	~Clear();
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

