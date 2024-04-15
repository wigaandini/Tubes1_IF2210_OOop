#ifndef __PRODUCT_HPP_
#define __PRODUCT_HPP_

#include "Item.hpp"

class Product : public Item{
private:
    ProductType type;
    int productId;
    string origin;
    int addedWeight;

public:
    Product();
    Product(string name);
    virtual ~Product();
    void setProductType(ProductType type);
    void setProductId(int productId);
    void setOrigin(string origin);
    void setAddedWeight(int addedWeight);
    ProductType getProductType() const;
    int getProductId() const;
    string getOrigin() const;
    int getAddedWeight() const;
};

#endif