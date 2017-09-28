//============================================================================
// Name        : MachineLearning Assignment-2
// Author      : Harshitha Yendapally
// Version     :1
// Copyright   : Blackboard Submitted file to UTSA
// Description : Program is about learning the linear function and predicting
//               unknown values.

//============================================================================

#include <iomanip>
#include "linreg.h"
#include<iostream>
using namespace std;


//Points are entered in array format.(one of the formats among 3 is choosen)
//Inputs gathered for training the system are entered
double x[] = {19.7,19.1,18.2,5.2,4.3,9.3,3.6,14.8,11.9,9.3,2.8,
		      9.9,15.4,2.7,10.6,16.6,11.4};
double y[] = {19.7,19.3,18.6,7.9,4.4,9.6,8.0,15.7,15.4,9.8,10.3,
              11.2,16.8,5.1,12.2,18.9,12.2};

//Points entered in point format
Point2D p[] = { Point2D(19.7, 19.7), Point2D(19.1, 19.3), Point2D(18.2, 18.6),
                Point2D(5.2, 7.9), Point2D(4.3, 4.4), Point2D(9.3, 9.6),
                Point2D(3.6, 8.0), Point2D(14.8, 15.7), Point2D(11.9, 15.4),
                Point2D(9.3, 9.8), Point2D(2.8, 10.3),Point2D(9.9, 11.2),
                Point2D(15.4, 16.8),Point2D(2.7, 5.1),Point2D(10.6, 12.2),
                Point2D(16.6, 18.9),Point2D(11.4, 12.2)};


int main()
{
    cout << "Learned Linear Function Analysis" << endl;
    LinearRegression lr_xy(x, y, 17);  // learned linear function calculation
    cout << "Number of x,y pairs = " << lr_xy.items() << endl;
    cout << lr_xy << endl;
    cout << "Coefficient of Determination = "
         << lr_xy.getCoefDeterm() << endl;
    cout << "Coefficient of Correlation = "
         << lr_xy.getCoefCorrel() << endl;
    cout << "Standard Error of Estimate = "
         << lr_xy.getStdErrorEst() << endl;

    cout << "\nLearned Linear Function Analysis when inputs are entered in point-2D format." << endl;
    LinearRegression lr_2D(p, 17);  // learned linear function calculation
    cout << "Number of x,y pairs = " << lr_2D.items() << endl;
    cout << lr_2D<< endl;
    cout << "Coefficient of Determination = "
         << lr_2D.getCoefDeterm() << endl;
    cout << "Coefficient of Correlation = "
         << lr_2D.getCoefCorrel() << endl;
    cout << "Standard Error of Estimate = "
         << lr_2D.getStdErrorEst() << endl;

    cout << "\nLearned Linear Function Analysis when inputs are entered in empty instance format." << endl;
    LinearRegression lr_empt;   // learned linear function calculation
    for (int i = 0; i < 17; i++)
    	lr_empt.addPoint(p[i]);
    cout << "Number of x,y pairs = " << lr_empt.items() << endl;
    cout << lr_empt<< endl;
    cout << "Coefficient of Determination = "
         << lr_empt.getCoefDeterm() << endl;
    cout << "Coefficient of Correlation = "
         << lr_empt.getCoefCorrel() << endl;
    cout << "Standard Error of Estimate = "
         << lr_empt.getStdErrorEst() << endl;

    int i,n;
    double in1,result;
    //code to find the estimated values of test samples  provided by user
     cout << "enter number of user values for which estimated results are to be predicted"<<endl;
     cin>>n;
     for(i=0;i<n;i++){
     cout <<"enter input "<<endl;
     cin>>in1;
     result=(in1*(lr_xy.getB()))+(lr_xy.getA());
     cout<<"predicted value for "<<in1<<" is "<<result<<endl;
     cout<<"\n";
    }
     cout<<"end of the user values.program exited.";
     return 0;
}
