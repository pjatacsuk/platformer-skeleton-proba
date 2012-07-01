#ifndef INC_ENTITYMANAGER_H
#define INC_ENTITYMANAGER_H

#include "Entity.h"
#include <set>
#include "resource.h"

namespace EntityManagerTypes {
	typedef std::set<Entity*>::iterator iterator;
	class EntityManager {
	private:
		std::set<Entity*>	entities;
		int					id_count;
	public:
		

		EntityManager();
		~EntityManager();
	
		void				Push(Entity* entity);
		Entity*				Get(Entity* entity);
		void				Remove(Entity* entity);
		void				Sort();
		//inline std::vector<Entity*> GetEntities() const {return entities;}
		inline				int GetIDcount() const {return id_count;}

		inline				iterator begin() {return entities.begin();}
		inline				iterator end()	{return entities.end();}

	};  
}


#endif