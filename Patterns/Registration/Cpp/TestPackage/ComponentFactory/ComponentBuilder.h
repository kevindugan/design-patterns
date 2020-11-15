#ifndef COMPONENT_BUILDER_H_09CA
#define COMPONENT_BUILDER_H_09CA

#include "ComponentBase.h"
#include <memory>

#include <unordered_map>
#include <functional>

class ComponentBuilder {
    public:
        using functionType = std::function<std::shared_ptr<ComponentBase>()>;
        using umap = std::unordered_map<std::string, functionType>;

        static std::shared_ptr<ComponentBase> build(const std::string &name);
        static bool registerComponent(const std::string &name, functionType func);
    
    private:
        static umap components;
    
};

#endif // COMPONENT_BUILDER_H_09CA