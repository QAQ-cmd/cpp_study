#include <iostream>
#include<string>
using namespace std;
#define MAX 100

// ��ϵ�˽ṹ��
struct Person
{
	string m_name;
	int m_sex;
	int m_age;
	string m_phone;
	string m_addr;
};

// ͨѶ¼�ṹ��
struct addressbooks
{
	struct Person personarry[MAX];
	int m_size;
};

// �˵�����
void ShowMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1. �����ϵ�� *****" << endl;
	cout << "***** 2. ��ʾ��ϵ�� *****" << endl;
	cout << "***** 3. ɾ����ϵ�� *****" << endl;
	cout << "***** 4. ������ϵ�� *****" << endl;
	cout << "***** 5. �޸���ϵ�� *****" << endl;
	cout << "***** 6. �����ϵ�� *****" << endl;
	cout << "***** 0. �˳�ͨѶ¼ *****" << endl;
	cout << "*************************" << endl;
}

void addperson(struct addressbooks * abs)
{
	if (abs->m_size == MAX)
	{
		cout << "ͨѶ¼������������" << endl;
		return;
	}
	string name;
	cout << "����������" << endl;
	cin >> name;
	abs->personarry[abs->m_size].m_name = name;

	int sex = 0;
	cout << "�����Ա�" << endl;
	cout << "1.��" << endl;
	cout << "2.Ů" << endl;
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
			cout << "���벻��" << endl;
		}
	}

	int age;
	cout << "�������䣺" << endl;
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
			cout << "���벻��" << endl;
			cout << "��������" << endl;
		}
	}

	string num;
	cout << "������ϵ�绰��" << endl;
	cin >> num;
	abs->personarry[abs->m_size].m_phone = num;

	string addr;
	cout << "������ϵ��ַ��" << endl;
	cin >> addr;
	abs->personarry[abs->m_size].m_addr = addr;

	cout << "��ӳɹ�" << endl;
	abs->m_size++;
	system("pause");
	system("cls");
	return;
}

void show(struct addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "��¼Ϊ��" << endl;
	}
	for (int i = 0; i < abs->m_size ; i++)
	{
		cout << "������" << abs->personarry[i].m_name << "\t";
		cout << "�Ա�" << ( abs->personarry[i].m_sex == 1 ?"��":"Ů" ) << "\t";
		cout << "���䣺" << abs->personarry[i].m_age << "\t";
		cout << "���룺" << abs->personarry[i].m_phone << "\t";
		cout << "��ַ��" << abs->personarry[i].m_addr << endl;
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
		cout << "ɾ���ɹ�" << endl;
	}
	else 
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
	return;
}

void modifyPerson(struct addressbooks* abs)
{
	int ret;
	cout << "������ҵ�������" << endl;
	string name;
	cin >> name;
	ret = isexist(abs, name);
	if ( ret == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		show(abs);
		int sex = 0;
		cout << "��������Ա�" << endl;
		cout << "1.��" << endl;
		cout << "2.Ů" << endl;
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
				cout << "���벻��" << endl;
			}
		}

		int age;
		cout << "����������䣺" << endl;
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
				cout << "���벻��" << endl;
				cout << "��������" << endl;
			}
		}

		string num;
		cout << "���������ϵ�绰��" << endl;
		cin >> num;
		abs->personarry[ret].m_phone = num;

		string addr;
		cout << "���������ϵ��ַ��" << endl;
		cin >> addr;
		abs->personarry[ret].m_addr = addr;
		cout << "�޸����" << endl;
		system("pause");
		system("cls");
	}

}

void cleanall(struct addressbooks* abs)
{
	abs->m_size = 0;
	cout << "�����" << endl;
	system("pause");
	system("cls");
}

// ������ 9825 4153
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
			cout << "����ɾ����������" << endl;
			string name;
			cin >> name;
			del(&abs, name);
			break;
		}
		case 4:
		{
			cout << "������ҵ�������" << endl;
			string name;
			cin >> name;

			if (isexist(&abs, name) == -1)
			{
				cout << "���޴���" << endl;
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
			cout << "��ӭ�´�ʹ��" << endl;
			return 0;
			break;

		default:
			break;
		}
	}



	return 0;
}