from TestPackage.Base.ComponentBuilder import ComponentBuilder
from TestPackage.Base.ComponentRegistration import ComponentRegistration
import pytest

def test_registration_pattern():
    # Collection of Already Registered components
    expected = {
        "SubModule_01_01": "SubModule_01_01 Required",
        "SubModule_01_02": "SubModule_01_02 Required",
        "SubModule_01_02_extra": "SubModule_01_02_extra Required",
        "SubSubModule_01_02_01": "SubSubModule_01_02_01 Required",
        "SubModule_02": "SubModule_02 Required"
    }

    # Check that each invocation of builder gives expected result
    for key, value in expected.items():
        comp = ComponentBuilder.build(key)
        assert comp.required() == value

    # Try to use class not registered to builder
    with pytest.raises(Exception):
        ComponentBuilder.build('Decoy')

def test_register_class():
    from TestPackage.Base.ComponentBase import ComponentBase

    # Register New Class which inherits from Base
    @ComponentRegistration.register('MyClass')
    class MyClass(ComponentBase):
        def required(self):
            return "MyClass Required"

    # Check that new class is available to builder
    testComp = ComponentBuilder.build('MyClass')
    assert testComp.required() == "MyClass Required"

    # Registering a class which doesn't inherit from Base should fail
    with pytest.raises(Exception):
        @ComponentRegistration.register('MyClass2')
        class MyClass2():
            pass

if __name__ == "__main__":
    test_registration_pattern()
    test_register_class()