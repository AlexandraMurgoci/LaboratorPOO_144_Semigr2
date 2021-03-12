#include <iostream>

using namespace std;
/*
class DynamicExample
{
    int m_size;
    int* m_vector;

public:
    DynamicExample(int size, int init_value)
    {
        m_size = size;
        m_vector = new int[m_size];
        for (int i=0;i<m_size;i++)
            m_vector[i]=init_value;
    }

    DynamicExample(const DynamicExample & dynamicExample)
    {
        m_size = dynamicExample.m_size;
        m_vector = new int[m_size];
        for (int i=0;i<m_size;i++)
            m_vector[i] = dynamicExample.m_vector[i];
    }

    DynamicExample & operator=(const DynamicExample & dynamicExample)
    {
        m_size = dynamicExample.m_size;
        for (int i=0;i<m_size;i++)
            m_vector[i] = dynamicExample.m_vector[i];
        return *this;
    }

    ~DynamicExample() {delete[] m_vector;}

    void display
    {
        for (int i=0;i<m_size;i++)
            cout << m_vector[i] << ' ';
    }

    bool ReplaceAt (int index, int value)
    {
        if (index>= m_size || index<0) return false;
            m_vector[index] = value;
            return true;
    }
};
*/

class Node {
    int m_info;
    Node *m_next;

public:
    Node(int info)
    {
        m_info = info;
        m_next = NULL;
    }

    void SetNext(Node* node)
    {
        m_next = node;
    }
    Node* GetNext() {return m_next;}
    int GetInfo() {return m_info;}
    void SetInfo(int info) {m_info = info;}

    ~Node()
    {
        //NU vrem sa dezalocam aici memoria pentru un nod "exterior" obiectului meu
//        delete m_next;
    }
};

class ListExample {
    Node *m_first;
    Node *n;

public:
    ListExample(int info)
    {
        m_first = new Node(info);
        n = m_first;
    }

    //TODO
    void Add(int info)
    {
        Node* newnode = new Node(info);
        n->SetNext(newnode);
        n = newnode;

    }
    void Display()
    {
        Node* temp = m_first;
        while (temp != NULL)
        {
            std::cout << temp->GetInfo() << ' ';
            temp = temp->GetNext();
        }
    }
    ~ListExample()
    {
        //aici trebuie sa ne asiguram ca se elibereaza memoria pentru toate nodurile din lista

        while (m_first !=NULL)
        {
            Node* temp = m_first;
            m_first = m_first->GetNext();
            delete temp;
        }

    }
};

void demoListExample() {
    //TODO
    //creez o lista
    ListExample lista1(3);
    //adaug 2 elemente
    lista1.Add(5);
    lista1.Add(6);
    lista1.Display();
}

int main() {
//    demoDynamicExample();
    demoListExample();
    return 0;
}
