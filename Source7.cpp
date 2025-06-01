#include <iostream>
using namespace std;

void inputStatus(char books[5][5]) {
    cout << "Enter status of books (A = Available, I = Issued, M = Missing):\n";
    for (int i = 0; i < 5; i++) {
        cout << "Shelf " << i + 1 << ":\n";
        for (int j = 0; j < 5; j++) {
            cout << "  Book " << j + 1 << ": ";
            cin >> books[i][j];
        }
    }
}

void displayBooks(char books[5][5]) {
    cout << "\nLibrary Book Status:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Shelf " << i + 1 << ": ";
        for (int j = 0; j < 5; j++) {
            cout << books[i][j] << ' ';
        }
        cout << endl;
    }
}

void countStatus(char books[5][5], int& available, int& issued, int& missing) {
    available = issued = missing = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            char ch = books[i][j];
            if (ch == 'A' || ch == 'a') available++;
            else if (ch == 'I' || ch == 'i') issued++;
            else if (ch == 'M' || ch == 'm') missing++;
        }
    }
}

void shelvesWithMostMissing(char books[5][5], bool mostMissing[5]) {
    int rowMissing[5];
    for (int i = 0; i < 5; i++) {
        rowMissing[i] = 0;
        for (int j = 0; j < 5; j++) {
            if (books[i][j] == 'M' || books[i][j] == 'm') {
                rowMissing[i]++;
            }
        }
    }

    int maxMissing = rowMissing[0];
    for (int i = 1; i < 5; i++) {
        if (rowMissing[i] > maxMissing) {
            maxMissing = rowMissing[i];
        }
    }

    for (int i = 0; i < 5; i++) {
        mostMissing[i] = (rowMissing[i] == maxMissing && maxMissing > 0);
    }
}

void displaySummary(int available, int issued, int missing, bool mostMissing[5]) {
    cout << "\nTotal Available Books : " << available << endl;
    cout << "Total Issued Books    : " << issued << endl;
    cout << "Total Missing Books   : " << missing << endl;

    cout << "\nShelf(s) with Highest Missing Count:\n";
    bool found = false;
    for (int i = 0; i < 5; i++) {
        if (mostMissing[i]) {
            cout << "Shelf " << i + 1 << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No missing books found.\n";
    }
}

int main() {
    char books[5][5];
    int available, issued, missing;
    bool mostMissing[5];

    inputStatus(books);
    displayBooks(books);
    countStatus(books, available, issued, missing);
    shelvesWithMostMissing(books, mostMissing);
    displaySummary(available, issued, missing, mostMissing);

    return 0;
}
