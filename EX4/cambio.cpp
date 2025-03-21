#include <iostream>

//using namespace std;

/* Tasso di cambio EURO-CHF */
static const double tasso{1.2};

double
convert(double chf)
{
	return chf / tasso;
}

double
convert2(double& chf)
{
	return chf / tasso;
}

int
main(void)
{
	double a, b;
	double *x, *y;
	
	a = 120;
	x = &a;
	y = &b;
	b = convert(*x);
	*y = convert2(b);
	a = 240;
	a = convert(a);

	return 0;
}
