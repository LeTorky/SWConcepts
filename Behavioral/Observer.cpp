#include <stdio.h>
#include <conio.h>

class Event{
    public:
        int Number;
        Event(int Number){
            this->Number = Number;
        };
};

class Subscriber{
    public:
        virtual void update(Event EventInstance) = 0;
};

class Publisher{
    public:
        virtual void Subscribe(Subscriber* SubscriberInstance) = 0;
        virtual void UnSubscribe(Subscriber* SubscriberInstance) = 0;
        virtual void Notify(int EventNumber) = 0;
};

class SubscriberOne: public Subscriber{
    private:
        int Id;
        static int Counter;
    public:
        SubscriberOne(){
            this->Id = SubscriberOne::Counter++;
        }
        virtual void update(Event EventInstance){
            printf("Subscriber #%d got updated with event number: %d.\n",
            this->Id + 1,
            EventInstance.Number);
        }
};

int SubscriberOne::Counter = 0;

class PublisherOne: public Publisher{
    private:
        Subscriber** SubscribersList;
        int SubscribersListSize = 0;
    public:
        void Subscribe(Subscriber* SubscriberInstance){
            Subscriber** NewSubscribersList = new Subscriber*[++SubscribersListSize];
            for(int i=0; i<SubscribersListSize-1; i++)
                NewSubscribersList[i] = SubscribersList[i];
            NewSubscribersList[SubscribersListSize-1] = SubscriberInstance;
            delete SubscribersList;
            SubscribersList = NewSubscribersList;
        };
        void UnSubscribe(Subscriber* SubscriberInstance){
            bool Found = false;
            for(int i=0; i<SubscribersListSize-1; i++)
                if(SubscribersList[i] == SubscriberInstance){
                    SubscribersList[i] = SubscribersList[i+1];
                    SubscribersList[i+1] = SubscriberInstance;
                    Found = true;
                }
            if(Found)
                --SubscribersListSize;
        };
        void Notify(int EventNumber){
            Event NewEvent = Event(EventNumber);
            for(int i=0; i<SubscribersListSize; i++)
                SubscribersList[i]->update(NewEvent);
        };
};

int main(){
    Publisher* PublisherInstance = new PublisherOne();
    Subscriber* SubscriberInstanceOne = new SubscriberOne();
    Subscriber* SubscriberInstanceTwo = new SubscriberOne();
    Subscriber* SubscriberInstanceThree = new SubscriberOne();
    PublisherInstance->Subscribe(SubscriberInstanceOne);
    PublisherInstance->Subscribe(SubscriberInstanceTwo);
    PublisherInstance->Subscribe(SubscriberInstanceThree);
    PublisherInstance->UnSubscribe(SubscriberInstanceTwo);
    PublisherInstance->Notify(1);
    return 0;
};
