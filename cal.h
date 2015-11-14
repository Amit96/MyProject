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
typedef struct chr{
	char a;
	struct chr * next;
	struct chr * prev;
}chr;
typedef chr *Large_Num;
typedef struct root{
	double rt1;
	double rt2;
}root;
typedef struct eqn_value2{
	double value1, value2;
}eqn_value2;
typedef struct eqn_value3{
	double value1, value2, value3;
}eqn_value3;

double infix(char *s, char *op, double *n, int lenofop, int lenofn);
void nested(char *s);
void reverse(char *);
char * ftoa(double);
void amend(char *, int, int, double);
void checker(char *s);
char *make(char *f, int pos1, int pos2, char *s);
char getnext(char *s);
Large_Num Add_num(Large_Num, Large_Num);
Large_Num Create_num(char *);
Large_Num Multiply_num(Large_Num, Large_Num);
Large_Num Subtract_num(Large_Num, Large_Num);
void Print_num(Large_Num);
root root2(double, double, double);
eqn_value2 lin_eq2(double *);
eqn_value3 lin_eq3(double *);

