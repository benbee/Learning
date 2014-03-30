#include <iostream>

using namespace std;

class CArray {
private:
    int size;
    int size_limit;
    int *ptr;
    void increase_size();
    int cal_sl(int s);
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
    void printSizeLimit(void) { cout << size_limit << endl; }
};

int CArray::cal_sl(int s)
{
    int i = 1;

    while (i < s) {
        i *= 2;
    }

    return i;
}

void CArray::increase_size(void)
{
    size_limit *= 2;

    int *tmpPtr = new int[size_limit];
    memcpy(tmpPtr, ptr, sizeof(int) * size);
    delete [] ptr;
    ptr = tmpPtr;
}

CArray::CArray(int s): size(s)
{
    if (s == 0)
        ptr = NULL;
    else{
        size_limit = cal_sl(s);
        ptr = new int[size_limit];
    }
}

CArray::CArray(CArray &a) {
    if (!a.ptr) {
        ptr = NULL;
        size = 0;
        size_limit = 1;
        return;
    }
    size_limit = cal_sl(a.size);
    ptr = new int[size_limit];
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
            size_limit = 1;
            return *this;
        }
    }

    if (size < a.size) {
        increase_size();
        if (ptr) {
            delete [] ptr;
        }
        ptr = new int[size_limit];
    }
    memcpy(ptr, a.ptr, sizeof(int) * a.size);
    size = a.size;
    return *this;
}

void CArray::push_back(int v)
{
    if (ptr) {
        if (size + 1 > size_limit) {
            increase_size();
        }
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

    for (int i = 0; i < 257; i++) {
        a4.push_back(i * 2);
    }

    for (int i = 0; i < a4.length(); i++) {
        cout << a4[i] << " ";
    }
    cout << endl;

    a4.printSizeLimit();

    return 0;
}
