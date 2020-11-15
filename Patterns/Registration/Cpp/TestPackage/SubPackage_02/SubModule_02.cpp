#include "SubModule_02.h"

// bool SubModule_02::registered = ComponentBuilder::registerComponent(
//     "SubModule_02",
//     [](){return std::make_shared<SubModule_02>();}
// );

std::string SubModule_02::required(){
    return "SubModule_02 Required";
}