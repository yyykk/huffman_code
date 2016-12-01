#include "iostream"

#include "huffman_tree.h"

using namespace std;

int main(){
	Huffman_Tree *demo = new Huffman_Tree("probability_68.txt", 68);//创建对象
	
	if ((demo = demo->build()) == nullptr){//build返回完成初始化后的哈夫曼根结点，切记一定要检查返回的是否为空指针
		cout << "initialize error" << endl;
	}else{
		demo->show(demo);
		demo->show_Huffman_code();
		string word_2_code = demo->to_Huffman_code("abc");
		string code_2_word = demo->to_Word(word_2_code);
		cout << word_2_code << "\t" << code_2_word << endl;
	}
	system("pause");
}

