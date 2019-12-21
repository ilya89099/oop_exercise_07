#include "Point.h"

Point::Point(const Vector& v)
: x(v.x), y(v.y) {}

Point::Point(double new_x, double new_y)
: x(new_x), y(new_y) {}

Point operator + (Point lhs, Point rhs) {
    return {lhs.x + rhs.x, lhs.y + rhs.y};
}

Point operator - (Point lhs, Point rhs) {
    return {lhs.x - rhs.x, lhs.y - rhs.y};
}

Point operator / (Point lhs, double a) {
    return { lhs.x / a, lhs.y / a};
}

Point operator * (Point lhs, double a) {
    return {lhs.x * a, lhs.y * a};
}

bool operator < (Point lhs, Point rhs) {
    return (lhs.x * lhs.x + lhs.y * lhs.y) < (lhs.x * lhs.x + lhs.y * lhs.y);
}

double operator * (Vector lhs, Vector rhs) {
    return lhs.x * rhs.x + lhs.y * rhs.y;
}

bool is_parallel(const Vector& lhs, const Vector& rhs) {
    return (lhs.x * rhs.y - lhs.y * rhs.x) == 0;
}

bool Vector::operator == (Vector rhs) {
    return
        std::abs(x - rhs.x) < std::numeric_limits<double>::epsilon() * 100
        && std::abs(y - rhs.y) < std::numeric_limits<double>::epsilon() * 100;
}

double Vector::length() const {
    return sqrt(x*x + y*y);
}

Vector::Vector(double a, double b)
: x(a), y(b) {

}

Vector::Vector(Point a, Point b)
: x(b.x - a.x), y(b.y - a.y){

}

Vector Vector::operator - () {
    return Vector(-x, -y);
}

bool is_perpendecular(const Vector& lhs, const Vector& rhs) {
    return (lhs * rhs) == 0;
}

Vector normalize_vector(const Vector& v) {
    return Vector(v.x / v.length(), v.y / v.length());
}

Point projection (Point p1, Point p2, Point p3) { // проекция точки p3 на прямую p1p2
    double x = p2.y - p1.y; //x и y - координаты вектора, перпендикулярного к AB
    double y = p1.x - p2.x;
    double L = (p1.x * p2.y - p2.x * p1.y + p1.y * p3.x - p2.y * p3.x + p2.x * p3.y - p1.x * p3.y) / (x * (p2.y - p1.y) + y * (p1.x - p2.x));
    Point H;
    H.x = p3.x + x * L;
    H.y = p3.y + y * L;
    return H;
}

double point_and_line_distance(Point p1, Point p2, Point p3) {
    double A = p2.y - p3.y;
    double B = p3.x - p2.x;
    double C = p2.x*p3.y - p3.x*p2.y;
    return (std::abs(A*p1.x + B*p1.y + C) / std::sqrt(A*A + B*B));
}

std::ostream& operator << (std::ostream& os, const Point& p) {
    return os << p.x << " " << p.y;
}

std::istream& operator >> (std::istream& is, Point& p) {
    return is >> p.x >> p.y;
}
