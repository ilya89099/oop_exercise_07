#include "CircleFactory.h"

void CircleFactory::AddPoint(const Point &p) {
    if (points_.size() == CIRCLE_VERTEX_COUNT) {
        throw std::logic_error("Too much points");
    }
    points_.push_back(p);
}

std::unique_ptr<Figure> CircleFactory::TryCreateObject() const {
    if (points_.size() < 2) {
        return nullptr;
    }
    if (points_.size() == 2) {
        return std::make_unique<Circle>(points_[0], points_[1]);
    } else {
        throw std::logic_error("Unreachable sutiatiion");
    }

}