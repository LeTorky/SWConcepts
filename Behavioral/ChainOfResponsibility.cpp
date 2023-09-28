#include <stdio.h>
#include <conio.h>

class Request{
    public:
        int Value = 0;
};

class CoR{
    protected:
        CoR* Next = nullptr;
    public:
        virtual Request* HandleRequest(Request* RequestInstance) = 0;
        virtual void SetNext(CoR* Next) = 0;
};

class NodeOne: public CoR{
    public:
        Request* HandleRequest(Request* RequestInstance){
            printf("Handling request with 1st operation.\n");
            ++RequestInstance->Value;
            if(this->Next != nullptr)
                return this->Next->HandleRequest(RequestInstance);
            return RequestInstance;
        };
        void SetNext(CoR* Next){
            this->Next = Next;
        };
};

class NodeTwo: public CoR{
    public:
        Request* HandleRequest(Request* RequestInstance){
            printf("Handling request with 2nd operation.\n");
            ++RequestInstance->Value;
            if(this->Next != nullptr)
                return this->Next->HandleRequest(RequestInstance);
            return RequestInstance;
        };
        void SetNext(CoR* Next){
            this->Next = Next;
        };
};

class NodeThree: public CoR{
    public:
        Request* HandleRequest(Request* RequestInstance){
            printf("Handling request with 3rd operation.\n");
            ++RequestInstance->Value;
            if(this->Next != nullptr)
                return this->Next->HandleRequest(RequestInstance);
            return RequestInstance;
        };
        void SetNext(CoR* Next){
            this->Next = Next;
        };
};

int main(){
    Request* RequestInstance = new Request();
    CoR* ListOfHandlers[3] = {
        new NodeOne(),
        new NodeTwo(),
        new NodeThree()
    };
    int ListSize = 3;
    for(int i=0; i<ListSize-1; ++i)
        ListOfHandlers[i]->SetNext(ListOfHandlers[i+1]);
    ListOfHandlers[0]->HandleRequest(RequestInstance);
    printf("Final value of request: %d", RequestInstance->Value);
    return 0;
};
