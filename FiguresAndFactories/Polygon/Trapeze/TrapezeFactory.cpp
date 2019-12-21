#include "TrapezeFactory.h"


void TrapezeFactory::AddPoint(const Point& p) {
    if (points_.size() == TRAPEZE_VERTEX_COUNT) {
        throw std::logic_error("Cannot add another point");
    }
    points_.push_back(p);
}

std::unique_ptr<Figure> TrapezeFactory::TryCreateObject() const {
    if (points_.size() < TRAPEZE_VERTEX_COUNT) {
        return nullptr;
    }

    if (points_.size() == TRAPEZE_VERTEX_COUNT) {
        return std::make_unique<Trapeze>(points_[0], points_[1], points_[2]);
    } else {
        throw std::logic_error("This is unreachable state");
    }
}