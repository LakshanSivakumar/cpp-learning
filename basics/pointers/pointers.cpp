#include <cstddef>
#include <iostream>

int main(){

    int *ptr {nullptr};

    int value {5};
    int *ptr2{&value};
    // ptr2 = nullptr;

    if (!ptr || !ptr2){
        std::cout<< "Both are null ptrs";
    }
    return 0;


}