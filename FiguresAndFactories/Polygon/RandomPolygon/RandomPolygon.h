#pragma once
#include "../Polygon.h"

class RandomPolygon : public Polygon {
public:
    RandomPolygon() = default;
    RandomPolygon(const std::vector<Point>& points);
    bool PointBelongsTo(Point p) const override;
    
    void Save(std::ostream& os) const override;
    void Load(std::istream& is) override;
};