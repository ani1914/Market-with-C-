//Anna-Maria Mitova
//F96288
#include <iostream>
#include <iomanip>
#include <vector>
#include <cstring>
using namespace std;

class Product
{
private:
    char* name;
    char* description;
    double price;
    double quantity;
public:
    Product();
    Product(const char* name, const char* description, double price);
    Product(const Product& product);
    Product& operator=(const Product& product);
    char* getName()const;
    char* getDescription()const;
    double getPrice()const;
    unsigned getQuantity()const;

    void removeQuantity(unsigned size);
    void addQuantity(unsigned size);
    ~Product();
};

class Inventory
{
private:
    vector<Product> products;
public:
    Inventory();
    Inventory(const Inventory& inventory);
    Inventory& operator=(const Inventory& inventory);
    void add(Product& product, unsigned times);
    int take(Product& product, int count);
    vector<Product> getProducts() const;
    int query(Product product) const;
};

void print(const Inventory &inventory);
void print(const Product &product);
void printLine(char c, int w);

// DO NOT CHANGE THIS FUNCTION
int main(int argc, char const *argv[])
{
    cout << fixed << setprecision(2);

    Inventory inventory;

    Product glass("Glass", "Crystal glass for wine", 12.40);
    Product vase("Vase", "Glass vase for flowers", 20.0);
    Product carpet("Carpet", "Wool carpet 50x120", 64.90);

    print(glass);

    inventory.add(glass, 12);
    inventory.add(vase, 3);
    inventory.add(carpet, 1);

    print(inventory);

    int glasses = inventory.take(glass, 1); // should return the items taken and decrease the number of items in the inventory
    if (glasses != 1)
    {
        cout << "Wrong answer" << endl;
        return -1;
    }
    print(inventory); // 11 glasses left

    int vases = inventory.take(vase, 3);
    if (vases != 3)
    {
        cout << "Wrong answer" << endl;
        return -1;
    }

    print(inventory); // 0 vases left

    int carpets = inventory.take(carpet, 2);
    if (carpets != 1)
    {
        cout << "Wrong answer" << endl;
        return -1;
    }

    print(inventory); // zero carpets left

    inventory.add(glass, 3);
    print(inventory); // 14 glasses left

    return 0;
}

// DO NOT CHANGE THIS FUNCTION
void printLine(char c, int w)
{
    cout << setfill(c) << setw(w) << "" << setfill(' ') << endl;
}

// DO NOT CHANGE THIS FUNCTION
void print(const Inventory &inventory)
{
    printLine('-', 40);
    cout << "Inventory" << endl;
    printLine('-', 40);
    for (auto product : inventory.getProducts())
    {
        cout << setw(20) << left << product.getName() << right << setw(10) << product.getPrice() << setw(10) << inventory.query(product) << endl;
    }
    printLine('=', 40);
    cout << endl;
}

// DO NOT CHANGE THIS FUNCTION
void print(const Product &product)
{
    cout << setw(20) << left << product.getName() << right << setw(10) << product.getPrice() << endl;
    printLine('-', 30);
    cout << product.getDescription() << endl;
    printLine('=', 30);
    cout << endl;
}
Product::Product(const char* name, const char* description, double price):quantity(0){
    unsigned len = strlen(name);
    this->name = new char[len+1];
    strcpy(this->name,name);
    len = strlen(description);
    this->description = new char[len+1];
    strcpy(this->description, description);
    this->price = price;
}
Product::~Product(){
    delete[] name;
    delete[] description;
}
char* Product::getName()const{
    return this->name;
}
char* Product::getDescription()const{
    return this->description;
}
double Product::getPrice()const{
    return this->price;
}

Product::Product():name(nullptr),description(nullptr),price(0),quantity(0) {

}

Product::Product(const Product &product) {
    this->name = new char[strlen(product.getName())+1];
    strcpy(this->name, product.getName());
    this->description = new char[strlen(product.getDescription())+1];
    strcpy(this->description, description);
    this->price = product.price;
    this->quantity = product.quantity;
}

Product &Product::operator=(const Product & product) {
    if(this!=&product){
        this->name = new char[strlen(product.getName())+1];
        strcpy(this->name, product.getName());
        this->description = new char[strlen(product.getDescription())+1];
        strcpy(this->description, description);
        this->price = product.price;
        this->quantity = product.quantity;
    }
    return *this;
}

void Product::addQuantity(unsigned size) {
    this->quantity+=size;
}

unsigned Product::getQuantity() const {
    return this->quantity;
}

void Product::removeQuantity(unsigned int size) {
    this->quantity -= size;
}

Inventory::Inventory() {  }
void Inventory::add(Product& product, unsigned times){
    for (int i = 0; i < products.size(); ++i) {
        if(!strcmp(products[i].getName(),product.getName())){
            products[i].addQuantity(times);
            return;
        }
    }
    product.addQuantity(times);
    products.push_back(product);
}
int Inventory::take(Product& product, int count){
    if(product.getQuantity()<=count) count=product.getQuantity();
    for (int i = 0; i < products.size(); ++i) {
        if(!strcmp(products[i].getName(),product.getName())){
            product.removeQuantity(count);
            products[i].removeQuantity(count);
            break;
        }
    }
    return count;
}
vector<Product> Inventory::getProducts() const {
    return products;
}
int Inventory::query(Product product) const{
    return product.getQuantity();
}

Inventory::Inventory(const Inventory &inventory) {
    this->products = inventory.products;
}

Inventory &Inventory::operator=(const Inventory &inventory) {
    if(this!=&inventory){
        this->products = inventory.products;
    }
    return *this;
}
