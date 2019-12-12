#ifndef ARBOL_H 
#define ARBOL_H 

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>
#include <map>
#include "BCE/Graphic/Camera.h"
#include "BCE/Graphic/Model.h"
#include "BCE/Base/Platform.h"
#include "BCE/Base/ShaderManager.h"
#include "Player.h"
#include "Enemy.h"

using namespace BCE::Base;
using namespace BCE::Graphics;

class Arbol : public Enemy
{
public:
	Arbol(glm::vec3 position, Player* player);
	void Init();
	void Update();
	void Draw();
private:
	void Shoot();
};

#endif // ! 