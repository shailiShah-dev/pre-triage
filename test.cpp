#include <iostream>
using namespace std;
struct Base {
	int m_v;
	Base(int v=0):m_v(v){}
	void display()const { cout << "B" << m_v; }
};
struct Derived: public Base
{
	int m_x;
	Derived(int x=1):Base(x+1),m_x(x){}
	void display()const { cout << "D" << m_x; }
};

int main() {
	Base* b[3] = { new Derived(0), new Base, new Derived() };
	for (int i = 0; i < 3; i++) {
		b[i]->display();
		delete b[i];
	}
	return 0;
}
