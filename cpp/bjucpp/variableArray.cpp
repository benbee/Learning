#include <iostream>

using namespace std;

class CArray {
private:
    int size;
    int *ptr;
public:
    CArray(int s = 0);          // s mean the size of the array
    CArray(CArray & a);
    ~CArray();
    void push_back(int v);      // add one element in the tail of array
    void opt_push_back(int v);
    CArray & operator= (const CArray & a);
    // assign between obj

    int length() {return size;}
    int & operator[] (int i)
        {
            return ptr[i];
        }
};

CArray::CArray(int s): size(s)
{
    if (s == 0)
        ptr = NULL;
    else
        ptr = new int[s];
}

CArray::CArray(CArray &a) {
    if (!a.ptr) {
        ptr = NULL;
        size = 0;
        return;
    }
    ptr = new int[a.size];
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
}

CArray::~CArray()
{
    if (ptr) {
        delete [] ptr;
    }
}

CArray & CArray::operator= (const CArray &a)
{
    if (ptr == a.ptr) {         // just incase a = a
        return *this;
    }

    if (a.ptr == NULL) {
        if (ptr) {
            delete [] ptr;
            ptr = NULL;
            size = 0;
            return *this;
        }
    }

    if (size < a.size) {
        if (ptr) {
            delete [] ptr;
        }
        ptr = new int[a.size];
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return *this;
}

void CArray::push_back(int v)
{
    if (ptr) {
        int *tmpPtr = new int[size + 1];
        memcpy(tmpPtr, ptr, sizeof(int) * size);
        delete [] ptr;
        ptr = tmpPtr;
    } else                      // array was empty
        ptr = new int[1];
    ptr[size++] = v;
}

// void CArray::opt_push_back(int v)
// {
//     if (ptr) {
//         if () {
            
//         }
//     }
// }
int main(int argc, char *argv[])
{
    CArray a;
    for (int i = 0; i < 5; i++) {
        a.push_back(i);
    }
    CArray a2, a3;
    a2 = a;
    for (int i = 0; i < a.length(); i++) {
        cout << a[i] << " ";
    }
    a2 = a3;
    for (int i = 0; i < a2.length(); i++) {
        cout << a2[2] << " ";
    }
    cout << endl;

    a[3] = 100;
    CArray a4(a);
    for (int i = 0; i < a4.length(); i++) {
        cout << a4[i] << " ";
    }
    cout << endl;
    
    return 0;
}
