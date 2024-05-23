#include "Models.h"

BlackScholes::BlackScholes(double Sigma) : Sigma(Sigma) {};

double BlackScholes::ComputeNextVolatility()
{
	return Sigma;
}

SABR::SABR(double Alpha, double Beta, double Rho, double Nu) : Alpha(Alpha), Beta(Beta), Rho(Rho), Nu(Nu) {};