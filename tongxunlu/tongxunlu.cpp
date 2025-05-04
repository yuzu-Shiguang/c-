// tongxunlu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;
#include <string>
#define max 1000


struct Person    //联系人结构体
{
	string m_name;
	int m_sex;  
	int m_age;
	string m_phone;
	string m_address;

};


struct addressbooks		//通讯录结构体  1 通讯录中保存的联系人个数  2 通讯录中当前记录的人数
{
	//1 定义了一个联系人结构体数组，通讯录中保存的联系人个数

	struct Person personarray[max];		
	
	//2 通讯录中当前记录的人数
	int m_size;							

};


// 1  添加联系人功能
void addperson(addressbooks* abs)
{
	//首先判断通讯录是否已满
	if (abs->m_size == max)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;

	}
	else
	{
		//此时未满，添加具体联系人信息
		string name;
		int sex;


		cout << "请输入联系人姓名" << endl;
		cin >> name;

		abs->personarray[abs->m_size].m_name = name;


		//添加性别
		cout << "请输入联系人性别" << endl;
		cout << "1  男" << endl;
		cout<<"2 女" << endl;
		 sex = 0;

		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[abs->m_size].m_sex = sex;
				break;
			}
			else
			{
				cout << "您输入有误，请重新输入" << endl;
			}
				
		}


		//输入联系人年龄
		cout << "请输入联系人年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personarray[abs->m_size].m_age = age;



		//联系电话
		cout << "请输入联系人电话" << endl;
		string phone;
		cin >> phone;
		abs->personarray[abs->m_size].m_phone = phone;


		//输入家庭住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personarray[abs->m_size].m_address = address;


		//最后更新通讯录人数
		abs->m_size++;
		cout << "操作成功" << endl;
		system("pause");//请按任意键继续
		system("cls");//清屏


	}

}


//显示联系人
void showperson(addressbooks * abs)
{
	//判断通讯录是否为空
	if (abs->m_size == 0)
	{
		cout << "当前通讯录为空" << endl;

	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "姓名" << abs->personarray[i].m_name << "\t";
			cout << "性别" <<( abs->personarray[i].m_sex == 1 ? "男":"女") << "\t";
			cout << "年龄" << abs->personarray[i].m_age << "\t";
			cout << "电话" << abs->personarray[i].m_phone << "\t";
			cout << "地址" << abs->personarray[i].m_address << endl;

		}

	}
	system("pause");
	system("cls");

}


//删除联系人
//首先判断是否存在该联系人
//若要创建判断联系人是否存在的函数.
// 则该函数参数1.在哪个通讯录中。 2.创建一个字符串参数存放名字进行比对

int isexist(addressbooks* abs,string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			cout << "该联系人存在" << endl;
			return i;

		}
	}
	return -1;

}

//删除指定联系人
void deleteperson(addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
	string name;
	cin >> name;
	//定义一个变量承接判断是否为空

	int ret = isexist(abs, name); 
	if (ret != -1)
	{
		//此时已查找到需要删除的联系人
		for (int i = ret; i < abs->m_size; i++)
		{
			//此时进行删除操作
			//删除可以看做后面的数据覆盖要删除的数据
			//并使数据依次前移

			abs->personarray[i] = abs->personarray[i + 1];

		}
		//此时已经删除需要删除的数据
		//所以通讯录数组长度减一
		abs->m_size--;
		cout << "删除成功" << endl;


	}
	else
	{
		cout << "查无此人" << endl;

	}
	system("pause");
	system("cls");


}

//4.查找指定联系人

