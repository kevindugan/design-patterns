#include "gtest/gtest.h"
#include "ComponentBuilder.h"
#include "ComponentRegistration.h"

TEST(RegistrationDemo, UseRegistration){
    // Collection of Already Registered components
    // std::map<std::string, std::string> expected = {
    //     {"SubModule_01_01", "SubModule_01_01 Required"},
    //     {"SubModule_01_02", "SubModule_01_02 Required"},
    //     {"SubModule_01_02_extra", "SubModule_01_02_extra Required"},
    //     {"SubModule_01_02_01", "SubModule_01_02_01 Required"},
    //     {"SubModule_02", "SubModule_02 Required"}
    // };
    std::map<std::string, std::string> expected = {
        {"SubModule_01_01", "SubModule_01_01 Required"}
    };

    // Check that each invocation of builder gives the expected result
    for (const auto item : expected){
        auto component = ComponentBuilder::build(item.first);
        EXPECT_EQ(component->required(), item.second);
    }

    // Try to use class not registered to builder
    ASSERT_THROW(ComponentBuilder::build("Decoy"), std::exception);
}

TEST(RegistrationDemo, RegisterClass){

    // Register new class which inherits from Base
    class MyClass : public ComponentBase {
        public:
            std::string required() {return "MyClass Required";}
    };
    singleton::registry().registerComponent("MyClass", [](){return std::make_shared<MyClass>();});

    // Check that new class is available to builder
    auto testComp = ComponentBuilder::build("MyClass");
    EXPECT_STREQ(testComp->required().c_str(), "MyClass Required");
}