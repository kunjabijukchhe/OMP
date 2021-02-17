#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define PARENT_TID 0

int main() {
  int tid;
  omp_set_num_threads(4);
  #pragma omp parallel
  {
    tid = omp_get_thread_num();
    if(tid == PARENT_TID)
      printf("Main: %d threads running\n", omp_get_num_threads());
    else
      printf("Child# %d: running\n", tid);
  }
  return EXIT_SUCCESS;
}
