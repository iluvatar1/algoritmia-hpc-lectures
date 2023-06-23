#include "parallel_avg.h"
void initialize(std::vector<double> & array, int pid, int np)
{
    std::mt19937 gen(pid); // pid == seed (what if seed == 0?)
    std::uniform_real_distribution<double> dis(0.0, 1.0);
    for (auto & x : array) {
        x = dis(gen);
    }
}

void compute_avg(const std::vector<double> & array, int pid, int np) {
  double t1 = 0, t2 = 0;
  // all processes perform the following
  t1 = MPI_Wtime();
  double result = 0.0;
  for (auto & x : array) {
    result += x;
  }
  t2 = MPI_Wtime();
  if (0 == pid) {
    std::cout << "comptime: " << t2-t1 << "\n";
  }
  // TODO: create reduction, collective communication
  int root = 0;
  double buf = 0.0;
  t1 = MPI_Wtime();
  MPI_Reduce(&result, &buf, 1, MPI_DOUBLE, MPI_SUM, root, MPI_COMM_WORLD);
  t2 = MPI_Wtime();
  if (0 == pid) {
    std::cout << "commtime: " << t2-t1 << "\n";
  }

  // TODO: only master prints 
  if (0 == pid) {
    std::cout.setf(std::ios::scientific);
    std::cout.precision(16);
    std::cout << "avg: " << buf/(array.size()*np) << "\n";
    //std::cout << pid << "\n";
  }
}
