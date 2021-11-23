# Exercises_MPI
Some minor exercises with MPI.

## Compilation
Compile the program by generating a build folder. Run the following code:

    mkdir build
    cd build
    cmake ..
    make ..


## Execution
Then, with no errors present, run the program in parallel:

    mpirun -np 4 bin/compute_pi 10000

You should expect an output like:

    Number of procs:  4
    Number of iterations: 10000
    Computing pi with n = 10000 on 4 processors.
    Result with the Riemann formula (zeta0): pi = 3.14149716395, error = 9.54896425793e-05
    Result with the Machin formula (mach0): pi = 3.14159265359, error = 8.881784197e-16

