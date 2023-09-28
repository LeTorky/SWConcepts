#include<conio.h>
#include<stdio.h>

class Service{
    public:
        virtual void DoOperation() = 0;
};

class ActualService: public Service{
    public:
        void DoOperation(){
            printf("Doing operation.\n");
        }
};

class ProxyToService: public Service{
    private:
        Service* ActualServiceInstance;
    public:
        ProxyToService(Service* ActualServiceInstance){
            this->ActualServiceInstance = ActualServiceInstance;
        };
        void DoOperation(){
            printf("Performing security check.\n");
            this->ActualServiceInstance->DoOperation();
        };
};

int main(){
    Service* ActualServiceInstance = new ActualService();
    Service* ProxyToServiceInstance = new ProxyToService(ActualServiceInstance);
    ProxyToServiceInstance->DoOperation();
    return 0;
}
