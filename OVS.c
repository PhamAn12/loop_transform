#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<omp.h>

#define NUMBER_OF_THREADS 2  
#define ARR_SIZE1  90000  
#define ARR_SIZE2  60000
#define ARR_SIZE3  600
#define ARR_SIZE4  60
#define ARR_SIZE5  6 
#define DIVIDER   20000
void initArr (int *a,int n) {
	srand (time(NULL));
	for (int i=0 ; i<n ; i++) {
		a[i]= rand()%DIVIDER;	
	}
}
void printArr (int *a,int n) {
	for (int i=0 ; i<n ; i++) {
		printf ("%d ",a[i]);
	}
}
void odd_even_sort (int *a, int n) {
	for (int phase =0; phase <n; phase ++) { 
	
		if (phase %2 == 0) {
			
			for (int i=1; i<n; i+=2) {
				
				if (a[i-1] >a[i]) {
					
					int temp = a[i];
					a[i] = a[i-1];
					a[i-1] = temp;
				}
			}
		}
		else {
			for (int i=1; i<n-1; i++) {
				if (a[i] > a[i+1]) {
					int temp = a[i];
					a[i] = a[i+1];
					a[i+1] = temp;
				}
			}
		}
	}
}
void odd_even_sort_openmp (int *a, int n) {
	int i , temp, phase;
	for ( phase =0; phase <n; phase ++) { 
	
		if (phase %2 == 0) {
			#pragma omp parallel for num_threads(NUMBER_OF_THREADS) shared(a,n) private(i,temp)
			for (int i=1; i<n; i+=2) {
				
				if (a[i-1] >a[i]) {
					
					temp = a[i];
					a[i] = a[i-1];
					a[i-1] = temp;
				}
			}
		}
		else {
			#pragma omp parallel for num_threads(NUMBER_OF_THREADS) shared(a,n) private(i,temp)
			for ( i=1; i<n-1; i++) {
				if (a[i] > a[i+1]) {
					temp = a[i];
					a[i] = a[i+1];
					a[i+1] = temp;
				}
			}
		}
	}
}
double measure_odd_even_sort(int *a, int n) {
	double start = omp_get_wtime();
	odd_even_sort(a,n);
	double end = omp_get_wtime();
	return end- start;
}

double measure_odd_even_sort_openmp(int *a, int n) {
	double start = omp_get_wtime();
	odd_even_sort_openmp(a,n);
	double end = omp_get_wtime();
	return end- start;
}
int main() {
	int a[ARR_SIZE1];
	initArr(a,ARR_SIZE1);
	
	
	printf ("element : %d \nparallel : %lf\nserial : %lf\n",ARR_SIZE5,measure_odd_even_sort(a,ARR_SIZE5),measure_odd_even_sort_openmp(a,ARR_SIZE5));
	printf ("element : %d \nparallel : %lf\nserial : %lf\n",ARR_SIZE4,measure_odd_even_sort(a,ARR_SIZE4),measure_odd_even_sort_openmp(a,ARR_SIZE4));
	printf ("element : %d \nparallel : %lf\nserial : %lf\n",ARR_SIZE3,measure_odd_even_sort(a,ARR_SIZE3),measure_odd_even_sort_openmp(a,ARR_SIZE3));
	printf ("element : %d \nparallel : %lf\nserial : %lf\n",ARR_SIZE2,measure_odd_even_sort(a,ARR_SIZE2),measure_odd_even_sort_openmp(a,ARR_SIZE2));
	printf ("element : %d \nparallel : %lf\nserial : %lf\n",ARR_SIZE1,measure_odd_even_sort(a,ARR_SIZE1),measure_odd_even_sort_openmp(a,ARR_SIZE1));
//	odd_even_sort_openmp(a, ARR_SIZE4);
//	printArr(a,ARR_SIZE4);
	return 0;
}
