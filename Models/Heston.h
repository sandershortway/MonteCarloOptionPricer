
#pragma once

#include "Base.h"

class Heston : public VolatilityBase
{
private:
	double LongTermVariance;
	double MeanReversion;
	double Correlation;
	double VolVol;

public:
	Heston(double InitialVol, double LongTermVariance, double MeanReversion, double Correlation, double VolVol)
		:
		VolatilityBase(InitialVol),
		LongTermVariance(LongTermVariance),
		MeanReversion(MeanReversion),
		Correlation(Correlation),
		VolVol(VolVol)
	{}

	double Get(const double CorrelatedNormal) override
	{
		double Variance = pow(CurrentVol, 2);
		double VarPositivePart = CurrentVol > 0 ? pow(CurrentVol, 2) : 0;
		double DeltaT = 1; // should be defined outside this scope

		//CurrentVol += MeanReversion * (LongTermVariance - PositiveVar) * DeltaT	// drift
		//	+ VolVol * sqrt(PositiveVar) * sqrt(DeltaT) * CorrelatedNormal;		// diffusion

		Variance += MeanReversion * (LongTermVariance - VarPositivePart) * DeltaT	// drift
			+ VolVol * sqrt(VarPositivePart * DeltaT) * CorrelatedNormal;			// diffusion

		CurrentVol = sqrt(Variance);
		
		return CurrentVol;
	}
};