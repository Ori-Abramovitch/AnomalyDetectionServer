// Ori Abramovitch 315598664

#include "minCircle.h"

Circle make_circle_2(Point &p1, Point &p2) {
    Point cen = center(p1, p2);
    float radius = delta(p1, p2) / 2;
    return Circle(cen, radius);
}

Point center(Point &p1, Point &p2) {
    float x = (p1.x + p2.x) / 2;
    float y = (p1.y + p2.y) / 2;
    return Point(x, y);
}

Point center(Point &a, Point &b, Point &c) {
    float xNum = ((a.x * a.x + a.y * a.y) * (b.y - c.y)
                  + (b.x * b.x + b.y * b.y) * (c.y - a.y)
                  + (c.x * c.x + c.y * c.y) * (a.y - b.y));
    float yNum = ((a.x * a.x + a.y * a.y) * (c.x - b.x)
                  + (b.x * b.x + b.y * b.y) * (a.x - c.x)
                  + (c.x * c.x + c.y * c.y) * (b.x - a.x));
    float denominator = (a.x * (b.y - c.y) - a.y * (b.x - c.x) + b.x * c.y - c.x * b.y);



    float x = xNum / ((2) * denominator);
    float y = yNum / ((2) * denominator);
    return Point(x, y);
}

float delta(Point &p1, Point &p2) {
    float dis = ((p1.x - p2.x) * (p1.x - p2.x)) + ((p1.y - p2.y) * (p1.y - p2.y));
    return std::sqrt(dis);
}

bool is_in_circle(Point &p, Circle &circle) {
    if (delta(p, circle.center) > circle.radius) {
        return false;
    } else {
        return true;
    }
}

Circle make_circle_3(vector<Point> &bound_vec) {
    Point p1 = bound_vec[0];
    Point p2 = bound_vec[1];
    Point p3 = bound_vec[2];


    Circle circle = make_circle_2(p1, p2);
    if (is_in_circle(p3, circle)) {
        bound_vec.erase(bound_vec.begin() + 2);
        return circle;
    }
    circle = make_circle_2(p1, p3);
    if (is_in_circle(p2, circle)) {
        bound_vec.erase(bound_vec.begin() + 1);
        return circle;
    }
    circle = make_circle_2(p3, p2);
    if (is_in_circle(p1, circle)) {
        bound_vec.erase(bound_vec.begin());
        return circle;
    }


    Point cen = center(p1, p3, p2);
    float radius = delta(p1, cen);
    return Circle(cen, radius);
}

Circle make_circle(vector<Point> &bound_vec) {
    int size = bound_vec.size();
    Circle circle = Circle(Point(0, 0), 0);

    switch (size) {
        case 3:
            circle = make_circle_3(bound_vec);
            break;
        case 2:
            circle = make_circle_2(bound_vec[0], bound_vec[1]);
            break;
        case 1:
            circle = Circle(bound_vec[0], 0);
            break;
        default:
            return circle;
    }
    return circle;



}

Circle recursive_find(vector<Point> &points_vec, vector<Point> bound_vec, int last) {
    if (last == -1 || bound_vec.size() == 3) {
        return make_circle(bound_vec);
    }
    Point point = points_vec[last];
    Circle circle = recursive_find(points_vec, bound_vec, last - 1);
    if (is_in_circle(point, circle)) {
        return circle;
    } else {
        bound_vec.push_back(point);
        return recursive_find(points_vec, bound_vec, last - 1);
    }
}

Circle findMinCircle(Point **points, size_t size) {

    vector<Point> points_vec;
    for (int i = 0; i < size; ++i) {
        points_vec.push_back(*points[i]);
    }
    vector<Point> bound_vec;


    Circle circle = recursive_find(points_vec, bound_vec, int(points_vec.size()) - 1);

    return circle;



}
