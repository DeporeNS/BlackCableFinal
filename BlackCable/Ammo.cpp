#include "Ammo.h"

Ammo::Ammo(glm::vec3 position, Player* player)
{
	this->player = player;
	this->platform = Platform::GetPtr();
	transform.SetTranslation(position.x, position.y - 10, position.z);
}

void Ammo::Update()
{
	spCollider->SetTranslation(transform.GetTranslation());
	x = abs(transform.GetTranslation().x) - abs(player->GetPosition().x);
	z = abs(transform.GetTranslation().z) - abs(player->GetPosition().z);
	if (x > -4 && x < 4 && z > -4 && z < 4) {
		player->bullet += 20;
		transform.SetTranslation(500, 500, 500);
	}
}

void Ammo::Init()
{
	weapon = new Model();
	weapon->LoadModel("Assets/Models/Ammo.obj");
	weapon->AddTexture("Ammo.png");
	spCollider = new SphereCollider(10, transform.GetTranslation());
}

void Ammo::Draw()
{
	transform.SetScale(1.0f, 1.0f, 1.0f);
	transform.SetRotation(0, 55, 0);
	weapon->SetTransform(&transform);
	weapon->Draw();
}
void Ammo::Shoot()
{

}