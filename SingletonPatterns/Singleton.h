#pragma once
#include <iostream>

using namespace std;

// ���� - ����ʽ/����ʽ����
class Singleton
{
public:
	static Singleton* GetInstance();

private:
	Singleton() {}  // ���캯������������

private:
	static Singleton* m_pSingleton;  // ָ���������ָ��

	// GC ����
	class GC
	{
	public:
		~GC()
		{
			// �����������������е���Դ�����磺db ���ӡ��ļ������
			if (m_pSingleton != NULL) {
				cout << "Here destroy the m_pSingleton..." << endl;
				delete m_pSingleton;
				m_pSingleton = NULL;
			}
		}
		static GC gc;  // �����ͷŵ���
	};
};

