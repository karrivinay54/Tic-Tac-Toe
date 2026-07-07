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

bool playerMove()
{
    cout << "\nPlayer " << currentPlayer << ", enter position (1-9): ";
    cin >> choice;

    switch(choice)
    {
        case 1:
    if(board[0][0]=='1')
        board[0][0]=currentPlayer;
    else
    {
        cout << "\nCell already occupied! Try again.\n";
        return false;
    }
    break;

        case 2:
            if(board[0][1]=='2')
             board[0][1]=currentPlayer;
            else
{
    cout << "\nCell already occupied! Try again.\n";
    return false;
}
break;

        case 3:
            if(board[0][2]=='3') board[0][2]=currentPlayer;
            else
{
    cout << "\nCell already occupied! Try again.\n";
    return false;
}
break;


        case 4:
            if(board[1][0]=='4') board[1][0]=currentPlayer;
           else
{
    cout << "\nCell already occupied! Try again.\n";
    return false;
}
break;


        case 5:
            if(board[1][1]=='5') board[1][1]=currentPlayer;
            else
{
    cout << "\nCell already occupied! Try again.\n";
    return false;
}
break;


        case 6:
            if(board[1][2]=='6') board[1][2]=currentPlayer;
           else
{
    cout << "\nCell already occupied! Try again.\n";
    return false;
}
break;


        case 7:
            if(board[2][0]=='7') board[2][0]=currentPlayer;
            else
{
    cout << "\nCell already occupied! Try again.\n";
    return false;
}
break;

        case 8:
            if(board[2][1]=='8') board[2][1]=currentPlayer;
           else
{
    cout << "\nCell already occupied! Try again.\n";
    return false;
}
break;

        case 9:
            if(board[2][2]=='9') board[2][2]=currentPlayer;
            else
{
    cout << "\nCell already occupied! Try again.\n";
    return false;
}
            break;

        default:
    cout << "\nInvalid Move!\n";
    return false;
    }


    if(currentPlayer=='X')
    currentPlayer='O';
else
    currentPlayer='X';

return true;
}

bool checkWin()
{
    // Rows
    for(int i = 0; i < 3; i++)
    {
        if(board[i][0] == board[i][1] &&
           board[i][1] == board[i][2])
            return true;
    }

    // Columns
    for(int i = 0; i < 3; i++)
    {
        if(board[0][i] == board[1][i] &&
           board[1][i] == board[2][i])
            return true;
    }

    // Main diagonal
    if(board[0][0] == board[1][1] &&
       board[1][1] == board[2][2])
        return true;

    // Other diagonal
    if(board[0][2] == board[1][1] &&
       board[1][1] == board[2][0])
        return true;

    return false;
}

bool checkDraw()
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if(board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }

    return true;
}

void resetBoard()
{
    char value = '1';

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            board[i][j] = value++;
        }
    }

    currentPlayer = 'X';
}

int main()
{
    char playAgain;

    do
    {
        resetBoard();

        cout << "=================================\n";
        cout << "        TIC TAC TOE GAME\n";
        cout << "=================================\n";

        while(true)
        {
            displayBoard();

            if(!playerMove())
                continue;

            if(checkWin())
            {
                displayBoard();

                if(currentPlayer == 'X')
                    cout << "\n🎉 Player O Wins!\n";
                else
                    cout << "\n🎉 Player X Wins!\n";

                break;
            }

            if(checkDraw())
            {
                displayBoard();

                cout << "\nMatch Draw!\n";

                break;
            }
        }

        cout << "\nPlay Again? (Y/N): ";
        cout << "\n";
        cout << "=================================\n";
        cin >> playAgain;

    } while(playAgain == 'Y' || playAgain == 'y');

    cout << "\nThanks for playing!\n";

    return 0;
}