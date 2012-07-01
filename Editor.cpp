#include "Editor.h"
#include <iostream>
#include "resource.h"
#include <fstream>
#include <math.h>
#include <SDL_ttf.h>
#include "GamePlay.h"
Editor::Editor():
offSet(0,0),
block_type(NORMAL),
playing(false){
	_map = new Map();
	textManager = new TextManager("./data/fonts/calibri.ttf",28,SDL_Color());
}

Editor::Editor(std::string source):
offSet(0,0),
block_type(NORMAL),
playing(false){
	_map = new Map(source);
	textManager = new TextManager("./data/fonts/calibri.ttf",28,SDL_Color());
}

Editor::~Editor() {
	delete _map;
	
	if(textManager != NULL) delete textManager;
}

void Editor::Save(std::string output) {
	
	
	fstream file;
	file.open(output,fstream::out);
	for(EntityManagerTypes::iterator it = _map->blocks->begin();
		it != _map->blocks->end();
		it++) 
	{
		file << (*it)->Serialize() << endl;
	}
	file.close();
	
	
}

void Editor::Loop(SDL_Surface* target,TextureManager* textureManager) {
	SDL_Event my_event;
	int x,y;
	bool mouse_down = false;
	
	while(running) {
		if(playing) {
			SDL_GetMouseState(&x,&y);
			
			x = (x + offSet.GetX()) / resource::consts::BLOCK_SIZE;
			y = (y + offSet.GetY()) / resource::consts::BLOCK_SIZE;
			Save("gameplaytest.txt");
			Map* gameplay = new Map("./gameplaytest.txt");
			GamePlay* gamePlay = new GamePlay(gameplay,offSet,Vector<int>(x*resource::consts::BLOCK_SIZE,y*resource::consts::BLOCK_SIZE));
			gamePlay->Loop(target,textureManager);
			delete gamePlay;
			playing = false;
		}

		while(SDL_PollEvent(&my_event)) {
			
			switch(my_event.type) {
				case SDL_KEYDOWN:
					switch(my_event.key.keysym.sym) 
					{
					case SDLK_ESCAPE:
						
						Save("map1.txt");
						textManager->Add(Vector<int>(50,50),"SAVED",5000);
					
						break;
					case SDLK_w:
						offSet.SetY(offSet.GetY() - resource::consts::BLOCK_SIZE);
						break;
					case SDLK_a:
						offSet.SetX(offSet.GetX() - resource::consts::BLOCK_SIZE);
					break;

					case SDLK_s:
						offSet.SetY(offSet.GetY() + resource::consts::BLOCK_SIZE);
						break;
					case SDLK_d:
						offSet.SetX(offSet.GetX() + resource::consts::BLOCK_SIZE);
						break;
					case SDLK_p:
						playing = true;
						break;
					}
					break;
				
			}
			if(my_event.type == SDL_MOUSEBUTTONDOWN || mouse_down)
			{
				mouse_down = true;
				switch(my_event.button.button)
				{
					case SDL_BUTTON_LEFT: 
						x = my_event.button.x / resource::consts::BLOCK_SIZE;
						y = my_event.button.y / resource::consts::BLOCK_SIZE;
						_map->Push(new Block(block_type,Vector<int>(x*resource::consts::BLOCK_SIZE + offSet.GetX(),
														   y*resource::consts::BLOCK_SIZE + offSet.GetY())));
					break;
					case SDL_BUTTON_RIGHT:
						x = my_event.button.x / resource::consts::BLOCK_SIZE;
						y = my_event.button.y / resource::consts::BLOCK_SIZE;
						_map->Remove(new Block(block_type,Vector<int>(x*resource::consts::BLOCK_SIZE + offSet.GetX(),
															 y*resource::consts::BLOCK_SIZE + offSet.GetY())));
						mouse_down = false;
					break;
					case SDL_BUTTON_WHEELUP:
						block_type = (block_type + 1) % textureManager->Size();
						mouse_down = false;
						break;
					case SDL_BUTTON_WHEELDOWN:
						if(block_type - 1 < 0) {
							block_type = textureManager->Size() -1;
						} else {
							block_type = block_type - 1 % textureManager->Size();
						}
						mouse_down = false;
						break;
				}
				
			} else if(my_event.type == SDL_MOUSEBUTTONUP) {
				mouse_down = false;
			} 
				
		}
		
		Render(target,textureManager);
		SDL_Flip(target);
	}
}

void Editor::Render(SDL_Surface* target,TextureManager* textureManager) {
	SDL_Rect* rect = new SDL_Rect();
	SDL_FillRect(target,NULL,SDL_MapRGB(target->format,187,186,237));
	for(int x=0; x<resource::consts::SCREEN_WIDTH; x+=resource::consts::BLOCK_SIZE) { 
			rect->y = 0;
			rect->x = x;
			rect->w = 1;
			rect->h = resource::consts::SCREEN_HEIGHT;
			SDL_FillRect(target,rect,SDL_MapRGB(target->format,0,0,0));
	}
	for(int y=0; y<resource::consts::SCREEN_HEIGHT; y+=resource::consts::BLOCK_SIZE) {
			rect->x = 0;
			rect->y = y;
			rect->h = 1;
			rect->w = resource::consts::SCREEN_WIDTH;
			SDL_FillRect(target,rect,SDL_MapRGB(target->format,0,0,0));
		}
	delete rect;
	
	_map->Render(target,textureManager,offSet);																	//Map rendelelése

	int x,y;
	SDL_GetMouseState(&x,&y);
	resource::function::apply_surface(x - resource::consts::BLOCK_SIZE/2,
									  y - resource::consts::BLOCK_SIZE/2,textureManager->operator[](block_type),target);
	//text rendelés
	textManager->DisplayText(target);
	
}