#!/bin/bash
#SBATCH --job-name="loops_openmp"
#SBATCH --mail-type=ALL
#SBATCH --mail-user=wfoquendop@unal.edu.co
#SBATCH --time=01:00:00
#SBATCH --nodes=4
#SBATCH --ntasks-per-node=1
#SBATCH --cpus-per-task=1
#SBATCH --partition=12threads
#SBATCH -o job_%j.out
#SBATCH -e job_%j.err

# Define the array of thread values and corresponding cpus-per-task values
threads=(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16)
cpus=(1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16)

# Get the index of the current job in the array
index=$((SLURM_ARRAY_TASK_ID - 1))

# Set the number of threads and cpus-per-task using the corresponding array elements
export OMP_NUM_THREADS=${threads[$index]}
cpus_per_task=${cpus[$index]}
#SBATCH --cpus-per-task=$cpus_per_task

./avg_openmp.x 100000000
