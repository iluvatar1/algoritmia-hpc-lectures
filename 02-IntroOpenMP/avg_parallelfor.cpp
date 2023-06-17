#include <omp.h>
#include <vector>
#include <iostream>

void init(std::vector<double> & array);

int main(int argc, char **argv) {
    // resources
    const int N = std::stoi(argv[1]);
    std::vector<double> data(N, 0.0);
    init(data);
    double suma_total = 0.0;

    double start = omp_get_wtime();
    // calcular las sumas parciales
#pragma omp parallel for reduction(+:suma_total)
    for(int ii = 0; ii < N; ++ii) {
        suma_total += data[ii];
    }
    double end = omp_get_wtime();
    std::cout << end-start << "\n";
    
    // imprimir la informacion
    std::cout << "avg: " << suma_total/N << "\n";
    
    return 0;
}

void init(std::vector<double> & array)
{
    for (auto & x : array) {
        x = 1.7;
    }
}
