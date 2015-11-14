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


