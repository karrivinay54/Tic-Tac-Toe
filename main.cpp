#include <iostream>

using namespace std;

// Game Board
char board[3][3] =
{
    {'1','2','3'},
    {'4','5','6'},
    {'7','8','9'}
};

char currentPlayer = 'X';
int choice;

// Display Board
void displayBoard()
{
    cout << "\n";

    cout << " " << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
    cout << "---|---|---" << endl;
    cout << " " << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

void playerMove()
{
    cout << "\nPlayer " << currentPlayer << ", enter position (1-9): ";
    cin >> choice;

    switch(choice)
    {
        case 1:
            if(board[0][0]=='1') board[0][0]=currentPlayer;
            else return;
            break;

        case 2:
            if(board[0][1]=='2') board[0][1]=currentPlayer;
            else return;
            break;

        case 3:
            if(board[0][2]=='3') board[0][2]=currentPlayer;
            else return;
            break;

        case 4:
            if(board[1][0]=='4') board[1][0]=currentPlayer;
            else return;
            break;

        case 5:
            if(board[1][1]=='5') board[1][1]=currentPlayer;
            else return;
            break;

        case 6:
            if(board[1][2]=='6') board[1][2]=currentPlayer;
            else return;
            break;

        case 7:
            if(board[2][0]=='7') board[2][0]=currentPlayer;
            else return;
            break;

        case 8:
            if(board[2][1]=='8') board[2][1]=currentPlayer;
            else return;
            break;

        case 9:
            if(board[2][2]=='9') board[2][2]=currentPlayer;
            else return;
            break;

        default:
            cout << "\nInvalid Move!\n";
            return;
    }

    if(currentPlayer=='X')
        currentPlayer='O';
    else
        currentPlayer='X';
}

int main()
{
    cout << "=================================\n";
    cout << "        TIC TAC TOE GAME\n";
    cout << "=================================\n";

    for(int i=0;i<9;i++)
    {
        displayBoard();
        playerMove();
    }

    displayBoard();

    return 0;
}