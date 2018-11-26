#include <iostream>
#include <iomanip>    

#include "./headers/Matrix.h"

using namespace std;

//this program tests the following method:    Matrix::determinant_by_Leibniz()
//the output is a random square matrix and its determinant


//the result can be tested  at the following link:
//http://www.bluebit.gr/matrix-calculator/



int main(){       





for(int n = 2; n < 11; n ++){     //matrix order loop   (for larger matrix the algorithm is too slow)





Matrix matrix(n,n);



for(int i=0; i<n; i++){
	
		for(int j=0; j<n; j++)	matrix[i][j]=double(rand() % 10);    //allocating random integers as matrix elements
}	;

cout << endl << endl << endl << n  << " x " << n << " matrix" << endl << endl;

matrix.print_matrix();

cout <<"Det = "<< setprecision(12) <<matrix.determinant_by_Leibniz() << endl << endl;

};

return 0;


};
