#include "Circle.h"
#include <memory>

Circle::Circle(const Point &p1, double radius)
: center_(p1), radius_(radius) {};

Circle::Circle(const Point &p1, const Point &p2)
: center_(p1), radius_(Vector(p1,p2).length()) {}


void Circle::Render(const sdl::renderer &renderer) const {
    renderer.set_color(rcolor, gcolor, bcolor);
    int points_count = 999;
    double step = 2*M_PI / points_count;
    Point first_point = center_ + Point(radius_, 0);
    for (int i = 1; i < 1000; ++i) {
        Point new_point = center_ + Point(radius_ * cos(step * i), radius_ * sin(step * i));
        renderer.draw_line(first_point.x, first_point.y, new_point.x, new_point.y);
        first_point = new_point;
    }
}

bool Circle::PointBelongsTo(Point p) const {
    return Vector(center_, p).length() <= radius_;
}

void Circle::Save(std::ostream &os) const {
    os << "circle\n";
    os << rcolor << " " << gcolor << " " << bcolor << "\n";
    os << center_ << "\n";
    os << radius_ << "\n";
}

void Circle::Load(std::istream &is) {
    is >> rcolor >> gcolor >> bcolor;
    is >> center_;
    is >> radius_;
}
