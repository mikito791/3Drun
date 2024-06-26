#pragma once
#include "Engine/GameObject.h"
class Gauge;
class Player :
    public GameObject
{
    int hModel_;
	int camState;

	Gauge* pGauge_;
	int hpCrr_;
	int hpMax_;
public:
	Player(GameObject* parent);
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
	void OnCollision(GameObject* pTarget) override;
};

