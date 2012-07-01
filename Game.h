#include <SDL.h>
#include <SDL_image.h>
#include "Map.h"
#include "EntityManager.h"
#include "TextureManager.h"
enum status {MENU,MAPCHOOSE,GAMEPLAY,EDITOR};

class Game {
private:
	bool				running;
	SDL_Surface*		screen;
	Map*				map;
	EntityManager*		entityManager;
	status				game_status;
	TextureManager*		textureManager;
public:
	Game();
	~Game();

	void	Init_Game();
	void	Load_Map(std::string map_source);
	void 	Free_Game();
	void	GameLoop();
	void	GameMenu();
	void	GamePlay();
	void	GameEditor();
	void	MapChoose();

};