#pragma once
#include <stdexcept>
#include <cstddef>

namespace lsl {
    template <typename T>
    class List {

    private: 

        struct node {
            T value{};
            node* nextNode{};
            node* prevNode{};
        };

        node* head{};
        node* tail{};
        size_t size_{};

    public: 

        List() = default;

        ~List() {
            clear();
        }

        List(const List& newList) {
            for (node* cur = newList.head; cur != nullptr; cur = cur->nextNode) {
                push_back(cur->value);
            }
        }

        //Clear the list and free all nodes 
        void clear() {
            node* curNode = head;

            while(curNode != nullptr) {

                node* nextNode = curNode->nextNode;
                delete curNode;
                curNode = nextNode;

            }

            head = tail = nullptr;
            size_ = 0;
        }

        void push_front (const T& v) {
            node* newNode = new node{v, head, nullptr};

            if (head != nullptr) head->prevNode = newNode;

            head = newNode;
            if (tail == nullptr) tail = newNode;
            size_++;
        }

        void push_back (const T& v) {
            node* newNode = new node{v, nullptr, tail};
            
            if (tail != nullptr) {
                tail->nextNode = newNode;
            } else {
                head = newNode;
            }
            
            tail = newNode;

            size_++;
        } 

        void pop_front() {
            if (head == nullptr) throw std::runtime_error("List is empty");

            node* temp = head;
            head = head->nextNode;

            if (head != nullptr) {
                head->prevNode = nullptr;
            } else {
                tail = nullptr;
            }

            delete temp;
            size_--;
        }

        void pop_back() {
            if (tail == nullptr) throw std::runtime_error("List is empty");

            node* temp = tail;
            tail = tail->prevNode;

            if (tail != nullptr) {
                tail->nextNode = nullptr;
            } else {
                head = nullptr;
            }

            delete temp;
            size_--;
        }

        size_t size() {
            return size_;
        }
        
        T& at(size_t index) {
            if (index >= size_) throw std::out_of_range("Index is out of range");
            node* cur = head;
            for (size_t i = 0; i < index; i++) {
                cur = cur->nextNode;
            }
            return cur->value;
        }

        const T& at(size_t index) const {
            if (index >= size_) throw std::out_of_range("Index is out of range");
            node* cur = head;
            for (size_t i = 0; i < index; i++) {
                cur = cur->nextNode;
            }
            return cur->value;
        }

        List& operator=(const List& rhs) {
            if (this == &rhs) return *this;
            clear();

            for (node* cur = rhs.head; cur != nullptr; cur = cur->nextNode) {
                push_back(cur->value);
            }

            return *this;
        }

    };
}