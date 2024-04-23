#pragma once
#include "Engine/GameObject.h"
class Clear :
    public GameObject
{
	int hPict;
public:

	Clear(GameObject* parent);
	~Clear();
	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;
};

