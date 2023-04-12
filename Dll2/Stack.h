

#include <string>

using namespace std;

class __declspec(dllimport) Stack {
private:
    int* array;
    int size;
    int topIndex;
public:
    Stack();
    ~Stack();
    void push(int element);
    int pop();
    int peek();
    bool isEmpty();
    void loadFromFile(string filename);
    void saveToFile(string filename);
};
