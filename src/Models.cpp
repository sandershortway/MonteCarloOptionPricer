#include "Models.h"

double VolatilityModel::GetCurrentVolatility() { return Volatility; }

VolatilityModel::VolatilityModel(double InitialVol) { Volatility = InitialVol; }

DeterministicModel::DeterministicModel(double InitialVol) : VolatilityModel(InitialVol) {};

StochVolModel::StochVolModel(double InitialVol) : VolatilityModel(InitialVol) {};

Heston::Heston(double InitialVol, double MeanReversionSpeed, double LongTermVariance, double VolVol, double Correlation)
	:
	StochVolModel(InitialVol),
	MeanReversionSpeed(MeanReversionSpeed),
	LongTermVariance(LongTermVariance),
	VolVol(VolVol),
	Correlation(Correlation) {};

double Heston::ComputeNextVolatility(double VolNormal)
{
	return VolNormal;
}

BlackScholes::BlackScholes(double InitialVol, double Sigma) : Sigma(Sigma), DeterministicModel(InitialVol) {};

double BlackScholes::ComputeNextVolatility()
{
	return Sigma;
}

//SABR::SABR(double Alpha, double Beta, double Rho, double Nu) : Alpha(Alpha), Beta(Beta), Rho(Rho), Nu(Nu) {};
//
//double SABR::ComputeNextVolatility(double VolNormal)
//{
//	return VolNormal;
//}