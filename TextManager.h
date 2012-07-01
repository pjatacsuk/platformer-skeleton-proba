#ifndef INC_TEXTMANAGER_H
#define INC_TEXTMANAGER_H

#include <SDL_ttf.h>
#include <queue>
#include <string>
#include "2DVector.hpp"
#include "resource.h"
#include "MyTimer.hpp"
using namespace std;

struct Text {
	Vector<int> coord;
	std::string text;
	MyTimer timer;

	Text(Vector<int> crd,std::string txt,int time):
	coord(crd),
	text(txt),
	timer(time) {

	}
	
	void StartTimer() {
		timer.StartTimer();
	}
	bool is_started() {
		return timer.is_started();
	}
};

class TextManager {
private:
	vector<Text>	texts; 
	TTF_Font*		font;
	SDL_Color		textColor;
public:
	TextManager(std::string source,int size,SDL_Color color);
	~TextManager();
	void	DisplayText(SDL_Surface* target);
	void	Add(Vector<int> crd,std::string txt,int time);
};
#endif