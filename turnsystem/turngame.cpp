#include <iostream>
#include <limits>
#include <math.h>

using namespace std;

#include "unit.cpp"

#define TIMECOUNTER 255

uint16_t createunits () {
    
    uint16_t n;
	cout << "Enter the number of units:\n";
	cin >> n;

    while (!cin.good() || n <= 0 || n > 10) {

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Enter the number of units: (Warning: Only integers between 1 and 10 allowed)\n";
        cin >> n;
    }

    return n;
}

void setupunits (unit *units, uint16_t n) {

    for (uint16_t i = 0; i < n; i++) {
        
        uint16_t sp;
        cout << "Enter unit " << i << " speed:\n";
        cin >> sp;

        while (!cin.good() || sp <= 0 || sp > 255) {

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Enter unit " << i << " speed: (Warning: Only integers between 1 and 255 allowed)\n";
            cin >> sp;
        }
        
        units[i].setSpeed(sp);
    }
}

bool gamelogic (uint16_t time, unit *units, uint16_t n) {
    
    uint16_t gtime = time+1;
    string input;

    // For each unit...
    for (uint16_t i = 0; i < n; i++) {

        // Check turn order
        if (units[i].checkTurn()) {
            
            cout << "(Time: " << gtime << ") Unit " << i << " turn";
            //cout << "\nPress enter to end turn";
            //cin >> input;
            cin.ignore();
            
            if (input == "\n")
                return true;
        }
    }

    return false;
}

int main() {
    

    Start:

    // Create units
    uint16_t unit_n = createunits();
    unit *units = new unit[unit_n];

    // Setup units stats
    setupunits(units, unit_n);

    // Start game
    uint16_t time = 0;

    // Setup units counters
    for (uint16_t i = 0; i < unit_n; i++)
        units[i].setCounter(TIMECOUNTER);

    cout << "-- Starting game --\n";
    cout << "INFO: Press ENTER to end the turn.\n";
    cin.ignore();
    
    while (true) {

        bool state;
        
        state = gamelogic(time, units, unit_n);

        if (state)
            break;

        if (++time > TIMECOUNTER)
            time = 0;
    }

    delete units;

    goto Start;
}

