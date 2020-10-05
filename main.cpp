// ���������� STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

//#include "stdafx.h"
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <iostream>
#include "Point.h"

#define pairStrStr std::pair<std::string, std::string>

#define stop __asm nop

struct MyPred
{
	bool operator()(const char* chl, const char* chr) const
		{
			return (0 < strcmp(chl, chr));
		}
};
//�������� ������ ������� ��� ������ �������� stack, queue, priority_queue
//�������� �������� �� ��, ��� ���������� ������������� ������ ������ ��� 
//��������� ��������


template<typename T>
const typename T::value_type& MyTop(const T& cont)
{
	return cont.top();
}

template<typename T, typename B>
const T& MyTop(const std::queue<T, B> &q)
{
	return q.front();
}

template <typename T> 
void printAdCon(T cont)
{
	while (!cont.empty())
	{
		//std::cout << cont.top() <<' ';
		std::cout << MyTop(cont) << ' ';
		cont.pop();
	}
	std::cout << '\n';
}



//template <typename T>
//void printAdCon(std::queue <T> cont)
//{
//	while (!cont.empty())
//	{
//		std::cout << cont.front() << ' ';
//		cont.pop();
//	}
//	std::cout << '\n';
//}


template <typename T>
void printConteiner(const T& cont)
{
	std::cout << typeid(cont).name() << " :\n";
	for (typename T::const_iterator it = cont.begin(); it != cont.end(); ++it)
	{
		std::cout << *it << ' ';
	}
	std::cout << '\n';
}

template<typename T, typename B>
void printMap(const std::map<T, B> &m)
{
	typename std::map<T, B>::const_iterator itM = m.cbegin();	//������ ���������� ������������

	while (itM != m.cend())
	{
		std::cout << itM->first << ' ' << itM->second << '\n';
		++itM;
	}
}
	

