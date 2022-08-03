#pragma once
#include<random>
namespace livewire
{
	inline void seedRandom(int seed) { srand(seed); }

	inline int random() { return rand(); }
	inline int random(int max) { return rand() % (max+1); }//exclusive
	inline int random(int min, int max) { return min + rand() % (max+1 - min) ; }

	inline float randomf() { return rand() / (float)RAND_MAX; }
	inline float randomf(float max) { return randomf() * max; }//exclusive
	inline float randomf(float min, float max) { return min + randomf(max - min); }
}