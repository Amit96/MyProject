#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
char g[15];
void reverse(char *);
char * ftoa(double);
void amend(char *, int, int, double);
int checker(char *s) { 
	int found = 1;
	int u;
	int pos = 0;
	char p[8];
	double p1,ans;
	int i = 0;
	int type;
	char *o;
	o = s;
	while(*o != '\0') {
		if(u == 1) {
			break;
		}
            
		if(*o == 'l' && *(o + 1) == 'o' && *(o + 2) == 'g') {    //it checks the occurence of log function
			 u = 1;
			type = pos;

			found = 1;
			pos = pos + 3;
			o = s;
			
				
			if(o[pos] == '(') {
				
				pos++;
			}
	
			
			while((o[pos] >= 48 && o[pos] <= 57) || (o[pos] == '.')) {  //this takes the value occuring in front of log
				p[i] = o[pos];
				pos++;
				i++;
		}
		p[i] = '\0';
		
		if(o[pos] == ')') {
			pos = pos + 1;
	
		
		}
	p1 = atof(p);   //converts p to double for usage in math.h log function
		ans = log(p1);
	printf("%lf\n", ans);
		amend(s, type, pos, ans);
	printf("%s\n", s); 
	
	
		
			if(*(o + 2) == '\0') {
				
				pos = 0;
				break;
			}
		}
		pos++;
		
		o++;
		
	}
	o = s;
	pos = 0;
	while(*o != '\0') {
            
		if(*o == 's' && *(o + 1) == 'i' && *(o + 2) == 'n') {
			type = pos;
			found = 1;
			if(o[pos] == '(') {
				o++;
			}
			while((o[pos] >= 48 && o[pos] <= 57) || (o[pos] == '.')) {
				p[i] = o[pos];
				pos++;
				i++;
			}
			if(o[pos] == ')') {
				pos = pos + 1;
			}
	
			p1 = atof(p);
			ans = log(p1);
			amend(s, type, pos, ans); 
			if(*(o + 2) == '\0') {
				pos = 0;
				break;
			}
		}
		pos++;
		o++;
		
	}
	o = s;
	pos = 0;
	while(*o != '\0') {
            
		if(*o == 'c' && *(o + 1) == 'o' && *(o + 2) == 's') {
			type = pos;
			found = 1;
			if(o[pos] == '(') {
				o++;
			}
			while((o[pos] >= 48 && o[pos] <= 57) || (o[pos] == '.')) {
				p[i] = o[pos];
				pos++;
				i++;
			}
			if(o[pos] == ')') {
				pos = pos + 1;
			}
	
			p1 = atof(p);
			ans = log(p1);
			amend(s, type, pos, ans); 
			if(*(o + 2) == '\0') {
				pos = 0;
				break;
			}
		}
		pos++;
		o++;
		
	}
	o = s;
	pos = 0;
	while(*o != '\0') {
            
		if(*o == 't' && *(o + 1) == 'a' && *(o + 2) == 'n') {
			type = pos;
			found = 1;
			if(o[pos] == '(') {
				o++;
			}
			while((o[pos] >= 48 && o[pos] <= 57) || (o[pos] == '.')) {
				p[i] = o[pos];
				pos++;
				i++;
			}
			if(o[pos] == ')') {
				pos = pos + 1;
			}
	
			p1 = atof(p);
			ans = tan(p1);
			amend(s, type, pos, ans); 
			if(*(o + 2) == '\0') {
				pos = 0;
				break;
			}
		}
		pos++;
		o++;
		
	}
	o = s;
	pos = 0;
	while(*o != '\0') {
            
		if(*o == 'e' && *(o + 1) == 'x' && *(o + 2) == 'p') {
			type = pos;
			found = 1;
			if(o[pos] == '(') {
				o++;
			}
			while((o[pos] >= 48 && o[pos] <= 57) || (o[pos] == '.')) {
				p[i] = o[pos];
				pos++;
				i++;
			}
			if(o[pos] == ')') {
				pos = pos + 1;
			}
	
			p1 = atof(p);
			ans = exp(p1);
			amend(s, type, pos, ans); 
			if(*(o + 2) == '\0') {
				pos = 0;
				break;
			}
		}
		pos++;
		o++;
		
	}
	o = s;
	pos = 0;
	while(*o != '\0') {
            
		if(*o == 's' && *(o + 1) == 'q' && *(o + 2) == 'r' && *(o + 3) == 't') {
			type = pos;
			found = 1;
			if(o[pos] == '(') {
				o++;
			}
			while((o[pos] >= 48 && o[pos] <= 57) || (o[pos] == '.')) {
				p[i] = o[pos];
				pos++;
				i++;
			}
			if(o[pos] == ')') {
				pos = pos + 1;
			}
	
			p1 = atof(p);
			ans = sqrt(p1);
			amend(s, type, pos, ans); 
			if(*(o + 3) == '\0') {
				pos = 0;
				break;
			}
		}
		pos++;
		o++;
		
	}
}
	


