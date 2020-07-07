const int typed=0;
const int typei=1;
class temps{
public:
	virtual temps* add(*temps A,*temps B)const=0;
	virtual temps* substract(*temps A,*temps B)const=0;
	virtual temps* multiply(*temps A,*temps B)const=0;
	virtual temps* divide(*temps A,*temps B)const=0;
	virtual temps* v()const=0;
	virtual temps* inv()const=0;
	virtual int type()const=0;
};
