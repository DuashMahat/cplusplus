#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string;
               
// meta, strictly increase

bool metadrome (string n , long base ) {   // METADROME............
    bool is_metadrome  = true;
    
    //cout << n.size() << endl;
    for (unsigned int i = 0; i < n.size(); ++i ){  // i = 0 , 1, 2 , 3
      
      
        if (( n[i]  < n[i+1]) && ( i != n.size()- 1)) {
            continue;
        }
        
        else if ( (n[i]  >    n[n.size() - 2]) && ( i == n.size()-1 )) {
            
            //cout << n[n.size() - 2] <<  " shit this fuck " << endl;
            //cout << n[i] <<  " shit this fuck " << endl;
            
            
            is_metadrome = true;
            
        }
        
        
        else {
            
            
            is_metadrome = false;
            
            break;
            
        }
        
    }
      
        return is_metadrome;
}
// plain, non-strictly increase


bool plaindrome (string n , int base ) { // PLAINDROME
    
    
    bool is_plaindrome = true;
    
    
    for ( unsigned int i = 0; i < n.size(); ++i ) {
        
        
        if (( (n[i] < n[i+1]) || (n[i] == n[i+1]) )  && ( i != n.size() - 1)) {
            
            
            continue;
        }
        
        
         else if ( (n[i]  >= n[n.size() - 2]) && ( i == n.size()-1 )) {
             
             
             is_plaindrome = true;
         }
        
        else {
            
            
            is_plaindrome = false;
            
            break;
        }
        
        
        
    }
    
    return is_plaindrome;
    
}
// kata, strictly decrease

bool katadrome ( string n , int base ) {   //KATADROME 
    
    
    bool is_katadrome = true;
    
    
    for ( unsigned int i = 0; i < n.size(); ++i ) 
        
        
        if ( (n[i] > n[i+1]) && ( i != n.size() - 1)) {
            
            
            continue; 
        }
    
      else if ( (n[i] < n[n.size() - 2]) && ( i == n.size()-1 )) {
           
           
           is_katadrome = true;
       }
    
       
       else {
           
           
           is_katadrome = false;
           
           break;
       }
    
    
    return is_katadrome;
}

// nialp, non-strictly decrease


bool nialpdrome ( string n , int base ) { //An integer whose digits are the same or decreasing
    
    
    bool is_nialpdrome = true;
    
    for ( unsigned int i = 0; i < n.size(); ++i ) {
        
        
        if (( (n[i] > n[i+1]) || (n[i] == n[i+1]) )  && ( i != n.size() - 1)) {
            
            continue;
        }
        
         else if ( (n[i]  <= n[n.size() - 2]) && ( i == n.size()-1 )) {
             
             
             is_nialpdrome = true;
             
         }
        
        
        else {
            
            
            is_nialpdrome = false;
            
            break;
        }
    }
    
    return is_nialpdrome;
    
}
// non, none of the above


bool nondrome ( string n , int base ) {  // if it neither of all dromes then it is nondrome
    
    
    bool is_nondrome = false ; 
    
    
    if ((!metadrome(n,2)) && (!katadrome(n,2)) && (!plaindrome(n,2)) && (!nialpdrome(n,2))) {
        
        
        is_nondrome = true;
    }
    
    
    return is_nondrome;
    
    
}



string classify ( string n , int base ) {  // let i say i put one of the five strings .....12345
    
    
    string met = "metadrome";
    string plain = "plaindrome";
    string kata = "katadrome";
    string nial = "nialpdrome";
    string none = "nondrome";
    
    if ( metadrome(n , base)  ||  plaindrome(n , base) ) {
        
        if (metadrome(n , base)) {
            
            return met;
            
        }
        
        else {
            
            
            return plain;
        }
    }
    
    else if (  katadrome(n , base)  ||  nialpdrome(n , base)  ){
        
        if (katadrome(n , base)) {
            
            return kata;
            
        }
        
        else {
            
            
            return nial;
        }
        
    }
    
    else {
        
        
        return none;
    }
    
}


const string base_vals = "0123456789abcdefghijklmnopqrstuvwxyz";


int main (){
  string num;
  long base;
  cout << boolalpha;
  cin >> num >> base;
  cout << metadrome (num, base) << " "
       << plaindrome (num, base) << " "
       << katadrome (num, base) << " "
       << nialpdrome (num, base) << " "
       << classify(num, base) << endl;
}
    



  
