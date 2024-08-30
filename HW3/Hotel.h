#include <iostream>

#ifndef HOTEL_H
#define HOTEL_H

using namespace std;

class Hotel {
    
private:
    
    unsigned long long room;
    int MAXROOMNUMBER;

public:

    Hotel() {
        room = 0;
        MAXROOMNUMBER = 60;
    }

    bool CheckAvailability(int roomNumber) {

        if (roomNumber < 1 && roomNumber > MAXROOMNUMBER) {
            cout << "Room number should be between 1 to 60." << endl;
            return false;
        }

        return (room >> (roomNumber - 1)) % 2 == 0;
    }

    void BookRoom(int roomNumber) {

        if (roomNumber < 1 || roomNumber > MAXROOMNUMBER) {
            cout << "Room number should be between 1 to 60." << endl;
            return;
        }

        if (CheckAvailability(roomNumber)) {
            unsigned long long num = 1;
            room += (num << (roomNumber - 1));
            cout << "Room " << roomNumber << " is reserved successfully." << endl;
        } else {
            cout << "Unsuccessful reservation. Room " << roomNumber << " is reserved bu others." << endl;
        }
    }

    void CheckOut(int roomNumber) {

        if (roomNumber < 1 || roomNumber > 60) {
            cout << "Room number should be between 1 to 60." << endl;
            return;
        }

        if (CheckAvailability(roomNumber)) {
            cout << "There is no reservation for room " << roomNumber << "." << endl;
        } else {
            unsigned long long num = 1;
            room -= (num << (roomNumber - 1));
            cout << "Room " << roomNumber << " is checked out successfully." << endl;
        }
    }

    void ShowRooms() {

        int available = 0;
        int reserved = 0;

        for (long long i = 7; i < LLONG_MAX; i = (i << 1) + 1) {
            cout << "Room " << available + reserved + 1 << ": ";

            if (CheckAvailability(available + reserved + 1)) {
                cout << "Available" << endl;
                available++;
            }
            else {
                cout << "Reserved" << endl;
                reserved++;
            }
        }
        
        cout << endl << "Number of available room: " << available << endl;
        cout << endl << "Number of reserved room: " << reserved << endl;
    }

    void Menu() {
        int input = 1;

        cout << "----------Menu----------" << endl;
        cout << "Please enter the option:" << endl;
        cout << "0: Exit Program" << endl;
        cout << "1: Show Rooms" << endl;
        cout << "2: Book Room" << endl;
        cout << "3: Check ROut" << endl;

        try {
            cin >> input;
            int roomNumber;

            if ((input >> 2) != 0) {
                cout << "Invalid input. Please enter again." << endl;
            } else {
                switch (input) {
                    case 0:
                        cout << "Problem terminated. Good bye..." << endl;
                        exit(1);
                    case 1:
                        ShowRooms();
                        break;
                    case 2:
                        cout << "Please enter the room number that you want to book." << endl;
                        cin >> roomNumber;
                        BookRoom(roomNumber);
                        break;
                    default:
                        cout << "Please enter the room number that you want to check out." << endl;
                        cin >> roomNumber;
                        CheckOut(roomNumber);
                }
            }


        } catch (...) {
            cout << "Invalid input. Please enter again." << endl;
        }

        Menu();
    }
};

#endif