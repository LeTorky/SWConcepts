#include <conio.h>
#include <stdio.h>

class Component{
    public:
        virtual int GetId() = 0;
        virtual void Receive() = 0;
        virtual void Notify(int Id) = 0;
};

class Mediator{
    public:
        virtual void AddComponent(Component* NewComponent) = 0;
        virtual void Notify(Component* Sender, int Id) = 0;
};

class ComponentOne: public Component{
    private:
        int Id;
        Mediator* MediatorInstance;
    public:
        ComponentOne(Mediator* MediatorInstance, int Id):MediatorInstance(MediatorInstance){
            MediatorInstance->AddComponent(this);
            this->Id = Id;
        };
        int GetId(){
            return this->Id;
        };
        void Receive(){
            printf("Getting notified.\n");
        }
        void Notify(int Id){
            this->MediatorInstance->Notify(this, Id);
        }
};

class MediatorOne: public Mediator{
    private:
        Component** ComponentList;
        int ComponentListSize = 0;
    public:
        void AddComponent(Component* NewComponent){
            Component** NewComponentList = new Component*[++ComponentListSize];
            for(int i=0; i<ComponentListSize-1; i++)
                NewComponentList[i] = ComponentList[i];
            NewComponentList[ComponentListSize-1] = NewComponent;
            delete ComponentList;
            ComponentList = NewComponentList;
        };
        void Notify(Component* Sender, int Id){
            Component* Receiver = nullptr;
            int CurrentIndex = 0;
            while(Receiver == nullptr && CurrentIndex < ComponentListSize)
                if(ComponentList[CurrentIndex++]->GetId() == Id)
                    Receiver = ComponentList[CurrentIndex-1];
            printf("Notifying component.\n");
            Receiver->Receive();
        }
};

int main(){
    Mediator* MediatorInstance = new MediatorOne();
    Component* ComponentInstanceOne = new ComponentOne(MediatorInstance, 1);
    Component* ComponentInstanceTwo = new ComponentOne(MediatorInstance, 2);
    ComponentInstanceOne->Notify(2);
    return 0;
}
