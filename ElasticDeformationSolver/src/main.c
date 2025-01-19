#include <gsl/gsl_integration.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <number_of_points> <output_file>\n", argv[0]);
    return 1;
  }

  // Parse number of points
  int num_points = atoi(argv[1]);
  if (num_points <= 0) {
    fprintf(stderr, "Error: Number of points must be positive\n");
    return 1;
  }

  // Get output filepath
  const char *output_file = argv[2];

  printf("Using %d points, output will be saved to: %s\n", num_points,
         output_file);

  // TODO: Add your computation code here

  return 0;
}