#include "Rhombus.h"

Rhombus::Rhombus(Point p1, Point p2, Point p3)
: Polygon(4) {
    if (is_parallel(Vector(p1, p2), Vector(p2, p3))) {
        throw std::logic_error("Points cannot lay on one line");
    }
    p3 = p2 + (((p3 - p2) / Vector(p3, p2).length()) * Vector(p1, p2).length());
    Point diag_middle = (p1 + p3) / 2;
    Point p4 = p2 + ((diag_middle - p2) * 2);
    points_ = {p1, p2, p3, p4};
}

//Rhombus::Rhombus(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
//: p1_(p1), p2_(p2), p3_(p3), p4_(p4) {
//    if (Vector(p1_, p2_).length() == Vector(p1_, p4_).length()
//        && Vector(p3_, p4_).length() == Vector(p2_, p3_).length()
//        && Vector(p1_, p2_).length() == Vector(p2_, p3_).length()) {
//
//    } else if (Vector(p1_, p4_).length() == Vector(p1_, p3_).length()
//           && Vector(p2_, p3_).length() == Vector(p2_, p4_).length()
//           && Vector(p1_, p4_).length() == Vector(p2_, p4_).length()) {
//        std::swap(p2_, p3_);
//    } else if (Vector(p1_, p3_).length() == Vector(p1_, p2_).length()
//              && Vector(p2_, p4_).length() == Vector(p3_, p4_).length()
//              && Vector(p1_, p2_).length() == Vector(p2_, p4_).length()) {
//        std::swap(p3_, p4_);
//    } else {
//        throw std::logic_error("This is not rhombus, sides arent equal");
//    }
//}

void Rhombus::Load(std::istream &is) {
    points_.resize(4);
    is >> rcolor >> gcolor >> bcolor;
    is >> points_[0] >> points_[1] >> points_[2] >> points_[3];
}

void Rhombus::Save(std::ostream &os) const {
    os << "rhombus\n";
    os << rcolor << " " << gcolor << " " << bcolor << "\n";
    for (size_t i = 0; i < points_.size(); ++i) {
        os << points_[i] << "\n";
    }
}