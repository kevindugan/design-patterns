from ....Base.ComponentBase import ComponentBase
from ....Base.ComponentRegistration import ComponentRegistration

@ComponentRegistration.register('SubSubModule_01_02_01')
class SubSubModule_01_02_01(ComponentBase):
    def required(self):
        return "SubSubModule_01_02_01 Required"