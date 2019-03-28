
#include <iostream>
#include<string>
#include<sstream>
#include<iomanip>


#include  "proj08_twod.h"


using std::cin; using std::cout; using std::endl; using std::ostringstream;
using std::setprecision; using std::fixed;


// TwoD::TwoD() {
    
//     x = 0;
    
//     y = 0;
// }




TwoD::TwoD(double xval, double yval) { 
    
    
    x = xval;
    
    y = yval;
}


string TwoD::to_string() { 
    
    
    TwoD d (x, y);
    
    
    ostringstream oss;
    
    
    oss << fixed << setprecision(2) << "(" <<  d.x << ", " << d.y << ")";
    
    return oss.str();
    
    
    
}
    
    
    



TwoD TwoD::diff (TwoD d) {   // two D is the type at whatever cose 
    
    TwoD diffs;
    diffs.x = diffs.x - x;
    diffs.y = diffs.y - y;
    return diffs;
    
}

// mult: a TwoD method. Multiply both elements of a 
// TwoD by the provided double. Returns a new TwoD. Also done in lab09


TwoD TwoD::mult(double dd) {
    TwoD multiply (x , y);
    multiply.x= multiply.x * dd;
    multiply.y = multiply.y * dd;
    return multiply;
}



double TwoD::dot_product(TwoD v1) {
    
    TwoD v2 ( x, y);
    
    double dd = ((v2.x * v1.x )+ (v2.y * v1.y));
    
    return dd;
}


double TwoD::magnitude_squared() {
    
    
    TwoD square ( x, y);
    
    double mag = (pow(square.x , 2) + pow(square.y , 2));
    
    return mag;
}