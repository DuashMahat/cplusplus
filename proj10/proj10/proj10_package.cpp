#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
using namespace std;
#include "proj10_package.h"
#include "proj10_knapsack.h"
// struct Package {
//      public:
//         long weight_;
//         long priority_;
//         Package(long w = 0, long p = 0):weight_(w),priority_(p){};
// };


// Package::Package (long weight , long priority) {
    
//       weight_ = weight;
//       priority_ = priority;
    
// }


//////////////////////////////////////////////////////////////
std::ostream&  operator << (ostream& out , Package& p ) {
  
  out << p.weight_ << ":" << p.priority_;
  
  return out;
}

/////////////////////////////////////////////////////////////
bool package_compare ( const Package &lhs , const Package &rhs){
  
  vector<Package>myvec;
 
  if ( (lhs.priority_/lhs.weight_) > (rhs.priority_/rhs.weight_)) {
    
    //   myvec.push_back(lhs);
    //   myvec.push_back(rhs);
       return true;
     }
  
    else {
    
        // myvec.push_back(rhs);
        // myvec.push_back(lhs);
        return false;
  }
}