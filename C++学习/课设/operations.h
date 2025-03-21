#pragma once
#include <sstream>
#include <vector>
#include <map>
#include <unordered_map>
#include <map>
#include <fstream>
#include <string>

#define MAXSIZE 100

// ��������
string operation;
bool ifsave = true;
bool ifbreak;

// ��������ý�������ŵ�����
std::unordered_map<std::string, disc> Disc_id_list;
std::unordered_map<std::string, book> Book_id_list;
std::unordered_map<std::string, drawing> Drawing_id_list;

// �����Լ���ű�������
std::map<int, int> ID_list;
std::unordered_map<std::string, std::vector<std::string>> Name_to_ID;

// ý����Ϣ��ʾ�б�
std::map<int, std::vector<std::string>> title = {{1, {"���", "����", "����", "����", "������", "����ʱ��", "��Ƶʱ��"}},
                                                 {2, {"���", "����", "����", "����", "������", "ISBN��", "��ҳ��"}},
                                                 {3, {"���", "����", "����", "����", "��������", "��(cm)", "��(cm)"}}};

std::map<int, std::string> guide = {{1, "----------------------------------------------- �� Ƶ �� �� ------------------------------------------------"},
                                    {2, "-------------------------------------------------- ��  �� --------------------------------------------------"}, 
                                    {3, "-------------------------------------------------- ͼ  �� --------------------------------------------------"},
                                    {4, "------------------------------------------------------------------------------------------------------------"}};

// ��Ϣ������ر���
std::stringstream information;
std::string tem;
std::vector<string> infor;

int type, Type;
string old_name;
string Name, Id;
double Len, Wid;
string oper;

//-----------����ҳ��-----------//

void Menu()
{
    std::cout << "[==================||ý������ϵͳ||==================]" << std::endl;
    std::cout << "[-----------------------||MENU||-----------------------]" << std::endl;
    std::cout << "|                     0. �˳�ϵͳ                      |" << std::endl;
    std::cout << "|                     1. �����Ϣ                      |" << std::endl;
    std::cout << "|                     2. �޸���Ϣ                      |" << std::endl;
    std::cout << "|                     3. ��ѯ��Ϣ                      |" << std::endl;
    std::cout << "|                     4. ��ʾ��Ϣ                      |" << std::endl;
    std::cout << "|                     5. ɾ����Ϣ                      |" << std::endl;
    std::cout << "|                     6. ͳ����Ϣ                      |" << std::endl;
    std::cout << "|                     7. ������Ϣ                      |" << std::endl;
    std::cout << "|                     8. ��ȡ��Ϣ                      |" << std::endl;
    std::cout << "[======================================================]" << std::endl;
}

//-----------������Ϣ-----------//

bool Input(int mode)
{
    infor.clear();
    information.clear();

    std::cout << "[  " << title[type][0] << ", " << title[type][1] << ", " << title[type][2] << ", " << title[type][3]
        << ", " << title[type][4] << ", " << title[type][5] << ", " << title[type][6] << "  ]" << std::endl;

    std::cin.sync();
    getline(std::cin, tem);
    information << tem;

    while (information >> tem) infor.push_back(tem);

    if (infor.size() != 7)
    {
        std::cout << std::endl;
        std::cout << "[            ������Ϣ�����������������룡            ]" << std::endl << std::endl;
        return false;
    }
    else if ((ID_list[stoi(infor[0])] && mode) || (!mode && ID_list[stoi(infor[0])] && infor[0] != Id))
    {
        std::cout << std::endl;
        std::cout << "[               ����Ѿ����ڣ����������룡              ]" << std::endl << std::endl;
        return false;
    }
    else if (infor[3] != "δ����" && infor[3] != "һ��" && infor[3] != "����" && infor[3] != "��ͯ")
    {
        std::cout << std::endl;
        std::cout << "[   ������Ϊ��δ������һ�㣬���ˣ���ͯ�����������룡   ]" << std::endl << std::endl;
        return false;
    }
    else
    {
    	ifsave = false;
    	return true;
	}

	return true;
}

//-----------�쳣����-----------//

bool Judge_StoD(string len, string wid)
{
    try
    {
        Len = stod(len);
        Wid = stod(wid);
    }
    catch (const std::exception&)
    {
        std::cout << std::endl << "[               ͼ���ĳߴ�����Ǹ�������               ]" << std::endl << std::endl;
        return false;
    }

    return true;
}

