#include <vector>
#include "Block.h"
#include "Map.h"
#include <string>
#include "TextureManager.h"
#include <SDL_ttf.h>
#include "TextManager.h"
using namespace std;

enum {NORMAL,WATER};

class Editor {
private:
  Map*			_map;
  bool			running;
  bool			playing;
  Vector<int>	offSet;
  int			block_type;
  TTF_Font*		font;
  SDL_Color		textColor;
  TextManager*	textManager;
public:
  Editor();
  Editor(std::string source);
  ~Editor();
  void			Loop(SDL_Surface* target,TextureManager* textureManager);
  void			Update();
  void			Render(SDL_Surface* target,TextureManager* textureManager);
  void			Save(std::string output);

};