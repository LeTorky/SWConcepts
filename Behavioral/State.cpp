#include <stdio.h>
#include <conio.h>

class State{
    public:
        virtual void DoLogic() = 0;
        virtual void ChangeState(State* NewState) = 0;
};

class StateOne: public State{
    private:
        State* Business;
    public:
        StateOne(State* Business): Business(Business){};
        void ChangeState(State* NewState){
            Business->ChangeState(NewState);
        };
        void DoLogic();
};

class StateTwo: public State{
    private:
        State* Business;
    public:
        StateTwo(State* Business): Business(Business){};
        void ChangeState(State* NewState){
            Business->ChangeState(NewState);
        };
        void DoLogic();
};

void StateOne::DoLogic(){
    printf("Perfomring logic with state one.\n"
            "Setting state to two.\n");
    State* NewState = new StateTwo(Business);
    ChangeState(NewState);
};

void StateTwo::DoLogic(){
    printf("Perfomring logic with state two.\n"
            "Setting state to one.\n");
    State* NewState = new StateOne(Business);
    ChangeState(NewState);
};

class Business: public State{
    private:
        State* CurrentState = new StateOne(this);
    public:
        void DoLogic(){
            CurrentState->DoLogic();
        };
        void ChangeState(State* NewState){
            CurrentState = NewState;
        };
};

int main(){
    State* BusinessInstance = new Business();
    BusinessInstance->DoLogic();
    BusinessInstance->DoLogic();
    return 0;
};
