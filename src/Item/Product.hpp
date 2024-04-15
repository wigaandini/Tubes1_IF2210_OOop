#ifndef __PRODUCT_HPP_
#define __PRODUCT_HPP_

#include "Item.hpp"

class Product : public Item{
private:
    ProductType type;
    int productId;
    string origin;
    float addedWeight;

public:
    Product();
    Product(string name);
    virtual ~Product();
    void setProductType(ProductType type);
    void setProductId(int productId);
    void setOrigin(string origin);
    void setAddedWeight(float addedWeight);
    ProductType getProductType() const;
    int getProductId() const;
    string getOrigin() const;
    float getAddedWeight() const;
};

#endif