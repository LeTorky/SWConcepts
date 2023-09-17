#include <stdio.h>
#include <conio.h>

class Ok{};

template <typename Type>
class Test{
    public:
        using name = Type;
};


int main(){
    Ok var = Test<Ok>::name();
};