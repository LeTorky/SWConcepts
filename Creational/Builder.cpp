#include <stdio.h>
#include <conio.h>

class IProduct{};

class ProductOne: public IProduct{};
class ProductTwo: public IProduct{};

class IBuilder{
    protected:
        IProduct* Product;
    public:
        virtual void CreateProduct() = 0;
        virtual void BuildStepOne() = 0;
        virtual void BuildStepTwo() = 0;
        virtual IProduct* ReturnProduct() = 0;
};

class BuilderOne:public IBuilder{
    public:
    virtual void BuildStepOne(){
        printf("Performing step one for type one.\n");
    };
    virtual void BuildStepTwo(){
        printf("Performing step two for type one.\n");
    };
    virtual void CreateProduct(){
        this->Product = new ProductOne();
    };
    virtual IProduct* ReturnProduct(){
        return this->Product;
    }
};

class BuilderTwo:public IBuilder{
    public:
    virtual void BuildStepOne(){
        printf("Performing step one for type two.\n");
    };
    virtual void BuildStepTwo(){
        printf("Performing step two for type two.\n");
    };
    virtual void CreateProduct(){
        this->Product = new ProductTwo();
    };
    virtual IProduct* ReturnProduct(){
        return this->Product;
    };
};

class IDirector{
    public:
        virtual void CreateObject() = 0;
        virtual void Orchestrate() = 0;
        virtual IProduct* ReturnObject() = 0;
};

class DirectorOne: public IDirector{
    private:
        IBuilder* Builder;
    public:
        DirectorOne(IBuilder* Builder){
            this->Builder = Builder;
        };
        virtual void CreateObject(){
            this->Builder->CreateProduct();
        };
        virtual void Orchestrate(){
            printf("%s", "Orchestrating in order #1.\n");
            this->Builder->BuildStepOne();
            this->Builder->BuildStepTwo();
        };
        virtual IProduct* ReturnObject(){
            return this->Builder->ReturnProduct();
        };
};

class DirectorTwo: public IDirector{
    private:
        IBuilder* Builder;
    public:
        DirectorTwo(IBuilder* Builder){
            this->Builder = Builder;
        };
        virtual void CreateObject(){
            this->Builder->CreateProduct();
        };
        virtual void Orchestrate(){
            printf("%s", "Orchestrating in order #2.\n");
            this->Builder->BuildStepOne();
            this->Builder->BuildStepTwo();
        };
        virtual IProduct* ReturnObject(){
            return this->Builder->ReturnProduct();
        };
};

int main(){
    IBuilder* Builder = new BuilderOne();
    IDirector* Director = new DirectorOne(Builder);
    Director->CreateObject();
    Director->Orchestrate();
    IProduct* Product = Director->ReturnObject();
    delete Director;
    delete Product;
    Director = new DirectorTwo(Builder);
    Director->CreateObject();
    Director->Orchestrate();
    Product = Director->ReturnObject();
    delete Builder;
    delete Director;
    delete Product;
    Builder = new BuilderTwo();
    Director = new DirectorOne(Builder);
    Director->CreateObject();
    Director->Orchestrate();
    Product = Director->ReturnObject();
    return 0;
}
