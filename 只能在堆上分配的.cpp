

class A
{
public:
	A() {}
	void destrory()
	{
		delete this;
	}
protected:
	~A();
};

class B
{
private:
	void* operator new(size_t t){}
	void operator delete(void* ptr){}
public:
	B() {}
	~B() {}
};