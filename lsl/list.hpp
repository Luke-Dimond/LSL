#include <stdexcept>
#include <cstddef>

template <typename T>
class List {

private: 

    struct node {
        T value{};
        node<T>* nextNode{};
        node<T>* prevNode{};
    };

    node<T>* head{};
    node<T>* tail{};
    size_t size{};

public: 

    List() = default;

    ~List() {
        clear();
    }

    List(const List& newList) {
        for (node<T>* cur = newList.head; cur != nullptr; cur = cur->nextNode) {
            push_back(cur->value);
        }
    }

    //Clear the list and free all nodes 
    void clear() {
        node<T>* curNode = head;

        while(curNode != nullptr) {

            node<T>* nextNode = curNode->nextNode;
            delete curNode;
            curNode = nextNode;

        }

        head = tail = nullptr;
        size = 0;
    }

    void push_front (const T& v) {
        node<T>* newNode = new node<T>{v, head, nullptr};

        if (head != nullptr) head->prevNode = newNode;

        head = newNode;
        if (tail == nullptr) tail = newNode;
        size++;
    }

    void push_back (const T& v) {
        node<T>* newNode = new node<T>{v, nullptr, tail};
        
        if (tail != nullptr) {
            tail->nextNode = newNode;
        } else {
            head = newNode;
        }
        
        tail = newNode;

        size++;
    } 

    void pop_front() {
        if (head == nullptr) throw std::runtime_error("List is empty");

        node<T>* temp = head;
        head = head->nextNode;

        if (head != nullptr) {
            head->prevNode = nullptr;
        } else {
            tail = nullptr;
        }

        delete temp;
        size--;
    }

    void pop_back() {
        if (tail == nullptr) throw std::runtime_error("List is empty");

        node<T>* temp = tail;
        tail = tail->prevNode;

        if (tail != nullptr) {
            tail->nextNode = nullptr;
        } else {
            head = nullptr;
        }

        delete temp;
        size--;
    }

    List& operator=(const List& rhs) {
        if (this == &rhs) return *this;
        clear();

        for (node<T>* cur = rhs.head; cur != nullptr; cur = cur->nextNode) {
            push_back(cur->value);
        }

        return *this;
    }

};