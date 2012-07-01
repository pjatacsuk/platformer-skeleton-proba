#include "GamePlay.h"
#include "MyTimer.hpp"
#include <sstream>
GamePlay::GamePlay(Map* map,Vector<int> offSet,Vector<int> player_coord):
_map(map),
_offSet(offSet){
	_player = new Player(player_coord,Vector<int>(0,0));
	_textManager = new TextManager("./data/fonts/Calibri.ttf",28,SDL_Color());
	_map->GenerateCollBoxes();
}

GamePlay::GamePlay(Map* map,Vector<int> offSet):
_map(map),
_offSet(offSet){
	_player = new Player(Vector<int>(30,30),Vector<int>(0,0));
	_textManager = new TextManager("./data/fonts/Calibri.ttf",28,SDL_Color());
	_map->GenerateCollBoxes();
}


GamePlay::~GamePlay() {
	delete _player;
	delete _textManager;
	delete _map;
}

void GamePlay::Render(SDL_Surface* target, TextureManager* textureManager) {
	SDL_Rect* rect = new SDL_Rect();
	SDL_FillRect(target,NULL,SDL_MapRGB(target->format,187,186,237));
	
	_map->Render(target,textureManager,_offSet);
	_player->Render(target,textureManager,_offSet);
	_textManager->DisplayText(target);
	
}

void GamePlay::Loop(SDL_Surface* target,TextureManager* textureManager) {
	SDL_Event MyEvent;
	MyTimer fps = MyTimer(1000/resource::consts::FPS);
	int frame = 0;
	fps.StartTimer();
	int key_down = 0;
	while(_running) {
		
		
		
		
		if(frame % resource::consts::FPS == 0) {
					while(SDL_PollEvent(&MyEvent)) {
					_player->UpdateKey(MyEvent,_offSet,_map);
					switch(MyEvent.type) {
					case SDL_KEYDOWN:
						key_down = 1;
						switch(MyEvent.key.keysym.sym) {
						case SDLK_ESCAPE:
							_running = false;
							break;
						}
						break;
					case SDL_KEYUP:
						key_down = false;
						break;
					}
					
				}
			
			if(!key_down) {
			_player->UpdateVelocity(_map);
			}
			
			_player->UpdatePosition();
			_player->CollosionLogic(_map);
			Render(target,textureManager);

			}
			SDL_Flip(target);
		frame++;
		if( fps.GetTicks() < 1000 / resource::consts::FPS ) 
        {
            //Sleep the remaining frame time
			SDL_Delay( ( 1000 / resource::consts::FPS ) - fps.GetTicks() );
        }

	}
}