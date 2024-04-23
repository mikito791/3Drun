#include "Enemy.h"
#include"Engine/Model.h"
#include"Engine/SphereCollider.h"
#include"Engine/SceneManager.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.x = 0.5;
	transform_.position_.z = 20;
	transform_.rotate_.y = -180;//Œü‚«
	SphereCollider* EnemyCollider = new SphereCollider(XMFLOAT3(0, 0, 0), 0.5);
	AddCollider(EnemyCollider);
}

void Enemy::Update()
{
	transform_.position_.z -= 0.1;
	if (transform_.position_.z < -2)
	{
		this->KillMe();		

	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