void amend(char *s, int type, int pos, double ans) {  //this function amends the original string by substituting the values of different math functions
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

void quadeq( ) { 
	double a, b, c;
	printf("Enter the coefficients (a , b , c) of the quadratic eqn");
	scanf("%lf %lf %lf", &a, &b, &c);
	double det, ans, root1, root2; 
	det = b * b - 4 * a * c;
	ans  = sqrt(det);
	root1 = (-b + ans) / (2.0 * a);
	root2 = (-b - ans) / (2.0 * a);
	printf("First root is %lf\n", root1);
	printf("Second root is %lf", root2);
}	


char * ftoa(double ans) {
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
		
		gk[i++] = fg % 10 + '0';
	}while((fg /= 10) > 0); 
	gk[i] = '\0';
	reverse(gk);
	
	strcat(g, gk);
	return g; 
	
}

void reverse(char l[]) {
	int c, i, j;
	for(i = 0, j = strlen(l) - 1; i < j; i++, j--) {
		c = l[i];
		l[i] = l[j];
		l[j] = c;
	}
}
static int i= 0;
double n[50];
char op[50];
int y =0,lenofn,lenofop;
int len(char *s) {  //function to calculate the length of the input string

	while(*(s++) != '\0') {
		(i++);
	}

	return i;
}

char getnext(char *s) {    //function to get the next token. this function cannot distinguish        between numbers operators and spaces
	static char *p;

if(y == 0) {

	p=s;
y++;
}

	char x=*(p++);
	return x;
}

char array(char *s) {
	int num=0,j= 0,k=0,o=0,n1, b=0;
char x= getnext(s);

while(j < i) {
	while(x>=48 && x<=57) {
	n1= x-'0';
	num=num*10+n1;
	x=getnext(s);
	k++;

}
if(x== '+' || x=='-' || x =='*' || x=='/') {
op[b++]=x;
}



if(k != 0) {
n[o++]=num;

k=0;
}
num=0;

if(x=='\0') {
 break;
}
if((x>=65 && x<=90) || (x>=97 && x<=122)) {
printf("error");
break;
}
x=getnext(s);


j++;


}
lenofn= o;
lenofop=b;
op[b+1] = '\0';
int q;


infix(s);

}

int main() {
int t;
	char s[100];
	printf("Enter the expression to be calculated\n");
	scanf("%[^\n]", s);

	int length = len(s);
	
	array(s);
	


}

int infix(char *s) {
int i =0,j=0,l=0;
	while(op[i] != '\0') {
	
		if(op[i]=='*'|| op[i]=='/') {
if(op[i]=='*') {
			n[i] = n[i] * n[i+1];
}
else if(op[i]=='/') {
n[i] = n[i] /n[i+1];
}
//printf("%d %lf\n",i,n[i]);

for(j= i; j<lenofop-1; j++) {
op[j] =op[j+1];
l=1;

}
op[lenofop-1] = '\0';
lenofop = lenofop-1;
for(j=i;j<lenofn-1;j++) {
n[j+1]=n[j+2];
}
lenofn=lenofn-1;
	}
else {
l=0;
}
if(l!=1) {
l=0;
i++;
}
}
i=0;
while(op[i] != '\0') {
		if(op[i]=='+' || op[i] == '-') {
if(op[i]=='+') {
			n[i] = n[i] + n[i+1];
}
else if(op[i]=='-') {
n[i] = n[i] - n[i+1];
}
for(j= i; j<lenofop-1; j++) {
op[j] =op[j+1];
l=1;

}
op[lenofop-1] = '\0';
lenofop = lenofop-1;
for(j=i;j<lenofn-1;j++) {
n[j+1]=n[j+2];
}
lenofn=lenofn-1;
	}
else {
l=0;
}
if(l!=1) {
l=0;
i++;
}
}

printf("%s",op);

printf("%lf\n", n[0]);

}


			
