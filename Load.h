#pragma once
#include "Engine/GameObject.h"
class Load :
    public GameObject
{
	int hModel_;
public:
	Load(GameObject* parent);
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

