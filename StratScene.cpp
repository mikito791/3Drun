#include "StratScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"Engine/SceneManager.h"
StratScene::StratScene(GameObject* parent)
	:GameObject(parent, "SceneManager"), hPict(-1)
{
}

void StratScene::Initialize()
{

}

void StratScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_PLAY);
	}
}

void StratScene::Draw()
{
}

void StratScene::Release()
{
}
