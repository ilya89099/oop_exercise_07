#include "Line.h"

Line::Line(const std::vector<Point>& points)
: Polygon(points) {}

void Line::Save(std::ostream &os) const {
    os << "line\n";
    os << rcolor << " " << gcolor << " " << bcolor << "\n";
    os << points_.size() << "\n";
    for (size_t i = 0; i < points_.size(); ++i) {
        os << points_[i] << "\n";
    }
}

void Line::Render(const sdl::renderer &renderer) const {
    renderer.set_color(rcolor, gcolor, bcolor);
    for (size_t i = 0; i < points_.size() - 1; ++i) {
        renderer.draw_line(points_[i].x, points_[i].y, points_[i + 1].x, points_[i + 1].y);
    }
}

void Line::Load(std::istream &is) {
    size_t points_count;
    is >> rcolor >> gcolor >> bcolor;
    is >> points_count;
    points_.resize(points_count);
    for (size_t i = 0; i < points_count; ++i) {
        is >> points_[i];
    }
}

bool Line::PointBelongsTo(Point p) const {
    return false;
}