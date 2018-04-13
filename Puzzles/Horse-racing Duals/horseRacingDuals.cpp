#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdlib.h>     /* abs */

using namespace std;

vector<int> strengths;
int closestValue = 99999;

void showVector()
{
    cerr << "showVector()" << endl;
    for (int i = 0; i < strengths.size(); i++)
    {
        cerr << "Horse Strength " << i << ": " << strengths[i] << endl;
    }
}

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    int N;
    cin >> N; cin.ignore();
    int firstPi;
    cin >> firstPi; cin.ignore();
    strengths.push_back(firstPi);
    for (int i = 1; i < N; i++) {
        int forPi;
        cin >> forPi; cin.ignore();
        
        
        strengths.push_back(forPi);
        //showVector();
    }
    
    std::sort (strengths.begin(), strengths.end());
    //showVector();
    
    
    for (int i = 0; i < strengths.size() - 1; ++i)
    {
        int temp = strengths[i + 1] - strengths[i];
        if (temp < closestValue)
        {
            closestValue = temp;
        }
        if (closestValue == 0) break;
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << closestValue << endl;
}