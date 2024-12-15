#include <iostream>
#include<string>
using namespace std;
#define MAX 100

// 联系人结构体
struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};

// 通讯录结构体
struct addressbooks
{
	struct Person personarry[MAX];
	int m_size;
};

// 菜单界面
void ShowMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1. 添加联系人 *****" << endl;
	cout << "***** 2. 显示联系人 *****" << endl;
	cout << "***** 3. 删除联系人 *****" << endl;
	cout << "***** 4. 查找联系人 *****" << endl;
	cout << "***** 5. 修改联系人 *****" << endl;
	cout << "***** 6. 清空联系人 *****" << endl;
	cout << "***** 0. 退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

void addperson(struct addressbooks * abs)
{
	if (abs->m_size == MAX)
	{
		cout << "通讯录已满。。。。" << endl;
		return;
	}
	string name;
	cout << "输入姓名：" << endl;
	cin >> name;
	abs->personarry[abs->m_size].m_name = name;

	int sex = 0;
	cout << "输入性别：" << endl;
	cout << "1.男" << endl;
	cout << "2.女" << endl;
	while (true)
	{
		cin >> sex;
		if (sex == 1 || sex == 2)
		{
			abs->personarry[abs->m_size].m_sex = sex;
			break;
		}
		else
		{
			cout << "输入不对" << endl;
		}
	}

	int age;
	cout << "输入年龄：" << endl;
	age = 0;
	while (true)
	{
		cin >> age;
		if (age > 0 && age <= 200)
		{
			abs->personarry[abs->m_size].m_age = age;
			break;
		}
		else
		{
			cout << "输入不对" << endl;
			cout << "重新输入" << endl;
		}
	}

	string num;
	cout << "输入联系电话：" << endl;
	cin >> num;
	abs->personarry[abs->m_size].m_phone = num;

	string addr;
	cout << "输入联系地址：" << endl;
	cin >> addr;
	abs->personarry[abs->m_size].m_addr = addr;

	cout << "添加成功" << endl;
	abs->m_size++;
	system("pause");
	system("cls");
	return;
}

void show(struct addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "记录为空" << endl;
	}
	for (int i = 0; i < abs->m_size ; i++)
	{
		cout << "姓名：" << abs->personarry[i].m_name << "\t";
		cout << "性别：" << ( abs->personarry[i].m_sex == 1 ?"男":"女" ) << "\t";
		cout << "年龄：" << abs->personarry[i].m_age << "\t";
		cout << "号码：" << abs->personarry[i].m_phone << "\t";
		cout << "地址：" << abs->personarry[i].m_addr << endl;
	}
	system("pause");
	system("cls");
}

int isexist( struct addressbooks* abs, string name )
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personarry[i].m_name == name)
		{
			return i;
		}
		return -1;
	}
}

void del(struct addressbooks* abs, string name)
{
	int ret;

	ret = isexist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personarry[i] = abs->personarry[i + 1];
		}
		abs->m_size--;
		cout << "删除成功" << endl;
	}
	else 
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
	return;
}

void modifyPerson(struct addressbooks* abs)
{
	int ret;
	cout << "输入查找的姓名：" << endl;
	string name;
	cin >> name;
	ret = isexist(abs, name);
	if ( ret == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		show(abs);
		int sex = 0;
		cout << "输入更新性别：" << endl;
		cout << "1.男" << endl;
		cout << "2.女" << endl;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personarry[ret].m_sex = sex;
				break;
			}
			else
			{
				cout << "输入不对" << endl;
			}
		}

		int age;
		cout << "输入更新年龄：" << endl;
		age = 0;
		while (true)
		{
			cin >> age;
			if (age > 0 && age <= 200)
			{
				abs->personarry[ret].m_age = age;
				break;
			}
			else
			{
				cout << "输入不对" << endl;
				cout << "重新输入" << endl;
			}
		}

		string num;
		cout << "输入更新联系电话：" << endl;
		cin >> num;
		abs->personarry[ret].m_phone = num;

		string addr;
		cout << "输入更新联系地址：" << endl;
		cin >> addr;
		abs->personarry[ret].m_addr = addr;
		cout << "修改完成" << endl;
		system("pause");
		system("cls");
	}

}

void cleanall(struct addressbooks* abs)
{
	abs->m_size = 0;
	cout << "已清空" << endl;
	system("pause");
	system("cls");
}

// 主函数 9825 4153
int main()
{
	struct addressbooks abs;
	int select;

	abs.m_size = 0;

	while (true)
	{

		ShowMenu();

		cin >> select;

		switch (select)
		{
		case 1:
			addperson(&abs);
			break;

		case 2:
			show(&abs);
			break;

		case 3:
		{
			cout << "输入删除的姓名：" << endl;
			string name;
			cin >> name;
			del(&abs, name);
			break;
		}
		case 4:
		{
			cout << "输入查找的姓名：" << endl;
			string name;
			cin >> name;

			if (isexist(&abs, name) == -1)
			{
				cout << "查无此人" << endl;
			}
			else
			{
				show(&abs);
			}
			break;
		}
		case 5:
			modifyPerson(&abs);
			break;

		case 6:
			cleanall(&abs);
			break;

		case 0:
			cout << "欢迎下次使用" << endl;
			return 0;
			break;

		default:
			break;
		}
	}



	return 0;
}