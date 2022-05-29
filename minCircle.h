// Ori Abramovitch 315598664

// ID1	ID2

#ifndef MINCIRCLE_H_
#define MINCIRCLE_H_

#include <iostream>
#include <cmath>
#include <vector>
#include <cassert>
#include "anomaly_detection_util.h"

using namespace std;

// ------------ DO NOT CHANGE -----------
//class Point {
//public:
//    float x, y;
//
//    Point(float x, float y) : x(x), y(y) {}
//};

class Circle {
public:
    Point center;
    float radius;

    Circle(Point c, float r) : center(c), radius(r) {}
};
// --------------------------------------


// you may add helper functions here

// The center between two points
Point center(Point &p1, Point &p2);

// The center between three points
Point center(Point &a, Point &b, Point &c);

float delta(Point &p1, Point &p2);

bool is_in_circle(Point &p, Circle &circle);

Circle make_circle_2(Point &p1, Point &p2);


Circle make_circle_3(vector<Point> &bound_vec);

Circle make_circle(vector<Point> &bound_vec);

Circle recursive_find(vector<Point> &points_vec, vector<Point> bound_vec, int last);


Circle findMinCircle(Point **points, size_t size);

#endif /* MINCIRCLE_H_ */


