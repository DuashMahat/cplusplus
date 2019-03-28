#ifndef SINGLELINK_H
#define SINGLELINK_H
#include<iostream>
using std::ostream; using std::cout; using std::endl;
#include<sstream>
using std::ostringstream;
#include<utility>
using std::swap;
#include<string>
using std::string;
// forward declaration so we can make Element a friend of TriMap
template<typename K, typename V>
class TriMap;
// private Element, friend of TriMap class
template <typename K, typename V>

class Element{

private:
   K key_;
   size_t index_ = 0;
   Element *next_ = nullptr;  

public:
  
  V value_;
 
  Element() = default;
  
  Element(K key, V val, size_t i) : key_(key),index_(i), next_(nullptr), value_(val) {};

// *defined* in the class, makes templating easier.
friend ostream& operator<<(ostream& out, Element& e){
out << e.key_ << ":" << e.value_ << ":" << e.index_;
return out;
}
friend class TriMap<K,V>;
};


template<typename K, typename V>
class TriMap{
private:
  Element<K,V> *head_ = nullptr;
  Element<K,V> *tail_ = nullptr;
  size_t size_ = 0;
 
// a private function, used by operator<<
void print_list(ostream& out);
 
public:
TriMap() = default;
TriMap(K, V);
TriMap(const TriMap&);
TriMap& operator=(TriMap);
~TriMap();
long size();
bool insert(K,V);
bool remove(K);
Element<K,V>* find_key(K);
Element<K,V>* find_value(V);
Element<K,V>* find_index(size_t);  
 
// *defined* in the class, makes templating easier.
// uses private method print_list
 
friend ostream& operator<<(ostream& out, TriMap<K,V>& sl){
     sl.print_list(out);
    return out;
   };
};


/*
  NAME: DUALE A.
  SECTION: 004
  DATE: 06 / 12 , 2017
*/
template<typename K, typename V>
TriMap<K,V>::TriMap(K k_value, V v_value){
     int starter = 0;  // starter initialized to 0
     int increment = 1;  // int increment to use for the size_
     this->head_ = new Element<K,V>(k_value, v_value, starter); // head_ initialized to new Element
     this->tail_ = this->head_; // tail_ initialized TO head_
     this->size_+=increment;  //size_ added to one 
      
};

/////////////////////////////////////////////////////////

/*
created a pointer that walks
down the list to copy, as tail_ walks down the new list. 
Make a new node (copy the current node of the list we are copying), 
update the tail_->next_ to point to the new node, update tail_ to new node
initialized nullptr to ret, pointer elem_pointer of type Element
setting size of the tm head to this pointer and checking if the elem_pointer is not null to ensure head_ is created from the elem_pointer key_, value_ and index_
 */

template<typename K, typename V>
TriMap<K,V>::TriMap(const TriMap& tm){
   auto ret = nullptr;
   Element<K,V> *elem_pointer = tm.head_;
   this->size_ = tm.size_;  
   if( elem_pointer != ret){
    this->head_ = new Element<K,V>(elem_pointer->key_, elem_pointer->value_, elem_pointer->index_);
   this->tail_ = this->head_;
   elem_pointer = elem_pointer->next_;
   Element<K,V> *node;
  
while (elem_pointer != ret) {
     node = new Element<K,V>(elem_pointer->key_, elem_pointer->value_, elem_pointer->index_);
     this->tail_->next_ = node;
     this->tail_ = node;
     elem_pointer = elem_pointer->next_;
   }
      }
}

template<typename K, typename V>
   TriMap<K,V>& TriMap<K,V>::operator=(TriMap tm){
   auto rets = nullptr;  // initialized to rets 
   this->size_ = tm.size_; // size_ initialized to size_
   Element<K,V> *elem_pointer = tm.head_; // elem_pointer of type Element initialized to tm.head_
if(elem_pointer != rets){  // as long as elem_pointer NOT equal to nullptr do below 
  this->head_ = new Element<K,V>(elem_pointer->key_, elem_pointer->value_, elem_pointer->index_);
   this->tail_ = this->head_;
   elem_pointer = elem_pointer->next_;
     Element<K,V> *node;
   while(elem_pointer != rets){
      node = new Element<K,V>(elem_pointer->key_, elem_pointer->value_, elem_pointer->index_);
      this->tail_->next_ = node;
      this->tail_ = node;
     elem_pointer = elem_pointer->next_;
   }
}
auto ret = *this;
return ret;
}
// walk down the list using head_ , keeping a trailer pointer called to_del
// delete what to_del points to
// move head_ and to_del to the next node.
template<typename K, typename V>

TriMap<K,V>::~TriMap(){
   auto ret = nullptr;
   Element<K,V> *to_del = this->head_;
   while(to_del != ret){
       this->head_ = this->head_->next_;
       delete to_del;
       to_del = this->head_;
  }
}

/*
returns size_
*/

template<typename K, typename V>
long TriMap<K,V>::size(){
  return this->size_;
}

