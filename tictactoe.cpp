// tictactoe.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include <conio.h>
#include <windows.h>
#include <iostream>
using namespace std;



class Board
{
    char permament[5][5];//x y
    char temp[5][5];

public:
    void printBoard(int x,int y,char choice);
    void setBoard();
    void puttoBoard(int x,int y, char choice);
    void copyBoard();
    void permmove(int x,int y,char choice);
    bool empty(int x,int y,char choice);
    bool winner(char player);
};

class Game
{
    Board gameboard;
    int px=0;
    int py=0;

public:
    void start();
};

void Game::start()
{
    char player='O';
    int numer_ruchu = 0;
    gameboard.setBoard();
    gameboard.copyBoard();
    gameboard.puttoBoard(0, 0, player);
    gameboard.printBoard(px,py,player);
    cout << "Wybierz kierunek: w-gora, s-dol, a-lewo, d-prawo, enter-postaw";
    while (true)
    {
        char ruch = _getch();
        
        if (ruch == 'd')
        {
            px = px + 2;
            if (px == 6)
                px = 0;
        }   
        if (ruch == 'a')
        {
            px = px - 2;
            if (px == -2)
                px = 4;
        }
            
        if (ruch == 'w')
        {
            py = py - 2;
            if (py == -2)
                py = 4;
        }
            
        if (ruch == 's')
        {
            py = py + 2;
            if (py == 6)
                py = 0;
        }
        if ((int)ruch == 13)
        { 
           
            if (gameboard.empty(px, py, player))
            {
                numer_ruchu++;
                gameboard.permmove(px, py, player);
                if (gameboard.winner(player))
                {
                    cout << "Winner: " << player << endl;
                    Sleep(5000);
                    gameboard.setBoard();
                    gameboard.copyBoard();
                    gameboard.puttoBoard(0, 0, player);
                    gameboard.printBoard(px, py, player);
                    numer_ruchu = 0;
                }
                else if (numer_ruchu == 9)
                {
                    cout << "Remis" << endl;
                    Sleep(5000);
                    gameboard.setBoard();
                    gameboard.copyBoard();
                    gameboard.puttoBoard(0, 0, player);
                    gameboard.printBoard(px, py, player);
                    numer_ruchu = 0;
                }
                if (player == 'O')
                    player = 'X';
                else
                    player = 'O';
            }

        }
       
        gameboard.copyBoard();
        gameboard.puttoBoard(px,py, player);
        gameboard.printBoard(px,py,player);
        
    }
   
    
}
void Board::printBoard(int x,int y,char choice)
{
    system("cls");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << temp[j][i];
        }
        cout << endl;
    }
    cout << "x: " << x/2 << " y: " << y/2<<endl;
    
}

void Board::setBoard()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i % 2 != 0)
                permament[j][i] = '-';
            else if (j % 2 != 0)
                    permament[j][i] = '|';
                else
                    permament[j][i] = ' ';
        }
    }
}

void Board::puttoBoard(int x, int y, char choice)
{
    temp[x][y] = choice;
}
void Board::copyBoard()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            temp[j][i] = permament[j][i];
        }
    }
}

void Board::permmove(int x,int y, char choice)
{
    permament[x][y] = choice;
}

bool Board::empty(int x,int y, char choice)
{
    if (permament[x][y] == ' ')
    {
        return true;
    }
    else return false;

}

bool Board::winner(char player)
{
    if (permament[0][0] == player && permament[2][0] == player && permament[4][0] == player)
        return true;
    if (permament[0][2] == player && permament[2][2] == player && permament[4][2] == player)
        return true;
    if (permament[0][4] == player && permament[2][4] == player && permament[4][4] == player)
        return true;
    if (permament[0][0] == player && permament[0][2] == player && permament[0][4] == player)
        return true;
    if (permament[2][0] == player && permament[2][2] == player && permament[2][4] == player)
        return true;
    if (permament[4][0] == player && permament[4][2] == player && permament[4][4] == player)
        return true;
    if (permament[0][0] == player && permament[2][2] == player && permament[4][4] == player)
        return true;
    if (permament[4][0] == player && permament[2][2] == player && permament[0][4] == player)
        return true;
    return false;
}
int main()
{
    Game game1;
    game1.start();
   
}

