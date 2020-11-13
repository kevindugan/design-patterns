#include "ComponentRegistration.h"
#include <memory>

#include "../SubPackage_01/SubPackage_01_01/SubModule_01_01.h"

umap ComponentRegistration::registry = {
    {"SubModule_01_01", [](){return std::make_shared<SubModule_01_01>();}}
};

void ComponentRegistration::registerComponent(const std::string &name){

}

umap ComponentRegistration::getRegistry(){
    return ComponentRegistration::registry;
}