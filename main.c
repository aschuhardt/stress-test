#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void* do_calc(void* iters) {
  long iterations = (long)iters;
  for (long i = 1; i < iterations; ++i) {
    // determine whether the number is prime
    bool prime = true;
    for (long j = 2; j < i; ++j) {
      (void)(i / j);  // perform a division operation for extra cost
      if (i % j == 0) {
        prime = false;
        break;
      }
    }

    // determine whether the number is one less than a power of two
    if (prime) {
      for (long j = 1; j <= i + 1; j <<= 1) {
        if (i == j - 1) {
          printf("%ld\n", i);
          break;
        }
      }
    }
  }

  pthread_exit(NULL);
}

int main(int argc, const char** argv) {
  if (argc < 3) {
    puts(
        "Must provide two numeric argument (thread count, number of "
        "iterations)\n");
    return -1;
  }

  long thread_count = atol(argv[1]);
  long iterations = atol(argv[2]);

  pthread_t threads[thread_count];
  for (int i = 0; i < thread_count; ++i) {
    pthread_create(&threads[i], NULL, do_calc, (void*)iterations);
  }

  pthread_exit(NULL);
}
