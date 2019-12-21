#pragma once

#include "../Factory.h"
#include "Circle.h"

#define CIRCLE_VERTEX_COUNT 2

class CircleFactory : public Factory {
public:

    void AddPoint(const Point& p) override;

    std::unique_ptr<Figure> TryCreateObject() const override;

protected:
    std::vector<Point> points_;

};