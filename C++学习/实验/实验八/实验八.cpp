#include <iostream>
#include <fstream>

using namespace std;

struct student 
{
    int no;
    char name[20];
    double score;
};

int main ()
{
    student stu1 = {1001, "С��", 99.7};
    student stu2 = {1002, "С��", 45.6};
    student stu3 = {1003, "С��", 87.3};

    ofstream file;
    file.open("./test.dat", ios_base::binary);
    file.write((char *) &stu1, sizeof(stu1));
    file.write((char *) &stu2, sizeof(stu2));
    file.write((char *) &stu3, sizeof(stu3));

    file.close();

    ifstream File("./test.dat", ios_base::binary);
    student stu;
    for (int i = 1; i <= 3; i++)
    {
        File.read((char *) &stu, sizeof(stu));
        cout << "��ţ�" << stu.no << " ������" << stu.name << " ������" << stu.score << endl;
    }

    File.close();

    fstream filee("./test.dat", ios_base::binary);
    filee.seekg(sizeof(stu));
    filee.write((char *) &stu3, sizeof(stu3));  // ���ɾ����Ϣ
    filee.close();

    File.open("./test.dat", ios_base::binary);

    cout << "ɾ���ڶ�����Ϣ��" << endl;

    for (int i = 1; i <= 2; i++)
    {
        File.read((char *) &stu, sizeof(stu));
        cout << "��ţ�" << stu.no << " ������" << stu.name << " ������" << stu.score << endl;
    }

    File.close();

    filee.open("./test.dat", ios_base::binary);

    int x;
    cout << "�����������ѯ����Ϣ��ţ�";
    cin >> x;

    filee.seekg((x - 1) * sizeof(stu));  // �ظ�ָ��
    filee.read((char *) &stu, sizeof(stu));
    cout << "��" << x << "����ϢΪ��" << endl;
    cout << "��ţ�" << stu.no << " ������" << stu.name << " ������" << stu.score << endl;

    filee.close();

    return 0;
}