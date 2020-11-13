from .ComponentBase import ComponentBase
from typing import Callable

# Class which manages component registration
class ComponentRegistration():
    componentMap = {}

    @classmethod
    def register(cls, name: str) -> Callable:

        # Wrapping class being registered
        def inner_wrapper(wrapped_class: ComponentBase) -> Callable:
            # Check that only unique names are used for registration
            assert name not in cls.componentMap, "'{0:s}' Component already Registered. Choose Unique Name".format(name)
            # Check that class being registered inherits from base class
            assert issubclass(wrapped_class, ComponentBase), "{0:s} does not inherit from {1:s}.".format(wrapped_class.__name__, ComponentBase.__name__)

            print("Registering: {0:s} -> {1:s}".format(name, str(wrapped_class)))
            # Save class registration
            cls.componentMap[name] = wrapped_class

            return wrapped_class

        return inner_wrapper