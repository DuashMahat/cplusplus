#include<iostream>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<functional>
using std::multiplies; using std::minus; using std::plus;
#include<numeric>
using std::accumulate;
using std::boolalpha;
using std::to_string;
#include<algorithm>
#include<string>
using std::string;
#include<vector>
using std::vector;
#include<iostream>
using std::ostream;
#include<sstream>
using std::istringstream;
using std::ostringstream;
#include <map>
#include <iterator>
//using std::split;
using std::cin; using std::cout; using std::endl;
using std::map;
using std::pair;
#include<string>
using std::string;
#include<iostream>
using std::ostream;
#include<vector>
using std::vector;
#include<initializer_list>
using std::initializer_list;
using std::find;
using std::upper_bound;
using std::remove_if;
#include "proj09_trimap.h"

/*
  NAME: DUALE ABDULLAHI
  SECTION: 004
  DATE: 20 / NOV / 2017
  PROJECT 09;
*/
TriMap::TriMap(const Element& el){ // Class Trimap with an argument of class Element
    int number = 1;   
    sz_ = number;
    vec_.push_back(el);  //pushing back Element el into the vector vec_ of Element;
}

TriMap::TriMap(initializer_list<Element> el){
    sz_= el.size();    // size_t which is rghe size of Element el;
    for (unsigned int i = 0; i < sz_; ++i) {  // for loop to form zero to the sizeof el minus one
        vec_.push_back(*(el.begin() + i)); // pushing back each el Element plus i  to the vector vec_ of Element ...
    }
}

size_t TriMap::size() {     // return type of size_t 
    return this->vec_.size();  // returning the size of the vector of Element vec_
    
}

bool TriMap::insert(string key , string value) {
   string k = key;  // inititializing key to k;
   string val = value;  // inititializing value to val;
   if(find_key(key)!= nullptr) {// calling from the find_key method
       return false;
    }
    //upper_bound:: returns an iterator pointing to the first element in the range [first,last) which compares greater than key.
    auto position = upper_bound(vec_.begin(), vec_.end(), key, [] ( const   string& str, const Element & element) {
        
        return str < element.key_; // returns true if str is less than the element vector key..
    });
    
    Element element(k , val ,sz_);  // element of class Element with the fields we have to insert to the vector vec_;
    vec_.insert(position ,element);  // inserting 
    sz_ ++;
    return true;
}
  


bool TriMap::remove (string key) {
    size_t index = - 1;
    for ( auto iter : vec_) {
        if ( iter.key_ == key )  {
            index = iter.index_;
        }
    }      
    
    int negative = - 1;  
    
     if ( index == negative )
       return false;
       
    vec_.erase(remove_if(vec_.begin(), vec_.end(), [&key] (const Element elem     ){
       return elem.key_ == key;
   }), vec_.end());
   
   
   for ( auto vec : vec_) {
       
       if ( vec.index_ > index) {
           
           vec.index_-=1;
       }
   }
        
    return true;
}


Element* TriMap::find_key(const string& keys) {
    int negatives = -1;
    auto position = upper_bound ( vec_.begin(), vec_.end(), keys, [](const string& str , const Element& elems){
         return str < elems.key_;
    });
    
    if ( position == vec_.begin()) 
        return nullptr;
     std::advance ( position, negatives );
     if ( position -> key_ == keys ) {
        return &(*position);
    } 
    else { 
       return nullptr;
    }
  }
        
Element* TriMap::find_value(const string& value ) {
     //vector<Element>::iterator iter;
     auto find_iter = find_if(vec_.begin(),vec_.end(), 
        [&value] (Element ele) {
            return ele.value_ == value;
        }
    );
    
    if ( find_iter == vec_.end()) {
        return nullptr;
    }
    else {
        return &(*find_iter);
    }
 }

Element* TriMap::find_index(size_t index) {
    //vector<Element>::iterator iter;
    auto find_iter = find_if (vec_.begin(), vec_.end(), 
            [&index] (Element ele) {
            return ele.index_ == index;
        }
    );
    
    if ( find_iter == vec_.end()) {
        
        return nullptr;
    }
    
    else {
        
        return &(*find_iter);
    }
    
  }
 ostream& operator<<(ostream& out , const Element& elem ) {

     out << elem.key_ << ":" << elem.value_ << ":" << elem.index_;
   
     return out;
  }

 ostream& operator<<(ostream& out , const TriMap& tri_elem){
     ostringstream oss;
     for (auto tr : tri_elem.vec_) {
         oss << tr << ", ";
     }
     string str = oss.str();
     str = str.substr(0, str.length()-2);
     out << str;
     return out;
 }
 
