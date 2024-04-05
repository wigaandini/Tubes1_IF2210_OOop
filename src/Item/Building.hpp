#ifndef __BUILDING_HPP_
#define __BUILDING_HPP_

#include "Item.hpp"
#include <map>
#include <string>

class Building : public Item{
private:
    map<string, int> material;
public:
    Building();
    Building(string name);
    ~Building();
    int getQuantityPerMaterial(string materialName) const;
    map<string, int> getBuildingMaterial() const;
};

#endif