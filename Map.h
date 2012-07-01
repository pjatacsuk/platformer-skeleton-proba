#include <vector>
#include "Block.h"
#include "EntityManager.h"
#include "TextureManager.h"
#include "2DVector.hpp"
#ifndef INC_MAP_H
#define INC_MAP_H
class Editor;
using namespace EntityManagerTypes;
using namespace std;

class Map {
private:
	EntityManager*	blocks;
	std::map<Vector<int>,bool> coll_boxes;
public:
	friend Editor;
  Map(std::string source);
  Map();
  ~Map();
  void				Render(SDL_Surface* target,TextureManager* textureManager,Vector<int> offSet);
  void				Update();
  void				Push(Entity* blck);
  void				Remove(Entity* blck);
  void				GenerateCollBoxes();
  bool				GetColBox(Vector<int> coord);
 
  Entity*			Get(Entity* entity);
  
};
#endif