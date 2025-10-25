/*
* Created by: Luke Manuel
* Description: A custom array made to mimic std::array
* 2025,
*/

#pragma once
#include <cstddef>
#include <stdexcept>

namespace lsl{
    template <typename T, size_t S>
    class array{

    public:
        using value_type = T;

        T data_[S]{};

        // Functions
        size_t size() const {
            return S;
        }

        const T* begin() const {
            return data_;
        }

        const T* end() const {
            return data_ + S;
        }
        
        T* begin() {
            return data_;
        }

        T* end() {
            return data_ + S;
        }


        // Operators
        array& operator= (const array& arr){

            if (S != arr.length()){
                throw std::invalid_argument("Both arrays must be of equal length");
            }

            for(size_t i = 0; i < S; i++){
                data_[i] = arr[i];
            }

            return *this;

        }

        const T& operator[] (size_t i) const {
            return data_[i];
        }

        T& operator[] (size_t i){
            return data_[i];
        }

    }; // End of class
}//end of namespace
