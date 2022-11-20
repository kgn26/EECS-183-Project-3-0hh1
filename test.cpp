/**
 * test.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 *
 * Khanh Gia Nguyen
 * kgnguyen
 *
 * This file contains the test cases for functions in ohhi.cpp
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_solve_balance_row();
void test_solve_balance_column();
void test_board_is_solved();
void test_check_valid_input();
void test_check_valid_move();

void startTests() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
    test_rows_are_different();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_solve_balance_row();
    test_solve_balance_column();
    test_board_is_solved();
    test_check_valid_input();
    test_check_valid_move();
}


void test_count_unknown_squares() {
    cout << "---- Testing count_unknown_squares() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << count_unknown_squares(board, size_1) << endl;

    // test case 2
    string test_board_2[] = {"----",
                             "----",
                             "----",
                             "----"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << count_unknown_squares(board, size_2) << endl;
    
    // test case 3
    string test_board_3[] = {"XXOO",
                             "OOXX",
                             "OXOX",
                             "XOXO"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << count_unknown_squares(board, size_3) << endl;
    
    // test case 4
    string test_board_4[] = {"--X---",
                             "--XO--",
                             "-----O",
                             "------",
                             "-XX---",
                             "---OO-"};
    int size_4 = 6;
    read_board_from_string(board, test_board_4, size_4);
    cout << count_unknown_squares(board, size_4) << endl;
    
    // test case 5
    string test_board_5[] = {"--X-----",
                             "--XO----",
                             "-----O--",
                             "O---OXX-",
                             "-XX-----",
                             "---OO---",
                             "-----X--",
                             "--------"};
    int size_5 = 8;
    read_board_from_string(board, test_board_5, size_5);
    cout << count_unknown_squares(board, size_5) << endl;
}

void test_row_has_no_threes_of_color() {
    cout << "---- Testing row_has_no_threes_of_color() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_board_1[] = {"----",
                             "XXX-",
                             "-XX-",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << row_has_no_threes_of_color(board, size_1, 1, RED) << endl;
    
    // Test case 2
    string test_board_2[] = {"----",
                             "XXX-",
                             "-XX-",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << row_has_no_threes_of_color(board, size_2, 2, RED) << endl;
    
    // Test case 3
    string test_board_3[] = {"----",
                             "XXX-",
                             "-XX-",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << row_has_no_threes_of_color(board, size_3, 1, BLUE) << endl;
    
    // Test case 4
    string test_board_4[] = {"----",
                             "X---",
                             "-O--",
                             "----"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << row_has_no_threes_of_color(board, size_4, 0, BLUE) << endl;
    
    // Test case 5
    string test_board_5[] = {"-XX-",
                             "X---",
                             "-XXX",
                             "-OOO"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << row_has_no_threes_of_color(board, size_5, 3, BLUE) << endl;
}

void test_col_has_no_threes_of_color() {
    cout << "---- Testing col_has_no_threes_of_color() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_board_1[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << col_has_no_threes_of_color(board, size_1, 1, RED) << endl;
    
    // Test case 2
    string test_board_2[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << col_has_no_threes_of_color(board, size_2, 2, RED) << endl;
    
    // Test case 3
    string test_board_3[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--O-"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << col_has_no_threes_of_color(board, size_3, 2, BLUE) << endl;
    
    // Test case 4
    string test_board_4[] = {"----",
                             "X---",
                             "-O--",
                             "----"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << col_has_no_threes_of_color(board, size_4, 0, BLUE) << endl;
    
    // Test case 5
    string test_board_5[] = {"-XX-",
                             "-X--",
                             "-XXX",
                             "-OOO"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << col_has_no_threes_of_color(board, size_5, 1, RED) << endl;
}

void test_board_has_no_threes() {
    cout << "---- Testing col_has_no_threes_of_color() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_board_1[] = {"-OX-",
                             "-O--",
                             "-OXX",
                             "-OOO"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, 4);
    cout << board_has_no_threes(board, size_1) << endl;
    
    // Test case 2
    string test_board_2[] = {"----",
                             "X---",
                             "-O--",
                             "----"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_threes(board, size_2) << endl;
}

void test_rows_are_different() {
    cout << "---- Testing rows_are_different() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_board_1[] = {"-OX-",
                             "-O--",
                             "-OOO",
                             "-OOO"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << rows_are_different(board, size_1, 2, 3) << endl;
    
    // Test case 2
    string test_board_2[] = {"XX--",
                             "XXO-",
                             "XXO-",
                             "----"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << rows_are_different(board, size_2, 0, 1) << endl;
}

void test_cols_are_different() {
    cout << "---- Testing cols_are_different() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_board_1[] = {"-OX-",
                             "-O--",
                             "-OOO",
                             "-OOO"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << cols_are_different(board, size_1, 1, 2) << endl;
    
    // Test case 2
    string test_board_2[] = {"XX--",
                             "XXO-",
                             "XXO-",
                             "----"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << cols_are_different(board, size_2, 0, 1) << endl;
}

void test_board_has_no_duplicates() {
    cout << "---- Testing board_has_no_duplicates() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_board_1[] = {"-OX-",
                             "-O--",
                             "-OOO",
                             "-OOO"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_has_no_duplicates(board, size_1) << endl;
    
    // Test case 2
    string test_board_2[] = {"XX--",
                             "XXO-",
                             "XXO-",
                             "----"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_has_no_duplicates(board, size_2) << endl;
    
    // Test case 3
    string test_board_3[] = {"XX--",
                             "XOO-",
                             "XXO-",
                             "-XXO"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_has_no_duplicates(board, size_3) << endl;
    
    // Test case 4
    string test_board_4[] = {"XOXO",
                             "----",
                             "XOXO",
                             "OXOX"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    cout << board_has_no_duplicates(board, size_4) << endl;
    
    // Test case 5
    string test_board_5[] = {"XOXO",
                             "X-X-",
                             "X-XO",
                             "OXOX"};
    int size_5 = 4;
    read_board_from_string(board, test_board_5, size_5);
    cout << board_has_no_duplicates(board, size_5) << endl;
}

void test_solve_three_in_a_row() {
    cout << "---- Testing solve_three_in_a_row() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_board_1[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "--XX"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    print_board(board, size_1);
    solve_three_in_a_row(board, size_1, 0, true);
    print_board(board, size_1);
    cout << endl;
    
    // Test case 2
    string test_board_2[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "--XX"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    print_board(board, size_2);
    solve_three_in_a_row(board, size_2, 1, true);
    print_board(board, size_2);
    cout << endl;
    
    // Test case 3
    string test_board_3[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "--XX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    print_board(board, size_3);
    solve_three_in_a_row(board, size_3, 2, true);
    print_board(board, size_3);
    cout << endl;
    
    // Test case 4
    string test_board_4[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "--XX"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    print_board(board, size_4);
    solve_three_in_a_row(board, size_4, 3, true);
    print_board(board, size_4);
}

void test_solve_three_in_a_column() {
    cout << "---- Testing solve_three_in_a_column() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_board_1[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    print_board(board, size_1);
    solve_three_in_a_column(board, size_1, 0, true);
    print_board(board, size_1);
    cout << endl;
    
    // Test case 2
    string test_board_2[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    print_board(board, size_2);
    solve_three_in_a_column(board, size_2, 1, true);
    print_board(board, size_2);
    cout << endl;
    
    // Test case 3
    string test_board_3[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    print_board(board, size_3);
    solve_three_in_a_column(board, size_3, 2, true);
    print_board(board, size_3);
    cout << endl;
    
    // Test case 4
    string test_board_4[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    print_board(board, size_4);
    solve_three_in_a_column(board, size_4, 3, true);
    print_board(board, size_4);
}

void test_solve_balance_row() {
    cout << "---- Testing solve_balance_row() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_board_1[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    print_board(board, size_1);
    solve_balance_row(board, size_1, 0, true);
    print_board(board, size_1);
    cout << endl;
    
    // Test case 2
    string test_board_2[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    print_board(board, size_2);
    solve_balance_row(board, size_2, 1, true);
    print_board(board, size_2);
    cout << endl;
    
    // Test case 3
    string test_board_3[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    print_board(board, size_3);
    solve_balance_row(board, size_3, 2, true);
    print_board(board, size_3);
    cout << endl;
    
    // Test case 4
    string test_board_4[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    print_board(board, size_4);
    solve_balance_row(board, size_4, 3, true);
    print_board(board, size_4);
    cout << endl;
}

void test_solve_balance_column() {
    cout << "---- Testing solve_balance_column() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_board_1[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    print_board(board, size_1);
    solve_balance_column(board, size_1, 0, true);
    print_board(board, size_1);
    cout << endl;
    
    // Test case 2
    string test_board_2[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    print_board(board, size_2);
    solve_balance_column(board, size_2, 1, true);
    print_board(board, size_2);
    cout << endl;
    
    // Test case 3
    string test_board_3[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    print_board(board, size_3);
    solve_balance_column(board, size_3, 2, true);
    print_board(board, size_3);
    cout << endl;
    
    // Test case 4
    string test_board_4[] = {"XX--",
                             "X-X-",
                             "-XX-",
                             "---X"};
    int size_4 = 4;
    read_board_from_string(board, test_board_4, size_4);
    print_board(board, size_4);
    solve_balance_column(board, size_4, 3, true);
    print_board(board, size_4);
}

void test_board_is_solved() {
    cout << "---- Testing solve_balance_column() ----" << endl;
    
    int board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_board_1[] = {"XXOO",
                             "XOXO",
                             "OOXX",
                             "OXOX"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << board_is_solved(board, size_1) << endl;
    
    // Test case 2
    string test_board_2[] = {"XOOO",
                             "XOXO",
                             "OOXX",
                             "OXOX"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << board_is_solved(board, size_2) << endl;
    
    // Test case 3
    string test_board_3[] = {"X-OO",
                             "XOXO",
                             "OO-X",
                             "OXOX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << board_is_solved(board, size_3) << endl;
}

void test_check_valid_input() {
    cout << "---- Testing check_valid_input() ----" << endl;
    
    int current_row = 0;
    int current_col = 0;
    
    // Test case 1
    int size_1 = 4;
    cout << check_valid_input(size_1, 2, 'A', 'O', current_row, current_col)
         << endl;
    cout << "Current row and column: " << current_row << " " << current_col
         << endl;
    
    // Test case 2
    int size_2 = 4;
    cout << check_valid_input(size_2, 3, 'C', 'X', current_row, current_col)
         << endl;
    cout << "Current row and column: " << current_row << " " << current_col
         << endl;
    
    // Test case 3
    int size_3 = 4;
    cout << check_valid_input(size_3, 2, 'E', 'X', current_row, current_col)
         << endl;
    cout << "Current row and column: " << current_row << " " << current_col
         << endl;
    
    // Test case 4
    int size_4 = 4;
    cout << check_valid_input(size_4, 5, '2', 'X', current_row, current_col)
         << endl;
    cout << "Current row and column: " << current_row << " " << current_col
         << endl;
}

void test_check_valid_move() {
    cout << "---- Testing check_valid_move() ----" << endl;
    
    int original_board[MAX_SIZE][MAX_SIZE];
    int current_board[MAX_SIZE][MAX_SIZE];
    
    // Test case 1
    string test_original_board_1[] = {"X--O",
                                      "XO--",
                                      "-X-X",
                                      "----"};
    string test_current_board_1[] = {"X--O",
                                     "XO--",
                                     "OXOX",
                                     "----"};
    int size_1 = 4;
    read_board_from_string(original_board, test_original_board_1, size_1);
    read_board_from_string(current_board, test_current_board_1, size_1);
    cout << check_valid_move(original_board, current_board, size_1, 0, 2, BLUE)
         << endl;
    
    // Test case 2
    string test_original_board_2[] = {"X--O",
                                      "XOX-",
                                      "-X-X",
                                      "----"};
    string test_current_board_2[] = {"X--O",
                                     "XOX-",
                                     "OXOX",
                                     "-X--"};
    int size_2 = 4;
    read_board_from_string(original_board, test_original_board_2, size_2);
    read_board_from_string(current_board, test_current_board_2, size_2);
    cout << check_valid_move(original_board, current_board, size_2, 3, 1, BLUE)
         << endl;
    
    // Test case 3
    string test_original_board_3[] = {"X--O",
                                      "XOX-",
                                      "-X-X",
                                      "----"};
    string test_current_board_3[] = {"X--O",
                                     "XOX-",
                                     "OXOX",
                                     "----"};
    int size_3 = 4;
    read_board_from_string(original_board, test_original_board_3, size_3);
    read_board_from_string(current_board, test_current_board_3, size_3);
    cout << check_valid_move(original_board, current_board, size_3, 0, 0, RED)
         << endl;
    
    // Test case 4
    string test_original_board_4[] = {"X--O",
                                      "XOX-",
                                      "-X-X",
                                      "----"};
    string test_current_board_4[] = {"X--O",
                                     "XOX-",
                                     "OXOX",
                                     "----"};
    int size_4 = 4;
    read_board_from_string(original_board, test_original_board_4, size_4);
    read_board_from_string(current_board, test_current_board_4, size_4);
    cout << check_valid_move(original_board, current_board, size_4, 1, 3, RED)
         << endl;
}
