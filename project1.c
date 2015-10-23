#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
//char g[15];
double infix(char *s, char *op, double *n, int lenofop, int lenofn);
void nested(char *s);
void reverse(char *);
char * ftoa(double);
void amend(char *, int, int, double);
//static int i= 0;

int y =0;
char *make(char *f, int pos1, int pos2, char *s);
/*int len(char *s) {  //function to calculate the length of the input string

	while(*(s++) != '\0') {
		(i++);
	}

	return i;
}*/

char getnext(char *s) {    //function to get the next token. this function cannot distinguish        between numbers operators and spaces
	static char *p;

if(y==0) {

	p=s;
y++;
}

	char x=*(p++);
	return x;
}

double array(char *s) {
	int lenofn,lenofop;
	int ne = 1;
	char gh[15];
	int num=0,j= 0,k=0,o=0,n1, b=0;
	int i = strlen(s);
	double n[50];
	char op[50];
	y = 0;
char x= getnext(s);

while(j < i) {
	if((x == '-') && (ne == 1)) {
		gh[k++] = '-';
		ne = 0;
		x = getnext(s);
	}
	while((x>=48 && x<=57) || (x == '.')) {
	gh[k++] = x;
	x=getnext(s);
	

}
gh[k] = '\0';

if(x== '+' || x=='-' || x =='*' || x=='/') {
op[b++]=x;
ne = 1;
}



if(k != 0) {
n[o++]=atof(gh);

k=0;
}


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
printf("%s\n", op);
double bt;
bt = infix(s, op, n, lenofop, lenofn);
return bt;
}

main() {
int t;
double bm;
	char s[100];
	scanf("%[^\n]", s);
	checker(s);
	nested(s);
	bm = array(s);
	printf("Final ans: %lf\n", bm);
//for make()...value of pos1 and pos2 are start and end of string....whereas for amend()...pos2 = po2+ 1.
	//int length = len(s);
	

}
void nested(char *s) {
	int j = 0;
	char *f;
	int pos1, pos2;
	double b;
	int num = 1;
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
	printf("%d %d\n", pos1, pos2);
	f = make(f, pos1, pos2, s);
	printf("%s\n", f);
	b = array(f);
	//amend
		printf("%lf\n", b);
	amend(s, pos1 - 1, pos2 + 2, b);
	j = 0;
	printf("%s\n", s);

	printf("here");
	while(s[j] != '\0') {
		if(s[j] == '(') {
			num++;
		}
		
		j++;
	}
	
	}
	//check the number of '('
	//and the outer most while loop condition will be (till number of '(' != 0)
	printf("ans :%lf", b);

}	

double infix(char *s, char *op, double *n, int lenofop, int lenofn) {
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
return n[0];

}
char *make(char *f, int pos1, int pos2, char *s) {
	
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

char * ftoa(double ans) {
	int count = 0;
	char *g;
	g = (char *)malloc(15);
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

void reverse(char l[]) {
	int c, i, j;
	for(i = 0, j = strlen(l) - 1; i < j; i++, j--) {
		c = l[i];
		l[i] = l[j];
		l[j] = c;
	}
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

void amend(char *s, int type, int pos, double ans) {  //this function amends the original string by substituting the values of different math functions
	int i, j = 0;
	char *f;
	
	char nm[50];
        f = ftoa(ans);
	printf("value of f:%s\n", f);
	int k = strlen(s);
	for(i = pos; i < k; i++) {
		nm[j++] = s[i];
	}
	nm[j] = '\0';
	s[type] = '\0';
	strcat(s, f);
	strcat(s, nm);
	printf("amend:%s\n", s);
	
	
}	


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
		printf("%d %d\n", type, pos);
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
	u = 0;
	while(*o != '\0') {
		
		if(u == 1) {
			break;
		}
            
		if(*o == 's' && *(o + 1) == 'i' && *(o + 2) == 'n') {    //it checks the occurence of log function      

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
		ans = sin(p1);
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
	u = 0;
	while(*o != '\0') {
		
		if(u == 1) {
			break;
		}
            
		if(*o == 'c' && *(o + 1) == 'o' && *(o + 2) == 's') {    //it checks the occurence of log function      

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
		ans = cos(p1);
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
	u = 0;
		while(*o != '\0') {
		
		if(u == 1) {
			break;
		}
            
		if(*o == 't' && *(o + 1) == 'a' && *(o + 2) == 'n') {    //it checks the occurence of log function      

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
		ans = tan(p1);
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
	u = 0;
			while(*o != '\0') {
		
		if(u == 1) {
			break;
		}
            
		if(*o == 'e' && *(o + 1) == 'x' && *(o + 2) == 'p') {    //it checks the occurence of log function      

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
		ans = exp(p1);
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
	u = 0;
				while(*o != '\0') {
		
		if(u == 1) {
			break;
		}
            
		if(*o == 's' && *(o + 1) == 'q' && *(o + 2) == 'r' && *(o + 3) == 't') {    //it checks the occurence of log function      

			 u = 1;
			type = pos;

			found = 1;
			pos = pos + 4;
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
		ans = sqrt(p1);
	printf("%lf\n", ans);
		amend(s, type, pos, ans);
	printf("%s\n", s); 
	
	
		
			if(*(o + 3) == '\0') {
				
				pos = 0;
				break;
			}
		}
		pos++;
		
		o++;
		
	}
}
