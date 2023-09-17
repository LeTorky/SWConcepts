#include <mutex>
#include <stdio.h>
#include <conio.h>

std::mutex mtx;

class Singleton{
    private:
        static Singleton* Instance;
        Singleton(){
            printf("%s", "Constructing instance.");
        };
    public:
        static Singleton* GetInstance(){
            if(Singleton::Instance != nullptr)
                return Singleton::Instance;
            else{
                mtx.lock();
                if(Singleton::Instance != nullptr)
                    return Singleton::Instance;
                else
                    return new Singleton();
                mtx.unlock();
            }
            
        };
};

Singleton* Singleton::Instance = nullptr;