void findperson(addressbooks* abs)
{
	cout << "请输入您所需查找的联系人" << endl;
	string name;
	cin >> name;
	/*
	 //自己编写的实现代码，可以正常使用
	for (int i = 0; i < abs->m_size;i++)
	{
		if (abs->personarray[i].m_name == name)
		{
			cout <<"姓名是" << abs->personarray[i].m_name << "\t";
			cout << "年龄是" << abs->personarray[i].m_age << "\t";
			cout << "性别是"<< abs->personarray[i].m_sex << "\t";
			cout << "姓名是" << abs->personarray[i].m_phone << endl;
		}
	}
	*/

	//讲解标准代码

	//判断是否存在于通讯录中
	int ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "姓名是" << abs->personarray[ret].m_name << "\t";
		cout << "性别是" << abs->personarray[ret].m_sex << "\t";
		cout << "年龄是" << abs->personarray[ret].m_age << "\t";
		cout << "年龄是" << abs->personarray[ret].m_phone << "\t";
		cout << "地址是" << abs->personarray[ret].m_address << endl;
	}
	else
	{
		cout << "查无此人" << endl;

	}
	
	system("pause");
	system("cls");

}


// 5.修改联系人
void modifyperson(addressbooks* abs)
{
	cout << "请输入您需要修改的联系人" << endl;
	string name;
	cin >> name;
	int  ret = isexist(abs, name);
	if (ret != -1)
	{
		cout << "已查找到您所需修改的联系人" << endl;
		//姓名
		cout << "请输入新的姓名" << endl;
		string name;
		cin >> name;

		abs->personarray[ret].m_name = name;

		//性别
		cout << "请输入新的性别" << endl;
		cout << "1-男" << endl;
		cout << "2-女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarray[ret].m_sex = sex;
				// 必须有退出循环的break语句
				break;

			}
			else
			{
				cout << "输入有误，请重新输入" << endl;

			}

		}
		

		//年龄
		 cout << "请输入新的年龄" << endl;
		 int age = 0;
		 cin >> age;
		 abs->personarray[ret].m_age = age;

		//电话
		 cout << "请输入新的电话" << endl;
		 string phone ;
		 cin >> phone;

		 abs->personarray[ret].m_phone = phone;

		//住址
		cout << "请输入新的住址" << endl;
		string address;
		cin >> address;


		abs->personarray[ret].m_address = address;
	}
	else
	{
		cout<<"查无此人" << endl;
	}
	system("pause");
	system("cls");

}


//6.清空联系人

void clearperson(addressbooks* abs)
{
	//此时应进行逻辑清空

	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
	system("pause");
	system("cls");

}

//菜单界面
void showmenu()
{
	cout << "***********************" << endl;
	cout << "     1 添加联系人     " << endl;
	cout << "     2 显示联系人     " << endl; 
	cout << "     3 删除联系人     " << endl;
	cout << "     4 查找联系人     " << endl;
	cout << "     5 修改联系人     " << endl;
	cout << "     6 清空联系人     " << endl;
	cout << "     0 退出通讯录     " << endl;
	cout << "*************************" << endl;

}

int main()
{

	//创建一个通讯录结构体
	 addressbooks abs;
	 //进行初始化
	 abs.m_size = 0;

	int selete = 0;

	while (true)
	{
		

		showmenu();//显示菜单
		cout << "请输入您需要做的操作" << endl;
		cin >> selete;
		switch (selete)
		{
		case 1:		//1 添加联系人 
			//创建一个用于添加联系人的函数
			addperson(&abs);	//使用地址传递才可以修饰实参，abs为创建的通讯录


			break;
		case 2:		//2 显示联系人 
			showperson(&abs);


			break;
		case 3:		//3 删除联系人 
		
		/*	cout << "请输入您需要删除的联系人姓名" << endl;
			string name;
			cin >> name;
			if (isexist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;

			}
			else
			{
				cout << "查无此人" << endl;

			}
		}*/

			deleteperson(&abs);


			break;
		case 4:		// 4 查找联系人

			findperson(&abs);

			break;
		case 5:		//5 修改联系人
			modifyperson(&abs);
			break;
		case 6:		//6 清空联系人
			clearperson(&abs);
			break;
		case 0:		//0 退出通讯录 
			system("pause");
			return 0;

			break;

		}

	}
	



	system("pause");
	return 0;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件


//ctrl + k + c  快捷多行注释
//ctrl + k + u  快捷取消多行注释
