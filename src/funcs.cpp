#include "funcs.h"


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

double myArctan_formpi(int* numbers, const double x, const int n){
    double s = 0.0;
    for (int i = 0; i < n; i++){
        if (numbers[i] % 2 == 1)
            s += pow(x, 2*numbers[i]-1)/(2*numbers[i]-1);
        else
            s -= pow(x, 2*numbers[i]-1)/(2*numbers[i]-1);
    }
    return s;
}

double zeta1(int* numbers, const int n){

    double s = 0.0;
    double tmp;
    for(int i = 0; i < n; i++){
        tmp = 1./numbers[i];
        s += tmp*tmp;
    }
    return 6*s;
}

double mach1(int* numbers, const int n){
    double a = myArctan_formpi(numbers, 0.2, n);
    double b = myArctan_formpi(numbers, 1./239., n);
    return 4*(4*a - b);
}