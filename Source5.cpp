#include <iostream>
using namespace std;

void displayseats(char seats[6][4]) {
    cout << "\nseating Chart:"<<endl;
    for (int i = 0; i < 6; i++) {
        cout << "row " << i + 1 << ": ";
        for (int j = 0; j < 4; j++) {
            cout << seats[i][j] << ' ';
        }
        cout << endl;
    }
}

void bookseat(char seats[6][4]) {
    int row, col;
    cout << "enter row (1-6): ";
    cin >> row;
    cout << "enter column (1-4): ";
    cin >> col;

    if (row >= 1 && row <= 6 && col >= 1 && col <= 4) {
        if (seats[row - 1][col - 1] == 'E') {
            seats[row - 1][col - 1] = 'B';
            cout << "seat booked successfully." << endl;
        }
        else {
            cout << "seat is already booked."<<endl;
        }
    }
    else {
        cout << "invalid seat position."<<endl;
    }
}

int countempty(char seats[6][4]) {
    int count = 0;
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            if (seats[i][j] == 'E') {
                count++;
            }
        }
    }
    return count;
}

int rowmaxempty(char seats[6][4]) {
    int maxEmpty = 0;
    int maxRow = 0;
    for (int i = 0; i < 6; i++) {
        int rowEmpty = 0;
        for (int j = 0; j < 4; j++) {
            if (seats[i][j] == 'E') {
                rowEmpty++;
            }
        }
        if (rowEmpty > maxEmpty) {
            maxEmpty = rowEmpty;
            maxRow = i;
        }
    }
    return maxRow;
}

int main() {
    char seats[6][4];
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 4; j++) {
            seats[i][j] = 'E';
        }
    }

    int choice;
    do {
        cout << "\n1. Display Seating Chart\n";
        cout << "2. Book a Seat\n";
        cout << "3. Count Available Seats\n";
        cout << "4. Row with Most Empty Seats\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            displayseats(seats);
        }
        else if (choice == 2) {
            bookseat(seats);
        }
        else if (choice == 3) {
            int available = countempty(seats);
            cout << "Total available seats: " << available << endl;
        }
        else if (choice == 4) {
            int row = rowmaxempty(seats);
            cout << "Row " << row + 1 << " has the most empty seats.\n";
        }

    } while (choice != 5);

    return 0;
}
