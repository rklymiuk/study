#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;

int** createZeroMatrix(int const x, const int y) {
    int** mat = new int* [x];
    for (int i = 0; i < x; i++) {
        mat[i] = new int[y];
        for (int j = 0; j < y; j++) {
            mat[i][j] = 0;
        }
    }
    return mat;
}
int** createMatrix(int const x, const int y) {
    int** mat = new int* [x];
    for (int i = 0; i < x; i++) {
        mat[i] = new int[y];
        for (int j = 0; j < y; j++) {
            mat[i][j] =rand() % 10;
        }
    }
    return mat;
}

void printMatrix(int** mat, int x, int y) {
    cout << "*******" << endl;
    
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                cout << mat[i][j] << " ";
            }

            cout << endl;
        }cout << "*******" << endl;   
}
int enterDataForMatrix(int** mat, int x, int y) {
    
    for(int i = 0; i<x;i++){
        for(int j = 0; j<y;j++){
            cout << "enter value" << endl;
            cin >> mat[i][j]; 
            
        }
    }return **mat;
}
int ** multiplyMatrix(int **mat,int** matF, int** matS, int x, int y, int x1, int y1) {
    
    for (int i = 0; i < y; i++) {
        for (int j = 0; j < x1; j++) {
            for (int k = 0; k < x;k++) {
                mat[i][j] += matF[i][k] * matS[k][j];
                
            }
            printMatrix(mat, x, y);
        }
    }return mat;
}
int** transMatrix(int** mat, int x, int y) {
    int** transMat = createZeroMatrix(y, x);

    for (int i = 0; i < x; i++) { 
        for (int j = 0; j < y; j++) { 
            transMat[j][i] = mat[i][j]; 
        }
    }
    return transMat;
}
void deleteMatrix(int **&Matrix, int x,int y) {
    if (x > y) {
        for (int i = 0; i < x; i++) {
            delete[] Matrix[i];
        }
    }
    else {
        for (int i = 0; i < y; i++) {
            delete[] Matrix[i];
        }
    }
    delete[] Matrix;
}


int main() {
    srand(time(NULL));

    int x, y,x1,y1;
    cout << "Enter firs matrix size : ";
    cin >> x >> y;
    cout << "Enter second matrix size : ";
    cin >> x1 >> y1;

    int** MatrixF = createMatrix(x, y);
    printMatrix(MatrixF, x, y);
    int** MatrixS = createMatrix(x1, y1);
    int** Matrix = createZeroMatrix(x, y);
    int**transMat = transMatrix(MatrixF,x,y);

    printMatrix(transMat, y, x);


 
    int MultiplayedM = (Matrix,MatrixF, MatrixS, x, y,x1,y1);
    enterDataForMatrix(Matrix, x, y);
    printMatrix(Matrix, x, y);

    
    
    deleteMatrix(Matrix, x,y);
    deleteMatrix(transMat, x, y);
    deleteMatrix(MatrixF, x, y);
    deleteMatrix(MatrixS, x, y);
    return 0;
}