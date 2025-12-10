#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // 1. Initialization
    MPI_Init(&argc, &argv);

    int rank, size;
    // Get the total number of processes (size) and the current process's rank
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // My rank (0 to size-1)
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Total processes

    // Define message parameters
    char send_msg[100];
    char recv_msg[100];
    MPI_Status status;

    // Determine the sender and receiver ranks
    int successor = (rank + 1) % size;
    int predecessor = (rank - 1 + size) % size;

    // Create the message to be sent
    snprintf(send_msg, 100, "Hello from process %d!", rank);

    // 2. Message Passing
    // Use MPI_Sendrecv for simultaneous Send and Receive to prevent deadlock.
    MPI_Sendrecv(
        send_msg,           // Buffer to send
        strlen(send_msg) + 1, // Size of send buffer (including null terminator)
        MPI_CHAR,           // Datatype of sent data
        successor,          // Destination rank
        0,                  // Send tag
        recv_msg,           // Buffer to receive
        100,                // Size of receive buffer
        MPI_CHAR,           // Datatype of received data
        predecessor,        // Source rank
        0,                  // Receive tag
        MPI_COMM_WORLD,     // Communicator
        &status             // Status object
    );

    // 3. Output
    // After execution, each process prints the message it received.
    printf("Process %d received message from process %d. Message: \"%s\"\n",
           rank, predecessor, recv_msg);

    // 4. Finalization
    MPI_Finalize();
    return 0;
}