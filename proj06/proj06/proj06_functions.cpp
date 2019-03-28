
#include<string>
#include<iostream>
using std::cout; using std::endl;
#include<iomanip>
using std::setw;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<sstream>
using std::ostringstream;
using std::right;
using std::left;
#include<string>
using std::string;
using std::vector;
#include<bits/stdc++.h>
#include <algorithm>
#include <fstream>
using std::ifstream;

#include "proj06_functions.h"


/*

converts the argument to a binary string that is 8 chars long 
consisting of either '0' or '1'
• Error Check: if the argument is not in the range 0 – 255,
returns a string of 8 '0' (binary 0)

*/




string to_binary(int val) { 
    
    
    ostringstream oss;  // initialized ostringstream object.
    
    string output;      // string to return later...
    
    string eight_binary = "00000000";  // a 8 bit string to compare size with
    
    
    if ((val < 0 ) || (  val > 255)) {   // if the argument is negative or greater than 255
        
        
        for ( unsigned int i = 0; i < 8; ++i ) { // the final output should be of size eight anyway
            
            
            oss << 0 << "";      // outputing binary zeros to oss 
        }
    }
    
    
    else {           // if not negative and less than 255
        
        
        do {         // do this condition until the "while" below is false
            
            
            if (  val % 2 == 0 ) {    // basic operations to output 0 or 1 depending on the remainder..
                
                
                oss << 0 << "";
            }
            
            else {
                
                
                oss << 1 << "";
            }
            
            
            val/=2;
        }
        
        while ( val > 0 );
         
    }
    
output = oss.str();    // string outpur...
    
    
    
reverse(output.begin(), output.end());   // reversing the order 
    

    // since we need a string of length 8 if the size of the string < 8 we have to fill then 
    // the rest with zeros anyway since this will not have an effect on the integer value represented
    
if ( output.size() < eight_binary .size()) {   // if the size of the output < 8 then 
    
     string forward ="";           // creates a new string to store the remaining size in chars       
    
     char zero ='0';                // character named zero initialized to 0
    
     int len = eight_binary .size() -  output.size();  // the size of the remaining size for INT LEN
    
     
     for ( int i = 0; i < len; ++i ) {
         
         
          forward+=zero;              // filling the forward string to the lenght of len 
     }
    
    
    output = forward + output;         // final output string = forward string plus the original 
    
}
    
    return output;   // return 
}




int next_val (const vector<int> &v, const string &binary_rule_string) {
    
    ostringstream oss;   // sstream object ostringstream ...
    
    
    
    vector<int> binary;   // an empty vector binary 
    
     
    for ( unsigned int i = 0; i < v.size(); ++i ) {  // from zero to size of v less than 1
        
        
        oss << v[i]<<"";                             // inputing every integer as char to oss 
        
    }
    
    oss << endl;                                     
    
    string all = oss.str();                         //  string named all to record values of v as string chars 
    
    
                                                    
    // creating an integer value for the binary string binary rule string;

    
    int bin = std::stoi( binary_rule_string , nullptr, 2);
    
    
    // creating a vector of the binary 0s and 1s of the value above to get the rules ...
    
    
    do {                                
        
        
        if ( bin % 2 == 0  ) {
            
            binary.push_back(0);
        }
        
        else {
            
            binary.push_back(1);
        }
        
        bin/=2;
    }
    
    while ( bin > 0);
    
    
    // i want the size of the vector to be 8 so that i can compare it with an eight bit integer 
    
    
    if ( binary.size() < 8 ) {
        
        
        int len = 8 - binary.size();
        
        
        for ( int i = 0; i < len; ++i ) {
            
            binary.push_back(0);
        }
        
        
        reverse( binary.begin() , binary.end() );
        
    }
    
    else {
        
         reverse( binary.begin() , binary.end());  // reversing the order to get the correct positions
     }
    
    
    // now i have a vector of binary ints that is eight sized long v [00011110] 
    // Also I have a string we got from the argument vector <in> &v 
    
    // since the vector tnat i changed to string is assumed to be size 3 i just use direct index
    
    if (all[0] == '1') {      //   Using the rules from the binary string to check the next val
                              // this can be any rule like 30, 60 ,64 etc
        
        if ((all[1] == '1') && (all[2] == '1')) {   // if the vector argument is v{1,1,1};
            
            
            return binary[0];                       // then the next val is index[0] of the vector binary;
        }
        
        else if ((all[1] == '1') && (all[2] == '0')){   // the rest of the code follows the rules from the index
            
            return binary[1]; 
        }
        
        else if ((all[1] == '0') && (all[2] == '1')){
            
            return binary[2];
        }
        
        else {
            
            return binary[3];
        }
        
        
    }
    
    
    else {
        
         if ((all[1] == '1') && (all[2] == '1')) {
            
            
            return binary[4];
        }
        
        
        else if ((all[1] == '1') && (all[2] == '0')){
            
            return binary[5];
        }
        
        else if ((all[1] == '0') && (all[2] == '1')){
            
            return binary[6];
        }
        
        else {
            
            return binary[7];
        }
        
    }
    
    
    
        
    
}



vector<int> one_iteration(const vector<int> &v, const string &binary_rule_string) {
    
    
    // from the pdf the first and the last indexes are just added 0s for rule application purposes 
    
    vector <int> new_vector ={0}; 
        
    
     for (unsigned int i = 1; i < v.size()-1 ; ++i ) {   
        
        // from index 1 which the rule starts second last which it stops                                                
                                                       
         
         vector<int>myvec = {v[i-1],v[i], v[i+1]};   // creating size 3 subset vector of the main vector
        
        
              int new_val = next_val (myvec , binary_rule_string );   // using next_val in each
        
         
              new_vector.push_back(new_val);   // putting the next value from the rule to new vector 
        
         
         
          }
    
    
    
    new_vector.push_back(0); // adding the last index 0 to the vector
    
    
    
    return new_vector;       // returning the final vector of all new _ vals
    
    
    
}





string vector_to_string(const vector<int> &v) {
    
    
     ostringstream oss;        // creating an ostringstream 
    
    
     for ( unsigned int i = 0; i < v.size(); ++i ) {  // from 0 to size of the vector size minus 1..
         
         if (i  != v.size() - 1) {  // as long as the i is not size of v - 1
             
             
             oss << v[i] << ",";     // output the value of index i in oss followed by a comma..
         }
         
         
         else {     // if i correspond to the last index of v ...                
             
             oss << v[i];     // ouput that value to oss with no comma or endl;
         }
         
     }
    
    string s = oss.str();    // creating a final string for that
    
     
    
    
    return s;               // return the string 
    
}



void read_vector(vector<int> &v, string file_str) {
    
     
   if (!v.empty()) {    // if v is not empty 
       
       
       v = v;           // v is equal to v and that is it 
   }
    
    
   else {              // otherwise 
      
      
     ifstream name;;   // ifstream called name 
      
     
      
     name.open(file_str.c_str());    // opening the file 
      
      
      if (!name) {                  // if it can not be opened
          
          
          v = v;                    // the vector remains the same
      }
       
       
      else {   // otherwise 
          
          
          while ( true ) {    // while true
              
              
              int x;
              
              
              
                  
                  
                 name >> x;
                  
                  
                  if( name.eof() )   // if the end of the file is reached break;
                      
                      break;
                  
                  
                  v.push_back(x);       // pushing back every value of the file into the vector 
              }
          }
      }                     
  }





