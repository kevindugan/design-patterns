#include "ComponentBuilder.h"
#include "ComponentRegistration.h"
#include <sstream>
#include <vector>
#include <iterator>

std::shared_ptr<ComponentBase> ComponentBuilder::build(const std::string &name){
    auto registry = ComponentRegistration::getRegistry();
    // Check that requested component is in registry
    if (registry.find(name) == registry.end()){
        // Gather Keys
        std::vector<std::string> keys;
        for (const auto item : registry)
            keys.push_back(item.first);
        // Write Error message
        std::stringstream strm;
        strm << "Unknown Component: " << name << ". Must be one of [";
        std::copy(keys.begin(), keys.end(), std::ostream_iterator<std::string>(strm, "|"));
        strm << "]";
        throw std::runtime_error(strm.str());
    }

    return registry[name]();
}