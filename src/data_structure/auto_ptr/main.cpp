#include <iostream>
#include <memory>

using namespace std;

class Test{
public:
    Test(string s) {
        this->s = s;
        cout << "s = " << this->s << "!!!Test create" << endl;
    }
    ~Test() {
        cout << s << " delete"<< endl;
    }
    string& GetStr(){
        return s;
    }
    void SetStr(string s) {
        this->s = s;
    }
    void print() {
        cout << s << endl;
    }
private:
    string s;
};

unique_ptr<Test> fun() {
    return unique_ptr<Test>(new Test("789"));
}

int main()
{
    unique_ptr<Test> ptest1(new Test("123"));
    unique_ptr<Test> ptest2(new Test("456"));
    ptest2 = move(ptest1);
    cout << "-------------" << endl;
    if(ptest1 == NULL) {
        cout << "ptest1 is NULL" << endl;
    }
    Test*p = ptest2.release();
    ptest1.reset(p);
    ptest1->print();
    ptest2 = fun();
    ptest2->print();
    return 0;
}
