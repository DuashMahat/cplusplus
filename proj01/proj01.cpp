#include <iostream>
#include <cmath>
#include <complex>
#include <iomanip>



using std::cin; using std::cout; using std::endl; using std::setprecision; using std::fixed;



int main () {
    
    
   // ( areal1 + bimag1i ) , ( creal2 + dimag2i)
   


    
   float real1, real2 , imag1 , imag2;
    
    
  // cout << "Enter real number1 and imaginary number1: " << " ";
    
   
   cin >> real1 >> imag1;
    
   
  // cout  << "Enter real number2 and imaginary number2: " << " ";
    
    
   cin >> real2 >> imag2;
    
    
   double sum1 = (real1 + real2);
    
   double sum2 = (imag1 + imag2);
    
   double diff1 = (real1-real2);
    
   double diff2 = (imag1-imag2);
    
   double prod1 = (real1*real2 - imag1*imag2);
   
   double prod2 = (imag1*real2 + real1*imag2);
    
   double quot1 = ((real1*real2 + imag1*imag2) / ( pow (real2 , 2) + pow (imag2 , 2)));
   
   // ( areal1 + bimag1i ) / ( creal2 + dimag2i)
   double quot2 = ((imag1*real2 -  real1*imag2) / ( pow (real2 , 2) + pow (imag2 , 2)));
    
   
    
   cout << setprecision(2) << fixed << sum1 << " + " << sum2 << "i" << endl;
    
   cout << setprecision(2) << fixed << diff1 << " + " << diff2 << "i" << endl;
  
   cout << setprecision(2) << fixed << prod1 << " + " << prod2 << "i" << endl;
   
   
   cout << setprecision(2) << fixed << quot1 << " + " << quot2 << "i" << endl;
    

}

