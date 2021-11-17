#include <iostream>
#include <math.h>
#include <array>

using namespace std;

double myArctan(const double x, const int n){
    double s = x;
    for (int i = 2; i < n; i++){
        if (i % 2 == 1)
            s += pow(x, 2*i-1)/(2*i-1);
        else
            s -= pow(x, 2*i-1)/(2*i-1);
    }
    return s;
}

double zeta0(const int n){

    double s = 1.0;
    double tmp;
    for(int i = 2; i < n; i++){
        tmp = 1./i;
        s += tmp*tmp;
    }
        

    return sqrt(6*s);
}

double mach0(const int n){
    double a = myArctan(0.2, n);
    double b = myArctan(1./239., n);
    return 4*(4*a - b);
}

int main(int argc, char **argv){

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
    
}