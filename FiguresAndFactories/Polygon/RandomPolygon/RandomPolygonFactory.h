#pragma once

#include "../../Factory.h"
#include "RandomPolygon.h"

class RandomPolygonFactory : public Factory {
public:

    void AddPoint(const Point& p) override;

    std::unique_ptr<Figure> TryCreateObject() const override;

};