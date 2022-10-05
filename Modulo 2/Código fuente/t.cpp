#include "t.h"
using namespace std;
T::T()
{

}
T::T(const string &ter)
{
    val = ter;

};
std::string T::get_val()
{
    return val;
};
void T::set_val(const std::string &data)
{
    val = data;
};
T &T::operator=(const T &myT)
{
    val = myT.val;

    return *this;
};

