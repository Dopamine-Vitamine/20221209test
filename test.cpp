// #include <iostream>

// int main()
// {
//     using namespace std;
//     cout<<"good!"<<"hello my test program project codes!~"<<endl;
//     system("pause");
//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;
class A
{
private:
    int a = 5;
    vector<void(*)(int)> funcs;
public:
    void setA(int a_);
    void registerCallback(void(*p)(int));
};

void display(int a)
{
    cout << "a=" << a << endl;
}

int main()
{
    A a1;
    a1.registerCallback(display);
    int xx =0;
    while(cin>>xx){a1.setA(xx);}
    
    system("pause");
    return 0;
}

void A::setA(int a_)
{
    a = a_;
    for (int i = 0; i < funcs.size(); ++i) {
        funcs[i](a);
    }
}

void A::registerCallback(void(*p)(int))
{
    funcs.push_back(p);
}