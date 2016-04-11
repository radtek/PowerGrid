#pragma once

#include <string>
#include "Region.h"
#include "Connection.h"
#include <memory>
#include <vector>
#include "House.h"

class City
{
public:
    City() {}
    explicit City(std::string name) : name(name) {}

    std::string GetName() const { return name; }
    void SetName(std::string name) { this->name = name; }

    std::shared_ptr<Region> GetRegion() const { return region; }
    void SetRegion(std::shared_ptr<Region> region) { this->region = region; }

    int GetNumberOfHouses() const { return houses.size(); }
    std::vector<std::shared_ptr<Connection>> const&  GetConnections() const { return connections; }

    void AddConnection(std::shared_ptr<Connection> connection) { connections.push_back(connection); }
    void RemoveConnection(std::shared_ptr<Connection> connection);

    bool AddHouse(House* house);

    int GetHousePrice() const;
    bool IsFull() const;
    bool IsConnectedTo(std::string cityName);

    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
    void setWidth(int width) { this->width = width; }
    void setHeight(int height) { this->height = height; }
    
    int getX() const { return x; }
    int getY() const { return y; }
    int getWidth() const { return width; }
    int getHeight() const { return height; }

    bool operator==(const City& other) const { return this->name == other.name; }
    bool operator==(const std::string& cityName) const { return this->name == cityName; }
    friend bool operator==(const std::shared_ptr<City>& first, const std::shared_ptr<City>& second);
    friend bool operator==(const std::shared_ptr<City>& first, const City& second);
    friend bool operator==(const std::shared_ptr<City>& city, const std::string& cityName);

private:
    static const int MAXIMUM_HOUSES = 3;

    int firstHousePrice  = 10;
    int secondHousePrice = 15;
    int thirdHousePrice  = 20;

    int x = 0, y = 0, width = 0, height = 0;

    std::string name = "";
    std::shared_ptr<Region> region;
    std::vector<std::shared_ptr<Connection>> connections;
    std::vector<House*> houses;
};

