#pragma once

class VolatilityModel
{
private:
	double Volatility;

public:
	VolatilityModel(double InitialVol);
	double GetCurrentVolatility();
};

class DeterministicModel : public VolatilityModel
{
public:
	DeterministicModel(double InitialVol);
	virtual double ComputeNextVolatility() = 0;
};

class StochVolModel : public VolatilityModel
{
public:
	StochVolModel(double InitialVol);
	virtual double ComputeNextVolatility(double VolNormal) = 0;
};

class BlackScholes : public DeterministicModel
{
	double Sigma;

public:
	BlackScholes(double InitialVol, double Sigma);
	double ComputeNextVolatility() override;
};

class Heston : public StochVolModel
{
	double MeanReversionSpeed;
	double LongTermVariance;
	double VolVol;
	double Correlation;

public:
	Heston(double InitialVol, double MeanReversionSpeed, double LongTermVariance, double VolVol, double Correlation);
	double ComputeNextVolatility(double VolNormal) override;
};

//class SABR : public StochVolModel
//{
//	double Alpha;
//	double Beta;
//	double Rho;
//	double Nu;
//
//public:
//	SABR(double Alpha, double Beta, double Rho, double Nu);
//	double ComputeNextVolatility(double VolNormal) override;
//};