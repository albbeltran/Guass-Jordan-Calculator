#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>
#include <iostream>
#include <string>

using std::runtime_error;

template <class E>
class Matrix{
	private:
		int m, n, l=0;
		E** matrix;
		float pivot, coefficient;
		
	public:
		//CONSTRUCTOR
		Matrix(int m, int n){
			this->m = m;
			this->n = n;
			matrix = new E*[m];
			for(int i=0; i<m; i++){
				matrix[i] = new E[n];
			}
		}
		
		//DESTRUCTOR
		~Matrix(){
			for(int i=0; i<m; i++){
				delete[] matrix[i];
			}
			delete[] matrix;
		}
		
		//GAUSS-JORDAN ALGORITHM
		void solveSystem(){
			for(int i=0; i<this->m; i++){
				pivot = matrix[i][l];
				for(int j=0; j<this->n; j++){					
					matrix[i][j] /= pivot;
				}
				for(int k=0; k<this->m; k++){		
					if(k!=i){
						coefficient = (matrix[k][l])*-1;	
						for(int j=0; j<this->n; j++){							
							matrix[k][j] += (matrix[l][j]*coefficient);
						}		
					}
				}
				l++;
			}		
		}
		
		void systemException(int row, int column){
			std::string value = std::to_string(matrix[row][column]);
			if(value=="nan") throw runtime_error("The system has no solution or has infinite solutions");
		}
		
		void valid(int row, int column){
			if(row < 0 || row >= m){
				throw runtime_error("Invalid row.");
			}
			if(column < 0 || column >= n){
				throw runtime_error("Invalid column.");
			}
		}
		
		int getRows(){
			return m;
		}
		
		int getColumns(){
			return n;
		}
		
		E getValue(int row, int column){
			valid(row,column);
			return matrix[row][column];
		}
		
		void setValue(int row, int column, E value){
			valid(row,column);
			matrix[row][column] = value;
		}
};

#endif // MATRIX_H
