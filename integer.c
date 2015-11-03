#include<stdio.h>
#include<stdlib.h>
#include"cal.h"

Large_Num w;
Large_Num e3;	
Large_Num h3;
Large_Num e4;
Large_Num e5;
Large_Num ans;
Large_Num ans1;
	
char itia(int h) {
	switch(h) {
		case 0 :return '0';
			break;
		case 1 :return '1';
			break;
		case 2 :return '2';
			break;
		case 3 :return '3';
			break;
		case 4 :return '4';
			break;
		case 5 :return '5';
			break;
		case 6 :return '6';
			break;
		case 7 :return '7';
			break;
		case 8 :return '8';
			break;
		case 9 :return '9';
			break;
		default : break ; 
	}
	return 0;
}
int atii(char d) {
	return (d-'0');
}

    

void Print_num(Large_Num hj) {
	Large_Num jk;
	jk = hj;
	while(jk != NULL) {
		printf("%c",jk->a);
		jk= jk->next;
	}
	printf("\n");
}

Large_Num Add_num(Large_Num t1, Large_Num t2) {
	Large_Num temp;


	int neg;
	
	if((t1->a == '-' && t2->a != '-') || (t2->a == '-' && t1->a != '-'))  {
	
		if(t1->a == '-') {
			t1 = t1->next;
			t1->prev = NULL;
			ans = Subtract_num(t2, t1);
			return ans;
		}
		if(t2->a == '-') {
			t2 = t2->next;
			t2->prev = NULL;
			ans = Subtract_num(t1, t2);
			return ans;
		}		
		}
	if(t1->a == '-' && t2->a == '-') {
		neg = 1;
		temp = t1;
		t1 = t1->next;
		t1->prev = NULL;
	
		temp = t2;
		t2 = t2->next;
		t2->prev = NULL;
	
	}
	while(t1->next != NULL) {
		t1= t1->next;
	}
	while(t2->next != NULL) {
		t2= t2->next;
	}
	
	

	
	int sum,sm,cy,a1,a2,a3;



	 
	e3= (Large_Num)malloc(sizeof(chr));
	
	
	e3->a= '0';
	e3->next=NULL;
	while((t1 != NULL) || (t2 != NULL)) {
		if(t1 != NULL) {
			a1=atii(t1->a);
		}
		if(t2 != NULL) {
			a2 = atii(t2->a);
		}
 		a3= atii(e3->a);

		if((t1 != NULL) && (t2 != NULL)) {
			sum = ((a1) + (a2) + (a3));

		}
		if(t1 == NULL) {
			sum = ((a2) + (a3));

		}
		else if(t2 == NULL) {
			sum = ((a1) + (a3));
		}
		sm = sum%10;
		cy = sum/10;
	

		e3->a=itia(sm);

		e3->prev= (Large_Num)malloc(sizeof(chr));
		e3->prev->next=e3;
		e3=e3->prev;
	

		e3->a=itia(cy);
		if(t1 != NULL) {
	
			t1=t1->prev;

		}
		if(t2 != NULL) {
	
			t2= t2->prev;
		}
	
	}

	e3->prev=NULL;
	
	if(neg == 1) {
		e3->prev = (Large_Num)malloc(sizeof(chr));
		e3->prev->next = e3;
		e3 = e3->prev;
		e3->a = '-';
		e3->prev = NULL;
	}


	return e3;

}

Large_Num Create_num(char * s) {
	
	

	w = (Large_Num)malloc(sizeof(chr));
	w->prev=NULL;


	while(*s != '\0') {
	
	
	
		w->a=*s;
		w->next=(Large_Num) malloc(sizeof(chr));;
		w->next->prev=w;
		w=w->next;
		s++;
	}
	Large_Num w1;
	w1= w;
	w = w->prev;
	w->next=NULL;
	free(w1);
	while(w->prev != NULL) {
		w=w->prev;
	}
	return w;


}



