#include "LineFactory.h"

void LineFactory::AddPoint(const Point &p) {
    points_.push_back(p);
}

std::unique_ptr<Figure> LineFactory::TryCreateObject() const {
    if (points_.size() < 2) {
        return nullptr;
    }
    return std::make_unique<Line>(points_);
}