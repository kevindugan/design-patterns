from ...Base.ComponentBase import ComponentBase
from ...Base.ComponentRegistration import ComponentRegistration

@ComponentRegistration.register('SubModule_01_01')
class SubModule_01_01(ComponentBase):
    def required(self):
        return "SubModule_01_01 Required"