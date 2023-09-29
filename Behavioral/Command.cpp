#include <conio.h>
#include <stdio.h>

class Editor{
    public:
        virtual void ExecutingOne(char* Param) = 0;
        virtual void ExecutingTwo(char* Param) = 0;
        virtual void ExecutingThree(char* Param) = 0;
};

class Command{
    protected:
        Editor* EditorInstance;      
    public:
        virtual void Execute() = 0;
        virtual void SetEditor(Editor* EditorInstance) = 0;
};

class CommandOne: public Command{
    public:
        void Execute(){
            this->EditorInstance->ExecutingOne("one");
        };
        void SetEditor(Editor* EditorInstance){
            this->EditorInstance = EditorInstance;
        };
};

class CommandTwo: public Command{
    public:
        void Execute(){
            this->EditorInstance->ExecutingTwo("two");
        };
        void SetEditor(Editor* EditorInstance){
            this->EditorInstance = EditorInstance;
        };
};

class CommandThree: public Command{
    public:
        void Execute(){
            this->EditorInstance->ExecutingThree("three");
        };
        void SetEditor(Editor* EditorInstance){
            this->EditorInstance = EditorInstance;
        };
};

class EditorOne: public Editor{
    public:
        void ExecutingOne(char* Param){
            printf("Executing editor logic one with command %s.\n", Param);
        };
        void ExecutingTwo(char* Param){
            printf("Executing editor logic two with command %s.\n", Param);
        };
        void ExecutingThree(char* Param){
            printf("Executing editor logic three with command %s.\n", Param);
        };
};

int main(){
    Editor* EditorInstance = new EditorOne();
    Command* CommandInstanceOne = new CommandOne();
    Command* CommandInstanceTwo = new CommandTwo();
    Command* CommandInstanceThree = new CommandThree();
    CommandInstanceOne->SetEditor(EditorInstance);
    CommandInstanceTwo->SetEditor(EditorInstance);
    CommandInstanceThree->SetEditor(EditorInstance);
    CommandInstanceOne->Execute();
    CommandInstanceTwo->Execute();
    CommandInstanceThree->Execute();
    return 0;
};