bool Judge_StoI(string tem)
{
    try 
    {
        for(int i = 0; i < tem.size(); i++)
        {
            if(!i && tem.size() > 1) continue;
            if(tem[i] < '0' || tem[i] > '9') throw 0;
        }
    }
    catch (int e)
    {
        if (!e) return false;
    }

    return true;
}

//-----------�����Ϣ-----------//

template <typename Media, typename A, typename B>
void Add_Each_Media(Media& m, string id, string title, string author, string rating, string other_1, A other_2, B other_3)
{
    m[id] = { id, title, author, rating, other_1, other_2, other_3 };
}

void Add_Media()
{
    if (MAXSIZE == ID_list.size())
    {
        std::cout << "[              ý�������������ɾ��ý�塣              ]" << std::endl << std::endl;
        return;
    }

    while (true)
    {
        std::cout << "��ѡ���������ý�����(1: ��Ƶ����, 2: �鼮, 3: ͼ��): ";
        std::cin.sync();
        std::getline(std::cin, oper);
        std::cout << std::endl;

        oper.erase(0, oper.find_first_not_of(' '));  // ɾ��ǰ���Ŀո�����������

        if (!Judge_StoI(oper) || oper == "") // ���ط���������
            std::cout << "[                ������Ϸ������������                ]" << std::endl << std::endl;
        else if (stoi(oper) > 3 || stoi(oper) < 1)  // ���ط�ΧԽ������
            std::cout << "[                ������Ϸ������������                ]" << std::endl << std::endl;
        else break;
    }

    type = stoi(oper);
    std::cout << "������ý��ĸ�����Ϣ��ÿ����Ϣ֮���ÿո����: " << std::endl;

    while (true)
        if (!Input(1)) continue;
        else
        {
            if (type== 1) Add_Each_Media(Disc_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], infor[5], infor[6]);
            if (type == 2) 
            {
                if (!Judge_StoI(infor[6])) 
                {
                    std::cout << std::endl << "[                �鼮��ҳ��������������                ]" << std::endl << std::endl;
                    continue;
                }
                else Add_Each_Media(Book_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], infor[5], stoi(infor[6]));
            }
            if (type == 3)
            {
                if (!Judge_StoD(infor[5], infor[6])) continue;
                Add_Each_Media(Drawing_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], Len, Wid);
            }

            break;
        }

    ID_list[stoi(infor[0])] = type;
    Name_to_ID[infor[1]].push_back(infor[0]);
    std::cout << std::endl << "[                    ý����ӳɹ���                    ]" << std::endl << std::endl;
}

//-----------�޸���Ϣ-----------//

template <typename Media, typename A, typename B>
void Update_Each_Media(Media& m, string id, string title, string author, string rating, string other_1, A other_2, B other_3)
{
    old_name = m[Id].title();
    m[Id].edit(id, title, author, rating, other_1, other_2, other_3);

    if (Id != id)
    {
        m[id] = m[Id];
        m.erase(Id);

        ID_list.erase(stoi(Id));
        ID_list[stoi(id)] = type;
    }
    else ID_list[stoi(id)] = type;

    if (title != old_name)
    {
        Name_to_ID[old_name].push_back(infor[0]);
        Name_to_ID[infor[1]] = Name_to_ID[old_name];
        Name_to_ID.erase(old_name);
    }
    else Name_to_ID[title].push_back(id);
}

void Update_Media()
{
    if (ID_list.size())
    {
        while (true)
        {
            std::cout << "�����������޸ĵ�ý���ţ�";
            std::cin.sync();
            std::getline(std::cin, Id);
            std::cout << std::endl;

            Id.erase(0, Id.find_first_not_of(' '));

            if (!Judge_StoI(Id) || Id == "") 
                std::cout << "[                  ������Ϸ��ı�ţ�                  ]" << std::endl << std::endl;
            else break;
        }

        if (!ID_list[stoi(Id)])   // ����ѯ�����ڵļ�ʱ��map���Զ�����һ��Ĭ��ֵ��ƥ����������ڵļ���
        {
            ID_list.erase(stoi(Id));
            std::cout << "[                 �����ڸñ�ŵ�ý�壡                 ]" << std::endl << std::endl;
        }
        else 
        {
            type = ID_list[stoi(Id)];
            std::cout << "��������µĸ���ý����Ϣ��ÿ����Ϣ֮���ÿո������" << std::endl;

            while (true)
                if (!Input(0)) continue;
                else
                {
                    if (type == 1) Update_Each_Media(Disc_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], infor[5], infor[6]);
                    if (type == 2) 
                    {
                        if (!Judge_StoI(infor[6])) 
                        {
                            std::cout << std::endl << "[                �鼮��ҳ��������������                ]" << std::endl << std::endl;
                            continue;
                        }
                        else Add_Each_Media(Book_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], infor[5], stoi(infor[6]));
                    }
                    if (type == 3)
                    {
                        if (!Judge_StoD(infor[5], infor[6])) continue;
                        Update_Each_Media(Drawing_id_list, infor[0], infor[1], infor[2], infor[3], infor[4], Len, Wid);
                    }

                    break;
                }

            std::cout << std::endl << "[                  ý����Ϣ�޸ĳɹ���                  ]" << std::endl << std::endl;
            ifsave = false;
        }
    }
    else std::cout << "[                    ��ǰý���Ϊ�գ�                  ]" << std::endl << std::endl;
}

