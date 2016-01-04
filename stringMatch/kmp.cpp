#include<iostream>
#include<vector>
#include<string>
/**
 * To preprocess pattern string
 * param: m  is a pattern string
 * param: automata is the result of preprocess, automata should have the same size as m
 */
void kmp_preprocess(const std::string& m, std::vector<int>& automata)
{
    int q = 0;
    if(m.length() == 0 ) return;
    automata[0] = q;
    size_t j = 1;
    for(size_t i = 1; i < m.length();i++)
    {
        while(j >=0 && m[j] != m[i])
        {
            j--;
        }
        automata[i] = j+1;
    }
}

/**
 * abababc
 * 0012340
 * tabababd
 */
void kmp(const std::string& m, const std::string& t)
{
    if(t.length() < m.length()) return;
    if(m.length() == 0) return;

    //preprocess the pattern
    std::vector<int> automata(m.length());
    kmp_preprocess(m, automata);

    int q = 0;
    for(size_t i =0; i < t.length(); i++)
    {
        q = automata[q];
        if(t[i] == m[q+1])
            q++;
        else
            q = automata[q];
        if(q == m.length())//this is a match
        {
            std::cout << "Match found at index(end): " << i << std::endl;
        }
    }
}
int main(int nargs, char* args[])
{
    if(nargs < 3)
        std::cout << "Usage: kmp pattern text" << std::endl;
    kmp(args[1], args[2]);
}
