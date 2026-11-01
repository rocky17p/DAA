#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> board; // board[row] = column

bool isSafe(int row, int col) {

    for(int i = 0; i < N; i++) {

        if(board[i] == -1)
            continue;

        // Same column
        if(board[i] == col)
            return false;

        // Same diagonal
        if(abs(board[i] - col) == abs(i - row))
            return false;
    }

    return true;
}

bool solve(int row, int firstRow) {

    // All rows processed
    if(row == N)
        return true;

    // First queen is already placed in this row
    if(row == firstRow)
        return solve(row + 1, firstRow);

    for(int col = 0; col < N; col++) {

        if(isSafe(row, col)) {

            board[row] = col;

            if(solve(row + 1, firstRow))
                return true;

            // Backtrack
            board[row] = -1;
        }
    }

    return false;
}

void printBoard() {

    for(int i = 0; i < N; i++) {

        for(int j = 0; j < N; j++) {

            if(board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }

        cout << endl;
    }
}

int main() {

    cout << "Enter N: ";
    cin >> N;

    int firstRow, firstCol;

    cout << "Enter position of first queen (row col): ";
    cin >> firstRow >> firstCol;

    // Validate position
    if(firstRow < 0 || firstRow >= N ||
       firstCol < 0 || firstCol >= N) {

        cout << "Invalid position\n";
        return 0;
    }

    board.assign(N, -1);

    // Place first queen
    board[firstRow] = firstCol;

    if(solve(0, firstRow)) {

        cout << "\nN-Queens Matrix:\n";
        printBoard();

    } else {

        cout << "\nNo solution exists for this position\n";
    }

    return 0;
}
