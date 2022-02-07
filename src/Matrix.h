#ifndef MATRIX_H
#define MATRIX_H

#include <stdexcept>

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
			if(m <= 0 || n <= 0) throw runtime_error("Numbers of rows and columns must be grather than zero.");
				
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
		
		E getValue(int row, int column){
			if(row < 0 || row >= m){
				throw runtime_error("Invalid row.");
			}
			if(column < 0 || column >= n){
				throw runtime_error("Invalid column.");	
			}
			
			return matrix[row][column];
		}
		
		void setValue(int row, int column, E value){
			if(row < 0 || row >= m){
				throw runtime_error("Invalid row.");
			}
			if(column < 0 || column >= n){
				throw runtime_error("Invalid column.");
			}
		
			matrix[row][column] = value;
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
						coefficient = matrix[k][l];
						coefficient *= -1;		
						for(int j=0; j<this->n; j++){							
							matrix[k][j] += (matrix[l][j]*coefficient);
						}		
					}
				}
				l++;
			}		
		}
		
		int getRows(){
			return m;
		}
		
		int getColumns(){
			return n;
		}
};

#endif // MATRIX_H
