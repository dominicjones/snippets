// from: https://stackoverflow.com/questions/25338795/is-there-a-name-for-this-tuple-creation-idiom

#include <iostream>

auto list = [](auto ...xs) { 
    return [=](auto access) { return access(xs...); }; 
}; 
    
auto length = [](auto xs) { 
    return xs([](auto ...z) { return sizeof...(z); }); 
}; 

int main()
{
    std::cout << length(list(1, '2', "3")); // 3    
}
