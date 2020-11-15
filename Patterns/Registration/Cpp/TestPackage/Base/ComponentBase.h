#ifndef COMPONENT_BASE_H_GM23
#define COMPONENT_BASE_H_GM23

#include <string>

class ComponentBase {
    public:
        virtual std::string required() = 0;
};

#endif // COMPONENT_BASE_H_GM23