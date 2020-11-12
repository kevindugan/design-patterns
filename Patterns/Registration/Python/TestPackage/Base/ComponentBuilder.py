# Import Top level subpackages
from TestPackage import SubPackage_01
from TestPackage import SubPackage_02

# Import Registration
from .ComponentRegistration import ComponentRegistration as register

class ComponentBuilder():

    @staticmethod
    def build(name):
        assert name in register.componentMap.keys(), "Unknown Component: {0:s}. Must be on of [{1:s}]".format(name, "|".join(register.componentMap.keys()))
        return register.componentMap[name]()