#include <iostream>
#include <algorithm>	//funzione next_permutation 
#include <cmath>	
#include <iomanip>      //setprecision
#include <vector>


//COMMENT  su un sample of 20 students


using namespace std;

//////////////////////////////////////////////////////////////////    	
/////////////////////////  INPUT  FORMAT/ ////////////////////////
//////////////////////////////////////////////////////////////////
//     [P_1]      	
// 	0.3	
// 	0.5	
//      0.6	
//	 .		
//       .		
//       .		
//      0.2	
//////////////////////////////////////////////////////////////////   
//////////////////////////////////////////////////////////////////
// P_1 = probability that the individual will enroll at RomaTre
//       University for a Master's Degree
//////////////////////////////////////////////////////////////////   



//////////////////////////////////////////////////////////////////    	
/////////////////////////  OUTPUT FORMAT   ///////////////////////
//////////////////////////////////////////////////////////////////
//    [P_2]  	
//     0.1
//     0.2
//     0.7
//      .
//      .
//      .
//     0.1
//////////////////////////////////////////////////////////////////   
//////////////////////////////////////////////////////////////////
// P_2 =   probability that K students in N will enroll at RomaTre
//	   University for a Master's Degree (with K = 0, 1,.., N)
//////////////////////////////////////////////////////////////////   


int main() {

    double output_data[20];
    double input_data[20] = {
0.7	,		
0.4	,		
0.48	,		
0.55	,	
0.5	,	
0.2	,	
0.55	,		
0.3	,		
0.7	,		
0.4	,		
0.2	,	
0.05	,
0.3	,
0.68	,
0.89	,
0.6	,
0.9	,
0.3	,
0.4	,
0.3	,
};	



//in order to calculate the probability that K students in N will enroll, we multiply and sum
//the necessary probabilities according to the probability theory. To do that, we use the following loops.


int n = 20;
   


for(int r = 0; r <= n; r++){
    vector<bool> v(n);
    fill(v.end() - r, v.end(), true);

    double tot = 0;
    double partial;

    do {
	partial = 1;
        for (int i = 0; i < n; ++i) {
	    if (v[i])   partial *= input_data[i]; 
            else partial *= (1- input_data[i]);  
        }; 
       
	tot += partial;
	

    } while (next_permutation(v.begin(), v.end()));

output_data[r] = tot;

};


for(int r=0; r<=n; r++){
			

			cout << output_data[r] << " " ;

				
			cout << endl;
		};



	return 0;
}