//-----------��ѯ��Ϣ-----------//

template <typename Media>
void Search_Media_in_Type(Media m)
{
    using std::left;
    std::cout << std::endl << "�ҵ��ˣ�ý����Ϣ���£�" << std::endl << std::endl;
    std::cout << guide[Type] << std::endl;
    std::cout << left << std::setw(10) << title[Type][0] << left << std::setw(20) << title[Type][1] << left << std::setw(20)
                << left << title[Type][2] << left << std::setw(10) << title[Type][3] << left << std::setw(20) << title[Type][4]
                << left << std::setw(20) << title[Type][5] << left << std::setw(10) << title[Type][6] << std::endl;
    std::cout << guide[4] << std::endl;

    for (auto i = ID_list.begin(); i != ID_list.end(); i++) 
        if (i->second == Type) std::cout << m[std::to_string(i->first)] << std::endl;
}

template <typename Media>
void Search_Media_in_Title_or_Id(Media m)
{	
	using std::left;
    std::cout << guide[Type] << std::endl;
    std::cout << left << std::setw(10) << title[Type][0] << left << std::setw(20) << title[Type][1] << left 
	          << std::setw(20) << title[Type][2] << left << std::setw(10) << title[Type][3] << left << std::setw(20)
	          << title[Type][4] << left << std::setw(20) << title[Type][5] << left << std::setw(10) << title[Type][6] << std::endl;
    std::cout << guide[4] << std::endl;

    std::cout << m[Id] << std::endl << std::endl;
}

void Search_Media()
{
    if (ID_list.size())
    {
        while (true)
        {
            std::cout << "���������ַ�ʽ��ѯ(1: ������, 2: �����, 3: �����): ";
            std::cin.sync();
            std::getline(std::cin, oper);

            oper.erase(0, oper.find_first_not_of(' '));

            if(!Judge_StoI(oper) || oper == "") 
                std::cout << std::endl << "[                ������Ϸ������������                ]" << std::endl << std::endl;
            else if (stoi(oper) > 3 || stoi(oper) < 1) 
                std::cout << std::endl << "[                ������Ϸ������������                ]" << std::endl << std::endl;
            else break;
        }

        type = stoi(oper);

        if (type == 1)
        {
            std::cout << "�����������ѯ��ý����⣺";
            std::cin.sync();
			std::getline(std::cin, Name);

            if (!Name_to_ID[Name].size()) 
                std::cout << std::endl << "[                   �ñ��ⲻ���ڣ�                     ]" << std::endl;
            else
            {
                std::cout << std::endl << "�ҵ��ˣ�ý����Ϣ���£�" << std::endl << std::endl;

                for (int i = 0; i < Name_to_ID[Name].size(); i++)
                {
                    Type = ID_list[stoi(Name_to_ID[Name][i])];
                    Id = Name_to_ID[Name][i];

                    if (Type == 1) Search_Media_in_Title_or_Id(Disc_id_list);
                    if (Type == 2) Search_Media_in_Title_or_Id(Book_id_list);
                    if (Type == 3) Search_Media_in_Title_or_Id(Drawing_id_list);
                }
            }
        }
        else if (type == 2)
        {
            while (true)
            {
                std::cout << "�����������ѯ��ý���ţ�";
                std::cin.sync();
                std::getline(std::cin, Id);
                std::cout << std::endl;

                Id.erase(0, Id.find_first_not_of(' '));

                if (!Judge_StoI(Id) || Id == "") 
                    std::cout << "[                  ������Ϸ��ı�ţ�                  ]" << std::endl << std::endl;
                else break;
            }

            if (!ID_list[stoi(Id)]) 
            {
                ID_list.erase(stoi(Id));
                std::cout << "[                    �ñ�Ų����ڣ�                    ]" << std::endl;
            }
            else
            {
                std::cout << std::endl << "�ҵ��ˣ�ý����Ϣ���£�" << std::endl << std::endl;
                Type = ID_list[stoi(Id)];

                if (Type == 1) Search_Media_in_Title_or_Id(Disc_id_list);
                if (Type == 2) Search_Media_in_Title_or_Id(Book_id_list);
                if (Type == 3) Search_Media_in_Title_or_Id(Drawing_id_list);
            }
        }
        else
        {
            while (true)
            {
                std::cout << "�����������ѯ��ý�����(1: ��Ƶ����, 2: �鼮, 3: ͼ��): ";
                std::cin.sync();
                std::getline(std::cin, oper);

                oper.erase(0, oper.find_first_not_of(' '));

                if (!Judge_StoI(oper) || oper == "") 
                    std::cout << std::endl << "[                ������Ϸ������������                ]" << std::endl << std::endl;
                else if (stoi(oper) > 3 || stoi(oper) < 1) 
                    std::cout << std::endl << "[                ������Ϸ������������                ]" << std::endl << std::endl;
                else break;
            }

            Type = stoi(oper);

            if (Type == 1) 
            {
                if (!Disc_id_list.size()) std::cout << std::endl << "[                 ��Ƶ������û����Ʒ��                 ]" << std::endl;
                else Search_Media_in_Type(Disc_id_list);
            }
            if (Type == 2) 
            {
                if (!Book_id_list.size()) std::cout << std::endl << "[                   �鼮��û����Ʒ��                   ]" << std::endl;
                else Search_Media_in_Type(Book_id_list);
            }
            if (Type == 3) 
            {
                if (!Drawing_id_list.size()) std::cout << std::endl << "[                   ͼ����û����Ʒ��                   ]" << std::endl;
                else Search_Media_in_Type(Drawing_id_list);
            }
        }

        std::cout << std::endl;
    }
    else std::cout << "[                    ��ǰý���Ϊ�գ�                  ]" << std::endl << std::endl;
}

