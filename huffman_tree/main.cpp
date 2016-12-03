#include "iostream"

#include "huffman_tree.h"

using namespace std;

int main(){
	Huffman_Tree *demo = new Huffman_Tree("demo.txt");//创建对象
	if (demo  == nullptr){//build返回完成初始化后的哈夫曼根结点，切记一定要检查返回的是否为空指针
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

