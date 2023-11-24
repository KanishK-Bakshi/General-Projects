#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int check_winner(char matrix[3][3]);
int tic_tac_toe_multiple_player();
int tic_tac_toe_single_player();
int display_tic_tac_toe_matrix(char matrix_function[3][3]);

int main() {
    cout << "Welcome to The Game of\n\tTIC TAC TOE";
    int number_of_players;
    cout << "Enter the number of players (1/2)";
    cin >> number_of_players;

    int winner;

    if (number_of_players == 1) {
        winner = tic_tac_toe_single_player();
    } else if (number_of_players == 2) {
        winner = tic_tac_toe_multiple_player();
    } else {
        cout << "Enter a valid number of players. Maximum only two players can play Tic Tac Toe." << endl;
    }

    if (winner == 1) {
        cout << "Congrats!!! Player 1 is the Winner" << endl;
    } else if (winner == 2) {
        cout << "Congrats!!! Player 2 is the Winner" << endl;
    } else if (winner == 0) {
        cout << "!!! DRAW !!!" << endl;
    } else {
        cout << "!!! Error !!!" << endl;
    }
    return 0;
}

int display_tic_tac_toe_matrix(char matrix_function[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << " | " << matrix_function[i][j];
        }
        cout << " | " << endl;
        if (i < 2) {
            cout << " |---|---|---| " << endl;
        }
    }
    return 0;
}

int check_winner(char matrix[3][3]){
    // Check rows
    for(int i = 0; i < 3; i++){
        if(matrix[i][0] == matrix[i][1] && matrix[i][1] == matrix[i][2]){
            if(matrix[i][0] == '0') return 1;
            if(matrix[i][0] == 'X') return 2;
        }
    }

    // Check columns
    for(int i = 0; i < 3; i++){
        if(matrix[0][i] == matrix[1][i] && matrix[1][i] == matrix[2][i]){
            if(matrix[0][i] == '0') return 1;
            if(matrix[0][i] == 'X') return 2;
        }
    }

    // Check diagonals
    if(matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2]){
        if(matrix[0][0] == '0') return 1;
        if(matrix[0][0] == 'X') return 2;
    }
    
    if(matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0]){
        if(matrix[0][2] == '0') return 1;
        if(matrix[0][2] == 'X') return 2;
    }

    // No winner
    return 0;
}


int tic_tac_toe_single_player(){
    int winner_player = 0; // draw condition by default
    int total_count = 0; // Variable to know how many times the input has been feeded in the Tic Tac Toe (Maximum 9 time only)
    char matrix_display[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char matrix[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    display_tic_tac_toe_matrix(matrix_display);

    while(total_count < 9){
        cout << "Choose from the numbers in this matrix to Play your move and put 0 or 1 at that location";

        // For Player 1
        cout << "Player 1 Choice: Enter a location to mark 0: ";
        int player1_input;
        cin >> player1_input;

        if(player1_input < 1 || player1_input > 9){
            cout << "Enter a valid number between (1-9)";
        }
        else{
            int count1 = 1;
            for (int i=0; i<3 ;i++){
                for(int j=0 ; j<3 ;j++){
                    if(count1 == player1_input && (matrix[i][j] == '0' || matrix[i][j] == 'X')){
                        cout << "Location already marked ";
                    }
                    else if(count1 == player1_input){
                        matrix[i][j] = '0';
                        total_count++;
                    }
                    count1++ ;
                }
            }
        }

        display_tic_tac_toe_matrix(matrix);

        // Check if Player 1 wins
        if(check_winner(matrix) == 1){
            return 1;
        }

        // For Player 2
        cout << "Computer Choice: Thinking...... " << endl;
        int player2_input;
        srand(time(0));  
        int randomNumber = rand() % 9 + 1;
        player2_input = randomNumber;

        if(player2_input < 1 || player2_input > 9){
            cout << "Enter a valid number between (1-9)";
        }
        else{
            int count2 = 1;
            for (int i=0; i<3 ;i++){
                for(int j=0 ; j<3 ;j++){
                    if(count2 == player2_input && (matrix[i][j] == '0' || matrix[i][j] == 'X')){
                        continue;
                    }
                    else if(count2 == player2_input){
                        matrix[i][j] = 'X';
                        total_count++;
                    }
                    count2++;
                }
            }
        }

        display_tic_tac_toe_matrix(matrix);

        // Check if Player 2 wins
        if(check_winner(matrix) == 2){
            return 2;
        }
    }

    // If no one wins and all spots are filled, it's a draw
    return 0;
}

int tic_tac_toe_multiple_player(){
    int winner_player = 0; // draw condition by default
    int total_count = 0; // Variable to know how many times the input has been feeded in the Tic Tac Toe (Maximum 9 time only)
    char matrix_display[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    char matrix[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    display_tic_tac_toe_matrix(matrix_display);

    while(total_count < 9){
        cout << "Choose from the numbers in this matrix to Play your move and put 0 or 1 at that location";

        // For Player 1
        cout << "Player Choice: Enter a location to mark 0: ";
        int player1_input;
        cin >> player1_input;

        if(player1_input < 1 || player1_input > 9){
            cout << "Enter a valid number between (1-9)";
        }
        else{
            int count1 = 1;
            for (int i=0; i<3 ;i++){
                for(int j=0 ; j<3 ;j++){
                    if(count1 == player1_input && (matrix[i][j] == '0' || matrix[i][j] == 'X')){
                        cout << "Location already marked ";
                    }
                    else if(count1 == player1_input){
                        matrix[i][j] = '0';
                        total_count++;
                    }
                    count1++ ;
                }
            }
        }

        display_tic_tac_toe_matrix(matrix);

        // Check if Player 1 wins
        if(check_winner(matrix) == 1){
            return 1;
        }

        // For Player 2
        cout << "Player 2 Choice: Enter a location to mark 1: ";
        int player2_input;
        cin >> player2_input;

        if(player2_input < 1 || player2_input > 9){
            cout << "Enter a valid number between (1-9)";
        }
        else{
            int count2 = 1;
            for (int i=0; i<3 ;i++){
                for(int j=0 ; j<3 ;j++){
                    if(count2 == player2_input && (matrix[i][j] == '0' || matrix[i][j] == 'X')){
                        cout << "Location already marked ";
                    }
                    else if(count2 == player2_input){
                        matrix[i][j] = 'X';
                        total_count++;
                    }
                    count2++;
                }
            }
        }

        display_tic_tac_toe_matrix(matrix);

        // Check if Player 2 wins
        if(check_winner(matrix) == 2){
            return 2;
        }
    }

    // If no one wins and all spots are filled, it's a draw
    return 0;
}