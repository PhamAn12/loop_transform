#include<stdio.h>
#include<omp.h>

int main () {
	#pragma omp parallel
	{
		printf ("ancanan\n");
	}
	printf ("Program exit\n");
	
}
