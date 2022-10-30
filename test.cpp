#include <iostream>

using namespace std;

class A {
    private:
    int num;
    public:
    A(int number)
    {
        num = number;
    }
    void setNum(int number)
    {
        num = number;
    }
    int getNum()
    {
        return num;
    }


};

int main()
{
    A a(5);
    cout << a.getNum() << endl;
    a.setNum(9);
    cout << a.getNum() << endl;
    return 0;
}