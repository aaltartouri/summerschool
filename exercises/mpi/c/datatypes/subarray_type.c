#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv)
{
    int rank;
    int array[8][8];
    //TODO: declare mpi datatype for the block
    int sizes[2], subsizes[2], offsets[2];
    MPI_Datatype subarr;
    int i, j;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    // Initialize arrays
    if (rank == 0) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                array[i][j] = (i + 1) * 10 + j + 1;
            }
        }
    } else {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                array[i][j] = 0;
            }
        }
    }

    //TODO: Create datatype for a subblock [2:5][3:5] of the 8x8 matrix

    sizes[0] = 8;
    sizes[1] = 8;
    subsizes[0] = 3;
    subsizes[1] = 2;
    offsets[0] = 2;
    offsets[1] = 3;

    MPI_Type_create_subarray(2, sizes, subsizes, offsets, MPI_ORDER_C, MPI_INT, &subarr);
    MPI_Type_commit(&subarr);

    // TODO:  Send a block of a matrix using the user-defined datatype from
    // rank 0 to rank 1
    if (rank == 0) {
        MPI_Send(&array, 1, subarr, 1, 0, MPI_COMM_WORLD);
    } else if (rank == 1) {
        MPI_Recv(&array, 1, subarr, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }

    // Print out the result on rank 1
    if (rank == 1) {
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                printf("%3d", array[i][j]);
            }
            printf("\n");
        }
    }

    //TODO: free datatype
    MPI_Type_free(&subarr);
    MPI_Finalize();

    return 0;
}
