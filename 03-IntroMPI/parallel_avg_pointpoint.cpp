#include "parallel_avg_pointpoint.h"
void initialize(std::vector<double> & array, int pid, int np)
{
    std::mt19937 gen(pid); // pid == seed (what if seed == 0?)
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    for (auto & x : array) {
        x = dis(gen);
    }
}

void compute_avg(const std::vector<double> & array, int pid, int np) {
    double result = 0.0;
    for (auto & x : array) {
        result += x;
    }
    // mpi communication: TODO
    if (0 == pid) {
        // receive and accumulate
    } else {
        // send
    }
    // only master prints
    std::cout.setf(std::ios::scientific);
    std::cout.precision(16);
    std::cout << "avg: " << result/array.size();
    std::cout << pid << "\n";
}
