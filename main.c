#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cal.h"

main(int argc, char *argv[]) {
	char d[10] = "expeval";
	char s[100];
	Large_Num get1;
	Large_Num get2;
	Large_Num get3;
	root root1;
	eqn_value2 eqn;
	eqn_value3 eq3;
	double eqn2[6], eqn3[12];
	double  a, b, c, bm = 0;
	char t[100];
	int choice, choice1, q;
	//printf("hey\n");
	//printf("%s\n", argv[0]);
	void print1() {
		printf("1. Add Integers\n");
		printf("2. Subtract Integers\n");
		printf("3. Multiply Integers\n");
	}
	void print2() {
		printf("1. Equation in two variables\n");
		printf("2. Equation in three variables\n");
	}
	if(strcmp(argv[1], d) == 0) {
		printf("Enter the expression to be evaluated\n");
		scanf("%[^\n]",s);
		bm = expression_eval(s);
		//printf("Ans is: %lf\n", bm);
	}
	strcpy(d, "largenum");
	if(strcmp(argv[1], d) == 0) {
		printf("Enter the first number\n");
		scanf("%s", s);
		printf("Enter the second number\n");
		scanf("%s", t);
		get1 = Create_num(s);
		get2 = Create_num(t);
		print1();
		scanf("%d", &choice);
		if(choice == 1) {
			get3 = Add_num(get1 , get2);
		}
		else if(choice == 2) {
			get3 = Subtract_num(get1, get2);
		}
		else if(choice == 3) {
			get3 = Multiply_num(get1, get2);
		}
		Print_num(get3);
	}
	strcpy(d, "quad");
	if(strcmp(argv[1], d) == 0) {
		printf("Enter the coefficient of x^2\n");
		scanf("%lf", &a);
		printf("Enter the coefficient of x^1\n");
		scanf("%lf", &b);
		printf("Enter the coefficient of x^0\n");
		scanf("%lf", &c);
		root1 = root2(a, b, c);
		
		printf("The roots are %lf and %lf\n", root1.rt1, root1.rt2);
	
	}
	strcpy(d, "lineq");
	if(strcmp(argv[1], d) == 0) {
		print2();
		scanf("%d", &choice1);
		if(choice1 == 1) {
			printf("Enter the values of a1, b1, c1, a2, b2, c2 serially\n");
			for(q = 0; q < 6; q++) {
				scanf("%lf", &eqn2[q]);
			}
			eqn = lin_eq2(eqn2);
			printf("The values of x and y are %lf, %lf\n", eqn.value1, eqn.value2);
		}
		else if(choice1 == 2) {
			printf("Enter the values of a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3, d3 serially\n");
			for(q = 0; q < 12; q++) {
				scanf("%lf", &eqn3[q]);
			}
			eq3 = lin_eq3(eqn3);
			printf("The values of x, y, z are %lf, %lf, %lf\n", eq3.value1, eq3.value2, eq3.value3);
		}
	}
} 
