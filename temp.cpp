#include "lsl/lsl.hpp"
#include <iostream>

int main(){
    
    lsl::array<int, 10> arr{6,3,4,5,2,1,8,9,7,10};

        for(int c : arr){
        std::cout << c << ",";
    }

    std::cout << std::endl;
    std::cout << "ordered" << std::endl;

    lsl::quickSort(arr);
    
    for(int c : arr){
        std::cout << c << ",";
    }

    std::cout << std::endl;


    
}