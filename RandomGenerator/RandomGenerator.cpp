#include "RandomGenerator.h"

template <typename T>
RandomNormalGenerator<T>::RandomNormalGenerator(const int Size, const int Seed) : Seed(Seed)
{
    Randoms.resize(Size);
    Generator.seed(Seed);

    assert(Seed != 0);
    std::normal_distribution<T> NormalDistribution(0, 1);

    for (size_t Index = 0; Index < Randoms.size(); Index++)
    {
        Randoms.at(Index) = NormalDistribution(Generator);
    }
}

template <typename T>
size_t RandomNormalGenerator<T>::Size() const
{
    return Randoms.size();
}

template <typename T>
double RandomNormalGenerator<T>::Get(const int Idx) const
{
    return Randoms.at(Idx);
}

template<typename T>
void RandomNormalGenerator<T>::Correlate(const RandomNormalGenerator& Other, const T Rho)
{
    assert(Size() == Other.Size());
    
    double AltRho = sqrt(1 - pow(Rho, 2));

    for (int Idx = 0; Idx < Size(); Idx++)
    {
        Randoms.at(Idx) = Rho * Other.Get(Idx) + AltRho * Randoms.at(Idx);
    }
}

// forces creation of these classes for float and double type
template class RandomNormalGenerator<float>;
template class RandomNormalGenerator<double>;