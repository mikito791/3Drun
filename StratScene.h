#pragma once
#include "Engine/GameObject.h"
class StratScene :
    public GameObject
{
	int hPict;
public:

	StratScene(GameObject* parent);
	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

};