//-----------չʾ��Ϣ-----------//

template <typename Media>
void Show_Each_Type(Media m, int type)
{
	using std::left;
    std::cout << guide[type] << std::endl;
    std::cout << left << std::setw(10) << title[type][0] << left << std::setw(20) << title[type][1] << left << std::setw(20) << left
	<< title[type][2] << left << std::setw(10) << title[type][3] << left << std::setw(20) << title[type][4] << left
	<< std::setw(20) << title[type][5] << left << std::setw(10) << title[type][6] << std::endl;
    std::cout << guide[4] << std::endl;         

    for (auto i = ID_list.begin(); i != ID_list.end(); i++)
        if (i->second == type) std::cout << m[std::to_string(i->first)] << std::endl;

    std::cout << std::endl;
}

void Show_Media()
{
    if (ID_list.size())
    {
        std::cout << "������ý���������ý�����Ϣ��" << std::endl << std::endl;
        if (Disc_id_list.size()) Show_Each_Type(Disc_id_list, 1);
        if (Book_id_list.size()) Show_Each_Type(Book_id_list, 2);
        if (Drawing_id_list.size()) Show_Each_Type(Drawing_id_list, 3);
    }
    else std::cout << "[                    ��ǰý���Ϊ�գ�                  ]" << std::endl << std::endl;
}

//-----------ɾ����Ϣ-----------//

template <typename Media>
void Delete_Each_Media(Media& m)
{
    Name = m[Id].title();
    m.erase(Id);
}

void Delete_Media()
{
    if (ID_list.size())
    {
        while (true)
        {
            std::cout << "����������ɾ����ý���ţ�";
            std::cin.sync();
            std::getline(std::cin, Id);

            Id.erase(0, Id.find_first_not_of(' '));

            if (!Judge_StoI(Id) || Id == "") 
                std::cout << std::endl << "[                  ������Ϸ��ı�ţ�                  ]" << std::endl << std::endl;
            else break;
        }

        if (!ID_list[stoi(Id)]) 
        {
            ID_list.erase(stoi(Id));
            std::cout << std::endl << "[                    �ñ�Ų����ڣ�                    ]" << std::endl << std::endl;
        }
        else 
        {
            type = ID_list[stoi(Id)];

            if (type == 1) Delete_Each_Media(Disc_id_list);
            if (type == 2) Delete_Each_Media(Book_id_list);
            if (type == 3) Delete_Each_Media(Drawing_id_list);

            ID_list.erase(stoi(Id));
            for (auto i = Name_to_ID[Name].begin(); i != Name_to_ID[Name].end(); i++)
                if (*i == Id)
                {
                    Name_to_ID[Name].erase(i);
                    break;
                }

            std::cout << std::endl << "[                      ɾ���ɹ���                      ]" << std::endl << std::endl;
            ifsave = false;
        }
    }
    else std::cout << "[                    ��ǰý���Ϊ�գ�                  ]" << std::endl << std::endl;
}

