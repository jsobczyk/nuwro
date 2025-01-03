#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

#include "src/event1.h"
#include "src/particle.h"
#include "TROOT.h"
#include "TTree.h"
#include "TFile.h"

//#include "TBrowser.h"
//#include "TGraph2D.h"

//const int bins = 100000;

//double weight_min=0;
//double weight_max=1e-38;
//double weight_width = (weight_max-weight_min)/bins;
//int wagi [bins+2];

int events = 100000;

double nowa_waga;

ofstream nuwro ("asia_weight.dat");

void asia_analysis ( TFile *Input)//, double &new_weight )
{
    //TH1D *waga = new TH1D ("waga", "waga", bins, weight_min, weight_max);
    
	TTree *tt1 = (TTree*)Input->Get("treeout");
	event * e= new event();
	tt1->SetBranchAddress("e",&e);
    
    double summa=0;
	for( int k=0; k < events; k++ )
	{
	tt1->GetEntry(k);
       
        double wynik = e->weight;
        summa+=wynik;
            //wynik->Fill(waga);
          
	}
	delete e;
    //new_weight=summa/events;
    cout<<"nowa waga = "<<summa/events<<endl;
    
    /*for (int j=0; j<bins+2; j++)
    {
    table_weight[j]=waga->GetBinContent(j);
    cout<<waga->GetBinContent(j)<<endl;
    }*/
    
}

//////////////////////////////////////////
/////////////////////////////////////////
void asia_reweight()
/////////////////////////////////////////
////////////////////////////////////////
{  
    //cout<<"dupa2"<<endl;
TFile *tf1 = new TFile("deuterium_plus_0.root");
    asia_analysis (tf1);//, nowa_waga);
delete tf1;
    
    //cout<<"change of weight 0->plus"<<endl;

}


