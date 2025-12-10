# Message-Passing-Interface-MPI-


# MPI Message Passing in a Ring Topology

## Project Objective (Problem 2)

This project implements a Message Passing Interface (MPI) program in C. The objective is to arrange multiple processes in a logical ring topology where each process sends a message to its successor and receives a message from its predecessor. The program prints the received message after execution.

## Execution Environment

* **Operating System:** Windows 10/11 (Execution performed via Windows Subsystem for Linux - WSL)
* **MPI Library:** OpenMPI
* **Compiler:** GCC / OpenMPI Wrapper (`mpicc`)

## Compilation and Execution (Proof of Execution)

The project was compiled and executed within the WSL/Ubuntu terminal.

### 1. Compilation Command

The `mpicc` compiler wrapper was used to compile the `mpi_ring.c` source file.
```bash
mpicc mpi_ring.c -o mpi_ring
```
### 2. Execution Command
The program was executed using the mpirun launcher with 4 processes (-np 4).
``` bash
mpirun -np 4 ./mpi_ring
```
output:
Process 3 received message from process 2. Message: "Hello from process 2!"
Process 0 received message from process 3. Message: "Hello from process 3!"
Process 1 received message from process 0. Message: "Hello from process 0!"
Process 2 received message from process 1. Message: "Hello from process 1!"
