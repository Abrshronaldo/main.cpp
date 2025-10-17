





#include <jni.h>


#include <iostream>



extern "C"

char board[3][3];
char currentPlayer = 'X';

void initializeBoard() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            board[i][j] = ' ';
}

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << "\n";
        if (i < 2) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool isWin() {
    for (int i = 0; i < 3; ++i)
        if (board[i][0] == currentPlayer &&
            board[i][1] == currentPlayer &&
            board[i][2] == currentPlayer)
            return true;

    for (int j = 0; j < 3; ++j)
        if (board[0][j] == currentPlayer &&
            board[1][j] == currentPlayer &&
            board[2][j] == currentPlayer)
            return true;

    if (board[0][0] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][2] == currentPlayer)
        return true;

    if (board[0][2] == currentPlayer &&
        board[1][1] == currentPlayer &&
        board[2][0] == currentPlayer)
        return true;

    return false;
}

bool isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (board[i][j] == ' ')
                return false;
    return true;
}

void switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

void playGame() {
    int row, col;
    initializeBoard();
    while (true) {
        printBoard();
        cout << "Player " << currentPlayer << ", enter row and column (0-2): ";
        cin >> row >> col;

        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            cout << "Invalid move. Try again.\n";
            continue;
        }

        board[row][col] = currentPlayer;

        if (isWin()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!\n";
            break;
        }

        if (isDraw()) {
            printBoard();
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }
}





  JNIEXPORT jstring JNICALL
Java_M_stringFromJNI(JNIEnv* env, jobject ,jobject data) {

   playGame();
    


    return env->NewStringUTF("Hello from C++");
}
                                                 
                                         
