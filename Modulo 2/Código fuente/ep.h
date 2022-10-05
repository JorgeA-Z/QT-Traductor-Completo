#ifndef EP_H
#define EP_H
#include <string>
class EP
{
protected:
    std::string val;

public:
    EP();
    virtual std::string get_val();

};

#endif // EP_H
