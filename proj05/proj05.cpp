
#include<iostream>
#include <algorithm>
using std::cout; using std::cin; using std::endl;
#include<string>
using std::all_of;
using std::string;


const string alphabet = "abcdefghijklmnopqrstuvwxyz";

string rotate_left (int num , string n )  {  // 
    
    
    string newOne = "";    // creates an empty string that will store a string object...
    
    
    
    if ( num < 0 ) {       // if the rotation integer is less than 0 return the original string...
        
        return n;
    }
    
    
    else {                 // otherwise  
    
    
      for ( unsigned int i = 0; i < num; ++i )  {   // from i  to i less than rotation integer
        
        
        newOne  += n[i];                           // add the newOne string to the char at n[i]
        
      }
    
    
    
    newOne = n.substr(num)+newOne;           // newOne is equal to newone plus what remained from the original string 
    
    }                                       
    
    return newOne;
    
    
    
}



char vigenere_letter ( char p , char k ) { // DONE WITH THIS MOTHER FUCKER .....
    
    
    char vigenere;              // an empty initialized char vigenere           
    
    
    int diff = p - 'a';    // r - a =17..   // get an integer of the difference between the plain and char a
    
    
    
    int index_key = alphabet.find(k);  // getting the postion of the key char from the string alphabet.....
    
    
    
    k = alphabet[index_key];  //  using the key index to find the char k....
    
    
    if ((isupper(p) || isupper(k)) || (isdigit(p) || isdigit(k))) {   // checking whether plain char or key char is UPPERCASE
        
        
        return p;             // if that is the case return the original plain character....
    }
    
    
    
    if ( (alphabet.find(k)  +  diff) > 25 ) {   // if the condition above doesnt apply then 
        
        k = 'a';      // if the diff plus the integer position of K in the alphabet is >25 then key char = char a
        
        vigenere = static_cast < char > (k + (25-diff));   //the vigenere cipher char is 'a' + the difference of 25 - diff
    }
    
    
    else {    // else 
    
    
    vigenere = static_cast < char > (k + diff); //  ................... // vigenere cipher char is key + diff static_casted
    
    }
        
        
    return vigenere;      // returning the encoded vigenere cipher 
    
    
}


char beaufort_letter ( char p , char k ) {
    
    
     if ((isupper(p) || isupper(k)) || (isdigit(p) || isdigit(k))) {  // return the original plain 
         
         // character if the plain character or the key character is UPPERCASE/digit
        
        
        return p;
    }
    
    
    int p_index = alphabet.find(p); // getting the index of plaintext character
    
    string new_string = rotate_left ( p_index , alphabet ); // use rotate left to rotate using P_index
    
    
    int k_index = new_string.find(k);                   // geting the position of key char from the rotated string..
    
    
    char beau = alphabet[k_index];                     // getting the beaufort char using the index of the key char
    
    
    return beau;
    
}



string encode_vigenere ( string plain , string key) {  
    
    string newcipher   = "";    // creates an empty string that will store a string object...
    
    string newPlain = "";       // creates an empty string that will store a string object...
    
    //if (( all_of (plain.begin() , plain.end(), isupper)) || ( all_of (key.begin() , key.end(), isupper))){
        
        
      //  return plain;
    //}
    
    
  for ( unsigned int i = 0; i < plain.size(); ++i ) {
        
        
        if ( islower(plain[i])) {          // ignoring any char in the plain that is not lowercase 
            
            newPlain+=plain[i];           // storing all the plain lower chars in a new string..
        }
    }
    
   plain = newPlain;                    // making sure plain is now newPlain
   
   if ( key.size() < plain.size() ) {   //  making sure the key ( if its size != plain size)
        
        int diff = plain.size() - key.size();  // an integer to see the difference in the sizes
        
        for ( unsigned int i = 0; i <  diff; ++i ) {  // putting the remaining differnce into the key...
            
            
            key += key[i];
        }
    }
    

  for ( unsigned int i = 0; i < plain.size();  ++i  ) { // iterating from 0 to the size of plain  less one 
        
        
        char p = plain[i];   // c   // record every char in plain[i]
        
        char k = key[i];     // f   // record every char in key[i]
        
        
        
        
        char vig = vigenere_letter (p , k);   // use that vigenere function to get the ciphered vigener 
        
        
        newcipher += vig;            // add each cipher to the new string newCipher
         
        
    }
    
  
    
    return newcipher;    // return the string for the encoded vigenere cipher ...
     
}




string encode_beaufort ( string plain , string key ) {
    
    
    string newcipher = "";   // creates an empty string that will store a string object...
    
    string newPlain = "";    // // creates an empty string that will store a string object...
    
    //if (( all_of (plain.begin() , plain.end(), isupper)) || ( all_of (key.begin() , key.end(), isupper))){
        
        
        //return plain;
    //}
    
    for ( unsigned int i = 0; i < plain.size(); ++i ) {
        
        
        if ( islower(plain[i])) {   // ignoring any char in the plain that is not lowercase 
            
            
            newPlain+=plain[i];    //  storing all the plain lower chars in a new string..
        }
    }
    
    plain = newPlain;        // making sure plain is now newPlain
    
    
    if (key.size() < plain.size()) {    //  making sure the key ( if its size != plain size)
        
        int diff = plain.size() - key.size(); // an integer to see the difference in the sizes
        
        
        for (unsigned int i = 0; i < diff; ++i ) { //putting the remaining differnce into the key...
            
            
            key += key[i];
        }
    }
    
    
    
    for ( unsigned int i = 0; i < plain.size(); ++i ) {
        
        
        char p = plain[i];     // record every char in plain[i]
        
        char k = key[i];     // f   // record every char in key[i]
        
        char beau = beaufort_letter ( p , k );
        
        
        newcipher += beau;     // // use that vigenere function to get the ciphered vigener 
    }
    
    
    return newcipher;    // returns the new ciphered encoded beaufort string .....
    
    
}


int main (){
  int case_number;
  cin >> case_number;

  switch (case_number){

  case 1: {
    int rotations;
    cin >> rotations;
    string s;
    cin >> s;
    cout << rotate_left(rotations, s) << endl;
    break;
  }
    
  case 2: {
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << beaufort_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 3:{
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << vigenere_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 4:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_beaufort(plain_text, key) << endl;
    break;
  }

  case 5:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_vigenere(plain_text, key) << endl;
    break;
  }

  } // of switch
} // of main
