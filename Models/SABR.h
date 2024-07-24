
#pragma once

#include "Base.h"

class SABR : public VolatilityBase
{
private:
	double alpha;
	double beta;
	double rho;
	double volvol;

public:
	double Get(const double CorrelatedNormal) override
	{
		// TODOSK compute next step
		return 0.15;
	}
};