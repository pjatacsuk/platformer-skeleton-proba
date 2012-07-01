#ifndef INC_TEXTURE_MANAGER
#define INC_TEXTURE_MANAGER

#include <SDL.h>
#include <map>
using namespace std;
class TextureManager {
private:
	
	map<int,SDL_Surface*> textures;
public:
	TextureManager();
	~TextureManager();

	inline	int		Size() const {return textures.size();}

	void			Add(int type,SDL_Surface* texture);
	void			Free_Texture(int type);
	void			Add(SDL_Surface* texture);
	SDL_Surface*	operator[](int i);

	
};


#endif