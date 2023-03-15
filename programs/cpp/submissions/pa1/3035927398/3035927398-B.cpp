#include <iostream>
#include <vector>
#include <stdio.h>
#include <iterator>
#include <algorithm>
#include <cmath>
using namespace std;

void solve(vector<vector<int> > matrix, int newSize){
    if(newSize>1){
        int mode[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        for(int i = 0; i < newSize; i++){
            for(int j = 0; j < newSize; j++){
                mode[matrix[i][j]]++;
            }
        }
        //up left
        vector<vector<int> > newMatrix(newSize/2, vector<int> (newSize/2)); 
        for(int i = 0; i < newSize/2; i++){
            for(int j = 0; j < newSize/2; j++){
                newMatrix[i][j] = matrix[i][j];
            }
        }
        solve(newMatrix, newSize/2);
        //up right
        for(int i = 0; i < newSize/2; i++){
            for(int j = newSize/2; j < newSize; j++){
                newMatrix[i][j-newSize/2] = matrix[i][j];
            }
        }
        solve(newMatrix, newSize/2);
        //mode print
        cout << std::distance(mode, max_element(mode, mode + sizeof(mode) / sizeof(int))) << " ";
        //bottom left
        for(int i = newSize/2; i < newSize; i++){
            for(int j = 0; j < newSize/2; j++){
                newMatrix[i-newSize/2][j] = matrix[i][j];
            }
        }
        solve(newMatrix, newSize/2);
        for(int i = newSize/2; i < newSize; i++){
            for(int j = newSize/2; j < newSize; j++){
                newMatrix[i-newSize/2][j-newSize/2] = matrix[i][j];
            }
        }
        solve(newMatrix, newSize/2);
    }
    else{
        cout << matrix[0][0] << " ";
    }

}

int main(){

    int size;
    cin >> size;
    
    const int newSize = pow(2, size);
    vector<vector<int> > matrix(newSize, vector<int> (newSize));


    for(int i = 0; i < newSize; i++){
        for(int j = 0; j < newSize; j++){
            cin >> matrix[i][j];
        }
    }

    solve(matrix, newSize);

    return 0;
}
