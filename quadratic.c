#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include "cal.h"
root root2(double a, double b, double c) {/*solves a quadratic equation with coefficients a, b, c and returns a structure "root1" that contains the value of the roots*/
	root root1;
	double det, ans; 
	det = b * b - 4 * a * c;
	ans  = sqrt(det);
	root1.rt1 = (-b + ans) / (2.0 * a);
	root1.rt2 = (-b - ans) / (2.0 * a);
	return root1;
}


