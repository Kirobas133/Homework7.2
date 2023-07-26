
#include <iostream>

template <class T>
class DoubleTable {
private:
    T** elems = nullptr;
    int v = 0;
    int g = 0;
public:
    DoubleTable(int a, int b)
        : elems(new T*[a]), v(a), g(b) {
        for (int i = 0; i < a; i++) {
            elems[i] = new T[b];
    }
    }
    ~DoubleTable() {
        for (int i = 0; i < v; i++) {
            delete[] elems[i];
        }
        delete[] elems;
    }
    const int Size() const {
        return v * g;
    }
    const T* operator [] (int num1) const{
        return elems[num1];
    }
    T* operator [] (int num2) {
        return elems[num2];
    }
};

int main()
{
    auto test = DoubleTable <int>(2, 3);
    test[0][0] = 4;
    std::cout << test[0][0]; // выводит 4
}