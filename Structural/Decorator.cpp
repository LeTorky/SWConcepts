#include <conio.h>
#include <stdio.h>

class IBusiness{
    public:
        virtual void DoLogic() = 0;
};

class BaseDecorator: public IBusiness{
    protected:
        IBusiness* Wrapped = nullptr;
    public:
        BaseDecorator(IBusiness* Wrapped){
            this->Wrapped = Wrapped;
        };
        BaseDecorator(){}
        void DoLogic(){
            printf("Performing extra logic and calling wrapped if exists.\n");
            if(this->Wrapped != nullptr)
                this->Wrapped->DoLogic();
        };
};

class SecondDecorator: public BaseDecorator{
    public:
        SecondDecorator(IBusiness* Wrapped){
            this->Wrapped = Wrapped;
        };
        void DoLogic(){
            printf("Performing extra custom logic and calling wrapped.\n");
            if(this->Wrapped != nullptr)
                this->Wrapped->DoLogic();
        };
};

int main(){
    IBusiness* Base = new BaseDecorator();
    IBusiness* CustomWrapper = new SecondDecorator(Base);
    CustomWrapper->DoLogic();
    return 0;
}