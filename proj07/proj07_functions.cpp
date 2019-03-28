#include<iostream>
#include<algorithm>
using std::cout; using std::endl;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<functional>
#include <iterator>
using std::multiplies; using std::minus; using std::plus; using std::iterator; using std::find;
using std::find_if; using std::distance;
#include<numeric>
using std::accumulate;
#include <iostream>
#include <map>
#include <iterator>
//using Collatz = pair<long, vector<long> >;
#include<vector>
using std::vector;
#include<string>
using std::string;
#include<map>
using std::map;
#include<utility>
using std::pair;
#include<fstream>
#include <sstream>
using std::ostringstream;
using std::pair;
#include <math.h>  
using std::setprecision;
//using std::substr;
#include<fstream>
using std::ostream;
using std::distance;
using std::fixed;
using std::stod;

#include "proj07_functions.h"

vector<string> split(const string &s, char delim) {
    vector<string>myvec;  //new vector initialised 
    std::size_t begin = 0; // size_t type initialised to 0;
    auto check =  s.find (delim , begin);//atutomatic position 
    while ( check != string::npos) {     //making sure check is within the string
       myvec.push_back(s.substr(begin, check - begin));  
       
         begin = check + 1;     //incrementing begin by one ...
         
         check =  s.find (delim , begin); //changing the vaue of check based on the begin   
    }
    
    //AS long as the value of begin is not equal to size of the string
    //push_back myvec a substring of the string starting from the position of begin
    if ( begin != s.size()) {
        
        myvec.push_back(s.substr(begin));
    }
    
    
    return myvec;
    
 }


string pair_to_string( const pair<vector<double>, string> &p ) {
    // creating ostringstream object;
    ostringstream oss;
    //iteration through each value of the vector which is elements first of pair
    for ( auto vec : p.first) {
        oss <<fixed<<setprecision(3)<<vec<< " "; // putting each value in to the string with precision of 3 and no exponent 
    
    }
    //putting the element second(string) of the pair into the ostringstream
    oss <<""<< p.second;
    //creating a final string for the ostringstream object
    string s = oss.str();
    //returning the string
    return s;
}

void read_data (map<vector<double>, string> &m, unsigned int feature_count, ifstream &inf) {
    // string named fileline
    string fileline;
    //character namef delim set to a comma
    char delim = ',';
    //string named adding    
    string adding;
    //getting each line in the file 
    while (getline (inf, fileline)){
         //if nothing of a file object found continue the loop
         if (fileline.size() == 0) {
             continue;
          }
          // using split function to split the fileline at any occurence of the delim character
          vector<string> myvec_splitted = split(fileline, delim);
          // creating a new empty vector 
          vector<double>myvec;
          // looping over until the size of the feature_count minus one
          for (unsigned i = 0; i< feature_count; ++i) 
              //changing string values to double using stod
              myvec.push_back (stod (myvec_splitted[i].c_str ()));
              //getting the last element 
              adding= myvec_splitted.back();
              //using the key myvec to add the value to the map
              m[myvec] = adding;
    }
}


void print_map(const map<vector<double>, string> &m, ostream &out) {
      // an iterator of type map <vector<double> , string > ::iterator
      map <vector<double> , string > ::iterator iter;
      //looping over the map from begin to end
      for ( auto iter = m.begin(); iter != m.end(); ++iter ) {
          //getting each pair of the map 
          pair <vector<double>, string> p ( iter->first , iter->second);
          //putting the called pair to the pair_to_string function into the ostream
         out << pair_to_string(p)<< endl;
      
      }
  }


double distance(const vector<double> &v1, const vector<double> &v2, unsigned int feature_count){
    
      // double named sum initialised to 0;
      double sum = 0;
      //looping until the size of feature_count minus one 
      for ( int i = 0; i < feature_count; ++i ) {
          // getting the diference of elements of the same position in the two vectors
          double diff = v1[i] - v2[i];
          //squaring the difference after and putting it into the sum everytime 
          sum += pow ( diff , 2);
        }
    //returning the square root of the sum;
    return sqrt(sum);
    
}

