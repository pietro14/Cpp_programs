#include <iostream>
#include <math.h>



//This simple program calculates the weighed mean of N measurements.
//In case the measurements are only 2, the program also says how those
//two measurements are compatible in terms of sigma.


using namespace std;

int main()
{

        int n;                                                                  //number of measurements

        cout << "Number of measurements: ";                     
	cin >> n;                                                   

	double val[n];                                               //estimate values array
	double err_val[n];                                           //uncertainties array
	double p[n];                                                 //weighs array

	double p_TOT = 0;                                                  
	double mean = 0;                                                  //weighed mean
	double err_mean;                                                  //weighed mean uncertainty

	double sigma;                                                      //distanza in termini di sigma (se n=2)
	
	for(int i=0; i < n; i++){	                                   //input section

	  cout << endl << i+1 << "° estimate value: ";
	  cin >> val[i];

          cout << endl << i+1 << "° uncertainty value: ";
	  cin >> err_val[i];

	  p[i]=1/pow(err_val[i], 2) ;                          //definition of weigh: p_i=(err_1)^(-2)	

	};



	for(int i=0; i < n; i++){                                          //summing the weighs 

  	  p_TOT = p_TOT + p[i];

	};


	
	for(int i=0; i < n; i++){                                          //calculating the weighed mean (step 1)

  	  mean = mean + p[i]*val[i];

	};


	mean = mean/p_TOT;                                                   //calculating the weighed mean (step 2)

	err_mean = sqrt( 1/p_TOT );                                           //calculating the mean uncertainty
	
        sigma = fabs(val[0]-val[1])/sqrt(err_val[0]*err_val[0]+err_val[1]*err_val[1]);   //compatibility between two measurements


	if(n==2)                                                          
	  {
	    cout << endl <<"The two measurements are compatible within: " << sigma << " sigma" << endl;               
	  }

	
	cout << endl <<"The weighed mean is: " << mean << " +/- " << err_mean <<  endl  << endl; //prints mean +/- err_mean

	      
	 

	return 0;
}

