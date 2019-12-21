#include "Trapeze.h"

Trapeze::Trapeze(Point p1, Point p2, Point p3)
: Polygon(4) {
    if (is_parallel(Vector(p1, p2), Vector(p2, p3))) {
        throw std::logic_error("Points cannot lay on one line");
    }
    if (Vector(p2,p3).length() > Vector(p1,p3).length()) {
        std::swap(p1,p2);
    }
    Point proj = projection(p1,p2,p3);
    Point p4;
    if (Vector(p1,proj).length() > Vector(p1,p2).length()) {
        p4 = p3 + (((p1 - p2) / Vector(p1,p2).length()) * (Vector(p1,p2).length() + 2 * Vector(p2,proj).length()));
    } else {
        p4 = p3 + (((p1 - p2) / Vector(p1,p2).length()) * (Vector(p1,p2).length() - 2 * Vector(p2,proj).length()));
    }
    points_ = {p1, p2, p3, p4};
}

//Trapeze::Trapeze(const Point& p1, const Point& p2, const Point& p3, const Point& p4)
//:  p1_(p1), p2_(p2), p3_(p3), p4_(p4){
//    Vector v1(p1_, p2_), v2(p3_, p4_);
//    if (v1 = Vector(p1_, p2_), v2 = Vector(p3_, p4_), is_parallel(v1, v2)) {
//        if (v1 * v2 < 0) {
//            std::swap(p3_, p4_);
//        }
//    } else if (v1 = Vector(p1_, p3_), v2 = Vector(p2_, p4_), is_parallel(v1, v2)) {
//        if (v1 * v2 < 0) {
//            std::swap(p2_, p4_);
//        }
//        std::swap(p2_, p3_);
//    } else if (v1 = Vector(p1_, p4_), v2 = Vector(p2_, p3_), is_parallel(v1, v2)) {
//        if (v1 * v2 < 0) {
//            std::swap(p2_, p3_);
//        }
//        std::swap(p2_, p4_);
//        std::swap(p3_, p4_);
//    } else {
//        throw std::logic_error("At least 2 sides of trapeze must be parallel");
//    }
//
//}


void Trapeze::Save(std::ostream &os) const {
    os << "trapeze\n";
    os << rcolor << " " << gcolor << " " << bcolor << "\n";
    for (size_t i = 0; i < points_.size(); ++i) {
        os << points_[i] << "\n";
    }
}

void Trapeze::Load(std::istream &is) {
    points_.resize(4);
    is >> rcolor >> gcolor >> bcolor;
    is >> points_[0] >> points_[1] >> points_[2] >> points_[3];
}
