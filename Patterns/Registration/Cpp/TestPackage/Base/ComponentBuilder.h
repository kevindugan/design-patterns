#ifndef COMPONENT_BUILDER_H_0C9S
#define COMPONENT_BUILDER_H_0C9S

#include "ComponentBase.h"
#include <memory>

class ComponentBuilder {
    public:
        static std::shared_ptr<ComponentBase> build(const std::string &name);
};

#endif // COMPONENT_BUILDER_H_0C9S