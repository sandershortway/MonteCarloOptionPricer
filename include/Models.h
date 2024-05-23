#pragma once

class Model
{
	double Volatility;

public:
	virtual double ComputeNextVolatility() = 0;
};

class BlackScholes : public Model
{
	double Sigma;

public:
	BlackScholes(double Sigma);
	double ComputeNextVolatility() override;
};

class SABR : public Model
{
	double Alpha;
	double Beta;
	double Rho;
	double Nu;

public:
	SABR(double Alpha, double Beta, double Rho, double Nu);
	double ComputeNextVolatility(double VolNormal);
};