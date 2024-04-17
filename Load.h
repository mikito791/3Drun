#pragma once
#include "Engine/GameObject.h"
class Load :
    public GameObject
{
	int hModel_;
public:
	Load(GameObject* parent);
	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};