//-----------ͳ����Ϣ-----------//

void Count_Media()
{
    std::cout << "��ǰý�����ý����Ϊ��" << ID_list.size() << std::endl;
    std::cout << "��ǰý�������Ƶ������ý����Ϊ��" << Disc_id_list.size() << std::endl;
    std::cout << "��ǰý������鼮��ý����Ϊ��" << Book_id_list.size() << std::endl;
    std::cout << "��ǰý�����ͼ����ý����Ϊ��" << Drawing_id_list.size() << std::endl << std::endl;
}

//-----------������Ϣ-----------//

template <typename Media>
void writeMapToFile(Media m, const std::string& filename, int type, int mode)
{
    std::ofstream outFile(filename);

    if (outFile.is_open())
	{
        for (auto i = ID_list.begin(); i != ID_list.end(); i++)
            if (i->second == type) outFile << m[std::to_string(i->first)] << std::endl;

        outFile.close();
        if (mode) std::cout << "[                      ����ɹ���                      ]" << std::endl << std::endl;
    } 
    else std::cout << "[           δ�ܳɹ����ļ����������ԭ��           ]" << std::endl << std::endl;
}

void Save_Media()
{
    std::cout << "��ʼ������Ƶ������ý����Ϣ..." << std::endl << std::endl;
	writeMapToFile(Disc_id_list, "data/Disc.txt", 1, 1);
    std::cout << "��ʼ�����鼮��ý����Ϣ..." << std::endl << std::endl;
	writeMapToFile(Book_id_list, "data/Book.txt", 2, 1);
    std::cout << "��ʼ����ͼ����ý����Ϣ..." << std::endl << std::endl;
	writeMapToFile(Drawing_id_list, "data/Drawing.txt", 3, 1);
}

//-----------��ȡ��Ϣ-----------//

void readLinesAndSplit(const std::string& filename, int type)
{
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        std::string line;

        while (std::getline(inFile, line)) {
        	if(!line.size())continue;
            std::istringstream iss(line);
            std::vector<std::string> tokens;

            // ʹ�ÿո���Ϊ�ָ�����ÿ�����ݴ�������
            std::string token;
            iss >> std::ws;
            while (iss >> token) tokens.push_back(token);

            if (type == 1) Add_Each_Media(Disc_id_list, tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], tokens[6]);
            if (type == 2) Add_Each_Media(Book_id_list, tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], tokens[5], stoi(tokens[6]));
            if (type == 3) Add_Each_Media(Drawing_id_list, tokens[0], tokens[1], tokens[2], tokens[3], tokens[4], stod(tokens[5]), stod(tokens[6]));

            ID_list[stoi(tokens[0])] = type;
    		Name_to_ID[tokens[1]].push_back(tokens[0]);
        }

        inFile.close();
        ifsave = false;
        std::cout << "[                      ��ȡ�ɹ���                      ]" << std::endl << std::endl;
    } 
    else std::cout << "[           δ�ܳɹ����ļ����������ԭ��           ]" << std::endl << std::endl;
}

void Read_Media()
{
    Disc_id_list.clear();
    Book_id_list.clear();
    Drawing_id_list.clear();
    ID_list.clear();
    Name_to_ID.clear();

    std::cout << "��ʼ������Ƶ������ý����Ϣ..." << std::endl << std::endl;
	readLinesAndSplit("data/Disc.txt", 1);
    writeMapToFile(Disc_id_list, "data/backup/Disc.txt", 1, 0);
    std::cout << "��ʼ�����鼮��ý����Ϣ..." << std::endl << std::endl;
	readLinesAndSplit("data/Book.txt", 2);
    writeMapToFile(Book_id_list, "data/backup/Book.txt", 2, 0);
    std::cout << "��ʼ����ͼ����ý����Ϣ..." << std::endl << std::endl;
	readLinesAndSplit("data/Drawing.txt", 3);
    writeMapToFile(Drawing_id_list, "data/backup/Drawing.txt", 3, 0);
}