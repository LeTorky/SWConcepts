#include <stdio.h>
#include <conio.h>

class IExtension{
    public:
        virtual void DoExtraLogic() = 0;
};

class IBridge{
    protected:
        IExtension* Extension;
    public:
        virtual void DoLogic() = 0;
};

class ConcreteOne: public IBridge{
    public:
        ConcreteOne(IExtension* Extension){
            this->Extension = Extension;
        };
        void DoLogic(){
            printf("Performing logic one.\n");
            this->Extension->DoExtraLogic();
        };
};

class ConcreteTwo: public IBridge{
    public:
        ConcreteTwo(IExtension* Extension){
            this->Extension = Extension;
        };
        void DoLogic(){
            printf("Performing logic two.\n");
            this->Extension->DoExtraLogic();
        };
};

class ExtensionOne: public IExtension{
    public:
        void DoExtraLogic(){
            printf("Performing extra logic one.\n");
        };
};

class ExtensionTwo: public IExtension{
    public:
        void DoExtraLogic(){
            printf("Performing extra logic two.\n");
        };
};

int main(){
    IExtension* Extension = new ExtensionOne();
    IBridge* Concrete = new ConcreteOne(Extension);
    Concrete->DoLogic();
    delete Extension;
    delete Concrete;
    Extension = new ExtensionTwo();
    Concrete = new ConcreteOne(Extension);
    Concrete->DoLogic();
    return 0;
}