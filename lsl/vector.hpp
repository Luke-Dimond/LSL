/*
* Created by: Luke Manuel
* Description: A custom vector made to mimic std::vector
* 2025, October
*/

#pragma once
#include <cstddef>
#include <stdexcept>

namespace lsl {

	template<typename T>
	class vector {

	private:
		size_t capacity_{ 10 };
		T* data_{ nullptr };
		size_t size_{};
	
		
	public:
		using value_type = T;

		// Constructor and Destructor
		vector() 
            : data_(new T[capacity_]{})
        {
		}

		~vector() {
			delete[] data_;
		}

		// Functions

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

		constexpr bool empty() const {
			return size_ == 0;
		}

		constexpr size_t size() const {
			return size_;
		}

		constexpr size_t capacity() const {
			return capacity_;
		}

		void erase(){
			size_ = 0;
		}

        void shrink(){
            if (size_ == capacity_) return;
           
            T* new_data = new T[size_];

			for (size_t i = 0; i < size_; i++) {
				new_data[i] = data_[i];
			}

			delete[] data_;

			data_ = new_data;
			capacity_ = size_;
        }

		void reserve(size_t new_capacity) {
			if (new_capacity <= capacity_) return;

			T* new_data = new T[new_capacity];

			for (size_t i = 0; i < size_; i++) {
				new_data[i] = data_[i];
			}

			delete[] data_;

			data_ = new_data;
			capacity_ = new_capacity;
			
		}

		void push_back(T value) {
			if (size_ + 1 > capacity_) {
				reserve(capacity_ * 2);
			}
			data_[size_++] = value;
		}
  
        void pop_back() {
            if (empty()) return;
            size_--;
        }

		T& at(size_t i) {
			if (i >= size_) throw std::out_of_range("exceeds size of vector");
			return data_[i];
		}

		const T& at(size_t i) const {
			if (i >= size_) throw std::out_of_range("exceeds size of vector");
			return data_[i];
		}

		//Operators
		vector& operator= (const vector& vec) {
			
			if(this == &vec) return *this;

			T* new_data = new T[vec.capacity()];

			for (size_t i = 0; i < vec.size(); i++) {
				new_data[i] = vec[i];
			}

			delete[] data_;

			data_ = new_data;
			size_ = vec.size();
			capacity_ = vec.capacity();

			return *this;
		}

		T& operator[] (size_t i) {
			return data_[i];
		}

	}; //end of class

}// End of namespace
