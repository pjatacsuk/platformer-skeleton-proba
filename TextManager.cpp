#include "TextManager.h"

TextManager::TextManager(std::string source,int size,SDL_Color color):
textColor(color) {
	font = TTF_OpenFont(source.c_str(),size);
	if(font == NULL) return;
	
}

TextManager::~TextManager() {
	texts.clear();
}

void TextManager::DisplayText(SDL_Surface* target) {
	for(vector<Text>::iterator it = texts.begin();it != texts.end(); it++) {
		if((*it).is_started() == false) {
			(*it).StartTimer();
		}
		
		if((*it).timer.End() == true) {
			
			it = texts.erase(it);
			if(texts.size() ==0) return;
		} 
		else {
		SDL_Surface* message = TTF_RenderText_Solid(font,(*it).text.c_str(),textColor);
		resource::function::apply_surface((*it).coord.GetX(),(*it).coord.GetY(),message,target);
		
		}
	}
}

void TextManager::Add(Vector<int> crd,std::string txt,int time) {
	texts.push_back(Text(crd,txt,time));
}