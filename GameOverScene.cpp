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
	hPict = Image::Load("Model\\GameOver.png");
	assert(hPict >= 0);
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
	Image::SetTransform(hPict, transform_);
	Image::Draw(hPict);
}

void GameOverScene::Release()
{
}
