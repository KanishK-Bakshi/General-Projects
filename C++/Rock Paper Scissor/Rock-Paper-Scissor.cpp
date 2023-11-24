#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void display_choices();
void multiplayer_make_decision(int player1_choice, int player2_choice);
void singleplayer_make_decision(int player_choice, int computer_choice);

int main() {
    cout << "If you want to play with the computer, press 1\nIf you want to play with a friend, press 2\n";
    int number_of_players;
    cin >> number_of_players;
    display_choices();

    if (number_of_players == 1) {
        cout << "Player 1 Choice ";
        int player_choice;
        cin >> player_choice;

        int computer_choice;
        srand(time(0));
        computer_choice = rand() % 3 + 1;

        cout << "\n";
        singleplayer_make_decision(player_choice, computer_choice);
    }
    else if (number_of_players == 2) {
        cout << "Player 1 Chance Choose ";
        int player1_choice;
        cin >> player1_choice;

        cout << "Player 2 Chance Choose ";
        int player2_choice;
        cin >> player2_choice;

        cout << "\n";
        multiplayer_make_decision(player1_choice, player2_choice);
    }
    else{
        cout << "!!! ONLY TWO PLAYERS CAN PLAY THE GAME ENTER NUMBER 1 OR 2 !!!";
    }

    return 0;
}

void singleplayer_make_decision(int player_choice, int computer_choice) {
    if (player_choice == computer_choice) {
        cout << "DRAW";
    }
    else if (player_choice == 1 && computer_choice == 2 || player_choice == 2 && computer_choice == 3 || player_choice == 3 && computer_choice == 1) {
        cout << "You Loose";
    }
    else if (player_choice == 1 && computer_choice == 3 || player_choice == 2 && computer_choice == 1 || player_choice == 3 && computer_choice == 2) {
        cout << "You Win Congratulations";
    }
    else {
        cout << "There has been some error";
    }
}

void multiplayer_make_decision(int player1_choice, int player2_choice) {
    if (player1_choice == player2_choice) {
        cout << "DRAW";
    }
    else if (player1_choice == 1 && player2_choice == 2 || player1_choice == 2 && player2_choice == 3 || player1_choice == 3 && player2_choice == 1) {
        cout << "Player 2 Wins Congratulations";
    }
    else if (player1_choice == 1 && player2_choice == 3 || player1_choice == 2 && player2_choice == 1 || player1_choice == 3 && player2_choice == 2) {
        cout << "Player 1 Wins Congratulations";
    }
    else {
        cout << "There has been some error";
    }
}

void display_choices() {
    cout << "Choose from rock paper scissor"
         << "\nRock  ----> 1"
         << "\nPaper  ----> 2"
         << "\nScissor  ----> 3\n";
}
