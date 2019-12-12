// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=k70aBlef-20&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=6
#include "Texture.h"

namespace BlackCable {
	// Carga un sprite desde un archivo
	Texture3::Texture3(std::string filename) {
		mGraphics = Graphics::Instance();

		// Carga la textura desde el assetManager para que no se cargue mas de 1 vez
		mTex = AssetManager::Instance()->GetTexture(filename);

		// Obtiene el ancho y largo de la textura
		SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

		//Es falso porque esta imagen no es cargada desde una spritesheet
		mClipped = false;

		mRenderRect.w = mWidth;
		mRenderRect.h = mHeight;
	}

	// Carga un aprite desde un archivo y se usa para las spritesheet
	Texture3::Texture3(std::string filename, int x, int y, int w, int h) {
		mGraphics = Graphics::Instance();

		// Carga la textura desde el assetManager para que no se cargue mas de 1 vez
		mTex = AssetManager::Instance()->GetTexture(filename);

		// Es verdadero porque la imagen fue sacada de una spriteSheet
		mClipped = true;

		mWidth = w;
		mHeight = h;

		mRenderRect.w = mWidth;
		mRenderRect.h = mHeight;

		// marcando el cuadrado que vas a texturizar de la imagen
		mClipRect.x = x;
		mClipRect.y = y;
		mClipRect.w = mWidth;
		mClipRect.h = mHeight;
	}

	// convierte un string a un render en la pantalla
	Texture3::Texture3(std::string text, std::string fontPath, int size, SDL_Color color) {
		mGraphics = Graphics::Instance();

		// Carga la textura desde el assetManager para que no se cargue mas de 1 vez
		mTex = AssetManager::Instance()->GetText(text, fontPath, size, color);

		// Es falso porque la imagen no viene de una spritesheet
		mClipped = false;

		// Obtiene el ancho y alto de la textura
		SDL_QueryTexture(mTex, NULL, NULL, &mWidth, &mHeight);

		mRenderRect.w = mWidth;
		mRenderRect.h = mHeight;
	}

	// destructor
	Texture3::~Texture3() {
		SDL_DestroyTexture(mTex);
		mTex = NULL;
		mGraphics = NULL;
	}

	// Sirve para sacar el tamano de la imagen ya dimensionada (Box Collider)
	Vector2 Texture3::ScaledDimensions() {
		Vector2 scaledDimensions = Scale();
		scaledDimensions.x *= mWidth;
		scaledDimensions.y *= mHeight;

		return scaledDimensions;
	}

	// se llama para hacer el render a la pantalla
	void Texture3::Render() {
		Vector2 pos = Pos(world);
		Vector2 scale = Scale(world);

		//Centra la imagen al mundo para que su posicion inicial no sea 0,0
		mRenderRect.x = (int)(pos.x - mWidth * scale.x * 0.5f);
		mRenderRect.y = (int)(pos.y - mHeight * scale.y * 0.5f);

		// Escala ancho y alto para quedar acorde a GameEntity
		mRenderRect.w = (int)(mWidth * scale.x);
		mRenderRect.h = (int)(mHeight * scale.y);

		mGraphics->DrawTexture(mTex, (mClipped) ? &mClipRect : NULL, &mRenderRect, Rotation(world));
	}
}
// Clase basada en los tutoriales de canal de youtube Ather Omar https://www.youtube.com/watch?v=k70aBlef-20&list=PLhJr2LOK-xwxQlevIZ97ZABLw72Eu9he7&index=6