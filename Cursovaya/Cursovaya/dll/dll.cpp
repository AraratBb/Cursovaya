// dll.cpp : Defines the exported functions for the DLL.

#include "framework.h"
#include "dll.h"

DLL_API int open = 0;
DLL_API bool flag = false;
DLL_API DB db;
DLL_API string KEY = "Ключ: ", text = "", enc_choose = "";

Base::Base() 
{
    lat_down = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    lat_up = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z' };
    kir_down = { 'а','б','в','г','д','е','ё','ж','з','и','й','к','л','м','н','о','п','р','с','т','у','ф','х','ц','ч','ш','щ','ъ','ы','ь','э','ю' };
    kir_up = { 'А','Б','В','Г','Д','Е','Ё','Ж','З','И','Й','К','Л','М','Н','О','П','Р','С','Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ','Ы','Ь','Э','Ю' };
}

Base::Base(const Base& m)
{
    print_key = m.print_key;
    lat_down = m.lat_down;
    lat_up = m.lat_up;
    kir_down = m.kir_down;
    kir_up = m.kir_up;
}

Base::~Base(){}

Caesar::Caesar()
{
    key = 0;
}
void Caesar::enc(vector<char>& alf, int key, char& c)
{
    vector<char>::iterator it = find(alf.begin(), alf.end(), c);
    int i = distance(alf.begin(), it) + key;
    c = alf[i % alf.size()];
}
string Caesar::Cipher(string ins)
{
    key = rand() % 26;
    for (char& c : ins)
    {
        if (binary_search(lat_down.begin(), lat_down.end(), c))
            enc(lat_down, key, c);

        else if (binary_search(lat_up.begin(), lat_up.end(), c))
            enc(lat_up, key, c);

        else if (binary_search(kir_down.begin(), kir_down.end(), c))
            enc(kir_down, key, c);

        else if (binary_search(kir_up.begin(), kir_up.end(), c))
            enc(kir_down, key, c);
    }

    print_key = to_string(key);

    return ins;
}
Caesar::Caesar(const Caesar& c)
{
    key = c.key;
}
Caesar* Caesar::copy()
{
    return new Caesar(*this);
}
Caesar::~Caesar(){}

Vigenere::Vigenere(){}

int index(char s, vector<char>& alf)
{
    vector<char>::iterator it = find(alf.begin(), alf.end(), s);
    int i = distance(alf.begin(), it);
    return i;
};

void Vigenere::enc(vector<char>& alf, char& c, mit& it, mit& sit, mit& lit)
{
    vector<char>::iterator iter = find(alf.begin(), alf.end(), c);
    int t = distance(alf.begin(), iter);
    c = alf[(t + it->first) % alf.size()];

    it++;

    if (it == lit)
        it = sit;
}

string Vigenere::Cipher(string ins)
{ 

    unordered_multimap <int, char> key;

    for (char& c : print_key)
    {
        if (binary_search(lat_down.begin(), lat_down.end(), c))
            key.insert({ index(c, lat_down), c});

        else if (binary_search(lat_up.begin(), lat_up.end(), c))
            key.insert({ index(c, lat_up), c });

        else if (binary_search(kir_down.begin(), kir_down.end(), c))
            key.insert({ index(c, kir_down), c });

        else if (binary_search(kir_up.begin(), kir_up.end(), c))
            key.insert({ index(c, kir_up), c });

    }

    mit it = key.begin(), sit = key.begin(), lit = key.end();

    for (char& c : ins)
    {
        if (binary_search(lat_down.begin(), lat_down.end(), c))
            enc(lat_down, c, it, sit, lit);

        else if (binary_search(lat_up.begin(), lat_up.end(), c))
            enc(lat_up, c, it, sit, lit);

        else if (binary_search(kir_down.begin(), kir_down.end(), c))
            enc(kir_down, c, it, sit, lit);

        else if (binary_search(kir_up.begin(), kir_up.end(), c))
            enc(kir_up, c, it, sit, lit);
    }

    return ins;
}