map<vector<double>, string> k_neighbors(const map<vector<double>, string> &m, const vector<double> &test, int k) {
    //A vector to store each euclidian distance..
    vector<double> save_euclidian;
    // a vector of vector to store all the key double vectors of the map 
    vector<vector<double>>myvec;
    // a new map to save the k nearst ones....
    map <vector<double> , string> new_map;
    // an iterator of type map <vector<double> , string>::iterator
    map <vector<double> , string>::iterator iter;
    
    //iterating through the map vector to check how much the distance is from test
    for (auto iter = m.begin(); iter != m.end(); ++iter ) {
        //recording each distance between the test vector and the vectors in the map
        double d = distance (test , iter->first , k);  // can change to 
        //pushing back each d into the save_euclidian vector
        save_euclidian.push_back(d);
        //new_map containing all the pairs 
        new_map.insert(pair<vector<double>, string>(iter->first , iter->second));
        //pushing back every double vector of the map into the myvec vector
        myvec.push_back(iter->first);
    }
    
    
    // SAVING THE DISTANCE IN A VECTOR OF DOUBLE 
    vector<double>euclidian_2;

    for (unsigned int i = 0; i < save_euclidian.size(); ++i ) {
        
        euclidian_2.push_back(save_euclidian[i]);
    }
    
    // sorting the new vector to get the indexes the lowest k distances 
    
    sort (euclidian_2.begin(),euclidian_2.end());
    
    
    
    // vector that stores the lowest k distances 
    vector <double> k_lowests;
    //getting the lowest k distances and pushing back into the k_lowests
    for ( int i = 0; i < k; ++i ) {
        
        k_lowests.push_back(euclidian_2[i]);
    }
    
    // a map to store the k_nearest vectors 
  
    map<vector<double> , string> final_klowest_map;
    
    for ( int j = 0 ; j < k+1; ++j ) {    // upto k + one to erase the test vector if in the map to remain with k_lowest pairs
    //finding the position of each double distance
     auto number = find(save_euclidian.begin(), save_euclidian.end(), k_lowests[j]);
        // the distance that double distance is from the firts element in the original save_euclidian vector 
        int dis = distance(save_euclidian.begin(), number);   // let us the distance
        
        //iterating through the map m
        for (auto iter = m.begin(); iter != m.end(); iter++) {
            
            // if the key value vector of double is equal to the vector at index dis
            if ((iter -> first == myvec[dis])){
                
                //inserting that key plus its value into the map
                final_klowest_map.insert(pair<vector<double> , string>(iter->first, iter -> second));
                
                
            }
        }
        }
   
   // iterating through the final_klowest_map to check if the test vector is there and removing it from the map 
   for ( auto iter = final_klowest_map.begin(); iter != final_klowest_map.end(); ++iter){
        
        if ( iter->first == test) {
            
            
            final_klowest_map.erase(iter->first);
        }
    }
    
    return final_klowest_map;
}  




double test_one (const map<vector<double>, string> &m, pair<vector<double>, string> test, int k) {
    
    // getting the first element of the pair to compare k-neighbors 
    vector <double> myvector = test.first;
    //empty map to use for the function call
    map<vector<double> , string> knn;
    //using the map , myvector and int k for the function k-neighbors
    knn = k_neighbors(m,myvector,k);
    //size of the map
    unsigned int num = knn.size();
    //double initialised to 0 to add values when in the for loop
    double sum = 0;
    //iterating through knn map 
    for ( auto itr = knn.begin(); itr != knn.end(); ++itr) {
        
        // if the label name pointed by the value vector double is the same as the test value string name 
        if ( itr -> second == test.second) {
            
            // add one to the sum
            sum +=1;
            
        }
        
    }
    
    // getting the final percentage of occurence when compared to the test label
    return sum / num;
    
        
}