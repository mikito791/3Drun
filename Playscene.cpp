#include "Playscene.h"
#include"Player.h"
#include"Enemy.h"
#include"Load.h"
#include"Engine/SceneManager.h"
namespace
{
	const int ENEMY_NUM{ 2 };
	const float space{ 0.5 };
}
Playscene::Playscene(GameObject* parent)
	:GameObject(parent, "SceneManager")
{
}

void Playscene::Initialize()
{
	
	Instantiate<Load>(this);
	Instantiate<Player>(this);
	enemyNum = ENEMY_NUM;
	switch (random)
	{
	case 0:
		for (int i = 0; i < enemyNum; i++)
		{
			Enemy* e = Instantiate<Enemy>(this);
			e->SetPosition(i + space, 0, 20);
		}
		break;
	case 1:
		for (int i = 0; i < enemyNum; i++)
		{
			Enemy* e = Instantiate<Enemy>(this);
			e->SetPosition(i - space, 0, 20);
		}
	
		break;
	case 2:
		Enemy* e = Instantiate<Enemy>(this);
		e->SetPosition(-0.5, 0, 20);

		Enemy* e2 = Instantiate<Enemy>(this);
		e2->SetPosition(1.5, 0, 20);

		break;
	}
}

void Playscene::Update()
{
	counter -= 1;
	if (counter <= 0)
	{
		counter = 100;
		Random = (lastLane + rand() % 2 + 1) % 3;
		lastLane = Random;
		Enemy* e = nullptr;
		switch (lastLane)
		{
		case 0:
			for (int i = 0; i < enemyNum; i++)
			{
				Enemy* e = Instantiate<Enemy>(this);
				e->SetPosition(i + space, 0, 20);
			}
			break;
		case 1:
			for (int i = 0; i < enemyNum; i++)
			{
				Enemy* e = Instantiate<Enemy>(this);
				e->SetPosition(i - space, 0, 20);
			}

			break;
		case 2:
			Enemy * e = Instantiate<Enemy>(this);
			e->SetPosition(-0.5, 0, 20);

			Enemy* e2 = Instantiate<Enemy>(this);
			e2->SetPosition(1.5, 0, 20);

			break;
		}
	}
}
void Playscene::Draw()
{
}

void Playscene::Release()
{
}
