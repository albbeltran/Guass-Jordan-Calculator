#include <iostream>
#include <conio.h>
#include "Matrix.h"

using namespace std;

void setData(Matrix<float> matrixObj, int, int, int);
void printMatrix(Matrix<float> matrixObj, int, int);

int main(int argc, char** argv) {
	int m,n,x;
	
	cout<<"Digit the number of rows: "; cin>>m;
	cout<<"Digit the number of columns: "; cin>>n;
	system("CLS");
	
	Matrix<float> matrixObj(m,n);
	
	cout<<"\n";
	setData(matrixObj,m,n,x);
	printMatrix(matrixObj,m,n);
	
	matrixObj.solveSystem();
	cout<<"\n\nSolution by Gauss-Jordan Algorithm:\n\n";
	printMatrix(matrixObj,m,n);
	
	getch();
	return 0;
}

//SET DATA 
void setData(Matrix<float> matrixObj, int m, int n, int x){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			cout<<"Digit the element ["<<i<<"]["<<j<<"]: "; cin>>x;
			matrixObj.setValue(i,j,x);
			system("CLS");
			cout<<"\n";
		}
	}
}

//PRINT THE MATRIX
void printMatrix(Matrix<float> matrixObj, int m, int n){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			matrixObj.systemException(i,j);
			cout<<matrixObj.getValue(i,j)<<"\t";
		}
		cout<<"\n";
	}	
}
