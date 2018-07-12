#include<stdio.h>
#include<omp.h>
int main () {
	#pragma omp parallel for schedule(dynamic,1) 
	
		for (int i=0; i<8; i++) {
			printf ("thread %d %d\n", omp_get_thread_num(),i);
		}
	
}
