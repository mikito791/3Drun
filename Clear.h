#pragma once
#include "Engine/GameObject.h"
class Clear :
    public GameObject
{
	int hPict;
public:

	Clear(GameObject* parent);
	~Clear();
	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

