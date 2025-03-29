#include <random>
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

#include <Credit.hpp>

int main()
{
    std::random_device rd;
    std::mt19937 gen(rd());

    auto max_range = std::uniform_int_distribution<>(10, 100)(gen);

    for(auto i = 0; i < 50; ++i){ // border
        std::cout << "-";
    }
    std::cout << std::endl;
    std::cout << "Original list\n";

    std::list<Credit> list_of_credits{};
    for (auto i = 0; i < max_range; ++i)
    {
        auto credit = Credit("Credit#" + std::to_string(i), 
                            std::uniform_int_distribution<>(1'000'000, 100'000'000)(gen),
                            (Currency)std::uniform_int_distribution<>(0, 2)(gen),
                            std::uniform_real_distribution<float>(19.5f, 31.f)(gen));
        std::cout << credit << std::endl;

        list_of_credits.push_back(credit);
    }

    for(auto i = 0; i < 50; ++i){ // border
        std::cout << "-";
    }
    std::cout << std::endl;
    std::cout << "Sorted list\n";

    list_of_credits.sort(); //sorting original container
    for(const auto& credit : list_of_credits){
        std::cout << credit << std::endl;
    }

    std::vector<Credit> vector_of_credits{};
    vector_of_credits.resize(list_of_credits.size());
    std::copy(list_of_credits.begin(),list_of_credits.end(),vector_of_credits.begin()); //copying one container to another

    for(auto i = 0; i < 50; ++i){ // border
        std::cout << "-";
    }
    std::cout << std::endl;
    std::cout << "Sorted vector\n";

    for(const auto& credit : vector_of_credits){
        std::cout << credit << std::endl;
    }
}