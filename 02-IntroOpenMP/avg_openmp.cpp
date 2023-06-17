#include <omp.h>
#include <vector>
#include <iostream>

void init(std::vector<double> & array);

int main(int argc, char **argv) {
    // resources
    const int N = std::stoi(argv[1]);
    std::vector<double> data(N, 0.0);
    init(data);
    
    // calcular las sumas parciales
#pragma omp parallel 
    {
        int thid = omp_get_thread_num();
        int nth = omp_get_num_threads();
        int Nlocal = N/nth;

        double suma = 0.0;
        for(int ii = Nlocal*thid; ii < (thid+1)*Nlocal; ++ii) {
            suma += data[ii];
        }
        std::cout << thid << "\t" << suma << "\n";
    }
    
    // imprimir la informacion
    
    return 0;
}

void init(std::vector<double> & array)
{
    for (auto & x : array) {
        x = 1.7;
    }
}
