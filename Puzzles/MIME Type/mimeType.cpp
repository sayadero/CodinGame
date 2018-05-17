#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Defibrilator
{
    int id;
    string name;
    string description;
    string unknown;
    float longitude;
    float latitude;
};

void replaceChar(string* str, const char* replace, const char* ch) {
    cerr << "String: " << *str << ", char: '" << replace << "', char: '" << ch << "'" << endl;
    int pos;
    while((pos = str->find(replace)) != string::npos)
    {
        cerr << pos << endl;
        std::replace( str->begin(), str->end(), ',', '.'); // replace all 'x' to 'y'
        cerr << *str << endl;
    }
    cerr << "Salida: " << *str << endl;
}

Defibrilator nearestDefibrilator;
float distanceToNearestDefibrilator;
bool haveNearestDefibrilator;
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
int main()
{
    string LON;
    cin >> LON; cin.ignore();
    replaceChar(&LON, ",", ".");
    float userLongitude = stof(LON);
    string LAT;
    cin >> LAT; cin.ignore();
    replaceChar(&LAT, ",", ".");
    float userLatitude = stof(LAT);
    cerr << LON << " : " << LAT << endl;
    cerr << userLongitude << " : " << userLatitude << endl;
    int N;
    cin >> N; cin.ignore();
    for (int i = 0; i < N; i++) {
        string DEFIB;
        getline(cin, DEFIB);
        cerr << "Defibrilator: " << DEFIB << endl;
        replaceChar(&DEFIB, ",", ".");

        Defibrilator defibrilator;

        defibrilator.id = stoi(DEFIB.substr(0, DEFIB.find(";")));
        DEFIB = DEFIB.substr(DEFIB.find(";") + 1, DEFIB.length());

        defibrilator.name = DEFIB.substr(0, DEFIB.find(";"));
        DEFIB = DEFIB.substr(DEFIB.find(";") + 1, DEFIB.length());

        defibrilator.description = DEFIB.substr(0, DEFIB.find(";"));
        DEFIB = DEFIB.substr(DEFIB.find(";") + 1, DEFIB.length());

        defibrilator.unknown = DEFIB.substr(0, DEFIB.find(";"));
        DEFIB = DEFIB.substr(DEFIB.find(";") + 1, DEFIB.length());

        defibrilator.longitude = stof(DEFIB.substr(0, DEFIB.find(";")));
        DEFIB = DEFIB.substr(DEFIB.find(";") + 1, DEFIB.length());

        defibrilator.latitude = stof(DEFIB.substr(0, DEFIB.find(";")));
        DEFIB = DEFIB.substr(DEFIB.find(";") + 1, DEFIB.length());

        float x = (defibrilator.longitude - userLongitude) * cos((userLatitude + defibrilator.latitude) / 2);
        float y = defibrilator.latitude - userLatitude;
        float d = sqrt(x * x + y * y) * 6371;

        if (d < distanceToNearestDefibrilator || !haveNearestDefibrilator)
        {
            nearestDefibrilator = defibrilator;
            distanceToNearestDefibrilator = d;
            haveNearestDefibrilator = true;
        }
    }

    // Write an action using cout. DON'T FORGET THE "<< endl"
    // To debug: cerr << "Debug messages..." << endl;

    cout << nearestDefibrilator.name << endl;
}