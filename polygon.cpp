#include<iostream>
using namespace std;
#define INFINIT 9999


struct Coordinate {
   double x, y;
};

struct line {
   Coordinate p1, p2;
};

bool onLine(line l1, Coordinate p) {        //check whether p is on the line or not
   if(p.x <= max(l1.p1.x, l1.p2.x) && p.x <= min(l1.p1.x, l1.p2.x) &&
      (p.y <= max(l1.p1.y, l1.p2.y) && p.y <= min(l1.p1.y, l1.p2.y)))
         return true;

   return false;
}

//colinear
int direction(Coordinate a, Coordinate b, Coordinate c) {
   int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
   if (val == 0)
      return 0;           
   else  return val>0 ? 1: 2;          //1 => clockwise direction, 2 =>anti-clockwise direction      
}

//intersecting lines
bool isIntersect(line l1, line l2) {
   int d1 = direction(l1.p1, l1.p2, l2.p1);
   int d2 = direction(l1.p1, l1.p2, l2.p2);
   int d3 = direction(l2.p1, l2.p2, l1.p1);
   int d4 = direction(l2.p1, l2.p2, l1.p2);

   if(d1 != d2 && d3 != d4)
      return true;           
   if(d1==0 && onLine(l1, l2.p1))        //when p2 of line2 are on the line1
      return true;
   if(d2==0 && onLine(l1, l2.p2))         //when p1 of line2 are on the line1
      return true;
   if(d3==0 && onLine(l2, l1.p1))       //when p2 of line1 are on the line2
      return true;
   if(d4==0 && onLine(l2, l1.p2))     //when p1 of line1 are on the line2
      return true;
   return false;
}

int checkInside(Coordinate poly[], int n, Coordinate p) {
   if(n < 3)
      return false;                  //when polygon has less than 3 edge, it is not polygon
   line extend = {p, {INFINIT, p.y}};   //create a point at infinity
   int count = 0;
   int i = 0;
   do {
      line side = {poly[i], poly[(i+1)%n]};     
      if(isIntersect(side, extend)) {          //if side is intersects extend
         if(direction(side.p1, p, side.p2) == 0)
            return onLine(side, p);
         count++;
      }
      i = (i+1)%n;
   } while(i != 0);
      if (count%2==1)          //for odd count
        return 1;
}

int main() {
//   Coordinate polygon[] = {{1, 0}, {8,3}, {8, 8}, {1, 5}};
//   Coordinate p = {3, 5};
//   int n = 4;

  Coordinate polygon[] = {{-3, 2}, {-2,-0.8}, {0, 1.2}, {2.2, 0},{2, 4.5}};
  Coordinate p = {0, 0};
  int n = 5;
   
   if( checkInside(polygon, n, p))
    cout<<"True";
   else
    cout<<"False";   
}