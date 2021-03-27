//
// Created by jacob on 2021/3/27.
//

#include <vector>

bool isValidSudoku(std::vector<std::vector<char>> &board) {
    std::vector<int> counts;
    // check the rows
    for (int row = 0; row < 9; ++row) {
        counts.assign(10, 0);
        for (int col = 0; col < 9; ++col) {
            if (board[row][col] != '.' && (counts[board[row][col] - '0']++) >= 1)
                return false;
        }
    }

    // check the columns
    for (int col = 0; col < 9; ++col) {
        counts.assign(10, 0);
        for (int row = 0; row < 9; ++row) {
            if (board[row][col] != '.' && (counts[board[row][col] - '0']++) >= 1)
                return false;
        }
    }

    // check the boxes
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            counts.assign(10, 0);
            // check the current box
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    int id1 = 3 * row + i, id2 = 3 * col + j;
                    if (board[id1][id2] != '.' && (counts[board[id1][id2] - '0']++) >= 1)
                        return false;
                }
            }

        }
    }
    return true;
}