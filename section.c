#include<stdio.h>
#include<omp.h>

int main () {
	
	int tid;
	omp_set_num_threads(4);
	#pragma omp parallel private(tid) 
	
	{
		tid = omp_get_thread_num();
		#pragma omp sections
		{
			#pragma omp section
			{
				printf ("thread %d dang chay o section 1a\n",tid);
			//	printf ("thread %d dang chay o section 1b\n",tid);
				
			}
			#pragma omp section
			{
				printf ("thread %d dang chay o section 2\n",tid);
			}
			#pragma omp section
			{
				printf ("thread %d dang chay o section 3\n",tid);
			}
			#pragma omp section
			{
				printf ("thread %d dang chay o section 4\n",tid);
			}
			
		}
	}
} 
