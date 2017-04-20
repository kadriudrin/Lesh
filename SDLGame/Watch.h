#ifndef Watch_h
#define Watch_h
struct Clock {
private:
	Uint64 NOW = SDL_GetPerformanceCounter();
	Uint64 LAST = 0;
public:
	float TimeScale = 1.f;
	double rawdt = 0;
	double dt = 0;
	void Tick() {
		LAST = NOW;
		NOW = SDL_GetPerformanceCounter();
		rawdt = (double)((NOW - LAST) / (double)SDL_GetPerformanceFrequency());
		dt = rawdt * TimeScale;
	}
	Clock();
	~Clock();
};
#endif