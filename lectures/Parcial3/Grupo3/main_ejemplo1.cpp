#include "poisson.h"
#include <cmath>

using namespace std;


int main() {
    //double x, y;
    double a = 0.0, b = 2.0, c = 0.0, d = 1.0; // Límites del dominio
    int m = 5, n = 6; // Número de puntos en cada dirección
    double TOL = 1e-10; // Tolerancia
    int N = 100; // Número máximo de iteraciones

    auto f = [](double x, double y) { return x * exp(y); };
    auto g = [](double x, double y) {
        if (x == 0.0 && y >= 0.0 && y <= 1.0) {
        return 0.0;
    } else if (x == 2.0 && y >= 0.0 && y <= 1.0) {
        return 2.0 * exp(y);
    } else if (y == 0.0 && x >= 0.0 && x <= 2.0) {
        return x;
    } else if (y == 1.0 && x >= 0.0 && x <= 2.0) {
        return exp(x);
    } else {
        return 0.0;
    }
};

    PoissonSolver solver(a, b, c, d, m, n, TOL, N, f, g);
    solver.solve();
    //solver.printSolution();
    solver.guardarcvs();
    

    return 0;

    
}