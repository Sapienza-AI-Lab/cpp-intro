#include <iostream> // we will discover this later

using namespace std; // we will discover this later

struct VecF {
    int size;
    float *v;

    float get(int i) { return v[i]; }

    void set(int i, float f) { v[i] = f; }

    VecF() {
        size = 0;
        v = nullptr;
    }

    VecF(int size) {
        this->size = size;
        v = new float[size];
    }

    VecF(const VecF &other) {
        size = 0;
        v = 0;
        if (!other.size) return;
        size = other.size;
        v = new float[size];
        for (int i = 0; i < size; ++i)
            v[i] = other.v[i];
    }

    ~VecF() { if (size) delete[] v; }

    VecF &operator=(const VecF &other) {
        if (size) delete[] v;
        size = 0;
        v = 0;
        if (!other.size) return *this;
        size = other.size;
        v = new float[size];
        for (int i = 0; i < size; ++i)
            v[i] = other.v[i];
        return *this;
    }

    string print() {
        string s = "[";
        for (int i = 0; i < size; ++i) {
            s += to_string(v[i]);
            if (i < size - 1) s += ", ";
        }
        s += "]";
        return s;
    }
};


int main(int argc, char **argv) {
    cout << "VecF v5(5)" << endl;
    VecF v5(5);
    cout << "V5 content: " << v5.print() << endl;
    cout << "v5.set(0, 0.1)" << endl;
    v5.set(0, 0.1);
    cout << "V5 content: " << v5.print() << endl;
    cout << "v5.set(1, 0.2)" << endl;
    v5.set(1, 0.2);
    cout << "V5 content: " << v5.print() << endl;

    cout << "VecF v7(v5)" << endl;
    VecF v7(v5); //(copy ctor)
    cout << "v7.set(2, 0.3)" << endl;
    v7.set(2, 0.3);
    cout << "V7 content: " << v7.print() << endl;
    cout << "v8 = v5" << endl;
    VecF v8 = v5;  //(copy ctor)
    cout << "V8 content: " << v8.print() << endl;
    cout << "v8 = v7" << endl;
    v8 = v7;       // op=
    cout << "V8 content: " << v8.print() << endl;
    cout << "v8.set(3, 0.4)" << endl;
    v8.set(3, 0.4);
    cout << "V8 content: " << v8.print() << endl;
    cout << "V7 content: " << v7.print() << endl;
    cout << "V5 content: " << v5.print() << endl;
}
