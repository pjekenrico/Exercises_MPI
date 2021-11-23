#include <iostream>
#include <math.h>
#include <array>
#include <mpi.h>
#include <iomanip>

#include "funcs.h"

using namespace std;

int main(int argc, char **argv){

    // Initialize MPI
    int n_procs, rank=0;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &n_procs);

      // Handle input arguments
    if (argc < 2)
    {
        if (rank == 0)
        {
            cout << "Please provide a number of total evaluations.\n" << endl;
        }
        exit(1);
    }

    // Retrieve nb of points and make it a multiple of n_procs
    int n = atoi(argv[1]);

    if (n%n_procs != 0)
        n += (n_procs - n%n_procs);

    // Printings
    if (rank == 0)
    {
      cout << "# Number of procs:  " << n_procs << endl;
      cout << "# Number of iterations: " << n << endl;
    }

    int n_per_proc = n / n_procs;
    int* numbers_of_proc = new int[n_per_proc];
    int* numbers_to_eval;

    // Start timing
    double time_start;
    if (rank == 0)
    {
        time_start = MPI_Wtime();

        numbers_to_eval = new int[n];

        for (int i = 0; i < n; i++)
        {
            numbers_to_eval[i] = i + 1;
        }
    }
    
    MPI_Scatter(numbers_to_eval, n_per_proc, MPI_INT, numbers_of_proc, n_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

    double partial_zeta = zeta1(numbers_of_proc, n_per_proc);
    double partial_mach = mach1(numbers_of_proc, n_per_proc);

    double pi_zeta=0.0;
    double pi_mach=0.0;

    MPI_Reduce(&partial_zeta, &pi_zeta, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&partial_mach, &pi_mach, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    pi_zeta = sqrt(pi_zeta);

    if (rank==0)
    {
        // double duration = MPI_Wtime() - time_start;
        const double pi = 4.0*atan(1.0);
        cout << "Computing pi with n = " << n << " on " << n_procs << " processors." << endl;
        cout << setprecision(12);
        cout << "Result with the Riemann formula (zeta0): pi = " << pi_zeta;
        cout << ", error = " << fabs(pi_zeta - pi);
        cout << "\nResult with the Machin formula (mach0): pi = " << pi_mach;
        cout << ", error = " << fabs(pi_mach - pi) << endl;
    }

    MPI_Finalize();

    /*
    if (argc == 2){
        const int n = stoi(argv[1]);
        cout << "Computing pi with n = " << n << endl;
        cout << "Result with the Riemann formula (zeta0): pi = " << zeta0(n);
        cout << "\nResult with the Machin formula (mach0): pi = " << mach0(n) << endl;
    } else {
        cout << "Please provide one integer denoting the length of the summation." << endl;
    }
    
    // Convergence study
    
    uint n = 2;
    cout << "\nConvergence study" << endl;
    cout << "N\terr(Riemann)\terr(Machin)" << endl;
    for(int i = 0; i < 10; i++){
        cout << n << "\t";
        cout << fabs( M_PI - zeta0(n) ) << "\t";
        cout << fabs( M_PI - mach0(n) ) << endl;
        n *= 2;
    }
    */
}