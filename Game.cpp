#include "Game.h"
#include "Block.h"
#include "resource.h"
#include "Editor.h"
#include <SDL_ttf.h>
Game::Game():
running(true),
game_status(MENU),
screen(NULL),
map(NULL) 
{
	Init_Game();
	
	
}

void Game::Init_Game() {
	 if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return;
    }
	if( TTF_Init() == -1) {
		return;
	}
	screen = SDL_SetVideoMode(resource::consts::SCREEN_WIDTH,resource::consts::SCREEN_HEIGHT,32,SDL_SWSURFACE);
	SDL_EnableKeyRepeat(250,SDL_DEFAULT_REPEAT_INTERVAL);
	entityManager = new EntityManager();
	textureManager = new TextureManager();
	textureManager->Add(resource::function::load_image("./data/images/block_normal.png"));
	textureManager->Add(resource::function::load_image("./data/images/block_water.png"));
	textureManager->Add(resource::function::load_image("./data/images/player.png"));
}

void Game::GameMenu() {
	SDL_Event my_event;
	
	while(SDL_PollEvent(&my_event)) {
		switch(my_event.type) {
			case SDL_KEYDOWN: 
				switch(my_event.key.keysym.sym) {
						case SDLK_1:
							game_status = GAMEPLAY;
						break;
						case SDLK_2:
							game_status = EDITOR;
							break;
				}
			break;
		}
	}
	SDL_Flip(screen);


}
void Game::GameLoop() {
	while(running) {
		switch(game_status) {
		case MENU:
			GameMenu();
			break;
		case EDITOR:
			GameEditor();
			break;
		
		case GAMEPLAY:
			GamePlay();
			break;
		case MAPCHOOSE:
			MapChoose();
			break;
		}
	}
}



void Game::Free_Game() {
	SDL_Quit();
}

void Game::GamePlay() {
	EntityManager* eM = new EntityManager();
	Block* blck = new Block(1,Vector<int>(3,2));
	Block* blck2 = new Block(1,Vector<int>(3,2));
	Block* blck3 = new Block(1,Vector<int>(4,2));
	Block A = Block();
	Block B = Block();
	
	if((*blck) < (*blck3)) {
		return;
	}
}

void Game::MapChoose() {

}

void Game::GameEditor() {
	Editor* editor = new Editor("map1.txt");
	editor->Loop(screen,textureManager);
	game_status = MENU;
}