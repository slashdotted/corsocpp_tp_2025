#include <iostream>

using namespace std;

/* Tasso di cambio EURO-CHF */
static double tasso{1.2};

double
convert(double chf)
{
	return chf / tasso;
}

void
displayInfo(void)
{
	cout << "CHF\tEUR" << endl;
	cout << tasso << "\t1" << endl;
}

double
iconvert(double eur)
{
	return eur * tasso;
}

int
main(void)
{

	cout << "Tasso 1 EURO = ... CHF: ";
	cin >> tasso;
	
	if (tasso <= 0 || cin.fail()) {
		tasso = 1.20;
		cerr << "Tasso di cambio non valido, uso predefinito " << tasso << endl;
	}
	
	displayInfo();
	
	cout << convert(100.0) << endl;
	cout << iconvert(100.0) << endl;
	 
	return 0;
}
