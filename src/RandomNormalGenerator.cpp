#include "RandomNormalGenerator.h"

template <typename T>
RandomNormalGenerator<T>::RandomNormalGenerator(const int Size, const int Seed) : Seed(Seed)
{
    Randoms.resize(Size);
    Generator.seed(Seed);
}

template <typename T>
void RandomNormalGenerator<T>::Resize(const int NewSize)
{
    Randoms.resize(NewSize);
}

template <typename T>
void RandomNormalGenerator<T>::Generate()
{
    assert(Seed != 0);
    std::normal_distribution<T> NormalDistribution(0, 1);

    for (size_t Index = 0; Index < Randoms.size(); Index++)
    {
        Randoms.at(Index) = NormalDistribution(Generator);
    }
}

template <typename T>
int RandomNormalGenerator<T>::Size() const
{
    return Randoms.size();
}

template <typename T>
double RandomNormalGenerator<T>::Get(const int Index) const
{
    return Randoms.at(Index);
}

// Forces creation of these classes for float and double type
template class RandomNormalGenerator<float>;
template class RandomNormalGenerator<double>;