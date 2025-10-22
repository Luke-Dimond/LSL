/*
* Created by: Luke Manuel
* Description: A custom array made to mimic std::array
* 2025
*/

#pragma once
#include <cstddef>
#include <stdexcept>

namespace lsl{
    template <typename T>
    class array{

    public:

        // Constructor and Destructor
        array(size_t size)
            : data_(new T[size]{}), size_(size)
        {
        }

        ~array() {
                delete[] data_;
            }


        // Functions
        size_t length() const {
            return size_;
        }

        const T* begin() const {
            return data_;
        }

        const T* end() const {
            return data_ + size_;
        }
        
        T* begin() {
            return data_;
        }

        T* end() {
            return data_ + size_;
        }


        // Operators
        array& operator= (const array& arr){

            if (size_ != arr.length()){
                throw std::invalid_argument("Both arrays must be of equal length");
            }

            for(size_t i = 0; i < size_; i++){
                data_[i] = arr[i];
            }

            return *this;

        }

        T& operator[] (size_t i) const {
            return data_[i];
        }

    private:

        T* data_{nullptr};
        size_t size_{};
    };
}
