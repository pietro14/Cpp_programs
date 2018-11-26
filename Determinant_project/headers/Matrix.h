

#include <algorithm>	//funzione next_permutation 
#include <cmath>   	//FORSE NON SERVE	



#include "Permutation_sign.h"





// this class


using namespace std;


class Matrix{

protected:

	int n;					//numero di righe della matrice
	int m;					//numero di colonne della matrice
	long double **element;			//elementi della matrice

public:

	Matrix();   				//costruttore senza parametri
	Matrix(int N,int M);			//costruttore con parametri (dimensioni della matrice)
	Matrix (Matrix &src);			//metodo che crea una copia del tutto indipendente dall'originale (per future applicazioni)
	double determinant_by_Leibniz();
	double determinant_by_LU();       
	Matrix product(Matrix B);
	Matrix transpose();	
	void print_matrix();			//metodo che stampa la matrice
	~Matrix(void);				//distruttore

	long double* operator[](int N){return element[N];};    //operatore per trattare questo oggetto come se fosse un array


};

	
	
Matrix::Matrix(){};	
Matrix::Matrix(int N,int M) {
		n= N;		
		m = M;
		element = new long double *[n]; 			
		for(int i=0; i<n; i++) element[i]=new long double[m];
};
	




Matrix::Matrix (Matrix &src){

		this->n=src.n;
		this->m=src.m;
		this->element = new long double *[n]; 			
		for(int i=0; i<n; i++) this->element[i]=new long double[m];
		
	



	for(int i=0; i<n; i++){
	
		for(int j=0; j<n; j++){this->element[i][j] = src.element[i][j];
	
	 	};
	};


};

	
double Matrix::determinant_by_Leibniz() {    // only for square matrix (N = M)



  int ints[n];


  double partialf ;


  double detl = 0 ;



  for(int i=0; i<n; i++)   ints[i]=i;


  
  
  int k = 0;

   do{
       partialf=1;
       for(int j=0; j<n; j++) {   


         partialf   *= element[j][ints[j]];
   
       };

	 partialf   *=  permutation_sign(n,ints);

	 detl+=partialf;

    } while(next_permutation(ints,ints+n));





  return detl;


};




double Matrix::determinant_by_LU() {    // only for square matrix (N = M)




	Matrix L(n,n);	
	Matrix U(n,n);
	
	for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
		
				if(i = j) L[i][j] = 1; 
				else L[i][j] = 0;			
	
				U[i][j] = 0;						
			}		
	};	

	int p = -1;
	int q = -1;
	
	for(int m = 0; m < n; m++){

		
			p++;
			for(int j = 0; j < n; j++) {

				U[p][j] = element[p][j];
				for(int k = 0; k < p; k++) U[p][j] -= L[p][k]*U[k][j];


					
						
				};		
	
			q++;
			for(int i = 0; i < n; i++) {
				L[i][q] = element[i][q]/U[q][q];
				
				
				for(int k = 0; k < p; k++)	L[i][q] -= L[i][k]*U[k][q]/U[q][q];	
		
			
				
			};  


		



	};

	
	double det = 1;


	for(int k = 0; k < n; k++) det *= U[k][k];


		


	return det;

};









Matrix Matrix::product(Matrix B){



		Matrix P(n,n);
 		for(int i=0; i<n; i++){
	
			for(int j=0; j<n; j++)	P[i][j]= 0;
		};

		for(int j=0; j<n; j++) {		
			for(int k=0; k<n; k++) {
				for(int i=0; i<n; i++) {
					P[k][j] += this->element[k][i] * B[i][j]; 
				};
			};
		};

return P;



};




Matrix Matrix::transpose(){

	Matrix T(n,n);

	for (int i=0; i<n; i++){
		for(int j=0; j<n; j++) T[i][j] = element[j][i];
	};



return T;

};




void Matrix::print_matrix() { 

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){

			cout << element[i][j] << " " ;

				};  
			cout << endl;
		};
};



Matrix::~Matrix(void){
	
	for(int i=0; i<n; i++) delete []element[i];

	delete [] element;
};



