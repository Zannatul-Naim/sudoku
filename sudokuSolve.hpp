
#include <iostream>
using namespace std;

#define N 9

class SudokuSolver {

    

    public:

    bool findUnassigned ( int grid[N][N], int *row, int *col) {

        for(*row = 0; *row < N; (*row)++) {
            for(*col = 0; *col < N; (*col)++) {

                if(grid[*row][*col] == 0) {

                    return true;
                }
            }
        }

        return false;
    }

    bool findInRow(int grid[N][N], int row, int n) {
        
        for(int i = 0; i < N; i++) {
            if(grid[row][i] == n) {
                return true;
            } 
        }
        return false;
    }

    bool findInColumn(int grid[N][N], int col, int n) {
        
        for(int i = 0; i < N; i++) {
            if(grid[i][col] == n) {
                return true;
            } 
        }
        return false;
    }

    /*
        Here, findInBox function have:-
        r = Small 3x3 Box Starting Row
        c = Small 3x3 Box Starting Column
        n = number to find
    */

    bool findInBox( int grid[N][N], int r, int c, int n) {

        r = r - r%3;
        c = c - c%3;

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {

                if(grid[i+r][j+c] == n ) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isValid( int grid[N][N], int row, int col, int num ) {

        if(!findInRow(grid, row, num) and !findInColumn(grid, col, num) and !findInBox(grid, row, col, num)) {

            return true;
        }
        return false;
    }

    bool solve(int grid[N][N]) {

        int row, col;

        if(!findUnassigned(grid, &row, &col)) {
            return true;
        }

        for(int i = 1; i <= N; i++) {

            if(isValid(grid, row, col, i)) {
                
                grid[row][col] = i;

                if(solve(grid)) {
                    return true;
                }
                // solve(grid);
                grid[row][col] = 0;
            }
        }

        return false;
    }

};