#include <cmath>

void myhisto(){
 


  gStyle->SetOptFit(11111);
  TCanvas *c1 = new TCanvas("c1","Data Analysis",200,10,700,500);
  
   TH1D* histo = new TH1D("histo", "", 21, 0, 21);



ifstream read("survey_data.dat");

for(int i=0; !read.eof(); i++)  {

double prob;

read >> prob;
histo->Fill(i, prob);


};
	read.close();

        histo->GetXaxis()->SetTitle("Number of enrolled students");   		
	histo->SetFillColor(5);   
        histo->SetTitle("Probability distribution of students enrolled at RomaTre");
  	histo->Draw();   


histo->Fit("gaus");

};
