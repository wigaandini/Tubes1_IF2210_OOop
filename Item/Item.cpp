#include "Item.hpp"
#include "PlantConfig.hpp"
#include "AnimalConfig.hpp"
#include "ProductConfig.hpp"

// class Item
int countIdItem = 1;

Item::Item(){
    this->itemId = -1;
    this->name = "";
    this->code = "";
    this->price = 0;
    // countIdItem ++;
}

Item::Item(string name, string code, int price){
    this->itemId = countIdItem + 1;
    this->name = name;
    this->code = code;
    this->price = price;
    countIdItem ++;
}

void Item::setItemId(int itemId){
    this->itemId = itemId;
}

void Item::setName(string name){
    this->name = name;
}

void Item::setCode(string code){
    this->code = code;
}

void Item::setPrice (int price){
    this->price = price;
}

int Item::getItemId() const{
    return this->itemId;
}

string Item::getName() const{
    return this->name;
}

string Item::getCode() const{
    return this->code;
}

int Item::getPrice() const{
    return this->price;
}


// class Plant
Plant::Plant() : Item(){
    this->plantId = 0;
    this->durationToHarvest = 0;
    this->age = 0;
}

Plant::Plant(string name, int age) : Item(PlantConfig::configs[name].name, PlantConfig::configs[name].code, PlantConfig::configs[name].price){
    this->type = PlantConfig::configs[name].type;
    this->plantId = PlantConfig::configs[name].id;
    this->durationToHarvest = PlantConfig::configs[name].durationToHarvest;
    this->age = age;
}

void Plant::setPlantType(PlantType type){
    this->type = type;
}

void Plant::setPlantId(int plantId){
    this->plantId = plantId;
}

void Plant::setDurationToHarvest(int durationToHarvest){
    this->durationToHarvest = durationToHarvest;
}

void Plant::setAge(int age){
    this->age = age;
}

PlantType Plant::getPlantType() const{
    return this->type;
}

int Plant::getPlantId() const{
    return this->plantId;
}

int Plant::getDurationToHarvest() const{
    return this->durationToHarvest;
}

int Plant::getAge() const{
    return this->age;
}

Plant& Plant::operator++(){
    ++this->age;
    return *this;
}

Plant Plant::operator++(int ){
    Plant temp = *this;
    ++this->age;
    return temp;
}

// class Animal
Animal::Animal() : Item(){
    this->animalId = 0;
    this->weight = 0;
    this->weighToHarvest = 0;
}
      
Animal::Animal(string name, float weight) : Item(AnimalConfig::configs[name].name, AnimalConfig::configs[name].code, AnimalConfig::configs[name].price){
    this->type = AnimalConfig::configs[name].type;
    this->animalId = AnimalConfig::configs[name].id;
    this->weight = weight;
    this->weighToHarvest = AnimalConfig::configs[name].weightToHarvest;
}

void Animal::setAnimalType(AnimalType type){
    this->type = type;
}

void Animal::setAnimalId(int animalId){
    this->animalId = animalId;
}

void Animal::setWeight(float weight){
    this->weight = weight;
}

void Animal::setWeightToHarvest(float weightToHarvest){
    this->weighToHarvest = weighToHarvest;
}

AnimalType Animal::getAnimalType() const{
    return this->type;
}

int Animal::getAnimalId() const{
    return this->animalId;
}

float Animal::getWeight() const{
    return this->weight;
}

float Animal::getWeightToHarvest() const{
    return this->weighToHarvest;
}

Animal& Animal::operator+(Product product){
    this->weight += product.getAddedWeight();
    return *this;
}
// class Product
Product::Product() : Item(){
    this->productId = 0;
    this->origin = "";
    this->addedWeight = 0;
}

Product::Product(string name) : Item(ProductConfig::configs[name].name, ProductConfig::configs[name].code, ProductConfig::configs[name].price){
    this->type = ProductConfig::configs[name].type;
    this->productId = ProductConfig::configs[name].id;
    this->origin = ProductConfig::configs[name].origin;
    this->addedWeight = ProductConfig::configs[name].addedWeight;
}

void Product::setProductType(ProductType type){
    this->type = type;
}

void Product::setProductId(int productId){
    this->productId = productId;
}

void Product::setOrigin(float origin){
    this->origin = origin;
}

void Product::setAddedWeight(float addedWeight){
    this->addedWeight = addedWeight;
}

ProductType Product::getProductType() const{
    return this->type;
}

int Product::getProductId() const{
    return this->productId;
}

string Product::getOrigin() const{
    return this->origin;    
}

float Product::getAddedWeight() const{
    return this->addedWeight;
}