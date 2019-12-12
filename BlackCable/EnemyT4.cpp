#include "EnemyT4.h"

EnemyT4::EnemyT4(glm::vec3 position, Player *player)
{
	this->player = player;
	this->platform = Platform::GetPtr();
	transform.SetTranslation(position.x, position.y - 10, position.z);
}

void EnemyT4::Update()
{
	spCollider->SetTranslation(transform.GetTranslation());
	x = abs(transform.GetTranslation().x) - abs(player->GetPosition().x);
	z = abs(transform.GetTranslation().z) - abs(player->GetPosition().z);
	if (x > -4 && x < 4 && z > -4 && z < 4) {
		exit(0);
	}

	if (x > -15 && x < 15 && z > -15 && z < 15 && GetKeyState('L') & 0x8000)
	{
		transform.SetTranslation(50, 50, 50);
	}
}

void EnemyT4::Init()
{
	weapon = new Model();
	weapon->LoadModel("Assets/Models/Enemy1.obj");
	weapon->AddTexture("Weapon_UV.png");
	spCollider = new SphereCollider(10, transform.GetTranslation());
}

void EnemyT4::Draw()
{
	transform.SetScale(0.45f, 0.45f, 0.45f);
	transform.SetRotation(0, 55, 0);

	float x = player->GetPosition().x;
	float y = player->GetPosition().y;
	float z = player->GetPosition().z;

	if (x > transform.GetTranslation().x) {
		x = transform.GetTranslation().x + 0.04f;
	}
	else if (x < transform.GetTranslation().x) {
		x = transform.GetTranslation().x - 0.04f;
	}
	else {
		x = transform.GetTranslation().x;
	}

	if (z > transform.GetTranslation().z) {
		z = transform.GetTranslation().z + 0.04f;
	}
	else if (z < transform.GetTranslation().z) {
		z = transform.GetTranslation().z - 0.04f;
	}
	else {
		z = transform.GetTranslation().z;
	}
	transform.SetTranslation(x, transform.GetTranslation().y, z);
	weapon->SetTransform(&transform);
	weapon->Draw();
}
void EnemyT4::Shoot()
{

}