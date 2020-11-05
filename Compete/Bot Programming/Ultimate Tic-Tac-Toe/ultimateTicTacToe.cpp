#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Position {
    int x;
    int y;

    Position() : x(0), y(0) {};
    Position(int posX, int posY) : x(posX), y(posY) {};
};

struct PosibleRow {
    Position posibleRowPositions[2];

    PosibleRow() : posibleRowPositions({Position(), Position()}) {};
    PosibleRow(Position firstPosition, Position secondPosition) : posibleRowPositions({firstPosition, secondPosition}) {};
};

unsigned char map[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

bool isCorner(const int x, const int y) {
    return  x != 1 && y != 1 && x % 2 == 0 && y % 2 == 0;
}

bool isCenter(const int x, const int y) {
    return x == 1 && y == 1;
}

bool isCenterFree() {
    return map[1][1] == ' ';
}

PosibleRow checkPosibleRow(Position pos, unsigned char character) {
    Position secondPosition;
    if (map[pos.x - 1][pos.y - 1] == character) {}
    if (map[pos.x - 1][pos.y] == character) {}
    if (map[pos.x - 1][pos.y + 1] == character) {}
    if (map[pos.x][pos.y] == character) {}
    if (map[pos.x][pos.y] == character) {}
    if (map[pos.x + 1][pos.y - 1] == character) {}
    if (map[pos.x + 1][pos.y] == character) {}
    if (map[pos.x + 1][pos.y + 1] == character){}

    return PosibleRow(pos, secondPosition);
}

void checkPosibleRows(Position pos) {
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int turn = 1;
    int posX, posY;
    int bestValue;
    int objectiveX, objectiveY;

    // game loop
    while (1) {
        //Restart variables
        posX = 0;
        posY = 0;
        bestValue = 0;

        int opponentRow;
        int opponentCol;
        cin >> opponentRow >> opponentCol; cin.ignore();

        if (turn > 1) {
            map[opponentCol][opponentRow] = 'o';
        }

        int validActionCount;
        cin >> validActionCount; cin.ignore();

        int actualValue = 0;
        for (int i = 0; i < validActionCount; i++) {
            int row;
            int col;
            cin >> row >> col; cin.ignore();

            if (bestValue < 100) {
                switch (validActionCount) {
                    case 9:
                        cerr << "Primer Turno" << endl;
                        if (isCorner(row, col)) {
                            cerr << "Esquina" << endl;
                            actualValue = 100;
                        }
                        break;
                    case 7:
                        cerr << "Segundo Turno" << endl;
                        if (isCenter(row, col) && isCenterFree()) {
                            cerr << "Centro Vacio" << endl;
                            actualValue = 100;
                        } else {
                            actualValue = 2;
                        }
                        break;
                    default:
                        actualValue = 1;
                        break;
                }

                if (actualValue > bestValue)
                {
                    bestValue = actualValue;
                    posX = row;
                    posY = col;
                }
            }
        }

        ++turn;
        map[posY][posX] = 'p';

        // Write an action using cout. DON'T FORGET THE "<< endl"
        // To debug: cerr << "Debug messages..." << endl;

        cout << to_string(posX) + " " + to_string(posY) << endl;
    }
}