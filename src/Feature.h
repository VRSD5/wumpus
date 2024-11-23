//
// Created by resig on 11/20/2024.
//

#ifndef FEATURE_H
#define FEATURE_H
#include <string>


class Entity;

class Feature {
public:
    Feature();
    ~Feature();

    virtual std::string recieveSnowball();
    virtual std::string sound();
    virtual bool interact(Entity *entity);

private:

};



#endif //FEATURE_H
