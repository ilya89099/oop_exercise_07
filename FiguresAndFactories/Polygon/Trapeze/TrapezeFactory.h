#pragma once

#include "../../Factory.h"
#include "Trapeze.h"

#define TRAPEZE_VERTEX_COUNT 3

class TrapezeFactory : public Factory {
public:

    void AddPoint(const Point& p) override;

    std::unique_ptr<Figure> TryCreateObject() const override;

};