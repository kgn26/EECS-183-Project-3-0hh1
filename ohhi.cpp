/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 *
 * Khanh Gia Nguyen
 * kgnguyen
 *
 * This file contains the functions: count unknown squares(),
 * check validity(), solve functions(), and gameplay functions()
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

/**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    int numUnknown = 0;
    
    // Iterate through every square and check if it's UNKNOWN
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            if (board[row][col] == UNKNOWN) {
                numUnknown++;
            }
        }
    }

    return numUnknown;
}


/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    
    // Loop through every square in row except for the last two
    for (int i = 0; i < size - 2; i++) {
        // Check if the next two squares have the same color
        // as the current one
        if (board[row][i] == color
            && board[row][i + 1] == color
            && board[row][i + 2] == color) {
            return false;
        }
    }
    
    return true;
}

bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    
    // Loop through every square in column except for the last two
    for (int i = 0; i < size - 2; i++) {
        // Check if the next two squares have the same color
        // as the current one
        if (board[i][col] == color
            && board[i + 1][col] == color
            && board[i + 2][col] == color) {
            return false;
        }
    }

    return true;
}

bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    // Check each row for threes
    for (int i = 0; i < size; i++) {
        if (!(row_has_no_threes_of_color(board, size, i, RED) &&
            row_has_no_threes_of_color(board, size, i, BLUE))) {
            return false;
        }
    }
    
    // Check each column for threes
    for (int i = 0; i < size; i++) {
        if (!(col_has_no_threes_of_color(board, size, i, RED) &&
            col_has_no_threes_of_color(board, size, i, BLUE))) {
            return false;
        }
    }

    return true;
}

bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    
    for (int i = 0; i < size; i++) {
        // Check if each square with the same index from
        // the two rows are different or row contains UNKNOWN
        if ((board[row1][i] != board[row2][i]) ||
            (board[row1][i] == UNKNOWN || board[row2][i] == UNKNOWN)) {
            return true;
        }
    }

    return false;
}

bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
  
    for (int i = 0; i < size; i++) {
        // Check if each square with the same index from
        // the two columns are different or columns contains UNKNOWN
        if ((board[i][col1] != board[i][col2]) ||
            (board[i][col1] == UNKNOWN || board[i][col2] == UNKNOWN)) {
            return true;
        }
    }

    return false;
}

bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (!(rows_are_different(board, size, i, j) &&
                  cols_are_different(board, size, i, j))) {
                return false;
            }
        }
    }
    
    return true;
}


/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    
    int color;
    
    for (int i = 0; i < size - 2; i++) {
        // Check for two consecutive same-colored tiles
        // next to current tile
        if (board[row][i] == UNKNOWN &&
            board[row][i + 1] != UNKNOWN &&
            board[row][i + 2] != UNKNOWN) {
            if (board[row][i + 1] == board[row][i + 2]) {
                // Mark the tile with the opposite color
                color = opposite_color(board[row][i + 1]);
                mark_square_as(board, size, row, i, color, announce);
            }
        }
        
        // Check if there is a same-colored tile next to or
        // one tile to the right from the current tile
        if (board[row][i] != UNKNOWN) {
            if ((board[row][i + 1] == board[row][i]) &&
                (board[row][i + 2] == UNKNOWN)) {
                // Mark the tile with the opposite color
                color = opposite_color(board[row][i]);
                mark_square_as(board, size, row, i + 2, color, announce);
            } else if ((board[row][i + 2] == board[row][i]) &&
                       (board[row][i + 1] == UNKNOWN)) {
                // Mark the tile with the opposite color
                color = opposite_color(board[row][i]);
                mark_square_as(board, size, row, i + 1, color, announce);
            }
        }
    }

    return;
}

void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
    
    int color;
    
    for (int i = 0; i < size - 2; i++) {
        // Check for two consecutive same-colored tiles
        // next to current tile
        if (board[i][col] == UNKNOWN) {
            if (board[i + 1][col] == board[i + 2][col] &&
                board[i + 1][col] != UNKNOWN &&
                board[i + 2][col] != UNKNOWN) {
                // Mark the tile with the opposite color
                color = opposite_color(board[i + 1][col]);
                mark_square_as(board, size, i, col, color, announce);
            }
        }
        // Check if there is a same-colored tile next to or
        // one tile to the right from the current tile
        if (board[i][col] != UNKNOWN) {
            if ((board[i + 1][col] == board[i][col]) &&
                (board[i + 2][col] == UNKNOWN)) {
                // Mark the tile with the opposite color
                color = opposite_color(board[i][col]);
                mark_square_as(board, size, i + 2, col, color, announce);
            } else if ((board[i + 2][col] == board[i][col]) &&
                       (board[i + 1][col] == UNKNOWN)) {
                // Mark the tile with the opposite color
                color = opposite_color(board[i][col]);
                mark_square_as(board, size, i + 1, col, color, announce);
            }
        }
    }

    return;
}


void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    
    int countX = 0;
    int countO = 0;
    
    // Get the valid number of each color in a board
    int maxTileOfSameColor = size / 2;

    for (int i = 0; i < size; i++) {
        if (board[row][i] == RED) {
            countX++;
        } else if (board[row][i] == BLUE) {
            countO++;
        }
    }
    
    // Check if the number of RED or BLUE tiles is at maximum value allowed
    if (countX == maxTileOfSameColor) {
        int color = opposite_color(RED);
        for (int i = 0; i < size; i++) {
            if (board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, color, announce);
            }
        }
    } else if (countO == maxTileOfSameColor) {
        int color = opposite_color(BLUE);
        for (int i = 0; i < size; i++) {
            if (board[row][i] == UNKNOWN) {
                mark_square_as(board, size, row, i, color, announce);
            }
        }
    }

    return;
}

void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int col,
                          bool announce) {
    int countX = 0;
    int countO = 0;
    
    // Get the valid number of each color in a board
    int maxTileOfSameColor = size / 2;
    
    for (int i = 0; i < size; i++) {
        if (board[i][col] == RED) {
            countX++;
        } else if (board[i][col] == BLUE) {
            countO++;
        }
    }
    
    // Check if the number of RED or BLUE tiles is at maximum value allowed
    if (countX == maxTileOfSameColor) {
        int color = BLUE;
        for (int i = 0; i < size; i++) {
            if (board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, color, announce);
            }
        }
    } else if (countO == maxTileOfSameColor) {
        int color = RED;
        for (int i = 0; i < size; i++) {
            if (board[i][col] == UNKNOWN) {
                mark_square_as(board, size, i, col, color, announce);
            }
        }
    }

    return;
}


/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    
    int count_unknown;
    count_unknown = count_unknown_squares(board, size);
    
    // Check if board still has UNKNOWN tiles,
    // if not then check if board is valid
    if (count_unknown > 0) {
        return false;
    } else {
        return board_is_valid(board, size);
    }
}

bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    
    // Check if row & col indices are out of bounds
    // and color char is not valid
    if ((row_input > size || row_input <= 0) ||
        (toupper(col_input) > 'A' + size - 1 || toupper(col_input) < 'A') ||
        (toupper(color_char) != RED_LETTER &&
         toupper(color_char) != BLUE_LETTER &&
         color_char != UNKNOWN_LETTER)) {
        cout << "Sorry, that's not a valid input." << endl;
        return false;
    }
    
    // Update the row and column indices if inputs are valid
    row = row_input - 1;
    col = toupper(col_input) - 'A';
    
    return true;
}

bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    
    // Make a copy of current board to evaluate
    int check_validity_board[MAX_SIZE][MAX_SIZE];
    copy_board(current_board, check_validity_board, size);
    
    if (original_board[row][col] == UNKNOWN) {
        // Mark in the move and check if board is valid
        mark_square_as(check_validity_board, size, row, col, color, false);
        if (board_is_valid(check_validity_board, size)) {
            return true;
        } else {
            cout << "Sorry, that move violates a rule." << endl;
        }
    }
    else {
        cout << "Sorry, original squares cannot be changed." << endl;
    }
    
    return false;
}
