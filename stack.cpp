#include <iostream>
#include <string>
using namespace std;

template <typename T>
class Node{
    private:
        T data;
        Node <T>* next;

    public:
        Node<T>(){

        }

        Node<T>(T data){
            this->data = data;
            next = nullptr;
        }

        T& get_data(){
            return data;
        }

        const T& get_data() const{
            return data;
        }

        void set_data(T data){
            this->data = data;
        }

        Node <T>* get_next() const{
            return next;
        }

        void set_next(Node <T>* next){
            this->next = next;
        }
};


template <typename T>
class Stack{
    private:
        Node <T>* top;
        int length;

    public:
        Stack <T> (){
            length = 0;
            top = nullptr;
        }

        void push(T data){
            Node <T>* node = new Node <T> (data);

            if (top == nullptr){
                node->set_next(nullptr);
                top = node;
            }
            else {
                node->set_next(top);
                top = node;
            }
            length++;
        }

        int size(){
            return length;
        }

        bool empty(){
            return top == nullptr;
        }

        T pop(){
            if (top == nullptr){
                return -1;
            }

            Node <T>* temp = top;

            top = top->get_next();
            T poped = temp->get_data();

            delete temp;
            length--;

            return poped;
        }

        T peek(){
            return top->get_data();
        }

        void traverse(){
            if (top == nullptr){
                cout<<"NULL\n";
                return;
            }

            Node <T>* temp = top;

            while (temp != nullptr){
                cout<<temp->get_data()<<"\n";
                temp = temp->get_next();
            }
        }
};

int main(){
    
}