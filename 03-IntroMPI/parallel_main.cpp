#include "parallel_avg_pointpoint.h"
#include "mpi.h"

int main(int argc, char **argv) {
    // MPI initialization
    MPI_Init(&argc, &argv); 
    int pid, np;
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    
    // local problem definition
    const int N = std::stoi(argv[1]); // total size
    int Nlocal = N/np; // size for this process
    std::vector<double> data(Nlocal, 0.0);
    
    initialize(data, pid, np);
    
    compute_avg(data, pid, np);
    
    MPI_Finalize();
    
    return 0;
}
