#include <iostream>
#include <complex>
#include <ctime>
#include <vector>
#include <omp.h>
using namespace std;

double Mandelb(complex<double>& z0, int max_iterations=1000)
{
    complex<double> z=0;
    for (int i=0; i < max_iterations; i++){
        if (norm(z) > 4.0) return i;
        z = z * z + z0;
    }
    return max_iterations * 1e3;
}

int main()
{
    int Nx = 400;
    int Ny = 400;
    for (int i=0; i<Nx; i++){
        for (int j=0; j<Ny; j++){
            double x = -2. + 3 * i /( Nx -1. );
            double y = -1. + 2 * 2 * j /( Ny - 1. );
            complex<double> z0(x, y);
            cout << x << " " << y << " " << 1 / Mandelb(z0) << endl;

        }
    }
}