#include "Player.h"
#include "resource.h"
Player::Player(Vector<int> coord, Vector<int> speed):
_speed(speed),
_coord(coord),
_speed_cap(15,15),
_speed_increase(5),
_movement_type(2),
_jumping(false),
_size(Vector<int>(resource::consts::BLOCK_SIZE,resource::consts::BLOCK_SIZE))

{

}

Player::~Player() {

}

void Player::Render(SDL_Surface* target,TextureManager* textureManager,Vector<int>& offSet) {
	resource::function::apply_surface(_coord.GetX() - offSet.GetX(),
									  _coord.GetY() - offSet.GetY(),
									  textureManager->operator[](_movement_type),
									  target);
}

bool Player::CheckCollosion(int direction,Map* map) {
	int ray;
	switch(direction) {
	case UP:
		ray = _coord.GetY() ;
		return	map->GetColBox(Vector<int>(_coord.GetX()/resource::consts::BLOCK_SIZE,ray/resource::consts::BLOCK_SIZE));
		break;
	case DOWN:
		ray = _coord.GetY() + _size.GetY() + _speed.GetY()  ;
		return	map->GetColBox(Vector<int>(_coord.GetX()/resource::consts::BLOCK_SIZE,ray/resource::consts::BLOCK_SIZE));
		break;

	case LEFT:
		ray = _coord.GetX()  ;
		return	map->GetColBox(Vector<int>(ray/resource::consts::BLOCK_SIZE,_coord.GetY()/resource::consts::BLOCK_SIZE));
		break;
	case RIGHT:
		ray = _coord.GetX() + _size.GetX() ;
		return	map->GetColBox(Vector<int>(ray/resource::consts::BLOCK_SIZE,_coord.GetY()/resource::consts::BLOCK_SIZE));
		break;
	}
	return false;
}
void Player::MovePlayer(int direction,Vector<int>& offSet,Map* map) {
	


	switch(direction) {

	case UP:
		_speed.SetY(-10);
		if(_coord.GetY() - offSet.GetY()  - _speed.GetY() < 0	+	resource::consts::SCREEN_EDGE) {
			offSet.SetY(offSet.GetY() - _speed.GetY());
		}
		
		break;
	case DOWN:
		
		if(_coord.GetY() - offSet.GetY() + _speed.GetY() >  resource::consts::SCREEN_HEIGHT  - resource::consts::SCREEN_EDGE) {
			offSet.SetY(offSet.GetY() + _speed.GetY());
		}
		
		break;
	case LEFT:
		if(_speed.GetX() > 0 ) _speed.SetX(-2);		//csúszás csökkentése reakció során
		if(_speed.GetX() - _speed_increase >= -1* _speed_cap.GetX()) {
			_speed.SetX(_speed.GetX() - _speed_increase);
		}
		if(_coord.GetX() - offSet.GetX() - _speed_cap.GetX() < 0	+ resource::consts::SCREEN_EDGE) {
			offSet.SetX(offSet.GetX() - _speed_cap.GetX());
		}
	
		break;
	case RIGHT:
		if(_speed.GetX() < 0) _speed.SetX(2);	//csúszás csökkentése reakció után
		if(_speed.GetX() + _speed_increase <= _speed_cap.GetX()) {
			_speed.SetX(_speed.GetX() + _speed_increase);

		}
		
		if(_coord.GetX() - offSet.GetX() + _speed_cap.GetX() > resource::consts::SCREEN_WIDTH - resource::consts::SCREEN_EDGE) {
			offSet.SetX(offSet.GetX() + _speed_cap.GetX());
		}
		
		break;

	}
	

	
	
}
void Player::UpdateKey(SDL_Event& my_event,Vector<int>& offSet,Map* map) {
	switch(my_event.type) {
	case SDL_KEYDOWN:
		switch(my_event.key.keysym.sym) {
				case SDLK_w:
					
					MovePlayer(UP,offSet,map);
					_jumping = true;
					break;

				case SDLK_a:
					MovePlayer(LEFT,offSet,map);
					break;
				case SDLK_s:
					MovePlayer(DOWN,offSet,map);
					break;
				case SDLK_d:
					MovePlayer(RIGHT,offSet,map);
					break;

		}
		break;
	}
	
}

void Player::UpdateVelocity(Map* map) {
	
	
	if(abs(_speed.GetX()) - 1 >= 0) {
		if(_speed.GetX() > 0 ) {
			_speed.SetX(_speed.GetX() - 1);
		} else {
			_speed.SetX(_speed.GetX() + 1);
		}
	}
	
		
	if(CheckCollosion(DOWN,map)==false) {
			_speed.SetY(_speed.GetY() + 1);
	}
	
}
void Player::UpdatePosition() {


	_coord.SetX(_coord.GetX() + _speed.GetX());
	_coord.SetY(_coord.GetY() + _speed.GetY());

	
}

void Player::CollosionLogic(Map* map) {
	bool is_coll = false;
	if(_speed.GetY() != 0) { 
		if(CheckCollosion(DOWN,map) == true) {
			
			
			_coord.SetY(_coord.GetY() -1);
			_speed.SetY(0);
		}
		if(CheckCollosion(UP,map) == true) {
			_speed.SetY(0);
			_coord.SetY(_coord.GetY() +1);
			
		}
		
		
	}
	if(_speed.GetX() != 0) {
			if(CheckCollosion(LEFT,map) == true) {  
					_coord.SetX(_coord.GetX() + 1 );
					_speed.SetX(0);
			}  
			if(CheckCollosion(RIGHT,map) == true) {
					_coord.SetX(_coord.GetX() - 1 );
					_speed.SetX(0);
			}
		}
}

		
	
