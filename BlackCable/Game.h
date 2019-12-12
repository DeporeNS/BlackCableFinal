#pragma once
#include "BCE/Base/GameState.h"
#include "BCE/Base/GameStateManager.h"
#include "BCE/Graphic/Mesh.h"
#include "BCE/Graphic/Shader.h"
#include "BCE/Graphic/Camera.h"
#include "BCE/Graphic/CubeModel.h"
#include "BCE/Graphic/PlaneModel.h"
#include "BCE/Base/ShaderManager.h"
#include "BCE/Graphic/Model.h"
#include "BCE/Graphic/Skybox.h"
#include "BCE/Graphic/Text.h"
#include "Player.h"
#include "EnemyT4.h"
#include "EnemyT5.h"
#include "Enemy.h"
#include "Pasillo.h"
#include "Arbol.h"
#include "Ammo.h"
#include <list>
#include <Windows.h>

#include<vector>
using namespace BCE::Base;
using namespace BCE::Lights;
using namespace BCE::Graphics;
class Game : public GameState
{
private:
	Platform* platform;
	GameStateManager* manager;
	ShaderManager* shaderManager;
	Player* player;
	Model *pasillo;
	Model* arbol;
	Model* ammo;
	CubeModel *cube;
	PlaneModel* plane;
	Model *enemy;
	Text text;
	Skybox skybox;
	bool game = false;
	std::list<Enemy *> enemyPool;
	std::list<Enemy *> pasilloPool;
	std::list<Enemy*> arbolPool;
	std::list<Enemy*> ammoPool;


public:
	Game();
	virtual ~Game();
	void Init() override;
	void Draw() override;
	bool Input(std::map<int, bool> keys) override;
	bool MouseInput(int x, int y, bool leftbutton);
	void Update() override;
	void CreateEnemies();
	void CreateAmmo();
	void CreateArbol();
	void Close() override;

};