#include <stdio.h>
#include <conio.h>

class Flyweight{
    private:
        int RepeatedState;
    public:
        Flyweight(){};
        Flyweight(int RepeatedState){
            this->RepeatedState = RepeatedState;
        };
        int GetReapeatedState(){
            return this->RepeatedState;
        };
        int UtilizeUniqueState(int UniqueState){
           printf("Utilizing unique state.\n"); 
           return this->RepeatedState + UniqueState;
        };
};

class Context{
    public:
        int UniqueState;
        Flyweight* RestOfData;
        Context(){};
        Context(Flyweight* RestOfData, int UniqueState){
            this->RestOfData = RestOfData;
            this->UniqueState = UniqueState;
        };
        int UtilizeRestOfData(){
            return this->RestOfData->UtilizeUniqueState(this->UniqueState);
        };
};

class Factory{
    private:
        Flyweight** FlyweightList;
        int FlyweightListSize;
        void AddToFlyweightList(Flyweight* Instance){
            Flyweight** NewFlyweightList = new Flyweight*[++FlyweightListSize];
            for(int i=0; i<FlyweightListSize-1; i++)
                NewFlyweightList[i] = FlyweightList[i];
            NewFlyweightList[FlyweightListSize-1] = Instance;
            delete this->FlyweightList;
            this->FlyweightList = NewFlyweightList;
        };
    public:
        Context* GetObject(int UniqueState, int RepeatingState){
            Context* Instance = nullptr;
            for(int i=0; i<FlyweightListSize; i++){
                if(FlyweightList[i]->GetReapeatedState() == RepeatingState){
                    printf("Using old Instance.\n");
                    Instance = new Context(FlyweightList[i], UniqueState);
                }
            }
            if(Instance == nullptr){
                printf("Adding new Instance.\n");
                Flyweight* RestOfData = new Flyweight(RepeatingState);
                Instance = new Context(RestOfData, UniqueState);
                this->AddToFlyweightList(RestOfData);
            }
            return Instance;
        }
};

int main(){
    Factory FactoryInstance = Factory();
    Context* InstanceOne = FactoryInstance.GetObject(1,1);
    Context* InstanceTwo = FactoryInstance.GetObject(2,2);
    Context* InstanceThree = FactoryInstance.GetObject(3,2);
    int UtilizedData = InstanceOne->UtilizeRestOfData();
    printf("%p %p\n", InstanceTwo->RestOfData, InstanceThree->RestOfData);
    if(InstanceTwo->RestOfData == InstanceThree->RestOfData){
        printf("Same object.\n");
    }
    return 0;
}
