#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stack>

using namespace std;

class Huffman_Tree
{
public:
	Huffman_Tree(){
		left = nullptr;
		right = nullptr;
		parent = 0;
	};
	Huffman_Tree(string file_name, int n);//概率文件路径，需要编码字符数，创建基础对象
	Huffman_Tree* build();//返回初始化后哈夫曼树的根节点，需用有参数的构造函数创建的对象调用，如果初始化失败将返回空指针
	string to_Huffman_code(string str = "");//传入str字符，返回编好的码
	string to_Word(string str = "");//传入哈夫曼码，传出译码字符
	void show(Huffman_Tree *t);//先序遍历,传入调用该函数对象的地址
	void show_Huffman_code();//显示哈夫曼码

private:
	void choose(Huffman_Tree* t, int n, int &num_1, int &num_2);
	void make_code(Huffman_Tree *root, Huffman_Tree *t, string s_codeing);
	bool Huffman_code();
	bool read_file(string file_name, int MAX);

private:
	Huffman_Tree    *left;
	Huffman_Tree    *right;
	pair<double, string> code;
	multimap<double, string> word;
	map<string, string> already_code;
	int parent;
};

#endif // HUFFMAN_TREE_H
