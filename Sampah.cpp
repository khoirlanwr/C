#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct array{
	float arr[100][100];
};

void perkalian(int size, array* matriks0, array* matriks1, array* matriks2) 
{
	int i, j, k;
	// Perkalian matriks
	for(i=0; i<size; i++) {
		for(j=0; j<size; j++) {
			matriks2->arr[i][j] = 0; 
			for(k=0; k<size; k++) {
				matriks2->arr[i][j] += matriks0->arr[i][k] * matriks1->arr[k][j];			
			}
		}
	}
	
}

int main() 
{
	// declare var
	int n;
	int i, j;
	
	//  creating object
	array matriks0;
	array matriks1;
	array matriks2;
	
	// Input size array
	cout << "Input size of array: ";
	cin >> n;
	
	cout << "Matriks0: " << endl;
	cout << "\nInput each element: " << endl;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			cout << "Input element[" << i << "][" << j << "]: ";
			cin >> matriks0.arr[i][j];
		} 
	}
	
	cout << "Output: " << endl;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			cout << matriks0.arr[i][j] << " ";
		}
		cout << "\n";	
	}
	
	cout << "Matriks1: " << endl;
	cout << "\nInput each element: " << endl;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			cout << "Input element[" << i << "][" << j << "]: ";
			cin >> matriks1.arr[i][j];
		} 
	}
	
	cout << "Output: " << endl;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			cout << matriks1.arr[i][j] << " ";
		}
		cout << "\n";	
	}
	
	perkalian(n, &matriks0, &matriks1, &matriks2);
	
	cout << "Output: " << endl;
	for(i=0; i<n; i++) {
		for(j=0; j<n; j++) {
			cout << matriks2.arr[i][j] << " ";
		}
		cout << "\n";	
	}
	
	return 0;
}
