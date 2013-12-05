#include <iostream>
#include <cmath>

const int HEIGHT = 5;
const int WIDTH = 5;

void Draw_Board();
void Init_Board(int, int);
using namespace std;

class Tile {
public:
    int Tile_Number, G, H, F, Parent;
    bool Wall, Start_P, End_P;
    char bd_tile;
    Tile();
    Tile(int);
};
Tile::Tile(){
    Wall = false;
    Start_P = false;
    End_P = false;
}

Tile board[HEIGHT * WIDTH];

void Init_Board(int H, int W){
    int i;
    for (i=0; i<=((H*W)-1); i++)
        board[i].Tile_Number = i;

}

void Draw_Board() {
    int i, j, k=0;

    for (i=1; i<=(HEIGHT); i++){
            for (j=1; j<= WIDTH; j++){
                cout << "|" << board[k].bd_tile;
                k++;
            }
        cout<< "|" << endl;
    }

}

void calculate_G(){
    int k= 0, calcG, vd, hd;
    for (int i = 0; i<=(HEIGHT-1); i++){
        for (int j = 0; j<=(WIDTH-1); j++){
            calcG = (abs(2-i)) + (abs(0-j));
            if (!board[k].Wall)
                cout << calcG << " " << k+1 << " " << i << j <<endl;
                board[k].G = calcG;
            k++;
        }
    }
}


int main()
{
    Init_Board(HEIGHT, WIDTH);
    board[5].bd_tile = 'X'; board[5].Wall = true;
    board[6].bd_tile = 'X'; board[6].Wall = true;
    board[7].bd_tile = 'X'; board[7].Wall = true;
    board[8].bd_tile = 'X'; board[8].Wall = true;
    board[0].bd_tile = 'S'; board[0].Start_P = true;
    board[10].bd_tile = 'E'; board[10].End_P = true;
    Draw_Board();
    calculate_G();
    while (true){
        calculate_H();
        Check_Open();
        Set_Closed();
        Draw_Board();

    }
    return 0;
}
