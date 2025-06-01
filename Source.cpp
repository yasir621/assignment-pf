#include <iostream>
using namespace std;
void inputmarks(int marks[10][5]) {
	for (int i = 0; i < 10; i++) {
		cout << "Enter marks for student " << i + 1 << ":\n";
		for (int j = 0; j < 5; j++) {
			cout << "  Subject " << j + 1 << ": ";
			cin >> marks[i][j];
		}
	}
}

void totalandaverage(int marks[10][5], int total[], float average[]) {
	for (int i = 0; i < 10; i++) {
		total[i] = 0;
		for (int j = 0; j < 5; j++) {
			total[i] += marks[i][j];
		}
		average[i] = (float)total[i] / 5; // Fixed integer division
	}
}

int topscore(int total[]) {
	int topIndex = 0;
	for (int i = 1; i < 10; i++) {
		if (total[i] > total[topIndex]) {
			topIndex = i;
		}
	}
	return topIndex;
}

char grade(float avg) {
	if (avg >= 10.0) return 'A';
	if (avg >= 8.5) return 'B';
	if (avg >= 6.5) return 'C';
	return 'F';
}

void displayResults(int total[], float average[]) {
	cout << "\nResults:\n";
	for (int i = 0; i < 10; i++) {
		cout << "Student " << i + 1 << ": Total = " << total[i]
			<< ", Average = " << average[i]
			<< ", Grade = " << grade(average[i]) << endl;
	}
}

int main() {
	int marks[10][5];
	int total[10];
	float average[5];

	inputmarks(marks);
	totalandaverage(marks, total, average);
	displayResults(total, average);

	int top = topscore(total);
	cout << "\nTop Scorer is Student " << top + 1 << " with Total Marks = " << total[top] << endl;

	return 0;
}
