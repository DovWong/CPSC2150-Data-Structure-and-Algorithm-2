#include "Hotel.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main() {

    srand(time(0));

//    Hotel hotel;
//
//    cout << hotel.CheckAvailability(30) << endl;
//
//    hotel.BookRoom(30);
//
//    cout << hotel.CheckAvailability(30) << endl;
//
//    hotel.CheckOut(30);
//
//    cout << hotel.CheckAvailability(30) << endl;
//
//    hotel.BookRoom(2);
//    hotel.BookRoom(7);
//    hotel.BookRoom(31);
//    hotel.BookRoom(15);
//    hotel.ShowRooms();

    Hotel hotel;

    hotel.Menu();

    return 0;
}