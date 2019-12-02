#include <iostream>
#include <cstring>

class Sudoku {
private:
    int grid[9][9]{};
	
	bool isCellValid(int rowIndex, int columnIndex, int val) {
		return isColumnValid(rowIndex, columnIndex, val)
			&& isRowValid(rowIndex, columnIndex, val)
		 	&& isBoxValid(rowIndex, columnIndex, val)
		;
	}

	bool isColumnValid(int rowIndex, int columnIndex, int val) {
		for(int i = 0; i < 9; i++) {
			if(grid[columnIndex][i] == val) {
				return false;
			}
		}

		return true;
	}

	bool isRowValid(int rowIndex, int columnIndex, int val) {
		for(int i = 0; i < 9; i++) {
			if(grid[i][rowIndex] == val) {
				return false;
			}
		}

		return true;
	}

	bool isBoxValid(int rowIndex, int columnIndex, int val) {
		// gives us the position of the minibox (from 0 to 2),
		// This gives us the index on the grid. because each
		// box is 3 x 3
		rowIndex = rowIndex / 3;
		rowIndex *= 3;

		columnIndex = columnIndex / 3;
		columnIndex *= 3;

		for(int i = columnIndex; i < columnIndex + 3; i++) {
			for(int j = rowIndex; j < rowIndex + 3; j++) {
				if(grid[i][j] == val) {
					return false;
				}
			}
		}

		return true;
	}

	bool isBoardFull() {
		std::vector<int> nextEmptyIndex = getNextEmptyIndex();

		if(nextEmptyIndex[0] == -1 || nextEmptyIndex[1] == -1) {
			return true;
		}
		
		return false;
	}
	
	std::vector<int> getNextEmptyIndex() {
		std::vector<int> emptyIndex(2);
		emptyIndex[0] = -1;
		emptyIndex[1] = -1;

		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < 9; j++) {
				if(grid[i][j] == 0) {
					emptyIndex[0] = i;
					emptyIndex[1] = j;

					return emptyIndex;
				}
			}
		}
		
		return emptyIndex;
	}

public:
    explicit Sudoku(int (*grid)[9]) {
        memcpy(this->grid, grid, 9 * 9 * sizeof(int));
    }

    bool operator ==(const int (*otherGrid)[9]) {
        for (int i=0; i<9*9; i++) {
            if (grid[i%9][i/9] != otherGrid[i%9][i/9]) {
                return false;
            }
        }
        return true;
    }

    bool operator ==(const Sudoku & other) {
        for (int i=0; i<9*9; i++) {
#ifdef PRINT
            printf("comparing grid(%d, %d)\n", i%9, i/9);
#endif
            if (grid[i%9][i/9] != other.grid[i%9][i/9]) {
                return false;
            }
        }
        return true;
    }

    int get(int i, int j) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j];
        }

        return -1;
    }

    int set(int i, int j, int val) {
        if (i >= 0 && i < 9 && j >= 0 && j < 9) {
            return grid[i][j] = val;
        }
        return -1;
    }

    void print() {
        for (int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                printf(" [%d] ", get(i, j));
                if (j == 8) {
                    printf("\n");
                }
            }
        }
    }

    bool solve() {

		if(isBoardFull()) {
			return true;
		}

		std::vector nextEmptyIndex = getNextEmptyIndex();
		// printf("NE: %d, %d == %d\n", nextEmptyIndex[0], nextEmptyIndex[1], grid[nextEmptyIndex[0]][nextEmptyIndex[1]]);

		for(int i = 1; i <= 9; i++) {
			if(isCellValid(nextEmptyIndex[0], nextEmptyIndex[1], i)) {
				grid[nextEmptyIndex[0]][nextEmptyIndex[1]] = i;

				if(solve()) {
					return true;
				}

				grid[nextEmptyIndex[0]][nextEmptyIndex[1]] = 0;
			}
		}		

        return false;
    }
};
