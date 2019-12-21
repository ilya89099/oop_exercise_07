#pragma once

#include "../Polygon.h"
#include <exception>

class Trapeze : public Polygon {
public:
    Trapeze() = default;
    Trapeze(Point p1,Point p2, Point p3);
    void Save(std::ostream& os) const override;
    void Load(std::istream& is) override;
};

