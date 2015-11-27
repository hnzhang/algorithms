//use backtrack to generate all subsets of given elements
#include<iostream>
#include<string>

void backtrack(const std::string& input, std::string output,  int k)
{
    if(k == input.size() )
    {
        //backtrack completed, output the subset
        std::cout << " {" << output << "} ";
    }
    else
    {
        backtrack(input, output, k+1);
        output.push_back(input[k]);
        backtrack(input, output, k+1);
    }
}
/**
 * to generate all subsets of given input chars
 * and print them out on screen
 */
void subsets(std::string& input)
{
    std::cout <<"subsets of  "<< input << ": ";
    std::string output;
    output.reserve(input.size());
    backtrack(input, output, 0);
    std::cout <<std::endl;
}

int main()
{
    std::string test1{"123"};
    subsets(test1);
    std::string test2{"abcde"};
    subsets(test2);
    return 0;
}
