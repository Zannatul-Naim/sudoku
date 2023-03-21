
#include <iostream>
#include "sudokuSolve.hpp"

using namespace std;

#define N 9

void print(int grid[N][N]) {

    for(int i = 0; i < N; i++) {
        cout << "        ";

        for(int j = 0; j < N; j++) {

            if(j == 3 or j == 6) {
                cout << "|";
            }
            cout << grid[i][j] << " ";
        }
        cout << endl;
        if(i== 2 or i == 5) {
            cout << "        ";
            for(int k  = 0; k < N; k++) {
                cout << "--";
            } cout << endl;
        }
    }
}


int main() {

    int grid[N][N] = {

        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
        
    };


    SudokuSolver sudokuSolver = SudokuSolver();

    cout << "\n          ---Problem---\n\n";
    print(grid);

    cout << endl << endl << endl;

    if(sudokuSolver.solve(grid) == true) {
        cout << "\n          ---Solution---\n\n";
        print(grid);
    } else {
        cout << "NO SOLUTION AVAILABLE!" << endl;
    }

    cout << endl << endl << endl;

}