#include <stdio.h>
#include <conio.h>

template <typename T>
class Iterator{
    public:
        virtual T* GetNext() = 0;
        virtual bool HasMore() = 0;
};

template <typename T>
class IterableCollection{
    public:
        virtual Iterator<T>* GetIterator() = 0;
        virtual void AddToDataList(T* Instance) = 0;
        virtual T* GetItem(int index) = 0;
};

template <typename T>
class LinearIterator: public Iterator<T>{
    private:
        IterableCollection<T>* Collection;
        int CurrentIndex = 0;
        int CollectionSize;
    public:
        LinearIterator(IterableCollection<T>* Collection, int CollectionSize){
            this->Collection = Collection;
            this->CollectionSize = CollectionSize;
        };
        bool HasMore(){
            if(CurrentIndex < CollectionSize)
                return true;
            return false;
        };
        T* GetNext(){
            if(this->HasMore())
                return this->Collection->GetItem(CurrentIndex++); 
            return nullptr;
        };
};

template <typename T>
class LinearCollection: public IterableCollection<T>{
    private:
        T** DataList;
        int DataListSize;
    public:
        void AddToDataList(T* Instance){
            T** NewDataList = new T*[++DataListSize];
            for(int i=0; i<DataListSize-1; i++)
                NewDataList[i] = DataList[i];
            NewDataList[DataListSize-1] = Instance;
            delete this->DataList;
            this->DataList = NewDataList;
        };
        Iterator<T>* GetIterator(){
            return new LinearIterator<T>(this, DataListSize);
        };
        T* GetItem(int index){
            return this->DataList[index];
        };
};

int main(){
    IterableCollection<int>* LinearCollectionInstance= new LinearCollection<int>();
    int x=1, y=2, z=3;
    LinearCollectionInstance->AddToDataList(&x);
    LinearCollectionInstance->AddToDataList(&y);
    LinearCollectionInstance->AddToDataList(&z);
    Iterator<int>* IteratorInstance = LinearCollectionInstance->GetIterator();
    int* X = IteratorInstance->GetNext();
    int* Y = IteratorInstance->GetNext();
    int* Z = IteratorInstance->GetNext();
    printf("%d %d %d", *X, *Y, *Z);
    return 0;
};
