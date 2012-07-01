#include "Entity.h"
#include "resource.h"
Entity::Entity() {

}

Entity::Entity(int id):_ID(id) {
	
}

Entity::~Entity() {

}

bool Entity::operator<(const Entity* entity) {
	return false;
}

bool Entity::operator==(Entity* entity) {
	return _ID == entity->_ID;
}

bool Entity::operator<(const Entity& entity) {
	return false;
}


