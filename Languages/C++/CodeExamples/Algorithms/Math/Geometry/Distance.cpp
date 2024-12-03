/*
Point objects have x and y attributes attributes.

Write a function calculating distance between Point a and Point b.

*/

#include <cmath>

class Point
{
	int x, y;
};

double distance_between_two_points(const Point& a, const Point& b) {
    return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}

double distance_between_two_points(const Point& a, const Point& b) {
    return sqrt(pow((b.y-a.y),2.0) + pow((b.x-a.x),2.0));
}

double distance_between_two_points(Point a, Point b){
   return std::hypot(a.x - b.x, a.y - b.y);
}
