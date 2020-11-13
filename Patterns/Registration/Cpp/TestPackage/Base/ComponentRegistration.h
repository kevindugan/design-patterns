#ifndef COMPONENT_REGISTRATION_H_9CV0
#define COMPONENT_REGISTRATION_H_9CV0

#include "ComponentBase.h"
#include <unordered_map>
#include <functional>
#include <memory>

namespace singleton {

class ComponentRegistration {
    public:
        using createMethodType = std::function<std::shared_ptr<ComponentBase>(void)>;
        using umap = std::unordered_map<std::string, createMethodType>;

        void registerComponent(const std::string &name, createMethodType const& method);
        umap getRegistry();

    private:
        ComponentRegistration();
        ~ComponentRegistration();

    private:
        umap _registry;

        friend ComponentRegistration& registry();
};

inline ComponentRegistration& registry() {
    static ComponentRegistration instance;
    return instance;
}

} // Namespace: Singleton
#endif // COMPONENT_REGISTRATION_H_9CV0