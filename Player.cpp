#include "Player.h"
#include<assert.h>
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/SphereCollider.h"
#include"Engine/SceneManager.h"
#include"Engine/Camera.h"
enum CAM_TYPE//�J�����؂�ւ�
{
	FIXED_TYPE,//�Œ�
	TPS_NOROT_TYPE,
	//TPS_TYPE,//3�l��
	//FPS_TYPE,
	MAX_TYPE,//�ԕ�����i�`�F�b�N�p�̒l�j
};
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
	if (Input::IsKey(DIK_LEFT))//���ړ�
	{
		transform_.position_.x -= 0.1f;
		if (transform_.position_.x < -0.5f)
		{
			transform_.position_.x = -0.5f;
		}
	}
	if (Input::IsKey(DIK_RIGHT))//�E�ړ�
	{
		transform_.position_.x += 0.1f;
		if (transform_.position_.x > 1.5f)
		{
			transform_.position_.x = 1.5f;
		}
	}
	if (Input::IsKey(DIK_UP))//�O�ړ�
	{
		transform_.position_.z += 0.1f;
		if (transform_.position_.z > 1.5f)
		{
			transform_.position_.z = 1.5f;
		}
	}
	if (Input::IsKey(DIK_DOWN))//���ړ�
	{
		transform_.position_.z -= 0.1f;
		if (transform_.position_.z < 0.5)
		{
			transform_.position_.z = 0.5;
		}
	}
	if (Input::IsKeyDown(DIK_Z))
	{
		camState++;
		if (camState == CAM_TYPE::MAX_TYPE)
			camState = CAM_TYPE::FIXED_TYPE;
	}
	switch (camState)
	{
	case CAM_TYPE::FIXED_TYPE:
	{
		Camera::SetPosition(XMFLOAT3(0.5, 10, -5));
		Camera::SetTarget(XMFLOAT3(0.5, 0, 5));
		break;
	}
	case CAM_TYPE::TPS_NOROT_TYPE:
	{
		XMFLOAT3 camPos = transform_.position_;
		camPos.y = transform_.position_.y + 5.0f;
		camPos.z = transform_.position_.z - 10.0f;
		Camera::SetPosition(camPos);
		Camera::SetTarget(transform_.position_);
		break;
	}
	default:
		break;
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
		pTarget->KillMe();
		SceneManager* pSM = (SceneManager*)(FindObject("SceneManager"));
		pSM->ChangeScene(SCENE_ID::SCENE_ID_GAMEOVER);
	}
}
