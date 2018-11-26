#include "execution_time_data.h"


//this ROOT macro uses the data stored in "execution_time_data.dat"
//to confirm the expected factorial increasing of the execution time,
//when using the method Matrix::determinant_by_Leibniz()

void myfit(){




   gStyle->SetOptFit(11111);
   TCanvas *c1 = new TCanvas("c1","Data Analysis",200,10,700,500);

   int max_order = sizeof(n)/sizeof(double);

   double *ratio = new double [max_order-1] ;

   for (int i = 0 ; i < (max_order-1); i++){
	
		ratio[i] = t[i+1]/t[i];   

   };


   TGraph* gr = new TGraph(max_order-1,n,ratio);

   TF1 *funz =new TF1("funz","[0]*x+[1]",0,12);    //we expect a factorial increasing of the execution time,
					           //so we can fit the ratio between two adjacent execution times
						   //with a linear trend y = m*x + q  where  m ~ 1
   funz->SetParameter(0,1);
   funz->SetParameter(1,-12);




  // SetLimits(double min, double max)
   gr->GetXaxis()->SetTitle("matrix order");   		//actually, this is not exactly the matrix order
   gr->GetYaxis()->SetTitle("(T_n) / (T_n-1)");           //ratio between two adjacent execution times    
   //gr->GetYaxis()->SetRange(5,15);
   //gr->GetXaxis()->SetRange(7,12);
   gr->SetTitle("Time exetucion development depending on the matrix order");
   gr->Fit(funz);
   gr->Draw("A*");


}
