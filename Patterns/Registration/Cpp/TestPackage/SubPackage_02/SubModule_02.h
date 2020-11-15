#ifndef SUBMMODULE_02_H_8C7A
#define SUBMMODULE_02_H_8C7A

#include "ComponentBase.h"
// #include "ComponentBuilder.h"

class SubModule_02 : public ComponentBase {
    public:
        std::string required() override;
        bool isRegistered() const {return registered;}
    private:
        static bool registered;
};

#endif // SUBMMODULE_02_H_8C7A