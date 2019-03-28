#include <iostream>
#include <cmath>
#include <iomanip> 


using std::cin; using std::cout; using std::endl; using std::fixed; using std::setprecision; 

using std::boolalpha;
long biggest_prime ( long n ) { 
    
    long biggest_pryme = 0;
    
    for (unsigned long i = 2; i <  n; ++i ) {  //  // 2 
        
        int count = 0;
        
        
        if ( n % i == 0 ) {     // 36 % 2 = 0 // 2 , 3, 4 , 6, 9 ,12 , 18..
            
            
            for ( unsigned long j = 2 ; j <= i ; ++j ) {  // j = 2
                
                
                if ( (j % 2 == 0) && ( j != 2) ) {
                    
                    
                    break;
                }
                
                else {
                    
                    
                    for ( unsigned long k = 2 ; k <= i; ++k ) {
                      
                        if ( i % k == 0 ) {
                           count ++;
                        }
                      }
                      
                      
                      if (count >= 2) {
                          
                          break;
                      }
                    
                      else {
                          
                          
                          biggest_pryme = i;
                          
                      }
                }
                
            } //:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::            
        }               
    }
    
    
    return  biggest_pryme;
}


long sum_of_divisors ( long n ) {
    
    
    long sum = 0;
    
    
    for ( long i = 1 ; i <= n; ++i ) {
        
        
        if ( n % i == 0 ) {
            
            
            sum += i;
        }
    }
    
    
    return sum;
}



long k_hyperperfect ( long n , long k_max ) {
    
    
    
    long k = 0;
    
    
    bool is_k_hyperperfect = false;
    
    
    for ( long i = 1; i < k_max; ++ i ) {
        
        
        if ( n == ( 1 + ( i*(sum_of_divisors(n) - n - 1)))){
        
            k = i;
            
            is_k_hyperperfect = true;
            
            break;
        }
        
        else {
            
            
            is_k_hyperperfect = false;
        }
    }
    
    
    if (is_k_hyperperfect) {
        
        return k;
    }
    
    else {
        
        
        return 0;
    }
        
}


bool  b_smooth ( long n , long b) {
    
    cout << boolalpha;
    
    bool is_Bsmooth = true;
    
    
    long max_prime_div =  biggest_prime(n);
    
    
    if (max_prime_div > b) {
        
        is_Bsmooth = false;
        
    }
    
    else {
        
        
        is_Bsmooth = true;
    }
    
    
    return is_Bsmooth;
    
}




int main () {
    
    
    long n;
    
    long k_max;
    
    long b;
    
    cout <<""<<endl;
    cin >> n;
    cout <<""<<endl;
    cin>>k_max;
    cout<<""<<endl;
    cin>>b; 
    
    long a = biggest_prime (n);
    
    long bb = sum_of_divisors (n);

    long c = k_hyperperfect ( n , k_max);
    
    bool is_Bsmooth =  b_smooth (n,b);
    
    cout << a << " " << bb << " " << c << " " << is_Bsmooth << endl;
    
    
}