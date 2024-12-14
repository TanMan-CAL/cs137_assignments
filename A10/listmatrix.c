#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

// A structure for representing a single entry in the matrix.  THis part is stored in the heap
struct MatrixEntry {
    int row;  // the row number of a specific entry
    int col;  // the col number of a specific entry
    int value;
    struct MatrixEntry* next; // Pointer to the next entry in the linked list
};
 
// A structure for representing the sparse matrix. This part is stored in the stack
struct SparseMatrix {
    int num_rows;  // the dimension of the matrix is
    int num_cols;  //  num_rows X num_cols
    struct MatrixEntry* head; // Pointer to the first entry of the linked list
};
 
// Define a function to insert a new entry into the front of the result matrix
// assume all arguments are valid
void insert_entry(struct SparseMatrix* result, int row, int col, int value) {
    struct MatrixEntry *newNode = malloc(sizeof(struct MatrixEntry));
    newNode->col = col;
    newNode->row = row;
    newNode->value = value;
    
    newNode->next = result->head;
    result->head = newNode;
}
 
// Define a function that multiplies two sparse matrices with valid sizes
struct SparseMatrix multiply_matrices(const struct SparseMatrix* matrix1, const struct SparseMatrix* matrix2) {
    int *m2 = calloc(matrix2->num_cols * matrix2->num_rows, sizeof(int));
    struct MatrixEntry *entry = matrix2->head;

    while (entry != NULL) { 
        int index = entry->row * matrix2->num_cols + entry->col;
        m2[index] = entry->value;
        entry = entry->next;
    }

    struct SparseMatrix result;
    result.num_rows = matrix1->num_rows;
    result.num_cols = matrix2->num_cols;
    result.head = NULL;

    struct MatrixEntry **result_tail = &result.head;

    struct MatrixEntry *m1_iteration = matrix1->head;
    while (m1_iteration != NULL) {
        for (int col = 0; col < matrix2->num_cols; col++) {
            int index = m1_iteration->col * matrix2->num_cols + col;
            int value = m1_iteration->value * m2[index];

            if (value != 0) {
                struct MatrixEntry *node = malloc(sizeof(struct MatrixEntry));
                node->row = m1_iteration->row;
                node->col = col;
                node->value = value;
                node->next = NULL;

                *result_tail = node;
                result_tail = &node->next;
            }
        }
        m1_iteration = m1_iteration->next;
    }

    free(m2);
    return result;
}


 

// Function to free memory allocated for a sparse matrix
void free_sparse_matrix(struct SparseMatrix* matrix) {
    struct MatrixEntry* entry = matrix->head;

    while (entry != NULL){ 
        struct MatrixEntry *temp = entry;
        entry = entry->next;        
        free(temp);
    }
    free(entry);
}

// Function to print a sparse matrix
// Do not change this function

void print_sparse_matrix(const struct SparseMatrix* matrix) {
    for (struct MatrixEntry* entry = matrix->head; entry != NULL; entry = entry->next) {
        printf("(%d, %d): %d\n", entry->row, entry->col, entry->value);
    }
}


//  int main(void) {
//     // Create and initialize sparse matrices (matrix1 and matrix2)
       
//     struct SparseMatrix matrix1;
//     matrix1.num_rows = 3;
//     matrix1.num_cols = 4;
//     matrix1.head = NULL;
//     // Initialize matrix1 with some entries
//     insert_entry(&matrix1, 0, 0, 1);
//     insert_entry(&matrix1, 1, 1, 2);
//     insert_entry(&matrix1, 2, 2, 3);
//     insert_entry(&matrix1, 0, 3, 5);
//     printf("Matrix1 3x4:\n");
//     print_sparse_matrix(&matrix1);
    
//     struct SparseMatrix matrix2;
//     matrix2.num_rows = 4;
//     matrix2.num_cols = 3;
//     matrix2.head = NULL;
 
//     // Initialize matrix2 with some entries
//     insert_entry(&matrix2, 0, 0, 4);
//     insert_entry(&matrix2, 1, 1, 5);
//     insert_entry(&matrix2, 2, 2, 6);
//     insert_entry(&matrix2, 3, 2, 3);
//     printf("Matrix2 4x3:\n");
//     print_sparse_matrix(&matrix2);
//     // Multiply matrices
//     struct SparseMatrix result = multiply_matrices(&matrix1, &matrix2);
 
//     // Print the result matrix
//     printf("Result matrix1 x matrix2:\n");
//     print_sparse_matrix(&result);
 
//     // Free memory allocated for matrices and result
//     free_sparse_matrix(&matrix1);
//     free_sparse_matrix(&matrix2);
//     free_sparse_matrix(&result);
 
//     return 0;
// }