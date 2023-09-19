#include <conio.h>
#include <stdio.h>

class ServiceOne{
    public:
        void PerformService(){
            printf("Performing serivce one.\n");
        };
};

class ServiceTwo{
    public:
        void PerformService(){
            printf("Performing serivce two.\n");
        };
};

class ServiceThree{
    public:
        void PerformService(){
            printf("Performing serivce three.\n");
        };
};

class Facade{
    private:
        ServiceOne ServiceOneInstance;
        ServiceTwo ServiceTwoInstance;
        ServiceThree ServiceThreeInstance;
    public:
        Facade(){
            this->ServiceOneInstance = ServiceOne();
            this->ServiceTwoInstance = ServiceTwo();
            this->ServiceThreeInstance = ServiceThree();
        };

        void PerformService(int TypeOfService){
            printf("Delegating to services.\n");
            switch(TypeOfService){
                case 1:
                    this->ServiceOneInstance.PerformService();
                    break;
                case 2:
                    this->ServiceTwoInstance.PerformService();
                    break;
                case 3:
                    this->ServiceThreeInstance.PerformService();
                    break;
            }
        };
};

int main(){
    Facade FacadeInstance = Facade();
    FacadeInstance.PerformService(1);
    FacadeInstance.PerformService(2);
    FacadeInstance.PerformService(3);
    return 0;
}