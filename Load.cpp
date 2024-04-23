#include "Load.h"
#include"Engine/Model.h"

Load::Load(GameObject* parent)
	:GameObject(parent,"Load"),hModel_(-1)
{
}

void Load::Initialize()
{
	hModel_ = Model::Load("Model\\Floor.fbx");
	assert(hModel_ >= 0);
}

void Load::Update()
{
}

void Load::Draw()
{
	Transform floorTrans;
	floorTrans.position_ = { 0,0,0 };
	for (int z = 0; z < 30; z++)
	{
		for (int x = 0; x < 3; x++)
		{
			floorTrans.position_ = { (float)x,0,(float)z };
			Model::SetTransform(hModel_, floorTrans);
			Model::Draw(hModel_);
		}
	}
}

void Load::Release()
{
}