Large_Num Multiply_num(Large_Num e1, Large_Num e2) {
	
	Large_Num temp;
	int neg;
	int length1 = 0, length2 = 0, i;
	if((e1->a == '-' && e2->a != '-') || (e2->a == '-' && e1->a != '-')) {
		neg = 1;
		if(e1->a == '-' ) {

			temp = e1;
			e1 = e1->next;
			e1->prev = NULL;
	
		}
		if(e2->a == '-') {
	
			temp = e2;
			e2 = e2->next;
			e2->prev = NULL;
	
		}
	}
	if(e1->a == '-' && e2->a == '-' ) {
		temp = e1;
		e1 = e1->next;
		e1->prev = NULL;
		
		temp = e2;
		e2 = e2->next;
		e2->prev = NULL;
		
	}
	
	while(e1->next != NULL) {
		e1= e1->next;
		length1++;
	}
	while(e2->next != NULL) {
		e2= e2->next;
		length2++;
	}
	
	h3 = (Large_Num)malloc(sizeof(chr));
	h3->next = NULL;
	h3->a = '0';
	if(length1 >=  length2) {
		for(i = 0;i <= length1 * 2 + 1; i++) {
			h3->prev = (Large_Num)malloc(sizeof(chr));
			h3->prev->next = h3;
			
			h3 = h3->prev;
			h3->a = '0';
			h3->prev = NULL;
		}
		
		
	}
	else {
		for(i = 0;i <= length2 * 2 + 1; i++) {
			h3->prev = (Large_Num)malloc(sizeof(chr));
			h3->prev->next = h3;
			
			h3 = h3->prev;
			h3->a = '0';
			h3->prev= NULL;
		}
	
		
	}
		
			
			
			 
	int sum,sm,cy,a1,a2,a3, j = 0;



	Large_Num f3;
	
	
	f3 = e1;
	while(e2 != NULL) {
		e4= (Large_Num)malloc(sizeof(chr));
		e4->a= '0';
		e4->next=NULL;
		for(i = 0; i < j; i++) {
	
			e4->prev = (Large_Num)malloc(sizeof(chr));
			e4->prev->next = e4;
			
			e4 = e4->prev;
			e4->a = '0';
			e4->prev = NULL;
		}
		
		if(e2 != NULL) {
 				a2 = atii(e2->a);
		}
		e1 = f3;
		while(e1 != NULL) {
			if(e1 != NULL) {
				a1=atii(e1->a);
			}
			
 			a3= atii(e4->a);

			if((e1 != NULL)) {
				sum = ((a1) * (a2) + (a3));

			}
			
			
			sm = sum%10;
			cy = sum/10;
	
			e4->a=itia(sm);

			e4->prev= (Large_Num)malloc(sizeof(chr));
			e4->prev->next=e4;
			e4=e4->prev;
	

			e4->a=itia(cy);
			if(e1 != NULL) {

				e1=e1->prev;
			}
		}	
	
	
		
		if(e2 != NULL) {
			j++;
			e2 = e2->prev;
		
		}
		e4->prev=NULL;

		e4=e4->next;
	
                h3 =  Add_num(e4,h3);
		
	}
	

	while(h3->prev != NULL) {
		h3 = h3->prev;
	} 
	Large_Num tmp;

	while(h3->a == '0') {
		tmp = h3;
		h3= h3->next;
		free(tmp);
		}
		h3->prev = NULL;
	if(neg == 1) {
		h3->prev = (Large_Num)malloc(sizeof(chr));
		h3->prev->next = h3;
		h3 = h3->prev;
		h3->a = '-';
		h3->prev =NULL;
	}

		
	
	



	
	return h3;

}

