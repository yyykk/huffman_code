#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

class Huffman_Tree
{
public:
	Huffman_Tree(){
		left = nullptr;
		right = nullptr;
		parent = 0;
	};
	Huffman_Tree(string file_name);//�����ļ�·������Ҫ�����ַ�����������������
	Huffman_Tree* build();//���س�ʼ������������ĸ��ڵ㣬�����в����Ĺ��캯�������Ķ�����ã������ʼ��ʧ�ܽ����ؿ�ָ��
	string to_Huffman_code(string str = "");//����str�ַ������ر�õ���
	string to_Word(string str = "");//����������룬���������ַ�
	int get_probability(string file_name);//��������ļ�
	void show();//�������,������øú�������ĵ�ַ
	void show_Huffman_code();//��ʾ��������

private:
	void choose(Huffman_Tree* t, int n, int &num_1, int &num_2);
	void make_code(Huffman_Tree *root, Huffman_Tree *t, string s_codeing);
	bool Huffman_code();
	bool read_file(string file_name, int MAX);
	void show_t(Huffman_Tree *p);

private:
	Huffman_Tree    *left;
	Huffman_Tree    *right;
	pair<double, string> code;
	multimap<double, string> word;
	map<string, string> already_code;
	string get_text;
	int parent;  
};

#endif // HUFFMAN_TREE_H
