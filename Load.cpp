#include "Load.h"
#include"Engine/Model.h"
#include"Engine/Camera.h"

Load::Load(GameObject* parent)
	:GameObject(parent,"Load"),hModel_(-1)
{
}

void Load::Initialize()
{
	hModel_ = Model::Load("Model\\Floor.fbx");
	assert(hModel_ >= 0);
	Camera::SetPosition(XMFLOAT3(0.5, 10, -5));
	Camera::SetTarget(XMFLOAT3(0.5, 0, 5));
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
