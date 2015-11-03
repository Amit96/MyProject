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

