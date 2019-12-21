#pragma once

#include "../../Factory.h"
#include "Rhombus.h"

#define RHOMBUS_VERTEX_COUNT 3



class RhombusFactory : public Factory {
public:

    void AddPoint(const Point& p) override;

    std::unique_ptr<Figure> TryCreateObject() const override;

};