#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

class String {
public:
    String() : datas{ new char[capacity] }, size{ 0 } {
        datas[0] = '\0';
    }

    ~String() {
        delete[]datas;
    }

    void pop_back() {
        if (size > 0) {
            --size;
            datas[size] = '\0';
        }
    }

    String& operator+=(const char* str) {
        size_t len = strlen(str);
        if (size + len < capacity) {
            strcpy(datas + size, str);
            size += len;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& out, const String& str) {
        out << str.datas;
        return out;
    }

private:
    static const size_t capacity = 100;
    char* datas;
    size_t size;
};

int main() {
    String myString;
    myString += "Hello, ";
    myString += "I Artem!";

    cout << myString << endl;

    myString.pop_back();
    cout << "pop_back: " << myString << endl;
}
