#ifndef INC_GAMEPLAY_H
#define INC_GAMEPLAY_H
#include "Player.h"
#include "TextManager.h"
#include "TextureManager.h"
#include "Map.h"
#include "resource.h"
#include <SDL.h>
class GamePlay{
private:
	Map*			_map;
	bool			_running;
	Vector<int>		_offSet;
	TextManager*	_textManager;
	Player*			_player;
public:
	GamePlay(Map* map,Vector<int> offSet);
	GamePlay(Map* map,Vector<int> offSet,Vector<int> player_coord);
	~GamePlay();

	void			Render(SDL_Surface* target,TextureManager* textureManager);
	void			Loop(SDL_Surface* target,TextureManager* textureManager);
};

#endif