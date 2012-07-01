#include "TextureManager.h"

TextureManager::TextureManager() {
	
}

TextureManager::~TextureManager() {
	for(map<int,SDL_Surface*>::iterator it = textures.begin();it != textures.end();it++) {
		SDL_FreeSurface((*it).second);
	}
	textures.clear();
}

void TextureManager::Add(int type,SDL_Surface* texture) {
	if(textures[type] == NULL) textures[type] = texture;
	else return;
}

void TextureManager::Free_Texture(int type) {
	SDL_FreeSurface(textures[type]);
	textures[type] = NULL;
}

SDL_Surface* TextureManager::operator[](int i) {
	if(i<0 || i > textures.size()) return NULL;
	return textures[i];
}

void TextureManager::Add(SDL_Surface* texture) {
	Add(textures.size(),texture);
}