#ifndef T_H
#define T_H
#include "ep.h"
#include <string>
class T: public EP
{
private:

public:
    T();
    T(const std::string &);
    std::string get_val();
    void set_val(const std::string &data);

    T &operator=(const T &);
};

#endif // T_H
