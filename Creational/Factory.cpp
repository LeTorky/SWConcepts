#include <stdio.h>
#include <conio.h>

class IProduct{};

class ProductOneTypeOne: public IProduct{};
class ProductTwoTypeOne: public IProduct{};

class IFactory{
    public:
        virtual IProduct* createProduct() = 0;
};

class FactoryOne: public IFactory{
    public:
        IProduct* createProduct(){
            printf("%s", "Creating a product of type one\n");
            return new ProductOneTypeOne();
        }
};
class FactoryTwo: public IFactory{
    public:
        IProduct* createProduct(){
            printf("%s", "Creating a product of type two\n");
            return new ProductTwoTypeOne();
        }
};

int main(){
    IFactory* Factory = new FactoryOne();
    IProduct* Product = Factory->createProduct();
    delete Factory;
    delete Product;
    Factory = new FactoryTwo();
    Product = Factory->createProduct();
    return 0;
}
