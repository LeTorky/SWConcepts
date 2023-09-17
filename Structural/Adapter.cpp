#include <stdio.h>
#include <conio.h>

class IBusiness{
    public:
        virtual int DoLogic() = 0;
};

class IService{
    public:
        virtual void Serve(float SpecificMetric) = 0;
};

class Business: IBusiness{
    public:
        int DoLogic(){
            printf("Performing logic.\n");
            return 1;
        };
};

class Service: public IService{
    public:
        void Serve(float SpecificMetric){
            printf("Performing service.\n");
        };
};

class Adapter: public IBusiness{
    private:
        IService* Service;
    public:
        Adapter(IService* Service){
            this->Service = Service;
        }
        int DoLogic(){
            printf("Performing logic.\n");
            float AdaptedValue = 1.00;
            this->Service->Serve(AdaptedValue);
            return 1;
        }
};

int main(){
    IService* ServiceInstance = new Service();
    IBusiness* BusinessInstance = new Adapter(ServiceInstance);
    BusinessInstance->DoLogic();
    return 0;
};
