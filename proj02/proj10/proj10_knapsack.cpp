
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <fstream>
using std::cin; using std::cout; using std::endl; 
using namespace std;
#include "proj10_knapsack.h"
#include "proj10_package.h"
// constructor with fields of class knapsack set to 0 , 10, and the 
// argument max equaling the weight_limit of the knapsack 
Knapsack::Knapsack( size_t wlimit ) {
   size_ = 0;
   capacity_ = 10;
   weight_limit_ = wlimit;
   data_ =  new Package[capacity_];
}
//copy constructor (one of the rule of three....)
//initializes  object knapsack_object
Knapsack::Knapsack(const Knapsack& knapsack_object) {
    size_ = knapsack_object.size_;
    capacity_ = knapsack_object.capacity_;
    weight_limit_ = knapsack_object.weight_limit_;
    data_ = new Package[capacity_];
    copy(knapsack_object.data_, knapsack_object.data_+size_, data_);
}
Knapsack::Knapsack(size_t wlimit, size_t cap) {
  int temp_Knapsack_size = 0;
  capacity_ = cap;
  weight_limit_ = wlimit;
  size_ = temp_Knapsack_size;
  data_ = new Package[capacity_];
} 
// deconstructor to delete the Package data_ array
Knapsack::~Knapsack() {
  
  delete [] data_;
}

// getter member function that returns weight_limit of the
// Knapsack instance 

long Knapsack::weight_limit() const {
  
    return weight_limit_;
 }
// getter member function that returns present size_
// of the array data

long Knapsack::size() const {
  
   return size_;
}

// getter member function that returns present capacity_
// of the array

long Knapsack::capacity() const {
  
  return capacity_;
}
//member function that  sums the maximum weight the 
//snapsack element can hold...

long Knapsack::weight() const{
    //initializing the total sum to zero
    auto max_weight_sum = 0;
    // for loop from 0 to size_ of the array les one
    // and adding the weight_ to the tota sum 
    
    if ( size_!= 0 ) {
    for ( unsigned int x = 0; x < size_; ++x) {
      
      max_weight_sum += data_[x].weight_;
      
    }
    }
   return max_weight_sum;
}
//member function bool to check if the weight is exeeded or not
//calls the member function weight and adds Package to the 
//Knapsack 

bool Knapsack::add(const Package& pack_it) {
  bool is_true = false;
  if (weight()+pack_it.weight_ > weight_limit_) {
    is_true =false;
    return is_true;
  }
  
  else {
    if ((capacity_ - size_) <= 0) {
      capacity_ *=2;
      Package *new_data = new Package[capacity_];
      std::copy(data_, data_+size_, new_data);
      std::swap(data_, new_data);
      delete [] new_data;
    }
    data_[size_++] = pack_it;
    is_true = true;
    return is_true;
  }
  is_true = false;
  return is_true;
}
// returns the total priorities available...
long Knapsack::priority() const {
  
   long max_priorities_sum = 0;
   if (size_!= 0) {
   for (unsigned int x = 0; x < size_; ++x){
     
      max_priorities_sum += data_[x].priority_;
   }
   }
   return max_priorities_sum;
}
// returns true if the Knapsack is empty and false otherwise
bool Knapsack::empty() const {
  
   if ( size_ >  0 ) {
     
     return false;
   }
   
   else {
     
     return true;
   }
}

// opens a file given while checking if it can be opened 
// creates a vector of type Package 
// creates fields long w and p from the file  to push back into the vector 
//  the vector is sorted 
//  iterates over the vector and adds to the vector the vector elements as 
// long as add function is application and the maximum weight is not exceeded;
void solve_KS(string fstring, Knapsack& pack_it3){
         ifstream file;
         file.open(fstring);
         if (!file) {
            cout <<"file can not be open" << endl;
          }
         else {
          vector<Package> myvec;
          long w , p;
          while(file >> w >> p) {
          myvec.push_back(Package(w,p));
            }
         sort(myvec.begin(), myvec.end(), package_compare);
         cout << pack_it3 << std::endl;
         for (auto vec : myvec){
            if (vec.weight_ + pack_it3.size_ <= pack_it3.weight_limit_){
                  pack_it3.add(vec);
              }
              else {
                 
                     break;
                 }
         
              }
         }
        cout << pack_it3 << endl;
        file.close();
 } 
 
// the assignment operator 
// checks if this pointer is equal to the Knapsack object and also if the
//the data_ is null 

Knapsack& Knapsack::operator=(const Knapsack pack_it4) {
     if ( this == &pack_it4) {
      return *this;
     }
     if ( data_ != NULL) {
      delete[] data_;
     }
     size_ = pack_it4.size_;
     capacity_ = pack_it4.capacity_;
     weight_limit_ = pack_it4.weight_limit_;
     data_ = new Package[capacity_];
     memcpy(data_, pack_it4.data_, capacity_);
     return *this;
}


// overload ostream operator << for outputs the weights and priority_
// uses ostringstream to prints pouts

 ostream& operator<<(ostream& out , Knapsack &  pack_it3) {
     ostringstream oss;
     for (unsigned int x = 0; x < pack_it3.size_-1 ; ++x) {
      
        out << pack_it3.data_[x].weight_ << ":" << pack_it3.data_[x].priority_            << ", ";
      }
      int x = 0;
      out << pack_it3.data_[x].weight_ << ":" << pack_it3.data_[x].priority_;
  
    
    string str = oss.str();
    out << str;
    return out;
}



