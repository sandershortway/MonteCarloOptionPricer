
#pragma once

#include "math.h"

// TODOSK move into seperate files

// VolatilityBase : Base class for Stochastic Volatility models

class VolatilityBase
{
protected:

	double InitialVol;
	double CurrentVol;

public:

	VolatilityBase(double InitialVol) : InitialVol(InitialVol), CurrentVol(InitialVol) {}
	virtual double Get(const double CorrelatedNormal) = 0;
	double GetIntial() { return InitialVol; }
};