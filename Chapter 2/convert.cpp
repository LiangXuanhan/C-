// convert.cpp -- converts stone to pounds
#include <iostream>
int stonetolb(int);     // function prototype
int main()
{
    using namespace std;
    int stone;
    cout << "Enter the weight in stone: ";
    cin >> stone;
	while(cin.fail())//���cin���������⣬��ôcin����fail()�ͻ᷵���棬Ҳ����˵����ѭ����
{
//cin.clear();
cin.sync();//��λ��־������cin�е�����״ֵ̬������Ϊ��Ч״̬
cout<<"��������������붨����������Ͳ�ƥ�䣬����������";
cin.clear();//����ϴ�����
cin >> stone;//��������x
}
    int pounds = stonetolb(stone);
    cout << stone << " stone = ";
    cout << pounds << " pounds." << endl;
	 cin.get();
	 cin.get();
    return 0;
}

int stonetolb(int sts)
{
     return 14 * sts;
}
