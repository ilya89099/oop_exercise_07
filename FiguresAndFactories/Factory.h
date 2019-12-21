#pragma once

#include "Figure.h"
#include <vector>
#include <memory>
#include <exception>

class Factory {
public:
    Factory() = default;
    virtual ~Factory() = default;

    virtual void AddPoint(const Point& p) = 0;

    virtual std::unique_ptr<Figure> TryCreateObject() const = 0;

protected:
    std::vector<Point> points_;

};