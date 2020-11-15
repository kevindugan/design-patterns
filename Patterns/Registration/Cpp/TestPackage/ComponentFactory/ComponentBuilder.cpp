#include "ComponentBuilder.h"
#include <exception>
#include <iostream>

#include "SubModule_02.h"

ComponentBuilder::umap ComponentBuilder::components = {
    {"SubModule_02", [](){return std::make_shared<SubModule_02>();} }
};

std::shared_ptr<ComponentBase> ComponentBuilder::build(const std::string &name){
    if (components.find(name) == components.end()){
        throw std::runtime_error(name);
    }
    return components.at(name)();
}

bool ComponentBuilder::registerComponent(const std::string &name, functionType func){
    if (components.find(name) == components.end()){
        std::cout << "Registering: " << name << std::endl;
        components[name] = func;
        return true;
    }
    return false;
}