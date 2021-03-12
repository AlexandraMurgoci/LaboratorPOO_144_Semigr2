#include <iostream>

class DynamicExample {
    int m_size;
    int* m_vector;

public:
    DynamicExample(int size, int initial_value)
    {
        m_size = size;
        m_vector = new int[m_size];
        for(int i=0;i<m_size;i++) m_vector[i]=initial_value;
    }

    DynamicExample(const DynamicExample &dynamicExample)
    {
        m_size = dynamicExample.m_size;
        //ASA NU
//        m_vector = dynamicExample.m_vector;
        m_vector = new int[m_size];
        for(int i=0;i<m_size;i++) m_vector[i] = dynamicExample.m_vector[i];
    }

    ~DynamicExample()
    {
        delete[] m_vector;
    }

    DynamicExample& operator=(const DynamicExample& dynamicExample)
    {
        m_size = dynamicExample.m_size;
        //ASA NU
//        m_vector = dynamicExample.m_vector;

        //obiectul exista deja, deci trebuie sa eliberez memoria alocata inainte de a aloca din nou
        delete[] m_vector;

        m_vector = new int[m_size];
        for(int i=0;i<m_size;i++) m_vector[i] = dynamicExample.m_vector[i];
        return *this;
    }

    void Display()
    {
        for(int i=0;i<m_size;i++) std::cout << m_vector[i] << ' ';
    }

    bool ReplaceAt(int index, int value)
    {
        if(index >= m_size || index < 0) return false;
        m_vector[index] = value;
        return true;
    }
};

void demoDynamicExample() {
    DynamicExample d1(3, 0);
    DynamicExample d2(d1);

//    d2=d1;

    d1.ReplaceAt(1, 4);

    d1.Display(); // 0 4 0
    std::cout << std::endl;
    d2.Display(); // 0 0 0
}

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
    
    Node * GetLast()
    {
        Node *iterator = m_first;
        while(iterator->GetNext() != nullptr) iterator = iterator->GetNext();
        return iterator;
    }

public:
    ListExample(int info)
    {
        m_first = new Node(info);
    }

    void Add(int info)
    {
        Node *last = GetLast();
        last->SetNext(new Node(info));
    }

    void Display()
    {
        Node *iterator = m_first;
        while (iterator != nullptr)
        {
            std::cout << iterator->GetInfo() << ' ';
            iterator = iterator->GetNext();
        }
    }
    ~ListExample()
    {
        //aici trebuie sa ne asiguram ca se elibereaza memoria pentru toate nodurile din lista
        std::cout << "Destructor ListExample" << std::endl;
        Node *iterator = m_first;
        while (iterator != nullptr)
        {
            Node *auxToBeDeleted = iterator;
            iterator = iterator->GetNext();
            delete auxToBeDeleted;
        }
    }
};

void demoListExample() {
    ListExample list(1);
    list.Add(2);
    list.Add(3);
    list.Display();
    std::cout << std::endl;
}

int main() {
//    demoDynamicExample();
    demoListExample();
    return 0;
}
