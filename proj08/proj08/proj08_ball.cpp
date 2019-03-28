#include <iostream>
#include<string>
#include<sstream>
#include<iomanip>  
#include<vector>
using std::vector;
#include  "proj08_ball.h"


using std::cin; using std::cout; using std::endl; using std::ostringstream;
using std::setprecision; using std::fixed;


// struct Ball{

//   double mass = 0;
//   TwoD coords;
//   TwoD velocity;
//   double radius = 0;

//   Ball()=default;
//   Ball(double m, TwoD pos, TwoD speed, double r);

//   string to_strings();
//   bool contact_ball(Ball);
//   bool contact_wall(long xdim, long ydim);
//   TwoD update_velocity_ball(Ball);
//   TwoD update_velocity_wall(long xdim, long ydim);
  
// };



Ball::Ball( double m , TwoD pos , TwoD speed , double r ) {
    
    
    mass = m;
    
    coords = pos;
    
    velocity = speed;
    
    radius = r;
    
}







bool Ball::contact_ball(Ball b ) {
    
    bool is_in_contact = false;
    
    Ball b2 ( mass , coords , velocity , radius);
    
    double distance = b2.radius + b.radius;
    
    if ( b2.radius + b.radius < distance) {
        
        is_in_contact = false;
    }
    
    else {
        
         is_in_contact = true;
    }
    
    return is_in_contact;
    
}


bool Ball::contact_wall(long xdim, long ydim){
    
    
    vector<string> wall;
    
    
    bool is_in_contact_with_the_wall = false;
    
    
    Ball wall_cont ( mass , coords , velocity , radius );
    
    if ( (coords.x + wall_cont.radius > xdim) || (coords.x  - wall_cont.radius < 0 )) {
    
    
        is_in_contact_with_the_wall  = true;
        
        
        //wall.push_back('x');
    }
    
    else if ( (coords.y + wall_cont.radius > ydim) || (coords.y - wall_cont.radius < 0)) {
    
    
        is_in_contact_with_the_wall  = true;
        
        //wall.push_back('y');
    }
    
    
    else {
    
        is_in_contact_with_the_wall = false;
        
        //wall.push('z');
        
    }
    
    
    return is_in_contact_with_the_wall;
    
}




TwoD Ball::update_velocity_ball(Ball b) {
    
    
        return 0;
}



TwoD update_velocity_wall(long xdim, long ydim){


     return 0;
}





