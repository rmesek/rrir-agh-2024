#include <gsl/gsl_integration.h>
#include <gsl/gsl_linalg.h>
#include <gsl/gsl_matrix.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Material property E(x)
double E(double x) { return (x < 1.0) ? 3.0 : 5.0; }

// Basis function phi_i
double phi(int i, int n, double x) {
  double h = 2.0 / (n - 1);
  double xi = i * h;
  if (x >= xi - h && x <= xi) {
    return (x - (xi - h)) / h;
  } else if (x >= xi && x <= xi + h) {
    return ((xi + h) - x) / h;
  }
  return 0.0;
}

// Derivative of basis function phi_i
double dphi(int i, int n, double x) {
  double h = 2.0 / (n - 1);
  double xi = i * h;
  if (x >= xi - h && x <= xi) {
    return 1.0 / h;
  } else if (x >= xi && x <= xi + h) {
    return -1.0 / h;
  }
  return 0.0;
}

// Gauss-Legendre quadrature points and weights for n=2
const double gauss_points[2] = {-0.577350269189626, 0.577350269189626};
const double gauss_weights[2] = {1.0, 1.0};

// Perform Gauss quadrature integration for matrix element B[i][j]
double gauss_quadrature_integral(int i, int j, int n) {
  double h = 2.0 / (n - 1);
  double integral = 0.0;

  // Integrate over each element
  for (int e = 0; e < n - 1; e++) {
    double x_e = e * h;

    // Gauss quadrature
    for (int q = 0; q < 2; q++) {
      double x = x_e + h / 2 * (gauss_points[q] + 1);
      integral +=
          E(x) * dphi(i, n, x) * dphi(j, n, x) * (h / 2) * gauss_weights[q];
    }
  }

  return integral;
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <number_of_points> <output_file>\n", argv[0]);
    return 1;
  }

  int n = atoi(argv[1]);
  if (n <= 0) {
    fprintf(stderr, "Error: Number of points must be positive\n");
    return 1;
  }

  const char *output_file = argv[2];
  double h = 2.0 / (n - 1);

  // Initialize GSL matrices (with zeros!)
  gsl_matrix *B = gsl_matrix_calloc(n, n);
  gsl_vector *L = gsl_vector_calloc(n);

  // Fill matrix B
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      double integral = gauss_quadrature_integral(i, j, n);
      gsl_matrix_set(B, i, j, integral - E(0) * phi(i, n, 0) * phi(j, n, 0));
    }
  }
  // Set last row for Dirichlet boundary condition
  for (int j = 0; j < n - 1; j++) {
    gsl_matrix_set(B, n - 1, j, 0.0);
  }
  gsl_matrix_set(B, n - 1, n - 1, 1.0);

  // Fill vector L
  // Set first element for Neumann boundary condition
  gsl_vector_set(L, 0, -10.0 * E(0) * phi(0, n, 0));

  // Solve system Bu = L
  gsl_vector *u = gsl_vector_calloc(n);
  gsl_permutation *p = gsl_permutation_alloc(n);
  int signum;
  gsl_linalg_LU_decomp(B, p, &signum);
  gsl_linalg_LU_solve(B, p, L, u);

  // Save results
  FILE *fp = fopen(output_file, "w");
  for (int i = 0; i < n; i++) {
    fprintf(fp, "%.6f %.6f\n", i * h, gsl_vector_get(u, i));
  }
  fclose(fp);

  // Cleanup
  gsl_matrix_free(B);
  gsl_vector_free(L);
  gsl_vector_free(u);
  gsl_permutation_free(p);

  return 0;
}