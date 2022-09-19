#include <iostream>
#include <string>
#include <cassert>

// Class for keeping track of the game state
// as well as the winner
class display_board {
public:
    display_board () :
        free_blocks(9), // to check empty spaces or blocks in the game
        winner(EMPTY)
    {
        for (int i = 0; i < 9; i++)
            values[i] = EMPTY;
    }
    ~display_board() = default;

    // Print function to display the broad
    void print () const;


    // Check if a spot is marked or not
    bool is_set (const int num) const { return values[num-1] != EMPTY; }

    // sets a cross at the given spot
    void mark_cross (const int num) {
        values[num-1] = CROSS;
        --free_blocks;
    }

    // sets a circle at the given spot
    void mark_circle (const int num) {
        values[num-1] = CIRCLE;
        --free_blocks;
    }

    int find_free_spot () const;

    // checking if the game on or not?
    bool complete ();

    // will check if the player won
    bool winner_cross ();

    // will check if the computer won
    bool winner_circle ();

private:
    enum tictactoe_moves {
        EMPTY = 0,
        CROSS,
        CIRCLE
    };
    bool is_full () const { return free_blocks == 0; }
    bool find_winner (tictactoe_moves player) const;
    void debug_values () const {
        std::cout << "values: ";
        for (int i = 0; i < 9; ++i)
            std::cout << values[i] << " ";
        std::cout << "\n";
    }

    static const char * const player_strings[3];
    tictactoe_moves values[9];
    int free_blocks;
    tictactoe_moves winner;
};

const char * const display_board::player_strings[3] = {"_","X","O"};

void display_board::print () const {
    int itr = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << player_strings[ values[itr++] ] << " ";
        }
        std::cout << "\n";
    }
}

int display_board::find_free_spot() const {
    assert(!is_full());
    for (int i = 8; i >= 0; --i)
        if (values[i] == EMPTY)
            return i+1;
    return -1;
}

bool display_board::find_winner (const tictactoe_moves player) const {
    // checking the rows
    for (int i = 0; i < 9; i += 3)
        if (values[i] == player &&
            values[i+1] == player &&
            values[i+2] == player) {
            return true;
        }

    // checking the columns
    for (int i = 0; i < 3; ++i)
        if (values[i] == player &&
            values[i+3] == player &&
            values[i+6] == player) {
            return true;
        }

    // check the diagonal cells
    if (values[0] == player &&
        values[4] == player &&
        values[8] == player)
        return true;

    if (values[2] == player &&
        values[4] == player &&
        values[6] == player)
        return true;

    return false;
}

bool display_board::winner_cross () {
    if (winner == CROSS)
        return true;

    if (find_winner (CROSS)) {
        winner = CROSS;
        return true;
    }

    return false;
}

bool display_board::winner_circle () {
    if (winner == CIRCLE)
        return true;

    if (find_winner (CIRCLE)) {
        winner = CIRCLE;
        return true;
    }

    return false;
}

bool display_board::complete() {
    return is_full() || winner_cross() || winner_circle();
}

static void start_game () {
    std::cout << "Welcome to Timmy's & Shawana's Tic-Tac-Toe\nYou play crosses, the computer plays circles\n";

    display_board board;

    while (!board.complete()) {
        board.print();

        std::cout << "Press 1 to 9: ";
        int num;
        std::cin >> num;
        if (num > 9 || num < 1)
            std::cout << "Number is out of range, try again\n";
        else if (board.is_set(num))
            std::cout << "That spot is already taken, try something else\n";
        else {
            board.mark_cross(num);
            if (!board.complete()) {
                board.mark_circle(board.find_free_spot());
            }
        }
        std::cout << "\n";
    }

    board.print();
    std::cout << "Game over\n";
    if (board.winner_circle())
        std::cout << "Computer won\n";
    else if (board.winner_cross())
        std::cout << "You won\n";
    else
        std::cout << "No winner\n";
}

int main () {
    start_game();
    return 0;
}