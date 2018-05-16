#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string MESSAGE;
    getline(cin, MESSAGE);

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;
    int lastBit = -1;
    string answer = "";
    for (int i = 0; i < MESSAGE.length(); i++)
    {
        cerr << MESSAGE[i] << endl;
        int byte = static_cast<int>(MESSAGE[i]);
        //cerr << byte << endl;
        byte &= 127;
        //cerr << byte << endl;
        unsigned int bit;
        for (int j = 0; j < 7; j++)
        {
            bit = byte >> 6 - j;
            bit &= 1;

            cerr << bit << endl;

            if (lastBit != -1)
            {
                if (lastBit == bit)
                {
                    answer += "0";
                }
                else
                {
                    if (bit == 0)
                    {
                        answer += " 00 0";
                    }
                    else
                    {
                        answer += " 0 0";
                    }
                    lastBit = bit;
                }
            }
            else
            {
                if (bit == 0)
                {
                    answer += "00 0";
                }
                else
                {
                    answer += "0 0";
                }
                lastBit = bit;
            }
        }
    }

    cerr << answer << endl;
    cout << answer << endl;

    //cout << "answer" << endl;
}