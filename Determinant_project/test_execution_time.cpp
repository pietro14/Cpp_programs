#include <iostream>
#include <time.h>     
#include "./headers/Matrix.h"

using namespace std;


//this program tests the execution time of the following method:    Matrix::determinant_by_Leibniz()
//the output is the execution time depending on the matrix order

int main(){  


    cout << "The execution could require some minutes" << endl;

	for(int n = 8; n < 13; n ++){           // matrix order loop

		Matrix matrix(n,n);

		for(int i=0; i<n; i++){
	
			for(int j=0; j<n; j++)	matrix[i][j]=double(rand() % 10);    //allocating random integers as matrix elements
		};

		clock_t tStart = clock();         

		matrix.determinant_by_Leibniz();
		
		cout << (double)(clock()-tStart)/(CLOCKS_PER_SEC) << endl; //printing execution time (milliseconds)		
	};

	return 0;


};
