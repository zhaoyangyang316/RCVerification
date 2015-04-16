// RCVerification.cpp : définit le point d'entrée pour l'application console.
//

//#include "stdafx.h"
#include "tools.h"



int main(int argc, _TCHAR* argv[])
{
	Vector cache_pos = Vector(80.0, 0.0, 10.0);
	Vector sample_pos = Vector(80.0, 5.0, 0.0);
	REAL *contrib = new REAL[max_SH_order * max_SH_order];
	Sample_contribution(cache_pos, sample_pos, contrib);

	cout << contrib[62] << endl;

	REAL lower_bound[2];
	REAL upper_bound[2];

	lower_bound[0] = 0.0;
	lower_bound[1] = 0.0;

	upper_bound[0] = 100.0;
	upper_bound[1] = 100.0;
	
	UniformSurfaceSampler *sampler = new UniformSurfaceSampler(lower_bound, upper_bound);
	//ConstantIntegrand *integrand = new ConstantIntegrand();
	ContributionIntegrand *integrand = new ContributionIntegrand(cache_pos, 7, 6);
	Integration_MC<Vector> integrationMC = Integration_MC<Vector>(sampler, integrand, 10000);

	REAL outttt = integrationMC.Run();
	cout << outttt << endl;



	delete[] contrib;
	int whatever;
	cin >> whatever;
	return 0;
}



