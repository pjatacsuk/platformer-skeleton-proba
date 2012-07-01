#include "resource.h"

using namespace resource::function;

SDL_Surface* resource::function::load_image(std::string filename ) 	{
				//The image that's loaded
				SDL_Surface* loadedImage = NULL;
    
				//The optimized image that will be used
				SDL_Surface* optimizedImage = NULL;
    
				//Load the image using SDL_image
				loadedImage = IMG_Load( filename.c_str() );
    
				//If the image loaded
				if( loadedImage != NULL )
				{
					//Create an optimized image
					optimizedImage = SDL_DisplayFormat( loadedImage );
        
					//Free the old image
					SDL_FreeSurface( loadedImage );
				}
    
				//Return the optimized image
				return optimizedImage;
}

void resource::function::apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination )
			{
				//Make a temporary rectangle to hold the offsets
				SDL_Rect offset;
    
				//Give the offsets to the rectangle
				offset.x = x;
				offset.y = y;
				//Blit the surface
				SDL_BlitSurface( source, NULL, destination, &offset );
			}