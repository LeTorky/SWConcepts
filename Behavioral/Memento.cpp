#include <stdio.h>
#include <conio.h>

class State{
    private:
        int One;
        int Two;
    public:
        State(int One, int Two): One(One), Two(Two){};
        int GetOne(){
            return this->One;
        };
        int GetTwo(){
            return this->Two;
        };
};


class Memento{
    public:
        virtual void Restore() = 0;
};

class Object{
    public:
        virtual Memento* SaveState() = 0;
        virtual void SetState(State* StateInstance) = 0;
        virtual State* GetState() = 0;
};

class MementoOne: public Memento{
    private:
        Object* ObjectInstance;
        State* SavedState;
    public:
        MementoOne(Object* ObjectInstance, State* SavedState): ObjectInstance(ObjectInstance), SavedState(SavedState){};
        void Restore(){
            printf("Restoring state.\n");
            this->ObjectInstance->SetState(SavedState);
        };
};

class ObjectOne: public Object{
    private:
        State* CurrentState;
    public:
        Memento* SaveState(){
            printf("Saving state.\n");
            return new MementoOne(this, this->CurrentState);
        };
        void SetState(State* CurrentState){
            this->CurrentState = CurrentState;
        };
        State* GetState(){
            return this->CurrentState;
        }
};

int main(){
    State* CurrentState = new State(1, 2);
    Object* ObjectInstance = new ObjectOne();
    ObjectInstance->SetState(CurrentState);
    Memento* CurrentStateSaved = ObjectInstance->SaveState();
    State* NewState = new State(2,3);
    ObjectInstance->SetState(NewState);
    printf("Current state: One:%d, Two:%d.\n", ObjectInstance->GetState()->GetOne(),
            ObjectInstance->GetState()->GetTwo());
    CurrentStateSaved->Restore();
    printf("Current state: One:%d, Two:%d.\n", ObjectInstance->GetState()->GetOne(),
        ObjectInstance->GetState()->GetTwo());
    return 0;
}