#include<stdio.h>
#include<omp.h>
int totalParallel(int number) {
  long long total = 1;
#pragma omp parallel for reduction(+:total) //share (total) private(i)

  for(long long i=1; i<=number; ++i)
    total += i;
  return total;
}

int totalSerial(int number) {
  long long total = 1;
  for(long long i=1; i<=number; ++i)
    total += i;
  return total;
}
void compare (int number) {
	double start_time;

    
    start_time = omp_get_wtime();
    totalSerial(number);
    double timeSer = omp_get_wtime() - start_time;
    start_time = omp_get_wtime();
    totalParallel(number);
    double timePal = omp_get_wtime() - start_time;
    
    printf ("%10d %lf %lf\n",number,timeSer,timePal);

}
int main () {

printf ("   Number  serial   parallel\n");
    compare(900000000);
    compare(90000000);
    compare(9000000);
    compare(900000);
    compare(90000);
    compare(9000);
    compare(900);

}
