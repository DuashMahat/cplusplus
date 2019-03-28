#include <iostream>
#include<string>
#include<sstream>
#include<iomanip>
#include<vector>
#include "proj08_ball.h"
#include<iomanip>
using std::vector;
using std::cin; using std::cout; using std::endl; using std::ostringstream;
using std::setprecision; using std::fixed;

#include "proj08_twod.h"

Ball::Ball( double m , TwoD pos , TwoD speed , double r ) {
    
    
    mass = m;
    
    coords = pos;
    
    velocity = speed;
    
    radius = r;
    
}

string Ball::to_string() {
    
    
    Ball b ( mass ,  coords  ,  velocity ,   radius );
    
    ostringstream oss;
    
    //oss << fixed << setprecision(2);
    
    oss <<fixed<< setprecision(2)<< mass << ", " <<  "("<< coords.x  << ", " << coords.y  << ")" << ", " << "(" << velocity.x << ", " <<  velocity.y << "), "
    
    << radius;
    
    
    return oss.str();
}



bool Ball::contact_ball(Ball b ) {
    
    
    
    bool is_in_contact = false;
    
    TwoD c=TwoD(coords.x-b.coords.x,coords.y-b.coords.y);
    double distance = sqrt(c.magnitude_squared());
    
    if ( radius + b.radius < distance) {
        
        is_in_contact = false;
    }
    
    else {
        
         is_in_contact = true;
    }
    
    return is_in_contact;
    
}






bool Ball::contact_wall(long xdim, long ydim) {
    
    
    vector < string > wall;
    
    
    bool is_in_contact_with_the_wall = false;
    
    
    //Ball wall_cont ( mass , coords , velocity , radius );
    
    if ( (xdim-coords.x < radius) || (ydim-coords.y < radius)) {
    
    
        is_in_contact_with_the_wall  = true;
        
        
        //wall.push_back('x');
    }
    
    
    
    
    else {
    
        is_in_contact_with_the_wall = false;
        
        //wall.push('z');
        
    }
    
    
    return is_in_contact_with_the_wall;
    
}




TwoD Ball::update_velocity_ball(Ball b) {
    
    
    double mass_m;
    
    
    int value = 2;
    
    
    TwoD  velocity_difference = velocity.diff(b.velocity);
    
    TwoD   cordinates_difference = coords.diff(b.coords);
    
    
    double  from_magnitu     =   cordinates_difference.magnitude_squared();
    
    double  from_dotprod     =   velocity_difference.dot_product(cordinates_difference);
    
    mass_m = (( b.mass * value) / ( b.mass * mass));
    
    
    cordinates_difference    =   cordinates_difference.mult(from_dotprod / from_magnitu);
    
    cordinates_difference    =    cordinates_difference.mult(mass_m);
    
    return velocity.diff(cordinates_difference);
    
    
}




TwoD Ball:: update_velocity_wall(long xdim, long ydim) {
    
    
    
    
    
    int initialdis = - 1;
    
    
    double wlldis1 , wlldis2;
    
    
    
    wlldis1 = initialdis;
    
    wlldis2 = initialdis;
    
    
    
    
    //Ball TwoD final_ret ( x ,y);
    
    
    if ( velocity.x > 0 ) {
        
        
        wlldis1 = ((xdim - coords.x) / (velocity.x));
        
        
    }
    
    
    else {
        
        
        
        wlldis1 = ((coords.x) / (-velocity.x));
    }
    
    
    
    if ( velocity.y > 0 ) {
        
        
        wlldis2 = ( ydim - coords.y) / velocity.y;
        
        
    }
    
    
    else {
        
        
        
        wlldis2 = ((coords.y) / (-velocity.y));
    }
    
    
    
     
   if (wlldis1 > wlldis2) {
       
       
       return TwoD(velocity.x , -velocity.y);
     }
    
    
    else {
        
        
       return TwoD(-velocity.x , velocity.y);
     
    }
    
    
    
}




    

    

    







