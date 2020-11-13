#include "ComponentRegistration.h"
#include <memory>
using namespace singleton;

// #include "../SubPackage_01/SubPackage_01_01/SubModule_01_01.h"

// ComponentRegistration::umap ComponentRegistration::registry = {
//     {"SubModule_01_01", [](){return std::make_shared<SubModule_01_01>();}}
// };
// ComponentRegistration::umap ComponentRegistration::registry;

ComponentRegistration::ComponentRegistration(){}

ComponentRegistration::~ComponentRegistration(){}

void ComponentRegistration::registerComponent(const std::string &name, createMethodType const& method){
    if(this->_registry.find(name) == this->_registry.end()){
        this->_registry[name] = method;
    }
}

ComponentRegistration::umap ComponentRegistration::getRegistry(){
    return this->_registry;
}