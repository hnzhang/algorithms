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
            std::string new_output(output);
            new_output.push_back(input[i]);
            //sub strin by removing input[i];
            std::string new_input = input.substr(0, i) + input.substr(i+1);
            backtrack(new_input, new_output, k+1, length);
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
    std::string test11("1234");
    permutation(test11);

    return 0;
}
