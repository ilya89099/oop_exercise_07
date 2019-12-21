#pragma once
#include "../Polygon.h"

class Line : public Polygon {
public:
    Line() = default;
    Line(const std::vector<Point>& points);
    void Render(const sdl::renderer& renderer) const override;
    virtual bool PointBelongsTo(Point p) const;
    void Save(std::ostream& os) const override;
    void Load(std::istream& is) override;
};