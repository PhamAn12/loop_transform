#include<stdio.h>
#include<omp.h>

int main () {
	
	int tid;
	omp_set_num_threads(4);
	#pragma omp parallel private(tid)
	{
 		tid = omp_get_thread_num();
 		#pragma omp master
			{
 				printf("Only thread %d doing this part\n",tid);
			}
 			//	printf("Thread %d doing this part\n",tid);
	}
}
