#include <iostream>
using namespace std;
void inputSales(float sales[4][7]);
void calculateTotals(float sales[4][7], float item[], float day[]);
int findMaxIndex(float arr[], int size);
void displayResults(float item[], float day[]);
int main() {
    float sales[4][7];
    float itemTotals[4];
    float dayTotals[7];

    inputSales(sales);
    calculateTotals(sales, itemTotals, dayTotals);
    displayResults(itemTotals, dayTotals);

    return 0;
}
void inputSales(float sales[4][7]) {
    for (int i = 0; i < 4; i++) {
        cout << "Enter sales for Item " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> sales[i][j];
        }
    }
}
void calculateTotals(float sales[4][7], float item[], float day[]) {
    for (int i = 0; i < 4; i++) {
        item[i] = 0;
    }
    for (int j = 0; j < 7; j++) {
        day[j] = 0;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 7; j++) {
            item[i] += sales[i][j];
            day[j] += sales[i][j];
        }
    }
}
int findMaxIndex(float arr[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }
    return maxIndex;
}
void displayResults(float item[], float day[]) {
    cout << "\nTotal Sales per Item:\n";
    for (int i = 0; i < 4; i++) {
        cout << "Item " << i + 1 << ": " << item[i] << endl;
    }
    cout << "\nTotal Sales per Day:\n";
    for (int j = 0; j < 7; j++) {
        cout << "Day " << j + 1 << ": " << day[j] << endl;
    }
    int maxDay = findMaxIndex(day, 7);
    int maxItem = findMaxIndex(item, 4);
    cout << "\nDay with highest sales: Day " << maxDay + 1  <<" "<< day[maxDay] << "\n";
    cout << "Item with highest sales: Item " << maxItem + 1  <<" "<< item[maxItem] << "\n";
}
