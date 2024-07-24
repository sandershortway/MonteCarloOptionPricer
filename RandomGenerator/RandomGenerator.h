#pragma once

#include <vector>
#include <random>
#include <cassert>

template <typename T>
class RandomNormalGenerator
{
private:
	std::vector<T> Randoms;
	std::default_random_engine Generator;
	int Seed;

public:
	// TODOSK also add constructor which uses the current time as seed
	RandomNormalGenerator(const int Size, const int Seed);

	size_t Size() const;

	double Get(const int Index) const;

	void Correlate(const RandomNormalGenerator& Other, const T Rho);
};