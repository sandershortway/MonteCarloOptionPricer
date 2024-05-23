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
	explicit RandomNormalGenerator(const int Size, const int Seed);

	void Resize(const int NewSize);

	void Generate();

	int Size() const;

	double Get(const int Index) const;
};