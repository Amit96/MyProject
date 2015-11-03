#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cal.h"
eqn_value2 lin_eq2(double *eqn2) {/*solves a equation in two variables, the eqn is in an array "eqn2" and returns a structure "eqn" with the values of x, y*/
	eqn_value2 eqn;
	double D, Dx, Dy;
	D = (eqn2[0] * eqn2[4]) - (eqn2[1] * eqn2[3]);
	Dx = (eqn2[2] * eqn2[4]) - (eqn2[1] * eqn2[5]);
	Dy = (eqn2[0] * eqn2[5]) - (eqn2[2] * eqn2[3]);
	eqn.value1 = Dx / D;
	eqn.value2 = Dy / D;
	return eqn;
}

eqn_value3 lin_eq3(double *eqn3) {/*solves a equation in three variables, the eqn is in an array "eqn3" and returns a structure "eqn" with the values of x, y, z*/
	eqn_value3 eqn;
	double D, Dx, Dy, Dz;
	D = eqn3[0] * ((eqn3[5] * eqn3[10]) - (eqn3[6] * eqn3[9])) - eqn3[1] * ((eqn3[4] * eqn3[10]) - 			(eqn3[6] * eqn3[8])) + eqn3[2] * ((eqn3[4] * eqn3[9]) - (eqn3[5] * eqn3[8]));

	Dx = eqn3[3] * ((eqn3[5] * eqn3[10]) - (eqn3[6] * eqn3[9])) - eqn3[1] * ((eqn3[7] * eqn3[10]) - 			(eqn3[6] * eqn3[11])) + eqn3[2] * ((eqn3[7] * eqn3[9]) - (eqn3[5] * eqn3[11]));

	Dy = eqn3[0] * ((eqn3[7] * eqn3[10]) - (eqn3[6] * eqn3[11])) - eqn3[3] * ((eqn3[4] * eqn3[10]) - 			(eqn3[6] * eqn3[8])) + eqn3[2] * ((eqn3[4] * eqn3[11]) - (eqn3[7] * eqn3[8]));

	Dz = eqn3[0] * ((eqn3[5] * eqn3[11]) - (eqn3[7] * eqn3[9])) - eqn3[1] * ((eqn3[4] * eqn3[11]) - 			(eqn3[7] * eqn3[8])) + eqn3[3] * ((eqn3[4] * eqn3[9]) - (eqn3[5] * eqn3[8]));

	eqn.value1 = Dx / D;
	eqn.value2 = Dy / D;
	eqn.value3 = Dz / D;
	return eqn;
}