template<typename K, typename V>
bool TriMap<K,V>::insert(K k_value, V v_value){
  
    int starter = 0;  // starter initialized to 0;
    auto ret = nullptr; // nullptr initialized
    auto num = 1;     // num initialized to 1
// elements are inserted in *key order*
   if(this->head_ == ret){  // if head_ points to nullptr
     
      this->head_ = new Element<K,V>(k_value, v_value , starter);
     
      this->tail_ = this->head_;
     
      this->size_++;
   }
  else{  // if not pointing to nullptr
   Element<K,V> *elem_pointer = this->head_;  // elem_pointer equals pointer to head_
    
   Element<K,V> *f_elem_pointer = ret;  // previous pointer points to nullptr
    
   while( (elem_pointer !=  ret) && (elem_pointer->key_ < k_value)){ // while loop to check as long as elem_pointer is not equal to nullptr amd key_ is less than the k_value
     
       f_elem_pointer = elem_pointer;  // f_elem_pointer is equal to elem_pointer
     
       elem_pointer = elem_pointer -> next_;  //elem_pointer equal to next_ 
    }

   if(elem_pointer == ret){  // as long as not nullptr equals elem_pointer
    
     Element<K,V> *node = new Element<K,V>(k_value, v_value, this->size_); // node of type Element equals to new pointer 
     
     f_elem_pointer->next_ = node;  // f_elem_pointer- next_ now equals to the new node created
     
     this->tail_ = node;  // tail_ initialized to node 
     
     this->size_++;  // increment size_ by one 
     
    }else if(elem_pointer->key_ == k_value){  
     
      return 0;
   }
    else{
      
   Element<K,V> *node = new Element<K,V>(k_value,v_value,this->size_);
    if(f_elem_pointer == ret){
      
         this->head_ = node;
      
     }
      else{
        
        f_elem_pointer->next_ = node;
     }
     node->next_ = elem_pointer;
     this->size_++;
     }
    
  }
  return num;
 }
 
template<typename K, typename V>

//  By deleting  a node, the indicies of all
// nodes with a higher index have that index reduced by one

bool TriMap<K,V>::remove(K k_value){

   auto ret = 0;
  
   int index;
   
   auto retss = nullptr;
   
   int ret2 = 1;
     
   if(this->head_ == nullptr){
     
     return ret;
   }
  
  else{
      
     auto rets = nullptr;
     Element<K,V> *f_elem_pointer = nullptr;
     Element<K,V> *elem_pointer = this->head_;
while((elem_pointer != nullptr) && (elem_pointer->key_ != k_value)){
    
       f_elem_pointer = elem_pointer;
      elem_pointer = elem_pointer->next_;
   }
    
// int index;
    
int ret = 0;

if(elem_pointer == nullptr){
  
   return ret;
  
}
    else{
if(f_elem_pointer == nullptr){
  
    this->head_ = elem_pointer->next_;
}
      else{
        
    f_elem_pointer->next_ = elem_pointer->next_;
}
      
index = elem_pointer->index_;

      
delete elem_pointer;
      
    this->size_--;
      
}

elem_pointer = this->head_;
    
    
while(elem_pointer != nullptr){
  
   if(elem_pointer->index_ > index){
   elem_pointer->index_--;
      }
   elem_pointer = elem_pointer->next_;
}
    
 return ret2;
    
   }
}
 
//////////////////////////////////////////
template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_key(K k_value){
//  linear search
Element<K,V> *node = this->head_;
  
auto rets = nullptr;    // rets pointer initialized to nullptr

  while(node != nullptr){  // as long as node is not Equal to nullptr
  
     if(node->key_ == k_value){  // if key_ value_ to be search 
       
        return node;  // return node 
     }
    node = node->next_;  // node initialized to next_ of node 
  }
  
  return rets;  // return rets pointer
}    


//////////////////////////////////////////
template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_value(V v_value){
// linear search
  auto ret4 = nullptr;  // initialized nullptr
  Element<K,V> *node = this->head_;  // node of type Element initialized to head_
  
  while(node != nullptr){  // while loop as long as the node- is not equal to nullptr
    
    if(node->value_ == v_value){  // if value_ node == the value of V in the search
      
      return node;  // return that node 
   }
     node = node->next_;  // node is the next_
  }
  
   return ret4;  // return ret4 pointer
 
}  

//////////////////////////////////////////

template<typename K, typename V>
Element<K,V>* TriMap<K,V>::find_index(size_t s_size){
    
// linear search
    auto ret5 = nullptr;
    Element<K,V> *node = this->head_;
  
while(node != nullptr){  // while node is not equal to nullptr
  
   if (node->index_ == s_size){    // if index_ of node == s_size
     
      return node;   // returns that specific node
    }
  
   node = node->next_;    // that node moves to the next_
 }
  
  return ret5;   // return nullptr
   
}  

template<typename K, typename V>
void TriMap<K,V>::print_list(ostream &output){
// this is a class member function, has access
// to private data. Called by operator<<
    Element<K,V> *node = this->head_;  // node points equals to this pointer of head_
    while( (node != nullptr) && (node->next_ != nullptr)){  // node must not be == to nullptr and next node must not be equal to nullptr 
      output  << *node << ", ";   // output node 
      node = node->next_;         // node is now next node 
     }
  
     if(node != nullptr){  // if node is not equal to nullptr
  
       output << *node;   // output/cout the node 
     }
  
};

#endif
 
