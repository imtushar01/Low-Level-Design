#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
    string name;
    double price;

    Product(string name, double price){
        this->name = name;
        this->price = price;
    }
};

class ShoppingCart {
private:
    vector<Product*> products;

public:
    void addProduct(Product* p){
        products.push_back(p);
    }

    const vector<Product*> getProducts(){
        return products;
    }

    double calculateTotal(){
        double total = 0;
        for(auto p: products){
            total += p->price;
        }
        return total;
    }

    void printInvoice(){
        cout << "Shopping Cart Invoice:\n";
        for(auto p: products){
            cout << p->name << " - Rs " << p->price << endl;
        }
        cout << "Total Price: " << calculateTotal() << endl;
    }

    void saveToDB(){
        cout << "Saving shopping cart to DB..." << endl;
    }
};

int main(){

    ShoppingCart* cart = new ShoppingCart();

    cart->addProduct(new Product("Laptop", 50000));
    cart->addProduct(new Product("Mouse", 1000));

    cart->printInvoice();
    cart->saveToDB();

    return 0;
}