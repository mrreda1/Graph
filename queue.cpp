#include <iostream>

using namespace std;

template<typename T>
class node {
public:
    node* next;
    T value;

    node(T Value) {
        this->value = Value;
        this->next = NULL;
    }
};

template<typename T>
class queue_methods {
    virtual unsigned long long size() = 0;
    virtual bool empty() = 0;
    virtual void push(T) = 0;
    virtual T front() = 0;
    virtual T back() = 0;
    virtual T pop() = 0;
};

template<typename T>
class queue_ds:queue_methods<T> {
private:
    unsigned long long length;
    node<T> *head;
    node<T> *tail;

public:
    queue_ds() {
        this->length = 0;
        this->head = this->tail = NULL;
    }
    unsigned long long size() {
        return length;
    }
    bool empty() {
        if( head == NULL ) return true;
        return false;
    }
    T front() {
        if(head == NULL) return 0;
        return head -> value;
    }
    T back() {
        if(head == NULL) return 0;
        return tail -> value;
    }
    T pop() {
        if(head == NULL) return 0;
        node<T> *temp_node = head;
        T temp_value = head -> value;
        head = head -> next;
        if(head == NULL) tail = NULL;
        delete(temp_node);
        length--;
        return temp_value;
    }
    void push(T Value) {
        node<T> *new_node = new node(Value);
        if(tail == NULL) head = new_node;
        else tail -> next = new_node;
        tail = new_node;
        length++;
    }
};
