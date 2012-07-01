#include "Block.h"
#include <cstring>
#include "resource.h"
#include "TextureManager.h"
#include <sstream>
using namespace resource::function;

Block::Block(int type,Vector<int> coord):
_coord(coord),
_type(type),
Entity(0){
//	_texture = load_image(path);
	//TODO: MAP
}
Block::~Block() {
	
}

Block::Block() {

}
void Block::Render(SDL_Surface* target,TextureManager* textureManager,Vector<int> offSet) {
	apply_surface(_coord.GetX() - offSet.GetX(),_coord.GetY() - offSet.GetY(),textureManager->operator[](_type),target);
}

void Block::Update() {

}

std::string Block::Serialize() {
	
	std::stringstream oss;
	oss << _coord.GetX() << " " << _coord.GetY() << " " << _type << " ";
	return oss.str();
}

void Block::deSerialize(std::string line) {
	
	char* tmp = new char[line.length()+1];
	strcpy(tmp,line.c_str());
	tmp = strtok(tmp," ");
	_coord.SetX(atoi(tmp));							// X coord
	
	tmp = strtok(NULL," ");					// Y coord
	_coord.SetY(atoi(tmp));

	tmp = strtok(NULL," ");					// Type
	_type = atoi(tmp);
}

bool Block::operator<(const Entity* entity) {
	const Block* blck = dynamic_cast<const Block*>(entity);
	return true;
}

bool Block::operator==(Entity* entity) {
	Block* block = dynamic_cast<Block*>(entity);
	if(block->_type == _type && block->_coord.GetX() == _coord.GetX() && block->_coord.GetY() == _coord.GetY()) {
		return true;
	}
	return false;
}

bool Block::operator<(const Entity& entity) {
	return true;
}