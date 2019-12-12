#include "Game.h"
#include<iostream>
#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <gtc\type_ptr.hpp>



Game::Game()
{

}

Game::~Game()
{
	delete player;
	delete cube;
	delete plane;
	delete enemy;
	delete pasillo;
	delete arbol;
	delete ammo;
}

void Game::Init()
{
	std::cout << " Menu Init" << std::endl;
	this->platform = Platform::GetPtr();
	this->manager = GameStateManager::getPtr();
	shaderManager = ShaderManager::getPtr();
	shaderManager->LoadShaders("phong", "Assets/Shaders/Default/phong-shader.vert", "Assets/Shaders/Default/phong-shader.frag");
	shaderManager->LoadShaders("gouraud", "Assets/Shaders/Default/gouraud-shader.vert", "Assets/Shaders/Default/gouraud-shader.frag");
	player = new Player(glm::vec3(0, 0, 0));
	player->Init(&enemyPool);


	cube = new CubeModel();
	cube->Init();
	plane = new PlaneModel();
	plane->Init();

	enemy = new Model();
	enemy->LoadModel("Assets/Models/Weapon.obj");
	enemy->AddTexture("Weapon_UV.png");
	enemy->AddTexture("Weapon_Normal.png");
	//enemy->Init();

	pasillo = new Model();
	pasillo->LoadModel("Assets/Models/Pasillo.obj");
	pasillo->AddTexture("Pasillo.png");
	pasillo->AddTexture("Weapon_Normal.png");
	auto pasillo = new Pasillo(glm::vec3(0, 0, 0), player);
	pasillo->Init();
	pasilloPool.push_back(pasillo);

	arbol = new Model();
	arbol->LoadModel("Assets/Models/Arbol.obj");
	arbol->AddTexture("Arbol.png");
	arbol->AddTexture("Weapon_Normal.png");

	ammo = new Model();
	ammo->LoadModel("Assets/Models/Ammo.obj");
	ammo->AddTexture("Ammo.png");
	ammo->AddTexture("Weapon_Normal.png");
	
	std::vector<std::string> skyboxFaces;
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_rt.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_lf.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_up.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_dn.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_bk.tga");
	skyboxFaces.push_back("Assets/Textures/Skybox/cupertin-lake_ft.tga");
	skybox = Skybox(skyboxFaces);

	//text = Text();
	text.LoadFont("Assets/Fonts/arial.ttf");

	CreateArbol();
	CreateAmmo();
	//CreateEnemies();
}

void Game::Draw()
{
	platform->RenderClear();
	skybox.Draw(shaderManager->GetViewMatrix(), shaderManager->GetProjectionMatrix());
	
	shaderManager->Activate("gouraud");
	shaderManager->draw();
	cube->Draw();
	
	if (game == false) {
		shaderManager->Activate("phong");
		shaderManager->draw();
		plane->Draw();
	}
	

	shaderManager->Activate("phong");
	shaderManager->draw();
	player->Draw();

	//text.RenderText("This is sample text", 25.0f, 25.0f, 1.0f, glm::vec3(0.5, 0.8f, 0.2f));
	for (auto pasillo : pasilloPool) {
		pasillo->Draw();
	}
	for (auto arbol : arbolPool) {
		arbol->Draw();
	}
	for (auto ammo : ammoPool)
	{
		ammo->Draw();
	}
	for (auto enemy : enemyPool)
	{
		enemy->Draw();
	}
	platform->RenderPresent();
}

bool Game::MouseInput(int x, int y, bool leftbutton)
{
	player->MouseInput(x, y, leftbutton);

	return false;
}

bool Game::Input(std::map<int, bool> keys)
{
	player->Input(keys);
	return false;
}

void Game::Update()
{
	for (auto pasillo : pasilloPool) {
		pasillo->Update();
	}
	for (auto arbol : arbolPool) {
		arbol->Update();
	}

	if (GetKeyState('L') & 0x8000)
	{
		game = true;
	}

	for (auto ammo : ammoPool)
	{
		ammo->Update();
	}

	if (game == true) {
		for (auto enemy : enemyPool)
		{
			enemy->Update();
		}
		player->Update();
	}
}

void Game::CreateEnemies()
{
	while (enemyPool.size() < 20)
	{
		if (rand() % 100 < 1)
		{
			int dir = -1;
			if (rand() % 100 > 50)
				dir = 1;
			auto enemy = new EnemyT4(glm::vec3(rand() % 300 * dir, 10, rand() % 300 * dir), player);
			enemy->Init();
			enemyPool.push_back(enemy);
		}

		if (rand() % 100 < 1)
		{
			int dir = -1;
			if (rand() % 100 > 50)
				dir = 1;
			auto enemy = new EnemyT5(glm::vec3(rand() % 300 * dir, 10, rand() % 300 * dir), player);
			enemy->Init();
			enemyPool.push_back(enemy);
		}
	}
}


void Game::CreateAmmo()
{
	while (ammoPool.size() < 20)
	{
		if (rand() % 100 < 1)
		{
			int dir = -1;
			if (rand() % 100 > 50)
				dir = 1;
			auto ammo = new Ammo(glm::vec3(rand() % 300 * dir, 10, rand() % 300 * dir), player);
			ammo->Init();
			ammoPool.push_back(ammo);
		}

		if (rand() % 100 < 1)
		{
			int dir = -1;
			if (rand() % 100 > 50)
				dir = 1;
			auto ammo = new Ammo(glm::vec3(rand() % 300 * dir, 10, rand() % 300 * dir), player);
			ammo->Init();
			ammoPool.push_back(ammo);
		}
	}
}


void Game::CreateArbol() {
	while (arbolPool.size() < 100)
	{
		if (rand() % 100 < 1)
		{
			int dir = -1;
			if (rand() % 100 > 50)
				dir = 1;
			auto arbol = new Arbol(glm::vec3(rand() % 300 * dir, 100, rand() % 300 * dir), player);
			arbol->Init();
			arbolPool.push_back(arbol);
		}
		if (rand() % 100 < 1)
		{
			auto arbol = new Arbol(glm::vec3(rand() % 300 * -1, 100, rand() % 300), player);
			arbol->Init();
			arbolPool.push_back(arbol);
			if (rand() % 100 > 50)
				auto arbol = new Arbol(glm::vec3(rand() % 300, 100, rand() % 300 * -1), player);
			arbol->Init();
			arbolPool.push_back(arbol);

		}
	}
}

void Game::Close()
{
	std::cout << " Close Init" << std::endl;
}