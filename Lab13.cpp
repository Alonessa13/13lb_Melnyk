#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
using namespace std;
class Discountable {
public:
    virtual double applyDiscount(double price) const = 0; 
    virtual ~Discountable() = default;
};
class Product {
protected:
    string name;     
    double price;     
public:
    Product(const string& name, double price) : name(name), price(price) {}
    string getName() const { return name; }
    double getPrice() const { return price; }
    void setName(const string& name) { this->name = name; }
    void setPrice(double price) { this->price = price; }
    virtual double getFinalPrice() const = 0;
    virtual ~Product() = default;
};
class Book : public Product, public Discountable {
public:
    Book(const string& name, double price) : Product(name, price) {}
    double applyDiscount(double price) const override {
        return price * 0.9; 
    }
    double getFinalPrice() const override {
        return applyDiscount(price);
    }
};
class Pen : public Product, public Discountable {
public:
    Pen(const string& name, double price) : Product(name, price) {}
    double applyDiscount(double price) const override {
        return (price > 5) ? price - 5 : price; 
    }
    double getFinalPrice() const override {
        return applyDiscount(price);
    }
};
int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<Product*> products;
    products.push_back(new Book("Все заради гри", 600.0));
    products.push_back(new Book("9 листопада", 550.0));
    products.push_back(new Pen("Просто ручка", 7.0));
    products.push_back(new Pen("Сталкерська ручка", 199.0));
    cout << "Список товарів:\n";
    for (const auto& product : products) {
        cout << "Назва: " << product->getName()
            << ", Звичайна ціна: " << product->getPrice() << " грн"
            << ", Кінцева ціна: " << product->getFinalPrice() << " грн\n";
    }
    for (auto& product : products) {
        delete product;
    }
    return 0;
}
