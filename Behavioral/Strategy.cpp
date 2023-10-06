#include <stdio.h>
#include <conio.h>

class Strategy{
    public:
        virtual void execute() = 0;
};

class StrategyOne: public Strategy{
    public:
        void execute(){
            printf("Executing strategy with plan one.\n");
        };
};

class StrategyTwo: public Strategy{
    public:
        void execute(){
            printf("Executing strategy with plan two.\n");
        };
};

class Context{
    public:
        virtual void execute() = 0;
        virtual void SetStrategy(Strategy* StrategyInstance) = 0;
};

class ContextOne: public Context{
    private:
        Strategy* StrategyInstance;
    public:
        void execute(){
            printf("Executing strategy one execute method.\n");
            this->StrategyInstance->execute();
        };
        void SetStrategy(Strategy* StrategyInstance){
            this->StrategyInstance = StrategyInstance;
        };
};

int main(){
    Strategy* StrategyInstance = new StrategyOne();
    Strategy* StrategyInstanceTwo = new StrategyTwo();
    Context* ContextInstance = new ContextOne();
    ContextInstance->SetStrategy(StrategyInstance);
    ContextInstance->execute();
    ContextInstance->SetStrategy(StrategyInstanceTwo);
    ContextInstance->execute();
    return 0;
};
