#include "RandomPolygon.h"

RandomPolygon::RandomPolygon(const std::vector<Point>& points)
: Polygon(points) {}

void RandomPolygon::Save(std::ostream &os) const {
    os << "random_polygon\n";
    os << rcolor << " " << gcolor << " " << bcolor << "\n";
    os << points_.size() << "\n";
    for (size_t i = 0; i < points_.size(); ++i) {
        os << points_[i] << "\n";
    }
}

void RandomPolygon::Load(std::istream &is) {
    size_t points_count;
    is >> rcolor >> gcolor >> bcolor;
    is >> points_count;
    points_.resize(points_count);
    for (size_t i = 0; i < points_count; ++i) {
        is >> points_[i];
    }
}