/*****************************************************************************
 * Copyright (C) Amit D.K. kamthead14.it@gmail.com
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "cal.h"
void print0() { /*Prints the options to be selected at the beginning*/
		printf("****************************************************************************\n");
		printf("\t\t1. Evaluate an expression\n");
		printf("\t\t2. Perform operations on large integers\n");
		printf("\t\t3. Find roots of quadratic equation\n");
		printf("\t\t4. Solve linear equations\n");
		printf("\t\t5. Exit\n");
		printf("****************************************************************************\n");
	}
void print1() { /*Prints the operations to be performed on Large integers*/ 
		printf("____________________________________________________________________________\n\n");
		printf("\t\t1. Add Integers\n");
		printf("\t\t2. Subtract Integers\n");
		printf("\t\t3. Multiply Integers\n");
		printf("\t\t4. Exit\n");
		printf("____________________________________________________________________________\n");
	}
void print2() { /*Prints the options for solving linear equations*/
		printf("\t\t1. Equation in two variables\n");
		printf("\t\t2. Equation in three variables\n");
	}
main(int argc, char *argv[]) {
	int choice2, select;
	char s[100];
	Large_Num get1;
	Large_Num get2;
	Large_Num get3;
	root root1;
	eqn_value2 eqn;
	eqn_value3 eq3;
	double eqn2[6], eqn3[12];
	double  a, b, c, bm = 0;
	char t[100], f[100];
	int choice, choice1, q;
	int v = 0;
	
	while(1) {
		print0();
		scanf("%d", &choice1);
	
		if(choice1 == 1) {
			printf("\t\t*enter the expression to be evaluated*\n");
			
			getchar();
			printf("\t\t\t");
			scanf("%[^\n]",s);
			bm = expression_eval(s);
			
		}
		else if(choice1 ==  2) {
			printf("\t\tEnter the first integer\n\t\t");
			
			scanf("%s", s);
			printf("\t\tEnter the second integer\n\t\t");
			
			scanf("%s", t);
			get1 = Create_num(s);
			get2 = Create_num(t);
		
			while(1) {
				if(v == 1) {
					printf("\t\t1. Enter a new Integer to perform an operation with the previous answer\n");
					printf("\t\t2. Exit\n");
					
					v = 0;
					scanf("%d", &select);
					if(select == 1) {
						choice = 5;
						
					}
					else if(select == 2) {
						choice = 4;
					}
				}
				else {
					print1();
					scanf("%d", &choice);
				}
				if(choice == 5) {
					printf("\t\t");
					scanf("%s", f);
					get2 = Create_num(f);
					v = 0;
				
				}
				else if(choice == 1) {
					get1 = Add_num(get1, get2);
				
					if(get1 == NULL) {
						get1 = (Large_Num)malloc(sizeof(chr));
						get1->next = NULL;	
						get1->a = '0';
					}
					printf("\t\tAnswer: ");	
					Print_num(get1);
					v = 1;
				
				}
				else if(choice == 2) {
					get1 = Subtract_num(get1, get2);
					printf("\t\tAnswer: ");
					Print_num(get1);
					v = 1;
				
				}
				else if(choice == 3) {
					get1 = Multiply_num(get1, get2);
					printf("\t\tAnswer: ");
					Print_num(get1);
					v = 1;
				
				}
				else if(choice == 4) {
					break;
				}
			}
			
		}
		else if(choice1 == 3) {
			printf("\t\tEnter the coefficient of x^2\n\t\t");
			scanf("%lf", &a);
			printf("\t\tEnter the coefficient of x^1\n\t\t");
			scanf("%lf", &b);
			printf("\t\tEnter the coefficient of x^0\n\t\t");
			scanf("%lf", &c);
			root1 = root2(a, b, c);
			
			printf("\t\tThe roots are %lf and %lf\n", root1.rt1, root1.rt2);
	
		}
		else if(choice1 == 4) {
			print2();
			scanf("%d", &choice2);
			if(choice2 == 1) {
				printf("\t\tEnter the values of a1, b1, c1, a2, b2, c2 (press enter after \n\t\t each value\n");
				for(q = 0; q < 6; q++) {
					printf("\t\t");
					scanf("%lf", &eqn2[q]);
					
				}
				eqn = lin_eq2(eqn2);
				printf("\t\tThe values of x and y are %lf, %lf\n", eqn.value1, eqn.value2);
			}
			else if(choice2 == 2) {
				printf("\t\tEnter the values of a1, b1, c1, d1, a2, b2, c2, d2, a3, b3, c3,\n\t\t d3 (press enter after each value)\n");
				for(q = 0; q < 12; q++) {
					printf("\t\t");
					scanf("%lf", &eqn3[q]);
				}
				eq3 = lin_eq3(eqn3);
				printf("\t\tThe values of x, y, z are %lf, %lf, %lf\n", eq3.value1, eq3.value2, eq3.value3);
			}
		}
		else if(choice1 == 5) {
			exit(0);
		}
	} 
}
