#include <stdio.h>
#include <conio.h>

class ElementOne;
class ElementTwo;
class Visitor{
    public:
        virtual void DoLogic(ElementOne* ElementInstance) = 0;
        virtual void DoLogic(ElementTwo* ElementInstance) = 0;
};

class Element{
    public:
        virtual void Accept(Visitor* VisitorInstance) = 0;
        virtual int GetTypeNumber() = 0;
};

class ElementOne: public Element{
    public:
        virtual void Accept(Visitor* VisitorInstance){
            printf("Invoking DoLogic for Element of type One.\n");
            VisitorInstance->DoLogic(this);
        };
        int GetTypeNumber(){
            return 1;
        }
};

class ElementTwo: public Element{
    public:
        virtual void Accept(Visitor* VisitorInstance){
            printf("Invoking DoLogic for Element of type Two.\n");
            VisitorInstance->DoLogic(this);
        };
        int GetTypeNumber(){
            return 2;
        }
};

class VisitorOne: public Visitor{
    public:
        void DoLogic(ElementOne* ElementInstance){
            printf("Doing logic for element type %d.\n", ElementInstance->GetTypeNumber());
        };
        void DoLogic(ElementTwo* ElementInstance){
            printf("Doing logic for element type %d.\n", ElementInstance->GetTypeNumber());
        };
};

int main(){
    Visitor* VisitorInstance = new VisitorOne();
    Element* ElementInstanceOne = new ElementOne();
    Element* ElementInstanceTwo = new ElementTwo();
    ElementInstanceOne->Accept(VisitorInstance);
    ElementInstanceTwo->Accept(VisitorInstance);
    return 0;
};
