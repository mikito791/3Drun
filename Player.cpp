#include "Player.h"
#include<assert.h>
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/SphereCollider.h"
#include"Engine/SceneManager.h"

Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\box.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.y = 0.5;
	transform_.position_.z = 0.5;
	SphereCollider* PlayerCollider = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5);
	AddCollider(PlayerCollider);
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT))//ç∂à⁄ìÆ
	{
		transform_.position_.x -= 0.1f;
		if (transform_.position_.x < -0.5f)
		{
			transform_.position_.x = -0.5f;
		}
	}
	if (Input::IsKey(DIK_RIGHT))//âEà⁄ìÆ
	{
		transform_.position_.x += 0.1f;
		if (transform_.position_.x > 1.5f)
		{
			transform_.position_.x = 1.5f;
		}
	}
	if (Input::IsKey(DIK_UP))//ëOà⁄ìÆ
	{
		transform_.position_.z += 0.1f;
		if (transform_.position_.z > 1.5f)
		{
			transform_.position_.z = 1.5f;
		}
	}
	if (Input::IsKey(DIK_DOWN))//å„ÇÎà⁄ìÆ
	{
		transform_.position_.z -= 0.1f;
		if (transform_.position_.z < 0.5)
		{
			transform_.position_.z = 0.5;
		}
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Enemy")
	{
		this->KillMe();
		pTarget->KillMe();
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_GAMEOVER);
	}
}
