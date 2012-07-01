#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include "Entity.h"
namespace resource {
	namespace function {
			SDL_Surface *load_image(std::string filename ); 
			void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );
					
			
	}

	namespace consts {
#ifndef res_const
#define res_const
		static const int SCREEN_WIDTH	=	780;
		static const int SCREEN_HEIGHT	=	600;
		static const int BLOCK_SIZE		=	30;
		static const int SCREEN_EDGE	=	100;		//mikor kell váltani az offSet-et
		static const int GRAVITY		=	5;
		static const int FPS			=	60;
#endif
	}
	namespace objects {
#ifndef res_objects
#define res_objects
		template<class T> struct lesser {
			bool operator()(const T* x,const T* y) const {
				return (*x) < (*y);
			}
		};

#endif

	}
}
