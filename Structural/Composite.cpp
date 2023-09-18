#include <conio.h>
#include <stdio.h>
#include <iostream>

class Composite{
    public:
        virtual void PerformLogic() = 0;
};

class Component: public Composite{
    private:
        Composite** Components;
        int ComponentsLength = 0;
    public:
        void PerformLogic(){
            printf("Performing logic and delegating to children.\n");
            for(int i=0; i<this->ComponentsLength; i++){
                Components[i]->PerformLogic();
            };
        };

        void addComponent(Composite* NewComponent){
            Composite** NewComponents = new Composite*[this->ComponentsLength+1];
            for(int i=0; i<this->ComponentsLength; i++){
                NewComponents[i] = Components[i];
            };
            NewComponents[ComponentsLength++] = NewComponent;
            delete Components;
            this->Components = NewComponents;
        };
};

class Leaf: public Composite{
    public:
        void PerformLogic(){
            printf("Performing leaf logic.\n");
        };
};

int main(){
    Component* ComponentInstanceOne = new Component();
    Component* ComponentInstanceTwo = new Component();
    Leaf* LeafInstanceOne = new Leaf();
    Leaf* LeafInstanceTwo = new Leaf();
    ComponentInstanceOne->addComponent(LeafInstanceOne);
    ComponentInstanceOne->addComponent(ComponentInstanceTwo);
    ComponentInstanceTwo->addComponent(LeafInstanceTwo);
    ComponentInstanceOne->PerformLogic();
    return 0;
}
