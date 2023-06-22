#pragma once
#include <vector>
#include <random>
#include <iostream>
#include "mpi.h"

void initialize(std::vector<double> & array, int pid, int np);
void compute_avg(const std::vector<double> & array, int pid, int np);
