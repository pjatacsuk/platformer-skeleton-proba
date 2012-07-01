#ifndef INC_MYTIMER_H
#define INC_MYTIMER_H
#include <SDL.h>


struct MyTimer {
	int		StartTick;
	int		Time;

	MyTimer(int time):
	Time(time),
	StartTick(0){

	}

	void StartTimer() {
		StartTick = SDL_GetTicks();
	}
	int GetTicks() {
		return SDL_GetTicks() - StartTick;
	}
	bool End() {
		int current = SDL_GetTicks();
		if(current - StartTick > Time) {
			return true;
		} else return false;
	}
	bool is_started() {
		return StartTick != 0;
	}
	
};
#endif