int main(int argc, char* argv[])
{
	setlocale(0, "");


	{
		std::stack <int> s;
		s.push(2);
		s.push(3);
		s.push(4);
		s.push(1);
		printAdCon(s);

		std::queue <int> q;
		q.push(15);
		q.push(41);
		q.push(58);
		q.push(51);
		printAdCon(q);

		std::queue <int, std::list<int>> q1;
		printAdCon(q1);

		std::priority_queue <int> pq;
		pq.push(1125);
		pq.push(4311);
		pq.push(5528);
		pq.push(5112);
		printAdCon(pq);
	}



	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//�������� ���� ����� �������, �����
	//�) �������� ����� ����� ������� ��������� �������
	//�) ��� ������ �������� ��� �������, ��� � ����� ������� �������� ��� ���������� 

	{
		std::vector<int> v;
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(1);

		
		std::stack<int, std::vector<int>> s(std::vector<int>(v.rbegin(),v.rend())); 


		std::cout << '\n';
	}





	////////////////////////////////////////////////////////////////////////////////////
	//queue

	//�������� �������, ������� �������� ��������� �� ������� ���� Point,
	//��� ���� ���� ������� ������� ���������.
	//�������� �������� ������� � ���������� ��������� ����������� front() � back()
	//���������, ��� ��������� ������� ��� ����������� ����� �������?


	{
		std::queue<Point*, std::deque<Point*>> qPp;
		qPp.push(new Point(1, 1));
		qPp.push(new Point(2, 4));
		qPp.push(new Point(1, 5));
		qPp.push(new Point(7, 2));

		//delete qPp.front();
		//qPp.front()=nullptr;
		*qPp.front() =  Point(2, 4);

		delete qPp.back();
		qPp.back()=nullptr;
		qPp.back() = new Point(2, 4);

		while (!qPp.empty())
		{
			delete qPp.back();
			qPp.back() = nullptr;
			qPp.pop();
		}
	}





	////////////////////////////////////////////////////////////////////////////////////
	//priority_queue
	//�) �������� ������� � ������������, ������� ����� ������� ������ ��������� ��������� - const char*
	//�) ������������������ ������� ��� �������� � ������� ���������������� ������� � ���������� const char*
	//�) ��������� "���������������" �������� (� ������� pop() ) - ���� ��� ����������� �� ��������������, ���������:
	//		��� ������������ ��� �������?




	{
		const char* ar[]= {"AOne", "BTwo", "CThree"};
		std::priority_queue <const char*, std::vector<const char*>, MyPred> pq(ar, ar+sizeof(ar)/sizeof(ar[0])); //�� ���������� ������ ��� ������������ �������� ������

		printAdCon(pq);
	}




	////////////////////////////////////////////////////////////////////////////////////
	//set
	//a) �������� ��������� � ���������� ���� Point - ���������, ��� ���������� ����������
	//		� ������ Point (� ����� �������)
	//�) ������������ �������� ��������� � ������� �������, �������������� � ���������� ���. ������
	//�) ���������� �������� ����� ��������...
	//�) �������� ��� ���������, ������� ����� ��������� ���������� ��������
	//		���� int, �� ���������� � ������ �������
	//�) �������� � ����� ��������� �������� ��������� �� ������ �������
	//	����������, ��������, ��������� �������	(��� ����������, ���� � ������� ������� �����?)


	{
		std::set <Point> s;
		s.insert(Point(2, 3));
		s.insert(Point(4, 5));
		s.insert(Point(6, 7));
		s.insert(Point(8, 9));
		printConteiner(s);
		//*(s.begin()) = Point(2, 0);


		std::set <int> s1;
		s1.insert(3);
		s1.insert(5);
		s1.insert(7);
		s1.insert(9);

		std::set <int> s2;
		s2.insert(9);
		s2.insert(7);
		s2.insert(5);
		s2.insert(3);

		//s1 == s2; (�������� ������ � ���������� ������� ���������)
		std::set <int> s3;
		int ar[] = { 1,7, 3, 14, 42,7,3 };

		s3.insert(ar, ar + sizeof(ar) / sizeof(ar[0]));	//����� ������������
	}






	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//�) �������� map, ������� ������ ���� "�������, ��������" - pair<const char*, int>,
	//	��� ���� ������ �������� ���������� ����������
	//�) ��������� ��������� ���������� ����������� operator[] � insert()
	//�) ������������ ����������

	//�) �������� ���� �� ������ �� ����� (���� "�������", ����� ����� => ����� "�������")
	{
		std::map<const char*, int> m;
		m["AIvanov"] = 1231;
		m["BPetrov"] = 5232;
		m["CSidorov"] = 2511;

		m.insert(m.begin(), std::pair<const char*, int>("Volkov", 1233));

		std::map<const char*, int, MyPred>::const_iterator it = m.cbegin();	//������ ���������� ������������

		while (it != m.cend())
		{
			std::cout << it->first<<' ' << it->second <<'\n';
			++it;
		}

		int tmp = m["AIvanov"];
		if (m.erase("AIvanov"))
		{
			m["HOrlov"] = tmp;
		}

	}
	stop




		//�) ����������� ����� �������� ������ � ���������� ���� string.
		//�������� (� ������������ ��� ��������) map<string, int>, ������� �����
		//��������� ������������� �� �������� ������ �
		//���������� ���������� ������ ������ � �������

	{
		std::vector<std::string> vs;
		vs.push_back(std::string("ZZZ"));
		vs.push_back(std::string("XXX"));
		vs.push_back(std::string("AAA"));
		vs.push_back(std::string("BBB"));
		vs.push_back(std::string("BBB"));

		std::map<std::string, int> m;

		std::vector<std::string>::const_iterator it = vs.cbegin();

		while (it != vs.cend())
		{
			++m[*it];
			++it;
		}

		printMap(m);
		
	}



		//�) 
		//����� ������:
		//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
		//�������� map, � ������� ������ ����� ����� ��������������� ������������ 
		//��������������� ������������� ����, ������������ � ���� �����.
		//���������: �� ����� ������� ����� ����� � ��� �� ������

		//'A' -  "Abba" "Alfa"
		//'B' -  "Beauty" "Beta"  ...
		//...
	{
		const char* words[] = { "Abba", "Alfa", "Beta", "Beauty" , "Center", "Carry"};
		std::map <char, std::set<std::string>> m;
		for (int i = 0; i < sizeof(words) / sizeof(words[0]); i++)
		{
			m[words[i][0]].insert(words[i]);
		}

		for (std::map<char, std::set<std::string>>::const_iterator it = m.cbegin(); it != m.cend(); ++it)
		{
			std::cout << it->first << " : ";
			for (std::set<std::string>::const_iterator it2 = it->second.cbegin(); it2 != it->second.cend(); ++it2)
			{
				std::cout << *it2 << ' ';
			}
			std::cout << '\n';
		}
		stop
	}


		//�)
		//�������� ��������� ������, ������� ����� ������� ���������� � ������������ �������.
		//��� ������ ������ ������ �������� ������� ��������� (�� ��������). ��� ���� 
		//������� ����� �������������
		//���� ������ ���� ������ ���� ����������� �� ������
		//
		//������ 
	{
		std::map<unsigned int, std::multiset<const char*, MyPred>> m;

		m[1244].insert({"Ivanov", "Petrov", "Sidorov", "Ivanov"});
		m[1245].insert({"Orlov", "Vorobiev", "Sorokin"});
		m[1130].insert({"Volkov", "Zaicev", "Medvedev"});

		for (std::map<unsigned int, std::multiset<const char*, MyPred>>::const_iterator it = m.cbegin(); it != m.cend(); ++it)
		{
			std::cout << it->first << " : ";
			for (std::multiset<const char*>::const_iterator it2 = it->second.cbegin(); it2 != it->second.cend(); ++it2)
			{
				std::cout << *it2 << ' ';
			}
			std::cout << '\n';
		}
	}




	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//�) �������� "�����-�������" �������, ��� ������ � ���� �� ����� ����� ���������������
	//		��������� ������� �������� - pair<string,string>, ��������: strange: �����, ��������...
	//�) ��������� ������� ������ � ������� ������ insert ��� ������������������ � ������� 
	//		���������������� ������� ���� (���� ����� �������������� ��� ��������� � ������� ������� make_pair)
	//�) �������� ��� ���������� ������� �� �����


	{

		std::multimap<std::string, std::string> m;
		m.insert(pairStrStr("strange", "�����"));
		m.insert(pairStrStr("strange", "��������"));
		m.insert(pairStrStr("sickness", "�������"));
		m.insert(pairStrStr("sickness", "�������"));
		m.insert(pairStrStr("nice", "�������"));
		m.insert(pairStrStr("nice", "�������"));

		for (auto it = m.begin(); it != m.end(); ++it)
		{
			std::cout << it->first << ": " << it->second << '\n';
		}

		//�) �������� �� ����� ������ �������� "���������" ��� ��������� �����. ���������: ��� ���������� ���������
		//   ���������� ����� ������������ ������ lower_bound() � upper_bound()

		std::string str = "sickness";
		std::cout << '\n' << str << ": ";
		for (auto it = m.lower_bound(str); it != m.upper_bound(str); ++it)
		{
			std::cout << it->second <<"; ";
		}

	}

		stop
		return 0;
}