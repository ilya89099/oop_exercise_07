#include "Polygon.h"

Polygon::Polygon(int points_count)
: points_(points_count) {}


Polygon::Polygon(const std::vector<Point>& points)
: points_(points) {}

void Polygon::Render(const sdl::renderer &renderer) const {
    renderer.set_color(rcolor, gcolor, bcolor);
    for (size_t i = 0; i < points_.size(); ++i) {
        size_t next_index = (i + 1) % points_.size();
        renderer.draw_line(points_[i].x, points_[i].y, points_[next_index].x, points_[next_index].y);
    }
}

bool Polygon::PointBelongsTo(Point p) const {
    bool is_ok = true;
    int first = 0;
    for (size_t i = 0; i < points_.size(); ++i) {
        size_t next_index = (i + 1) % points_.size();
        int elem = (points_[i].x - p.x) * (points_[next_index].y - points_[i].y) - (points_[next_index].x - points_[i].x) * (points_[i].y - p.y);
        if (i == 0) {
            first = elem / std::abs(elem);
        } else {
            if (first * (elem / std::abs(elem)) < 0) {
                is_ok = false;
                break;
            }
        }
    }
    return is_ok;
}