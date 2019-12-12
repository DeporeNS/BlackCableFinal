#include "Arbol.h"

Arbol::Arbol(glm::vec3 position, Player* player)
{
	this->player = player;
	this->platform = Platform::GetPtr();
	transform.SetTranslation(position.x, position.y - 109.5f, position.z);
}

void Arbol::Update()
{
}

void Arbol::Init()
{
	weapon = new Model();
	weapon->LoadModel("Assets/Models/Arbol.obj");
	weapon->AddTexture("Arbol.png");
}

void Arbol::Draw()
{
	transform.SetScale(1.6f, 1.6f, 1.6f);
	transform.SetRotation(0, 55, 0);
	weapon->SetTransform(&transform);
	weapon->Draw();
}

void Arbol::Shoot()
{

}