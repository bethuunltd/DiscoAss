#include<stdio.h>
#include<string.h>

//Kahn Algorithm

// k_alg(){

// }



int main(){
    FILE *file_ptr;
    file_ptr = fopen("a.txt", "r");
    int str_sep_v[2];
    fscanf(file_ptr, "%i %i\n", &str_sep_v[0], &str_sep_v[1]);
    int n = str_sep_v[0];
    int m = str_sep_v[1];
    int m_dep[m][2];//2D Array of size mx2
    
    for (int i = 0; i < m; i++) {//Taking in dependencies, and storing in the mx2 matrix
    fscanf(file_ptr, "%i %i\n", &m_dep[i][0], &m_dep[i][1]);
    }

    //Making adjacency matrix from the given dependencies, and initialising to zero. In Kahn's algorithm, whenever the node is removed, the corresponding elements=0.
    int adj_mat[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            adj_mat[i][j]=0;
        }
    }
    //Making the matrix:
    
    for(int i=0;i<m;i++){
        adj_mat[m_dep[i][0]-1][m_dep[i][1]-1] = 1;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            printf("%d ",adj_mat[i][j]);
            }
        printf("\n");
    }
    
    
    //Matrix for "removed" nodes, to ensure no duplicate outputs.
    int removed[n];
    for(int i=0;i<n;i++){
        removed[i]=0;
    }
    

    int output[n][n];
    for(int i=0;i<n;i++){
        for(int j;j<n;j++){
            output[i][j]=0;
            }
        
    }



    
    //Calling Kahn Algorithm for each step
    //Finding the first root
    // for(int j=0;j<n;j++){

    // }

    

    
    
}
