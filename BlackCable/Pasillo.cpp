#include "Pasillo.h"

Pasillo::Pasillo(glm::vec3 position, Player* player)
{
	this->player = player;
	this->platform = Platform::GetPtr();
	transform.SetTranslation(position.x, position.y - 20.2f, position.z);
}

void Pasillo::Update()
{
}

void Pasillo::Init()
{
	weapon = new Model();
	weapon->LoadModel("Assets/Models/Pasillo.obj");
	weapon->AddTexture("Pasillo.png");
}

void Pasillo::Draw()
{
	transform.SetScale(10.0f, 10.0f, 10.0f);
	transform.SetRotation(0, 55, 0);
	weapon->SetTransform(&transform);
	weapon->Draw();
}

void Pasillo::Shoot()
{

}