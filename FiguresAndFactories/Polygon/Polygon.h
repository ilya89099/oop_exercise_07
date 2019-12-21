#pragma once

#include "../Figure.h"
#include <math.h>

class Polygon : public Figure {
public:
    Polygon() = default;
    Polygon(int points_count);
    Polygon(const std::vector<Point>& points);
    virtual void Render(const sdl::renderer& renderer) const override;
    virtual bool PointBelongsTo(Point p) const override;

protected:
    std::vector<Point> points_;
};