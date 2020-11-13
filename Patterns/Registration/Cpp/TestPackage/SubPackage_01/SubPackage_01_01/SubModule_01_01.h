#ifndef SUBMODULE_01_01_H_0C98
#define SUBMODULE_01_01_H_0C98

#include "ComponentBase.h"
#include "ComponentRegistration.h"

class SubModule_01_01 : public ComponentBase {
    public:
        std::string required() override;
};

singleton::registry().registerComponent("SubModule_01_01", [](){return std::make_shared<SubModule_01_01>();});

#endif // SUBMODULE_01_01_H_0C98