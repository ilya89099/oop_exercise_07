#pragma once
#include "../Polygon.h"

class Rhombus : public Polygon {
public:
    Rhombus() = default;
    Rhombus(Point p1, Point p2, Point p3);
    void Save(std::ostream& os) const override;
    void Load(std::istream& is) override;
};