
#include <iostream>

#include "RandomGenerator.h"

int main()
{
    int NumberOfPaths = 100000;
    int NumberOfSteps = 1000;
    double Maturity = 1.0;
    double Dt = Maturity / NumberOfSteps;
    double InitialStockPrice = 100;
    double InitialVariance = 0.15;
    double Strike = 80;

    double Kappa = 0.5;
    double Vbar = 0.15;
    double Zeta = 0.5;
    double R = 0.03;
    double Rho = 0.5;

    //RandomNormalGenerator<double> A{ NumberOfPaths, 123 };
    //RandomNormalGenerator<double> B{ NumberOfPaths, 321 };
    //B.Correlate(A, Rho);
    //
    //std::cout << "A = np.array([";
    //for (size_t i = 0; i < NumberOfPaths-1; i++)
    //{
    //    std::cout << A.Get(i) << ",";
    //}
    //std::cout << A.Get(NumberOfPaths - 1) << "])" << std::endl;
    //
    //std::cout << "B = np.array([";
    //for (size_t i = 0; i < NumberOfPaths - 1; i++)
    //{
    //    std::cout << B.Get(i) << ",";
    //}
    //std::cout << B.Get(NumberOfPaths - 1) << "])" << std::endl;


    RandomNormalGenerator<double> StockPriceNormals{ NumberOfPaths * NumberOfSteps, 123 };
    RandomNormalGenerator<double> VolPathNormals{ NumberOfPaths * NumberOfSteps, 999 };
    StockPriceNormals.Correlate(VolPathNormals, Rho);
    
    std::vector<double> StockPrice(NumberOfPaths, InitialStockPrice);
    std::vector<double> Variance(NumberOfPaths, InitialVariance);
    
    for (size_t StepIdx = 1; StepIdx < NumberOfSteps; StepIdx++)
    {
        for (size_t PathIdx = 0; PathIdx < NumberOfPaths; PathIdx++)
        {
            int NormalIdx = StepIdx * NumberOfPaths + PathIdx;
            double VarPositivePart = std::max(Variance.at(PathIdx), 0.0);
    
            Variance.at(PathIdx) += Kappa * (Vbar - VarPositivePart) * Dt
                + Zeta * std::sqrt(VarPositivePart * Dt) * VolPathNormals.Get(NormalIdx);
    
            StockPrice.at(PathIdx) *= std::exp(
                (R - 0.5 * Variance.at(PathIdx)) * Dt
                + std::sqrt(std::max(Variance.at(PathIdx), 0.0) * Dt) * StockPriceNormals.Get(NormalIdx)
            );
        }
    }
    
    double Sum = 0.0;
    
    for (double ST : StockPrice)
    {
        Sum += std::max(ST - Strike, 0.0);
    }
    
    std::cout << std::exp(-R * Maturity) * Sum / NumberOfPaths << std::endl;

    return 0;
}