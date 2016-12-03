#include "iostream"

#include "huffman_tree.h"

using namespace std;

int main(){
	Huffman_Tree *demo = new Huffman_Tree("demo.txt");//��������
	if (demo  == nullptr){//build������ɳ�ʼ����Ĺ���������㣬�м�һ��Ҫ��鷵�ص��Ƿ�Ϊ��ָ��
		cout << "initialize error" << endl;
	}else{
		demo->show();
		demo->show_Huffman_code();
		string word_2_code = demo->to_Huffman_code();
		string code_2_word = demo->to_Word(word_2_code);
		cout << word_2_code << "\n" << code_2_word << endl;
	}
	delete demo;
	system("pause");
}

