#pragma once
#include "Engine/GameObject.h"
class StratScene :
    public GameObject
{
	int hPict;
public:

	StratScene(GameObject* parent);
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

};

