#include "Map.h"
#include <iostream>
#include <fstream>
#include "TextureManager.h"
Map::Map(std::string source) {
	blocks = new EntityManager();
	fstream file;
	file.open(source,fstream::in);
	std::string line;
	while(file.eof() != true && getline(file,line)) {
		
		
		
		Block* blck = new Block();
		blck->deSerialize(line);

		blocks->Push(blck);
	}
	
}

Map::Map() {
	blocks = new EntityManager();

}

Map::~Map() {
	delete blocks;
}
/** Map rendelés **/
void Map::Render(SDL_Surface* target,TextureManager* textureManager,Vector<int> offSet) {
	for(EntityManagerTypes::iterator it = blocks->begin();
		it != blocks->end();
		it++) {
			(*it)->Render(target,textureManager,offSet);								//block-ok egyenkénti kirendelelése
	}
}

void Map::Push(Entity*  blck) {
	blocks->Push(blck);
}

Entity* Map::Get(Entity* entity) {
	
	return blocks->Get(entity);
	
}

void Map::Remove(Entity* entity) {
	blocks->Remove(entity);
}

void Map::GenerateCollBoxes() {
	for(EntityManagerTypes::iterator it = blocks->begin();
		it != blocks->end();
		it++) {
			Block* blck = dynamic_cast<Block*>(*it);
			int x = blck->GetCoord().GetX()/resource::consts::BLOCK_SIZE;
			int y = blck->GetCoord().GetY()/resource::consts::BLOCK_SIZE;
			coll_boxes[Vector<int>(x,y)] = true;
	}
	

}

bool Map::GetColBox(Vector<int> coord) {
	return coll_boxes[coord];
}
