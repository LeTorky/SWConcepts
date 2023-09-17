#include <stdio.h>
#include <conio.h>

class IProductOne{};
class IProductTwo{};

class ProductOneTypeOne: public IProductOne{};
class ProductTwoTypeOne: public IProductTwo{};

class ProductOneTypeTwo: public IProductOne{};
class ProductTwoTypeTwo: public IProductTwo{};

class IFactory{
    public:
        virtual IProductOne createProductTypeOne() = 0;
        virtual IProductTwo createProductTypeTwo() = 0;
};

class FactoryOne: public IFactory{
    public:
        IProductOne createProductTypeOne(){
            printf("%s", "Creating a product one of type one\n");
            return ProductOneTypeOne();
        }
        IProductTwo createProductTypeTwo(){
            printf("%s", "Creating a product two of type one\n");
            return ProductTwoTypeOne();
        }
};
class FactoryTwo: public IFactory{
    public:
        IProductOne createProductTypeOne(){
            printf("%s", "Creating a product one of type two\n");
            return ProductOneTypeTwo();
        }
        IProductTwo createProductTypeTwo(){
            printf("%s", "Creating a product two of type two\n");
            return ProductTwoTypeTwo();
        }
};

int main(){
    IFactory* Factory = new FactoryOne();
    IProductOne ProductOne = Factory->createProductTypeOne();
    IProductTwo ProductTwo = Factory->createProductTypeTwo();
    delete Factory;
    Factory = new FactoryTwo();
    ProductOne = Factory->createProductTypeOne();
    ProductTwo = Factory->createProductTypeTwo();
    return 0;
}
