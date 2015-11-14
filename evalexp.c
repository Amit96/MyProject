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

int y = 0;

char getnext(char *s) {    /*function to get the next token. this function cannot distinguish        between numbers operators and spaces*/
	static char *p;

	if(y==0) {

		p=s;
		y++;
	}

	char x = *(p++);
	return x;
}

double array(char *s) {/*separates the operators and operands of string "s" into two different arrays "op" and "n" and returns a double value i.e. "bt"*/ 
	int lenofn, lenofop;
	int ne = 1;
	char gh[50];
	int num = 0,j = 0,k = 0,o = 0, n1, b = 0;
	int i = strlen(s);
	double n[50];
	char op[50];
	y = 0;
	char x= getnext(s);
	op[0] = '\0';

	while(j < i) {
		if((x == '-') && (ne == 1)) {
			gh[k++] = '-';
			ne = 0;
			x = getnext(s);
		}
		while((x >= '0' && x <= '9') || (x == '.')) {
			gh[k++] = x;
			x = getnext(s);
	

		}
		gh[k] = '\0';

		if(x == '+' || x == '-' || x == '*' || x == '/' || x == '^') {
			op[b++]=x;
			ne = 1;
		}



		if(k != 0) {
			n[o++]=atof(gh);

			k = 0;
		}


		if(x == '\0') {
 			break;
		}
		if((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z')) {
			printf("error");
			return 0;
			break;
		}
		x = getnext(s);


		j++;


	}
	lenofn = o;
	lenofop = b;
	op[b+1] = '\0';
	int q;
	
	double bt;
	
	bt = infix(s, op, n, lenofop, lenofn);
	
	return bt;
}

double expression_eval(char *s) {
	int t = 0, j = 0;
	double bm;
	
	
	while(s[t] != '\0') {
		if(s[t] == '(') {
			j = 1;
		}
		t++;
	}
	if(j == 1) {
		 
		nested(s);
	}
	checker(s);
	t = 0;
	while(t < 6) {
		checker(s);
		t++;
	}
		
	bm = array(s);
	printf("\t\tFinal ans: %lf\n", bm);

	
	return bm;

}
void nested(char *s) {/*evaluates nested brackets of string "s"*/
	int j = 0;
	char *f;
	int pos1, pos2;
	double b;
	int num = 1;
	int v = 0;
	while(num != 0) {
		j = 0;
		pos1 = 0;
		pos2 = 0;
		num = 0;
		while((s[j] != ')') && (s[j] != '\0')) {
			if(s[j] == '(') {
				pos1 = j + 1;;
			}
			j++;
		}
		pos2 = j - 1;
		
		f = make(f, pos1, pos2, s);
		
		checker(f);
		j = 0;
		
		while(f[j] != '\0') {
			if(f[j] == '-' && f[j + 1] == '-') {
				v = j;
				
				while(f[v] != '\0') {
					f[v] = f[v + 2];
					v++;
				}
				f[v] = '\0';
			}
			j++;
		}
		
		b = array(f);
	
		amend(s, pos1 - 1, pos2 + 2, b);
		j = 0;
		
		
		
		while(s[j] != '\0') {
			if(s[j] == '(') {
				num++;
			}
		
			j++;
		}
	
	}
	
	
}	

double infix(char *s, char *op, double *n, int lenofop, int lenofn) {/*evaluates the expressions "s" using array of operators "op" of length "lenofop" and array of operands "n" of length "lenofn"*/
	int i = 0, j = 0, l = 0;
	while(op[i] != '\0') {
	
		if(op[i] == '^') {
			
				n[i] = pow(n[i],n[i+1]);
			
			
			

			for(j = i; j < lenofop - 1; j++) {
  				op[j] = op[j + 1];
				l = 1;

			}
			op[lenofop - 1] = '\0';
			lenofop = lenofop - 1;
			for(j = i; j < lenofn - 1; j++) {
				n[j + 1] = n[j + 2];
			}
			lenofn = lenofn - 1;
		}
		else {
			l = 0;
		}
		if(l != 1) {
			l = 0;
			i++;
		}
	}
	
	i = 0;
	
	while(op[i] != '\0') {
	
		if(op[i] == '*'|| op[i] == '/') {
			if(op[i] == '*') {
				n[i] = n[i] * n[i+1];
			}
			else if(op[i] == '/') {
				n[i] = n[i] / n[i+1];
 			}
			
			for(j = i; j < lenofop - 1; j++) {
  				op[j] = op[j + 1];
				l = 1;

			}
			op[lenofop - 1] = '\0';
			lenofop = lenofop - 1;
			for(j = i; j < lenofn - 1; j++) {
				n[j + 1] = n[j + 2];
			}
			lenofn = lenofn - 1;
		}
		else {
			l = 0;
		}
		if(l != 1) {
			l = 0;
			i++;
		}
	}
	
	i = 0;
	while(op[i] != '\0') {
		if(op[i] == '+' || op[i] == '-') {
			if(op[i] == '+') {
				n[i] = n[i] + n[i+1];
			}
			else if(op[i] == '-') {
				n[i] = n[i] - n[i+1];
			}
			for(j = i; j < lenofop - 1; j++) {
				op[j] = op[j + 1];
				l = 1;

			}
			op[lenofop - 1] = '\0';
			lenofop = lenofop - 1;
			for(j = i; j < lenofn - 1; j++) {
				n[j + 1] = n[j + 2];
			}
			lenofn = lenofn - 1;
		}
		else {
			l = 0;
		}
		if(l != 1) {
			l = 0;
			i++;
		}
	}

	

	
	return n[0];

}
char *make(char *f, int pos1, int pos2, char *s) {/*creates a substring "f" out of existing string "s" from position "pos1" to position "pos2"*/
	
	f = (char *)malloc(pos2 - pos1 + 3);
	int p = pos1;
	int m = 0;
	while(p <= pos2) {
		 f[m++] = s[p];
		p++;
	}
	f[m] = '\0';
	return f;
} 

char * ftoa(double ans) {/*converts a double "ans" into a string "g"*/
	int count = 0;
	char *g;
	g = (char *)malloc(30);
	int j = 0;
	int neg = 0;
	if(ans < 0) {
		ans = ans * -1;
		neg = 1;
	}
	int sd = ans;
	int i = 0;
	char gk[6];
	double po = ans - sd;
	do {
		
		g[i++] = sd % 10 + '0';
	}while((sd /= 10) > 0);
	g[i] = '\0';
	reverse(g);
	 
	g[i++] = '.';
	
        int fg = po * 10000;
	
	i = 0;
	do {
		count++;
		gk[i++] = fg % 10 + '0';
	}while((fg /= 10) > 0);
	if((4 - count) != 0) {
		
		while(j < (4 - count)) {
			
			gk[i] = '0';
			i++;
			j++;
		} 
	}
	gk[i] = '\0';
	
	reverse(gk);
	
	strcat(g, gk);
	
		
	if(neg == 1) {
		i = strlen(g);
		while(i > 0) {
			g[i] = g[i - 1];
			i--;
		}
		g[0] = '-';
	}
	return g; 
	
}

void reverse(char l[]) {/*reverses a string "l"*/
	int c, i, j;
	for(i = 0, j = strlen(l) - 1; i < j; i++, j--) {
		c = l[i];
		l[i] = l[j];
		l[j] = c;
	}
}



void amend(char *s, int type, int pos, double ans) {  /*this function amends the original string "s" by substituting the value "ans" from position "type" to position "pos"*/
	int i, j = 0;
	char *f;
	
	char nm[50];
        f = ftoa(ans);
	
	int k = strlen(s);
	for(i = pos; i < k; i++) {
		nm[j++] = s[i];
	}
	nm[j] = '\0';
	s[type] = '\0';
	strcat(s, f);
	strcat(s, nm);
	
	
	
}	


void checker(char *s) {
	int found = 1;
	int u = 0;
	int h = 0;
	int pos = 0;
	double p1,ans;
	int i = 0;
	char a, b, c;
	int type;
	int no = 0;
	while(h <= 14) {
		char p[50];
		if(h == 0) {
			a = 's';
			b = 'i';
			c = 'n';	
		}
		if(h == 1) {
			a = 'c';
			b = 'o';
			c = 's';	
		}
		if(h == 2) {
			a = 't';
			b = 'a';
			c = 'n';	
		}
		if(h == 3) {
			a = 'l';
			b = 'o';
			c = 'g';	
		}
		if(h == 4) {
			a = 's';
			b = 'q';
			c = 'r';	
		}
		if(h == 5) {
			a = 'e';
			b = 'x';
			c = 'p';	
		}
		if(h == 6) {
			a = 'a';
			b = 's';
			c = 'n';
		}	
		if(h == 7) {
			a = 'a';
			b = 'c';
			c = 'n';
		}
		if(h == 8) {
			a = 'a';
			b = 't';
			c = 'n';
		}
		if(h == 9) {
			a = 's';
			b = 'n';
			c = 'h';
		}
		if(h == 10) {
			a = 't';
			b = 'n';
			c = 'h';
		}
		if(h == 11) {
			a = 'l';
			b = 't';
			c = 'n';
		}
		if(h == 12) {
			a = 'c';
			b = 'e';
			c = 'l';
		}
		if(h == 13) {
			a = 'f';
			b = 'l';
			c = 'r';
		}
		if(h == 14) {
			a = 'c';
			b = 'n';
			c = 'h';
		}
		
		char *o;
		o = s;
		while(*o != '\0') {
		
			if(u == 1) {
				break;
			}
           	 
			if(*o == a && *(o + 1) == b && *(o + 2) == c) {    
	       
				 u = 1;
				type = pos;

				found = 1;
				pos = pos + 3;
				o = s;
			
				if(o[pos] == '(') {
				
					pos++;
				}
				i = 0;
				o = s;
				no = pos;
			
			while(((o[pos] >= '0' && o[pos] <= '9') || (o[pos] == '.') || (o[no] == '-')) && o[pos] != '\0') { 
		
				p[i] = o[pos];
				pos++;
				i++;
			}
			
			
			p[i] = '\0';
			
			if(o[pos] == ')') {
				pos = pos + 1;
	
		
			}
			p1 = atof(p);  
			
			if(h == 0) {
				ans = sin(p1);
			}
			if(h == 1) {
				ans = cos(p1);
			}
			if(h == 2) {
				ans = tan(p1);
			}
			if(h == 3) {
				ans = log(p1);
			}
			if(h == 4) {
				ans = sqrt(p1);
			}
			if(h == 5) {
				ans = exp(p1);
			}
			if(h == 6) {
				ans = asin(p1);
			}
			if(h == 7) {
				ans = acos(p1);
			}
			if(h == 8) {
				ans = atan(p1);
			}
			if(h == 9) {
				ans = sinh(p1);
			}
			if(h == 10) {
				ans = tanh(p1);
			}
			if(h == 11) {
				ans = log10(p1);
			}
			if(h == 12) {
				ans = ceil(p1);
			}
			if(h == 13) {
				ans = floor(p1);
			}
			if(h == 14) {
				ans = cosh(p1);
			}
			
		
			
			amend(s, type, pos, ans);
			
			if(*(o + 2) == '\0') {
				
				pos = 0;
				break;
			}
		}
		pos++;
		
		o++;
		
	}
	h++;
	u = 0;
	pos = 0;
	type = 0;
	i = 0;
	}
}
