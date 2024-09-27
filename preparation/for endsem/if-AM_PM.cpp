#include <iostream>
using namespace std;

// using switch 

int main(){
    int hours, minutes;

    // Get user input
    cout << "Enter hours (0-23): ";
    cin >> hours;

    cout << "Enter minutes (0-59): ";
    cin >> minutes;

    // Validate input
    if (hours < 0 || hours > 23 || minutes < 0 || minutes > 59) {
        cerr << "Invalid input. Please enter valid hours (0-23) and minutes (0-59)." << endl;
        return 1; // Exit with an error code
    }

    // Determine AM or PM using a loop for cases
    string period;

    switch (hours) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            period = "AM";
            if (hours == 0) {
                hours = 12;
            }
            break;

        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
        case 23:
            period = "PM";
            if (hours > 12) {
                hours -= 12;
            }
            break;

        default:
            cerr << "Invalid input for hours." << endl;
            return 1; // Exit with an error code
    }
    // Display the result
    cout << "Time: " << hours << ":" << (minutes < 10 ? "0" : "") << minutes << " " << period << endl;

    return 0;  
    
}

// using conditional statements - replace after string period; line 23 upto line 65

/*
if (hours >= 0 && hours <= 11) {
        period = "AM";
        if (hours == 0) {
            hours = 12;
        }
    } else if (hours >= 12 && hours <= 23) {
        period = "PM";
        if (hours > 12) {
            hours -= 12;
        }
    }
*/