// RCVerification.cpp : définit le point d'entrée pour l'application console.
//

//#include "stdafx.h"
#include "tools.cpp"

int main(int argc, _TCHAR* argv[])
{

	Vector v=Vector(1.0,1.0,1.0);
	v = v /0.0f;
	std::cout << "ahhh"<<endl;

	int i;
	cin >> i;
	return 0;
}



