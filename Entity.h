#include <SDL.h>
#include "2DVector.hpp"
#include <string>
#include "TextureManager.h"
#ifndef INC_ENTITY_H
#define INC_ENTITY_H
class Entity {
private:
  int _ID;

public:
  Entity();
  Entity(int id);
  virtual ~Entity()=0;
  virtual void Render(SDL_Surface* target,TextureManager* textureManager,Vector<int> offSet)=0;
  virtual void Update()=0;
  virtual std::string Serialize()=0;
  virtual void deSerialize(std::string line)=0;
  virtual bool operator<(const Entity* entity);
  virtual bool operator==(Entity* entity);
  virtual bool operator<(const Entity& entity);

};

#endif