#include <iostream>
#include <conio.h>
#include <time.h>
#include "Matrix.h"

using namespace std;

int setRows(int,int);
int setColumns(int,int);
void setData(Matrix<float>, int, int, int);
void printMatrix(Matrix<float>, int, int);
void printRowsColumns(Matrix <float>);
void solveSystem(Matrix<float>, int, int);

int main(int argc, char** argv) {
	int m,n,x;
	
	cout<<"Digit the length of the matrix or the digit 0 to generate a random length.\n\n";
	cout<<"Digit the number of rows: "; cin>>m;
	cout<<"Digit the number of columns: "; cin>>n;
	system("CLS");
	
	if(m==0) m = setRows(m,n);
	if(n==0) n = setColumns(m,n);
	
	Matrix<float> matrixObj(m,n);
	
	cout<<"\n";
	setData(matrixObj,m,n,x);
	solveSystem(matrixObj,m,n);
	
	getch();
	return 0;
}

//RANDOM ROW LENGTH
int setRows(int m, int n){
	srand(time(NULL));
	if(n==0){
		n = 3 + rand()%(6);
		m = 2 + rand()%(n-1);
	}
	else m = 1 + rand()%(n-1);
	return m;
}

//RANDOM COLUMN LENGTH
int setColumns(int m, int n){
	srand(time(NULL));
	n = (m+1) + rand()%(6);
	return n;
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

void printRowsColumns(Matrix <float> matrixObj){
	cout<<"\n\nNumber of rows: "<<matrixObj.getRows()<<endl;
	cout<<"Number of columns: "<<matrixObj.getColumns()<<endl;
}

void solveSystem(Matrix <float> matrixObj, int m, int n){
	int changeValue,columnValue,rowValue,newValue;
	
	do{
		printMatrix(matrixObj,m,n);
		cout<<"\nPress 1 if you want to solve this matrix or 0 if you want to change a value: "; cin>>changeValue;
		if(changeValue==1){
			matrixObj.solveSystem();
			cout<<"\n\nSolution by Gauss-Jordan Algorithm:\n\n";
			printMatrix(matrixObj,m,n);
			printRowsColumns(matrixObj);
		}
		else if(changeValue==0){	
			cout<<"\n\tMatrix["<<m<<"]["<<n<<"]"<<endl;
			cout<<"\nDigit the new value and its position"<<endl;
			cout<<"\nRow: "; cin>>rowValue;
			cout<<"Column: "; cin>>columnValue;
			cout<<"New value: "; cin>>newValue;
			matrixObj.setValue(rowValue,columnValue,newValue);
			system("CLS");
			cout<<"\n";
		}
		else {
			system("CLS");
			cout<<"\n\tERROR: Press a valid key\n"<<endl;
		}	
	}while(changeValue!=1);
}
