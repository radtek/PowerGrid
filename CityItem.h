#pragma once

#include <QGraphicsEllipseItem>
#include <Player.h>
#include <memory>
#include "City.h"

class CityItem : public QGraphicsEllipseItem {
    std::string name;
    QColor regionColor;
    City *city;

public:
    CityItem(QPoint topLeft, int width, int height);

    std::string GetName() const { return name; }
    void SetName(std::string name) { this->name = name; }

    void SetRegionColor(QColor regionColor);
    QColor GetRegionColor() const { return regionColor; }

    QPoint GetNameLocation(QFont font) const;
    QPoint GetCenter() const;
    QGraphicsSimpleTextItem* GetNameTextItem(QFont font) const;

    QPoint GetHousePosition(int index) const;
    void SetCity(City* city) { this->city = city; }
    City* GetCity() { return city; }
};
