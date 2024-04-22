#include "GameOverScene.h"
#include"Engine/Image.h"
#include"Engine/Input.h"
#include"StratScene.h"
#include"Engine/SceneManager.h"

GameOverScene::GameOverScene(GameObject* parent)
	:GameObject(parent, "SceneManager"), hPict(-1)
{
}

void GameOverScene::Initialize()
{
}

void GameOverScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_STRAT);
	}
}

void GameOverScene::Draw()
{
}

void GameOverScene::Release()
{
}
