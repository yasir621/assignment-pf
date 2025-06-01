#include<iostream>
using namespace std;
void input(char situation[5][7]);
void countpatients(char situation[5][7], int& stable, int& critical, int& recoverd);
void criticalcount(char situation[4][7], int cdays[]);
void disply(int stable, int critical, int recoverd, int cdays[]);
int main() {
	char status[4][7];
	int stable, critical, recovered;
	int criticalDays[4];

	input(status);
	countpatients(status, stable, critical, recovered);
	criticalcount(status, criticalDays);
	disply(stable, critical, recovered, criticalDays);

	return 0;
}
void input(char situation[5][7]) {
	cout << "Enter situatin of patient(S for stable,C for critical,R for recovered)" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << "Patient " << i + 1 << ":" << endl;
		for (int j = 0; j < 7; j++)
		{
			cout << "  Day " << j + 1 << ": ";
			cin >> situation[i][j];
		}

	}
}
void countpatients(char situation[5][7], int& stable, int& critical, int& recoverd) {
	stable = 0;
	critical = 0;
	recoverd = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			if (situation[i][j]=='S'||situation[i][j]=='s')
			{
				stable++;
			}
			else if (situation[i][j] == 'C' ||situation[i][j]=='c')
			{
				critical++;
			}
			else if (situation[i][j] == 'R' || situation[i][j] == 'R')
			{
				recoverd++;
			}
		}
	}
}
void criticalcount(char situation[4][7],int cdays[]) {
	for (int i = 0; i < 4; i++)
	{
		cdays[i] = 0;
		for (int j = 0; j < 7; j++)
		{
			if (situation [i][j]=='C'||situation[i][j]=='c')
			{
				cdays[i]++;
			}
		}
	}

}
void disply(int stable, int critical, int recoverd, int cdays[]) {
	cout << "Record of patients:" << endl;
	cout << "Stable days" << stable << endl;
	cout << "Critical days" << critical << endl;
	cout << "Recoverd days" << recoverd << endl;
	cout << "\nCritical Days Per Patient:\n";
	for (int i = 0; i < 4; i++) {
		cout << "Patient " << i + 1 << ": " << cdays[i] << " day(s) in critical condition.\n";
	}
}


