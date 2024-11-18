#include<stdio.h>
#include<string.h>

//Kahn Algorithm

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
    //Making the matrix; Remember that numbers represented = matrix index +1 (eg: 1 is index 0)
    
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
    int removed_arr[n];//in the array, removed numbers are represented with 0 and the existing ones with 1
    for(int i=0;i<n;i++){
        removed_arr[i]=1;
    }
    

//Making a flag function to decide when to stop Kahn's algorithm
int cont_flag(int removed_arr[]){
    int cont =0;
    for(int i=0;i<n;i++){
        if (removed_arr[i]==1){
            cont = 1;
        }
    }
    return cont; 
}

//Kahn's algorithm 
    //while the removed array isnt completely empty(meaning all indices =1), the algorithm keeps running
while (cont_flag(removed_arr)){
    for(int j=0;j<n;j++){
        if (removed_arr[j] == 1){
            int ptr = 0;//if it gets through all rows and ptr=0, then it is a root
            for(int i=0;i<n;i++){
                if(adj_mat[i][j]==1){
                    ptr=1;
                } 
            }
           if(ptr==0){//if it is a root, then remove corresponding dependencies, and set removed=0
            printf("%d ",j+1);
            removed_arr[j] = 0;
            for(int ni=0;ni<n;ni++){
                adj_mat[j][ni]=0;
            }
        }
            
        }
        // flag = false
        //checking if removed is true for the column, then dont take into consideration

    }
    printf("\n");
}



    
    //Calling Kahn Algorithm for each step
    //Finding the first root
    // for(int j=0;j<n;j++){

    // }

    

    
    
}
