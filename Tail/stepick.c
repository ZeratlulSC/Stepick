#include <stdio.h>

void spiral (int m, int n){
    //m,n - m количество строк, n количество столбцов;
    //scanf;
    int arr [m][n];
    int number = 1;
    int lw = -1;
    int rw = n;
    int uw = -1;
    int dw = m;
    int iter_gorizontal = 0;
    int iter_vertical = 0;
    int g_gor_f = 1;
    int g_gor_b = 0;
    int g_ver_f = 0;
    int g_ver_b = 0;
    while (number != (m*n+1)){
        if (g_gor_f){
            if (iter_gorizontal != rw - 1){
                if (iter_gorizontal == lw){
                    iter_gorizontal++;
                    number--;
                }
                else{
                    arr[iter_vertical][iter_gorizontal] = number;
                    iter_gorizontal++;
                }
            }
            else if (iter_gorizontal == rw - 1){
                arr[iter_vertical][iter_gorizontal] = number;
                g_gor_f = 0;
                g_ver_f = 1;
                uw++;
            }
        }
        else if (g_ver_f){
            if (iter_vertical != dw - 1){
                if (iter_vertical == uw){
                    iter_vertical++;
                    number--;
                }
                else {
                    arr[iter_vertical][iter_gorizontal] = number;
                    iter_vertical++;
                }
            }
            else if (iter_vertical == dw - 1){
                arr[iter_vertical][iter_gorizontal] = number;
                g_ver_f = 0;
                g_gor_b = 1;
                rw--;
            }
        }
        else if (g_gor_b){
            if (iter_gorizontal != lw + 1){
                if (iter_gorizontal == rw){
                    iter_gorizontal--;
                    number--;
                }
                else {
                    arr[iter_vertical][iter_gorizontal] = number;
                    iter_gorizontal--;
                }
            }
            else if (iter_gorizontal == lw + 1){
                arr[iter_vertical][iter_gorizontal] = number;
                g_gor_b = 0;
                g_ver_b = 1;
                dw--;
            }
        }
        else if (g_ver_b){
            if (iter_vertical != uw + 1){
                if (iter_vertical == dw){
                    iter_vertical--;
                    number--;
                }
                else {
                    arr[iter_vertical][iter_gorizontal] = number;
                    iter_vertical--;
                }
            }
            else if (iter_vertical == uw + 1){
                arr[iter_vertical][iter_gorizontal] = number;
                g_ver_b = 0;
                g_gor_f = 1;
                lw++;
            }
        }
        number++;
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%3d", arr[i][j]);
        }
        printf("\n");
    }  
}

int main (){
    spiral(6,7);
    return 0;
}