Vigenere::Vigenere(const Vigenere& v) : Base(v)
{
    key_word = v.key_word;
}

Vigenere* Vigenere::copy()
{
    return new Vigenere(*this);
}

Vigenere::~Vigenere() { }

vector<int> Gronsfeld::key_generate()
{

    vector<int> keys_1(rand() % 100),
                keys_2(rand() % 100);

    for_each(keys_1.begin(), keys_1.end(), [](int& i) {i = 1 + rand() % 26; });
    for_each(keys_2.begin(), keys_2.end(), [](int& i) {i = 1 + rand() % 26; });

    sort(keys_1.begin(), keys_1.end());
    sort(keys_2.begin(), keys_2.end());
    pair<vector<int>::iterator, vector<int>::iterator> it;

    vector<int> keys_intersection;
    set_intersection(
        keys_1.begin(), keys_1.end(),
        keys_2.begin(), keys_2.end(),
        back_inserter(keys_intersection)
    );

    sort(keys_intersection.begin(), keys_intersection.end());

    vector<int> final_keys;

    for (int i = 0; i < 3 + rand() % 5; i++)
    {
        it = equal_range(keys_1.begin(), keys_1.end(), 1 + rand() % 26, [](int i, int j) { return (i > j); });
        final_keys.push_back(it.second - it.first + rand() % 10);
    }

    random_shuffle(final_keys.begin(), final_keys.end());

    return final_keys;
}

void Gronsfeld::enc(vector<char>& alf, vector<int>& keys, char& c, int& ind)
{
    vector<char>::iterator it = find(alf.begin(), alf.end(), c);
    int t = distance(alf.begin(), it);
    c = alf[(t + keys[ind % keys.size()]) % alf.size()];
    ind++;
}

Gronsfeld::Gronsfeld(){}

string Gronsfeld::Cipher(string ins)
{
    keys = key_generate();
    int i = 0;
    for (char& c : ins)
    {
        if (binary_search(lat_down.begin(), lat_down.end(), c))
            enc(lat_down, keys, c, i);

        else if (binary_search(lat_up.begin(), lat_up.end(), c))
            enc(lat_up, keys, c, i);

        else if (binary_search(kir_down.begin(), kir_down.end(), c))
            enc(kir_down, keys, c, i);

        else if (binary_search(kir_up.begin(), kir_up.end(), c))
            enc(kir_up, keys, c, i);
    }

    print_key = "( ";

    for (int i : keys)
        print_key += to_string(i) + ' ';

    print_key += ')';

    return ins;
}

Gronsfeld::Gronsfeld(const Gronsfeld& g): Base(g)
{
    keys = g.keys;
}

Gronsfeld* Gronsfeld::copy()
{
    return new Gronsfeld(*this);
}

Gronsfeld::~Gronsfeld(){}

DB::DB()
{
    v.push_back(new Caesar);
    v.push_back(new Gronsfeld);
    v.push_back(new Vigenere);
}

Base* DB::operator[](string s)
{
    if (s == "Шифр Цезаря")
        return v[0];

    if (s == "Шифр Гронсфельда")
        return v[1];

    if (s == "Шифр Виженера")
        return v[2];
}

DB::DB(const DB& db)
{
    for (vector<Base*>::iterator it = v.begin(); it != v.end(); it++)
        delete* it;
    v.clear();

    for (vector<Base*>::const_iterator it = db.v.begin(); it != db.v.end(); it++)
    {
        Base* new_obj = (*it)->copy();
        v.push_back(new_obj);
    }
}

DB& DB::operator=(const DB& db)
{
    if (this == &db)
        return *this;
    
    for (vector<Base*>::iterator it = v.begin(); it != v.end(); it++)
        delete* it;
    v.clear();

    for (vector<Base*>::const_iterator it = db.v.begin(); it != db.v.end(); it++)
    {
        Base* new_obj = (*it)->copy();
        v.push_back(new_obj);
    }

    return *this;
}

DB::~DB()
{
    for (int i = 0; i < v.size(); i++)
        delete v[i];
    v.clear();
}
