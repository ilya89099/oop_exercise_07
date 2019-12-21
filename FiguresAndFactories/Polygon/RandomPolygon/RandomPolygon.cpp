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

bool RandomPolygon::PointBelongsTo(Point p) const {
    Point start = points_[0];
    for (size_t i = 1; i < points_.size() - 1; ++i) {
        std::vector<Point> temp_vector(3);
        temp_vector[0] = start;
        temp_vector[1] = points_[i];
        temp_vector[2] = points_[i + 1];

        int first = 0;
        bool is_ok = true;
        for (size_t i = 0; i < 3; ++i) {
            size_t next_index = (i + 1) % points_.size();
            int elem = (temp_vector[i].x - p.x) * (temp_vector[next_index].y - temp_vector[i].y) - (temp_vector[next_index].x - temp_vector[i].x) * (temp_vector[i].y - p.y);
            if (i == 0) {
                first = elem / std::abs(elem);
            } else {
                if (first * (elem / std::abs(elem)) < 0) {
                    is_ok = false;
                    break;
                }
            }
        }
        if (is_ok) {
            return true;
        }

    }
    return false;
}