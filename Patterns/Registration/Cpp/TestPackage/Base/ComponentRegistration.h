#ifndef COMPONENT_REGISTRATION_H_9CV0
#define COMPONENT_REGISTRATION_H_9CV0

#include "ComponentBase.h"
#include <unordered_map>
#include <functional>
#include <memory>

using umap = std::unordered_map<std::string, std::function<std::shared_ptr<ComponentBase>(void)>>;

class ComponentRegistration {
    public:
        ComponentRegistration() = delete;

        static void registerComponent(const std::string &name);
        static umap getRegistry();

    private:
        static umap registry;
};

#endif // COMPONENT_REGISTRATION_H_9CV0