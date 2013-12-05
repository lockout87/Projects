#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;
char chBoard[9];
int iCMove;
bool NoWin = true;

void initilize_board(char board[9]){
    for (int i = 0; i<9; i++){
        board[i] = ' ';
    }
}

void draw_board(char board[9]){
    cout << board[0] << "|" << board[1] << "|" << board[2] << endl;
    cout << board[3] << "|" << board[4] << "|" << board[5] << endl;
    cout << board[6] << "|" << board[7] << "|" << board[8] << endl;
}

int Check_Win(char bd[9]){
    if ((bd[0] == 'X' && bd[1] == 'X' && bd[2] == 'X') ||
        (bd[3] == 'X' && bd[4] == 'X' && bd[5] == 'X') ||
        (bd[6] == 'X' && bd[7] == 'X' && bd[8] == 'X') ||
        (bd[0] == 'X' && bd[3] == 'X' && bd[6] == 'X') ||
        (bd[1] == 'X' && bd[4] == 'X' && bd[7] == 'X') ||
        (bd[2] == 'X' && bd[5] == 'X' && bd[8] == 'X') ||
        (bd[0] == 'X' && bd[4] == 'X' && bd[8] == 'X') ||
        (bd[2] == 'X' && bd[4] == 'X' && bd[6] == 'X'))
    {
        return 1;
    }
    else if((bd[0] == 'O' && bd[1] == 'O' && bd[2] == 'O') ||
        (bd[3] == 'O' && bd[4] == 'O' && bd[5] == 'O') ||
        (bd[7] == 'O' && bd[8] == 'O' && bd[6] == 'O') ||
        (bd[0] == 'O' && bd[3] == 'O' && bd[6] == 'O') ||
        (bd[1] == 'O' && bd[4] == 'O' && bd[7] == 'O') ||
        (bd[2] == 'O' && bd[5] == 'O' && bd[8] == 'O') ||
        (bd[0] == 'O' && bd[4] == 'O' && bd[8] == 'O') ||
        (bd[2] == 'O' && bd[4] == 'O' && bd[6] == 'O'))
    {
        return -1;
    }
    else return 0;
}

bool Check_Tie(char bd[9]){
    for (int i= 0; i<9; i++){
        if (bd[i] == ' '){
            return false;
        }
    }
    if (Check_Win(bd) == 0) return true;
}

void WinEnd(){
    cout << "You Win!";
    NoWin = false;
}

void LoseEnd(){
    cout << "You Lose!";
    NoWin = false;
}

void TieEnd(){
    cout << "Tie Game!";
    NoWin = false;
}

void Player_Turn(){
    int iMovein;
    string sMovein;
    while(true){
        cout << "Choose a place to play:";
        getline(cin, sMovein);
        iMovein = atoi(sMovein.c_str());
        if (chBoard[iMovein-1] == ' '){
            break;
        }
    }
    chBoard[iMovein-1] ='X';
}

int MaxMove(int Player, char Board[9], int Depth){ // Takes Tic Tac Toe board and current depth.
    int i=0, valuemax[9], res;
    int chk = Check_Win(Board);
    if (chk == 1)return 1; //checks if X has won.
    else if (chk == (-1)) return -1; //checks if O has won.
    else if (Check_Tie(Board)) {return 0;} // checks for a tie.
    int dpo = Depth + 1;
    int vmax = -1<<20; // intitial 'max' value
    int vmin = 1<<20; // initial 'min' value. These values are used as placeholders for the Max/Min values to find next best move.

    for (i; i<9; i++){
        if (Board[i] == ' '){ //checks for empty space.
            if (Player == 2) { //checks turn
                Board[i] = 'X';
                res = MaxMove(1, Board, dpo); //recursive function - digs down and checks all possible routes.
                Board[i] = ' ';
                if (res > vmax){
                    vmax = res;
                }
            }
            else {
                Board[i] = 'O';
                res = MaxMove(2, Board, dpo);
                Board[i] = ' ';
                if (res < vmin){
                    if (dpo < 6) cout <<Depth << " " << vmin << " " << res<< " " << i << endl;
                    vmin = res;
                    if (Depth == 1) iCMove = i;
                }
            }
        }
    }

    if (Player == 2) return vmax;
    else return vmin;
}

void turn(int Turn){
    iCMove = -1;
    if (Turn == 1){
        Player_Turn();
    }
    else {
        MaxMove(1, chBoard, 1);
        chBoard[iCMove] = 'O';
    }
}

int main(){
    int iP_Turn = 1;
    initilize_board(chBoard);
    while (NoWin){
        draw_board(chBoard);
        iCMove = -1;
        turn(iP_Turn);
        if (Check_Win(chBoard) == 1) {WinEnd();}
        else if (Check_Win(chBoard) == -1) {LoseEnd();}
        else if (Check_Tie(chBoard)) {TieEnd();}

        iP_Turn = (iP_Turn == 2 ? 1:2);

        //if (iP_Turn == 1){iP_Turn = 2;}
        //else if (iP_Turn == 2){iP_Turn = 1;}

    }
}
