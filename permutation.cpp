//to generate all permutation sets
#include<string>
#include<iostream>

void backtrack(const std::string& input, std::string output, size_t k, size_t length)
{
    if(k == length)
    {
        std::cout << " {" << output  << "} ";
    }
    else
    {
        for(size_t i = 0; i < input.size(); i++)
        {
            output.push_back(input[k]);
            //sub strin by removing input[i];
            std::string new_input = input.substr(0, i) + input.substr(i+1);
            std::cout << std::endl << "\t newinput:" << new_input  <<std::endl;
            backtrack(new_input, output, k+1, length);
        }
    }
}

void permutation(const std::string& input)
{
    std::cout << "permutation of [" << input <<"]: ";
    std::string output;
    output.reserve(input.size());
    backtrack(input, output, 0, input.size());
    std::cout << std::endl;
}

int main()
{
    std::string test1("123");
    permutation(test1);

    return 0;
}
