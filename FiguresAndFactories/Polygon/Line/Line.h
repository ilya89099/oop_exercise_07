#pragma once
#include "../Polygon.h"

class Line : public Polygon {
public:
    Line() = default;
    Line(const std::vector<Point>& points);
    void Render(const sdl::renderer& renderer) const override;
    bool PointBelongsTo(Point p) const override;
    void Save(std::ostream& os) const override;
    void Load(std::istream& is) override;
};