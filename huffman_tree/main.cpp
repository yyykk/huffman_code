#include "iostream"
#include "bitset"
#include "math.h"
#include "huffman_tree.h"
#include "stdio.h"
#include "stdlib.h"
using namespace std;

unsigned char bin_to_8(string::iterator bin){
	unsigned char num8 = 0;
	for (int i = 8; i != 0; --i, ++bin){
		if (*bin == '1'){
			num8 += pow(2, i - 1);
		}
	}
	return num8;
}

void init8(string &str){
	for (int i = (8 - (str.size() % 8)); i != 0; --i){
		str += "0";
	}
}

void test(char *file_name, string code, map<string, string> already_code){
	//char md[100] = "md ";
	//strcat(md, file_name);
	//system(md);
	ofstream outfile;
	string file = "./test/" + string(file_name) + ".dat";
	outfile.open(file, ios::binary | ios::app);
	init8(code);
	for (auto iter = code.begin(); iter != code.end(); iter += 8){
		unsigned  char temp = bin_to_8(iter);
		outfile.write((char*)&temp, sizeof(temp));
	}
	outfile.close();
	outfile.open("./" + string(file_name) + "/probability.dat", ios::out);
	for (auto &a : already_code){
		outfile << a.first << "\t" << a.second << endl;
	}
	outfile.close();
}


int main(){
	char* text[5] = { "demo0", "demo1", "demo2", "demo3", "demo4" };
	for (int i = 0; i < 5; ++i){
		string file_name = "./test/" + string(text[i]) + ".txt";
		Huffman_Tree *demo = new Huffman_Tree(file_name);//创建对象
		string word_2_code = demo->to_Huffman_code();
		test(text[i], word_2_code, demo->get_already());
		delete demo;
	}
	system("pause");
}

