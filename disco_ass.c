#include<stdio.h>
#include<string.h>

//Kahn Algorithm

k_alg(){
}



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

    int key[n];//the labelling for the nxn adjacency matrix
    
    for(int i=0;i<n;i++){//dont need this at all(because i forgot the fact that numbers come after one another) still committing because want a record of how dumb i can get my god
        key[i]= i+1;
    }


    //Calling Kahn Algorithm for each step

    

    
    
}
