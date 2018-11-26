// In this header is implemented an algorithm for calculating the sign of a permutation 

// Calculating the sign permutation is fundamental to implement the Leibniz formula  




#include <cmath>	


using namespace std;



//definizione del fattoriale
int factorial(int x, int result = 1) {
  if (x == 1) return result;
  else return factorial(x - 1, x * result);
}




//definizione della funzione per il calcolo del segno della permutazione

int permutation_sign(int n, int *myvector){


  int copy[n];     		// vettore ausiliario per la copia di myvector[] 

  for(int i=0; i<n; i++)     copy[i]=myvector[i];   // copio la permutazione originale
     

  
  double aux;                   //variabile ausiliare per lo scambio di due elementi 
  int counter = 0;              //variabile che conta il numero di scambi
  bool swapped; 		//variabile che tiene conto se è stato fatto lo scambio
 
 
  do{                           // i seguenti loop implementano un semplice algoritmo di ordinamento di un vettore
    				// e contemporaneamente contanto il numero di scambi per determinare il segno della permutazione
    swapped = false;
    
    for(int i=0; i<n-1; i++){
      
      if(myvector[i]>myvector[i+1]){
	aux = myvector[i];		// Scambio di due elementi 
	myvector[i]=myvector[i+1];	// vicini con l'aiuto di 	
	myvector[i+1]=aux;		// una variabile ausiliaria 
      swapped=true;                     
      counter++;
      }   
    }
    
  }while(swapped);       // il loop continua fino a che non ci sono più scambi da fare ovvero il vettore è ordinato
  
  for(int i=0; i<n; i++)     myvector[i]=copy[i];   // così myvector non risulta modificato alla fine

  return pow(-1,counter);  //la funzione restituisce 1 se il numero di scambi è pari (permut. pari), -1 se è dispari (permut. dispari)
  
};

//fine definizione della funzione per il segno della permutazione



