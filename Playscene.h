#pragma once
#include "Engine/GameObject.h"
class Playscene :
    public GameObject
{
	int random = rand() % 3;
	int enemyNum;
	int counter;
	int Random;
	int lastLane = -1;
	int enemyCount;
	//random = 2.0 * random;
public:
	
	Playscene(GameObject* parent);
	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

};

