#include <stdio.h>
#include <conio.h>

class Prototype{
    public:
        virtual Prototype* clone() = 0;
};

class Child:public Prototype{
    protected:
        int attr1;
        int attr2;
    public:
        Child(Child* Reference){
            printf("Clonning Child Instance.\n");
            this->attr1 = Reference->attr1;
            this->attr2 = Reference->attr2;
        };
        Child(){
            this->attr1 = 1;
            this->attr2 = 2;
        };
        Prototype* clone(){
            Child* ClonedInstance = new Child(this);
            return ClonedInstance;
        };
};

class GrandChild:public Child{
    protected:
        int attr3;
        int attr4;
    public:
        GrandChild(GrandChild* Reference):Child(Reference){
            printf("Clonning GrandChild Instance.\n");
            this->attr3 = Reference->attr3;
            this->attr4 = Reference->attr4;
        };
        GrandChild(){
            this->attr3 = 3;
            this->attr4 = 4;
        };
        Prototype* clone(){
            Child* ClonedInstance = new GrandChild(this);
            return ClonedInstance;
        };
};

int main(){
    Prototype* Instance = new GrandChild();
    Prototype* ClonedInstance = Instance->clone();
    return 0;
}
