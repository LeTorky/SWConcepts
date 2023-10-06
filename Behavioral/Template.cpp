#include <stdio.h>
#include <conio.h>

class Template{
    public:
        void virtual StepOne() = 0;
        void virtual StepTwo(){
            printf("Default implementation for step two.\n");
        };
        void virtual StepThree() = 0;
        void virtual ExecuteSteps(){
            printf("Executing steps in order.\n");
            this->StepOne();
            this->StepTwo();
            this->StepThree();
        };
};

class ConcretOne: public Template{
    public:
        void virtual StepOne(){
            printf("Custom implementation 'One' for step one.\n");
        };
        void virtual StepThree(){
            printf("Custom implementation 'One' for step three.\n");
        };
};

class ConcretTwo: public Template{
    public:
        void virtual StepOne(){
            printf("Custom implementation 'Two' for step one.\n");
        };
        void virtual StepThree(){
            printf("Custom implementation 'Two' for step three.\n");
        };
};

int main(){
    Template* ConcretOneInstance = new ConcretOne();
    Template* ConcretTwoInstance = new ConcretTwo();
    ConcretOneInstance->ExecuteSteps();
    ConcretTwoInstance->ExecuteSteps();
    return 0;
};
