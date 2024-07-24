
#pragma once

class BlackScholes
{
private:
	double Volatility;

public:
	BlackScholes(double VolatilityParameter) : Volatility(VolatilityParameter) {}

	double Get() const
	{
		return Volatility;
	}
};