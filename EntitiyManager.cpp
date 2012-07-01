#include "EntityManager.h"
#include <algorithm>
using namespace EntityManagerTypes;
EntityManager::EntityManager():id_count(0) {

}

EntityManager::~EntityManager() {
	for(iterator it = entities.begin();it != entities.end();it++) {
		(*it)->~Entity();
	}
	entities.clear();
}

void EntityManager::Push(Entity* entity) {
	for(EntityManagerTypes::iterator it = begin();
		it!= end();
		it++) {
			if((*it)->operator==(entity)) {
				return;
			}
	}
	entities.insert(entity);
	id_count++;
}

Entity* EntityManager::Get(Entity* entity) {
	for(EntityManagerTypes::iterator it = begin();
		it != end();
		it++) {
			if( (*it)->operator==(entity)) {
				return (*it);
			}
	
		}
}

void EntityManager::Remove(Entity* entity) {
		for(EntityManagerTypes::iterator it = begin();
		it != end();
		it++) {
			if( (*it)->operator==(entity)) {
				entities.erase(it);
				return;
			}
		}
		
}

void EntityManager::Sort() {
	
}



