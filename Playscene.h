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
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};

