#include "e.h"
using namespace std;

E::E()
{

}
E::E(const int&estado)
{
    val = to_string(estado);
}

int E::get_estado()
{
    return stoi(val);
};
