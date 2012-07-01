#include "Entity.h"
#include <SDL.h>
#include <string>
#include "2DVector.hpp"
#include "TextureManager.h"
#ifndef INC_BLOCK_H
#define INC_BLOCK_H

class Block : public Entity {
private:
  
  Vector<int>	_coord;
  int			_type;
public:
  Block(int type,Vector<int> coord); 
  Block();
  virtual	 ~Block();
  virtual	void		Render(SDL_Surface* target,TextureManager* textureManager,Vector<int> offSet);
  virtual	void		Update();
  virtual	std::string Serialize();
  virtual	void		deSerialize(std::string line);
			bool		operator<(const Entity* entity);
			bool		operator==(Entity* entity);
			bool		operator<(const Entity& entity);
			
  inline	Vector<int>	GetCoord() {return _coord;}
};
#endif