// convert.cpp -- converts stone to pounds
#include <iostream>
int stonetolb(int);     // function prototype
int main()
{
    using namespace std;
    int stone;
    cout << "Enter the weight in stone: ";
    cin >> stone;
	while(cin.fail())//如果cin出现了问题，那么cin调用fail()就会返回真，也就是说进入循环中
{
//cin.clear();
cin.sync();//复位标志，将流cin中的所有状态值都重设为有效状态
cout<<"键入的数据类型与定义的数据类型不匹配，请重新输入";
cin.clear();//清空上次输入
cin >> stone;//重新输入x
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
