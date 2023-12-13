#include <iostream>
#include <cmath>
#include <vector>

template<typename T>
class ModVector: public std::vector<T> {
    public:
    T getUsingMod(int index) {
        int posIdx = std::abs(index);
        size_t i = posIdx % this->size();
        return (*this)[i];
    }
};

int main()
{
    std::vector<int> *a = new ModVector<int>();
    a->resize(3, 0);
    (*a)[0] = 1;
    (*a)[1] = 2;
    (*a)[2] = 3;
    
    auto b = static_cast<ModVector<int>*>(a);
    std::cout<<b->getUsingMod(8)<<std::endl;
    std::cout<<b->getUsingMod(-8)<<std::endl;
    std::cout<<b->getUsingMod(0)<<std::endl;
    std::cout<<b->getUsingMod(10)<<std::endl;
    return 0;
}