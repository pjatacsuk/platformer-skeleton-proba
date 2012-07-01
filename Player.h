#ifndef INC_PLAYER_H
#define INC_PLAYER_H

#include <SDL.h>
#include "TextureManager.h"
#include "Map.h"
#include "Entity.h"
#include "2DVector.hpp"
enum {UP,DOWN,LEFT,RIGHT};
class Player{
private:
	Vector<int>		_coord;							//coordinátája
	int				_movement_type;					//ez még csak animációhoz kell
	Vector<int>		_speed_cap;
	int				_speed_increase;
	Vector<int>		_size;
	bool			_jumping;
	
public:
	Vector<int>		_speed;
	Player(Vector<int> coord,Vector<int> speed);
	~Player();
	void			Render(SDL_Surface* target,TextureManager* textureManager,Vector<int>& offSet);
	void			UpdateKey(SDL_Event& my_event,Vector<int>& offSet,Map* map);
	void			UpdatePosition();
	void			UpdateVelocity(Map* map);
	void			Jump();
	void			MovePlayer(int direction,Vector<int>& offSet,Map* map);
	bool			CheckCollosion(int direction,Map* map);
	void			CollosionLogic(Map* map);
	
	

};
#endif