#include <iostream>
using namespace std;
template <typename T>
struct node
{
    T data;
    node<T> *next;
    node<T>()
    {
        next = NULL;
    }
    node<T>(T val)
    {
        this->data = val;
        next = NULL;
    }
};
template <typename T>
class stack
{
    node<T> *top;
    int size;

public:
    stack()
    {
        this->top = NULL;
        this->size = 0;
    }
    void push(T val)
    {
        node<T> *n = new node<T>(val);
        if (isEmpty())
        {
            ++size;
            this->top = n;
            return;
        }
        ++size;
        n->next = top;
        top = n;
    }
    void pop()
    {
        // if (isEmpty())
        //     return;
        // --size;
        node<T> *t = this->top;
        this->top = this->top->next;
        delete t;
    }
    bool isEmpty()
    {
        return (this->top == NULL);
    }
    T get_top_element()
    {
        return this->top->data;
    }
    stack<T> *sort(stack<T> *stack_s)
    {
        stack<T> *temp_s = new stack<T>;
        while (!stack_s->isEmpty())
        {
            T val = stack_s->get_top_element();
            stack_s->pop();
            while (!temp_s->isEmpty() && temp_s->get_top_element() > val)
            {
                stack_s->push(temp_s->get_top_element());
                temp_s->pop();
            }
            temp_s->push(val);
        }
        return temp_s;
    }
    void display()
    {
        for (node<T> *temp = top; temp != NULL; temp = temp->next)
            cout << temp->data << "->";
        cout << "NULL\n";
    }
    void delete_middle()
    {
        if (top == NULL || size == 1)
            return;
        node<T> *temp = top;
        for (int i = 0; i < size / 2 - 1; i++)
            temp = temp->next;
        node<T> *t = temp->next;
        temp->next = t->next;
        delete t;
        --size;
    }
    bool check_pallindrome()
    {
        node<T> *temp = top;
        node<T> *temp2 = NULL;
        for (int i = 0; i < size / 2; i++)
        {
            temp2 = top;
            for (int j = 0; j < size - i - 1; j++)
                temp2 = temp2->next;
            if (temp->data != temp2->data)
                return false;
            temp = temp->next;
        }
        return true;
    }
    void get_k_sum_elements(T k)
    {
        node<T> *temp = top;
        node<T> *temp1 = top;
        bool flag = false;
        for (; temp != NULL; temp = temp->next)
        {
            for (temp1 = temp; temp1 != NULL; temp1 = temp1->next)
            {
                if (temp->data + temp1->data == k)
                {
                    cout << temp->data << "  " << temp1->data << endl;
                    // return;
                    flag = true;
                }
            }
        }
        if (!flag)
            cout << "Not Found a pair Equal to K\n";
    }
};
int main()
{
    stack<int> *s = new stack<int>;
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(1);
    s->push(2);
    s->push(3);
    s->display();

    if (s->check_pallindrome())
        cout << "Pallindrome\n";
    else
        cout << "Not Pallindrome\n";
    s->get_k_sum_elements(5);
    stack<int> *a = new stack<int>;
    a->push(45);
    a->push(97);
    a->push(67);
    a->push(100);
    a->push(56);
    a->push(22);
    a->display();
    stack<int> *sort_s = new stack<int>;
    sort_s = sort_s->sort(a);
    sort_s->display();
}