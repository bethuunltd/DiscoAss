#include <stdio.h>
#include <string.h>
#include <stdlib.h> //as online GDB says it is needed for

// Kahn Algorithm

// Making a flag function to decide when to stop Kahn's algorithm
int cont_flag(int removed_arr[],int n)
    { 
        int cont = 0;
        for (int i = 0; i < n; i++)
        {
            if (removed_arr[i] == 1)
            {
                cont = 1;
            }
        }
        return cont;
    }

int main()
{
    FILE *file_ptr;
    file_ptr = fopen("a.txt", "r");

    int str_sep_v[2];
    fscanf(file_ptr, "%i %i\n", &str_sep_v[0], &str_sep_v[1]);
    int n = str_sep_v[0];
    int m = str_sep_v[1];

    // int m_dep[m][2]; // 2D Array of size mx2
    int **m_dep = NULL;
    m_dep = malloc(m * sizeof(int*));
    for (int j = 0; j < m; j++)
    {
        m_dep[j] = malloc(2 * sizeof(int));
    } 

    for (int i = 0; i < m; i++)
    { // Taking in dependencies, and storing in the mx2 matrix
        fscanf(file_ptr, "%i %i\n", &m_dep[i][0], &m_dep[i][1]);
    }
    fclose(file_ptr);

    // Making adjacency matrix from the given dependencies, and initialising to zero. In Kahn's algorithm, whenever the node is removed, the corresponding elements=0.
    // int adj_mat[n][n];//Instead of creating an array 
    int **adj_mat = NULL;
    adj_mat = malloc(n * sizeof(int*));
    for (int j = 0; j < n; j++)
    {
        adj_mat[j] = malloc(n * sizeof(int));
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adj_mat[i][j] = 0;
        }
    }
    // Making the matrix; Remember that numbers represented = matrix index +1 (eg: 1 is index 0)

    for (int i = 0; i < m; i++)
    {
        adj_mat[m_dep[i][0] - 1][m_dep[i][1] - 1] = 1;
    }

    free(m_dep);
    m_dep = NULL;

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++){
    //         printf("%d ",adj_mat[i][j]);
    //         }
    //     printf("\n");
    // }

    // Matrix for "removed" nodes, to ensure no duplicate outputs.
    //int removed_arr[n]; // in the array, removed numbers are represented with 0 and the existing ones with 1
    int *removed_arr= NULL;
    removed_arr= malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        removed_arr[i] = 1;
    }

    // int output[n][n]; // 2D Array needed to print outputs after the number of rounds; maximum size of it can be n rounds
    int **output = NULL;
    output = malloc(n * sizeof(int*));
    
    for(int i=0;i<n;i++){
        output[i] = malloc(n * sizeof(int));
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            output[i][j] = 0;
        }
    }




    
    int rounds = 0;
    // int to_remove_arr[n];// the array of nodes to be removed in a specific round
    int* to_remove_arr = NULL;
    to_remove_arr = malloc(n * sizeof(int));
    while (cont_flag(removed_arr,n))// while the removed array isnt completely empty(meaning all indices =1), the algorithm keeps running
    {
        for (int i = 0; i < n; i++)
        { // before every loop, this array is cleared to zero; as it only applies to this round
            to_remove_arr[i] = 0;
        }
        for (int j = 0; j < n; j++)
        {
            if (removed_arr[j] == 1)
            {
                int ptr = 0; // if it gets through all rows and ptr=0, then it is a root
                for (int i = 0; i < n; i++)
                {
                    if (adj_mat[i][j] == 1)
                    {
                        ptr = 1;
                    }
                }
                if (ptr == 0)
                { // if it is a root, then remove corresponding dependencies, and set removed=0
                    to_remove_arr[j] = 1;
                }
            }
            // flag = false
            // checking if removed is true for the column, then dont take into consideration
        }
        int out_count = 0;
        for (int i = 0; i < n; i++)
        {
            if (to_remove_arr[i] == 1)
            {
                // printf("%d ",i+1);
                output[rounds][out_count] = i + 1;
                out_count++;
                removed_arr[i] = 0;
                for (int ni = 0; ni < n; ni++)
                { // removing all dependencies for the corresponding row
                    adj_mat[i][ni] = 0;
                }
            }
        }
        rounds++;
        printf("\n");
    }

    //freeing all the multiple pointers I've used.
    free(to_remove_arr);
    to_remove_arr = NULL;

    free(removed_arr);
    to_remove_arr = NULL;

    free(adj_mat);
    adj_mat = NULL;



    FILE *fp1 = fopen("b.txt", "w");
    if (fp1 == NULL)
    {
        printf("Error opening file\n");
        exit(1);
    }
    fprintf(fp1, "%d\n", rounds);

    for (int i = 0; i < rounds; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (output[i][j] != 0)
            {
                fprintf(fp1, "%d ", output[i][j]);
            }
        }
        fprintf(fp1, "\n");
    }

    fclose(fp1);

    free(output);
    output = NULL;
}
