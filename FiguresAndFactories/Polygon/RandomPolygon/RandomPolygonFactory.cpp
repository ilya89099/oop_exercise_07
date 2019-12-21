#include "RandomPolygonFactory.h"

void RandomPolygonFactory::AddPoint(const Point &p) {
    points_.push_back(p);
}

std::unique_ptr<Figure> RandomPolygonFactory::TryCreateObject() const {
    if (points_.size() < 3) {
        return nullptr;
    }
    return std::make_unique<RandomPolygon>(points_);
}