Large_Num Subtract_num(Large_Num e1, Large_Num e2){
	int length1=1, length2=1, e1isb = 0, e2isb = 0, i;
        Large_Num tempi;

	if(e1->a == '-' && e2->a != '-') {
			e2->prev = (Large_Num)malloc(sizeof(chr));
			e2->prev->next = e2;
			e2 = e2->prev;
			e2->a = '-';
			e2->prev = NULL;
			ans1 = Add_num(e1, e2);
			return ans1;
		}
		if(e1->a != '-' && e2->a == '-') {
			tempi = e2;
			e2 = e2->next;
			e2->prev = NULL;
			
			ans1 = Add_num(e1, e2);
			return ans1;
		}
		if(e1->a == '-' && e2->a =='-') {
			tempi = e2;
			e2 = e2->next;
			e2->prev = NULL;
			
			tempi = e1;
			e1 = e1->next;
			e1->prev = NULL;
			
			ans1 = Subtract_num(e2, e1);
			
			return ans1;
	
		
		}
			


	Large_Num t1;
	Large_Num t2;
	Large_Num temp;
	t1 = e1;
	t2 = e2;
	while(e1->next != NULL) {
		e1 = e1->next;
		length1++;
	}
	while(e2->next != NULL) {
		e2 = e2->next;
		length2++;
	}
	
	if(length1 > length2) {
		e1isb =1;
	}
	else if(length1 < length2) {
		e2isb = 1;
	}
	
	if(length1 == length2) {
		e1isb = e2isb = 0;
	}
	e1 = t1;
	e2 = t2;
	
	if(e1isb == 1) {
		for(i = 0; i < length1 - length2; i++) {
			e2->prev = (Large_Num)malloc(sizeof(chr));
			e2->prev->next = e2;
			e2 = e2->prev;
			e2->a = '0';
 			e2->prev = NULL;
		}
	}
	
	if(e2isb == 1) {
		for(i = 0; i < length2 - length1; i++) {
			e1->prev = (Large_Num)malloc(sizeof(chr));
			e1->prev->next = e2;
			e1 = e1->prev;
			e1->a = '0';
 			e1->prev = NULL;
		}
	}
	e1 = t1;
	e2 = t2;
	if(length1 == length2) {

		while(e1->next != NULL) {
			if(e1->a > e2->a) {
				e1isb = 1;
				break;
			}
			else if(e2->a > e1->a) {
				e2isb = 1;
				break;
			}
		e1 = e1->next;
		e2 = e2->next;
		}
	}

	
	e5= (Large_Num)malloc(sizeof(chr));
	
	int a1, a2, a3, diff, bw;	
	e5->a= '0';
	e5->next=NULL;
	while((e2->next != NULL)) {
		e2 = e2->next;
		
	}

	while((e1->next != NULL)) {
		e1 = e1->next;
		
	}
	
	if(e2isb == 1) {
		temp = e1;
		e1 = e2;
		e2 = temp;
	
	}

	while((e1 != NULL) || (e2 != NULL)) {
		if(e1 != NULL) {
			a1=atii(e1->a);
		}
		if(e2 != NULL) {
 			a2 = atii(e2->a);
		}
 		a3= atii(e5->a);

		if((a1 > a2) || ((a1 == a2) && a3 == 0)) {
			diff = a1 - a2 - a3;
               		bw = 0;
		}
		if(a1 < a2) {
			diff = (10 + a1) - a2 - a3;
			bw = 1;
		}
		if((a1 == a2) && (a3 == 1)) {
			diff = (10 + a1) - a2 - a3;
			bw = 1;
		}	
		e5->a = itia(diff);

		e5->prev= (Large_Num)malloc(sizeof(chr));
		e5->prev->next=e5;
		e5=e5->prev;
	

		e5->a=itia(bw);
		if(e1 != NULL) {
	
			e1=e1->prev;

		}
		if(e2 != NULL) {
	
			e2= e2->prev;
		}
		
	}

	if(e2isb == 1) {
	
		e5->prev = (Large_Num)malloc(sizeof(chr));
		e5->prev->next = e5;
		e5 = e5->prev;
		e5->a = '-';
		e5->prev = NULL;
	}
	else {
		e5 = e5->next;
		e5->prev=NULL;
	
	}
	return e5;
}
	

	
	
