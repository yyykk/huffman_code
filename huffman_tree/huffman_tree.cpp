// Huffman_tree.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "huffman_tree.h"

Huffman_Tree::Huffman_Tree(string file_name, int n){
	left = nullptr;
	right = nullptr;
	parent = 0;
	if (read_file(file_name, n)){
		//cout << "create object success" << endl;
	}else{
		cout << "create object error" << endl;
	}
}

bool Huffman_Tree::read_file(string file_name, int MAX){
	word.clear();
	double probability = 0;
	double weight = 0;
	string txet;
	ifstream infile;
	infile.open(file_name, ios::in);
	if (!infile){
		cout << "Can not open probability text" << endl;
		return 0;
	}else{
		for (int i = 0; i < MAX; i++){
			infile >> weight >> txet;
			if (txet == "_"){
				txet = " ";
			}
			word.insert(make_pair(weight, txet));
			probability = probability + weight;
		}
		if ((probability - 1) < 0.0001){
			return 1;
		}else{
			cout << "Sum of probability != 1" << endl;
			cout << probability << endl;
			return 0;
		}
	}
}

Huffman_Tree* Huffman_Tree::build(){
	int n = word.size();
	if (n<2){
		cout << "Your code is < 2" << endl;
		return nullptr;
	}
	int m = 2 * n - 1;
	Huffman_Tree* root = new Huffman_Tree[m];
	auto r = root;
	auto w1 = word.begin();
	for (int i = 0; i < n; ++i){
		r->code = *w1;
		++r; ++w1;
	}
	for (int i = n; i < m; ++i){
		int num1, num2;
		choose(root, i, num1, num2);
		root[i].left = &root[num1];
		root[i].right = &root[num2];
		root[num1].parent = i;
		root[num2].parent = i;
		root[i].code.first = root[num1].code.first + root[num2].code.first;
		root[i].code.second = "NULL";
	}
	root[m - 1].word = this->word;
	root[m - 1].Huffman_code();
	return &root[m - 1];
}

void Huffman_Tree::choose(Huffman_Tree* t, int n, int &num_1, int &num_2){
	double m1, m2;
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++){
		if (t[i].parent == 0){
			m1 = t[i].code.first;
			num_1 = i;
			j = ++i;
			break;
		}
	}
	for (i = j; i < n; i++){
		if (t[i].parent == 0){
			m2 = t[i].code.first;
			num_2 = i;
			break;
		}
	}
	for (i = j; i < n; i++){
		if (t[i].parent == 0 && i != num_1 && i != num_2){
			if (t[i].code.first < m1){
				m2 = m1;
				num_2 = num_1;
				m1 = t[i].code.first;
				num_1 = i;
			}
			else if (t[i].code.first < m2){
				m2 = t[i].code.first;
				num_2 = i;
			}
		}
	}
}

bool Huffman_Tree::Huffman_code(){
	if (this->word.size() == 0){
		cout << "�ö���δ��ȡ�ַ�����" << endl;
		return false;
	}else{
		make_code(this, this, "");
		return true;
	}
}

void Huffman_Tree::make_code(Huffman_Tree *root, Huffman_Tree *t, string s_codeing){
	if (t != nullptr){
		string temp = s_codeing;
		s_codeing = s_codeing + "0";
		if (t->left == nullptr && t->right == nullptr){
			root->already_code.insert(make_pair(t->code.second, temp));
		}
		else{
			make_code(root, t->left, s_codeing);
			s_codeing = temp;
			s_codeing += "1";
			make_code(root, t->right, s_codeing);
		}
	}
}

string Huffman_Tree::to_Huffman_code(string str){
	string sentence = "";
	if (already_code.size() == 0){
		cout << "this object no configure" << endl;
	}else{
		for (auto &s : str){
			string temp("");
			temp = s;
			sentence += already_code.find(temp)->second;
		}
	}
	return sentence;
}

string Huffman_Tree::to_Word(string str){
	string new_word;
	cout << str << endl;
	if (word.empty()){
		cout << "this object no configure" << endl;
	}
	else{
		Huffman_Tree *p = this;
		for (auto s : str){
			switch (s){
			case '0': p = p->left; break;
			case '1': p = p->right; break;
			default:break;
			}
			if (p->left == nullptr && p->right == nullptr){
				new_word += p->code.second;
				p = this;
			}
		}
	}
	cout << new_word << endl;
	return new_word;
}

void Huffman_Tree::show_Huffman_code(){
	ofstream Outfile;
	string file = "show_Huffman_code.txt";
	Outfile.open(file, ios::out);
	if (!Outfile){
		cout << "no open" << endl;
		return;
	}
	Outfile << "\t" << "Word" << "\t" << "Code" << endl;
	cout << "\t" << "Word" << "\t" << "Code" << endl;
	for (auto &s : already_code){
		Outfile << "\t" << s.first << "\t" << s.second << endl;
		cout << "\t" << s.first << "\t" << s.second << endl;
	}
}

void Huffman_Tree::show(Huffman_Tree *t){
	if (t != nullptr){
		cout << t->code.first << "\t" << t->code.second << endl;
		show(t->left);
		show(t->right);
	}
}

