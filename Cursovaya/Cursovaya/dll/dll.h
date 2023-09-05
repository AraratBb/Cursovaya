// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the DLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// DLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif

#include<string>
#include<vector>
#include<algorithm> 
#include<iostream> 
#include<unordered_map>

using std::set_intersection;
using std::pair;
using std::random_shuffle;
using std::back_inserter;
using std::unordered_multimap;
using std::for_each;
using std::binary_search;
using std::find;
using std::distance;
using std::string;
using std::vector;
using std::to_string; 

typedef unordered_multimap <int, char>::iterator mit;

extern DLL_API int open;
extern DLL_API bool flag;
extern DLL_API string KEY, text, enc_choose;


class DLL_API Base
{
public:
	string print_key;
	vector<char> lat_down, lat_up, kir_down, kir_up;
	Base();
	virtual string Cipher(string ins) = 0;
	Base(const Base& m);
	virtual Base* copy() = 0;
	virtual ~Base();
};

class DLL_API Caesar: public Base
{
private:
	int key;
	void enc(vector<char>& alf, int key, char& c);
public:
	Caesar();
	string Cipher(string ins);
	Caesar(const Caesar& c);
	Caesar* copy();
	~Caesar();
};

class DLL_API Gronsfeld: public Base
{
	vector<int> key_generate();
	vector<int> keys;
	void enc(vector<char>& alf, vector<int>& keys, char& c, int& ind);
public:
	Gronsfeld();
	string Cipher(string ins);
	Gronsfeld(const Gronsfeld& g);
	Gronsfeld* copy();
	~Gronsfeld();
};

class DLL_API Vigenere: public Base
{
	string key_word;
	void enc(vector<char>& alf, char& c, mit& it, mit& sit, mit& lit);
public:
	Vigenere();
	string Cipher(string ins);
	Vigenere(const Vigenere& v);
	Vigenere* copy();
	~Vigenere();
};

class DLL_API DB
{
	vector<Base*> v;
public:
	DB();
	Base* operator[](string s);
	DB(const DB& db);
	DB& operator=(const DB& db);
	~DB();
};

extern DLL_API DB db;