#include<stdio.h>
#define SIZE 10
typedef struct {
   int    x;
   int    y;
} point;

int parallware__root(){
	int sum=0;
	int a_x = 0;
	point a;
#pragma omp parallel for reduction(+:sum,a_x)
	for(int i=0;i<SIZE;i++){
		
		a.x=3;
		a.y=4;
		a_x +=4;
		sum=sum+a.x+a.y;
	}
	a.x = a_x;
	return sum + a.x;
}
int main () {
	printf ("%d",parallware__root());
}
