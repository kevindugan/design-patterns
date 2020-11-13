from ...Base.ComponentBase import ComponentBase
from ...Base.ComponentRegistration import ComponentRegistration

@ComponentRegistration.register('SubModule_01_02')
class SubModule_01_02(ComponentBase):
    def required(self):
        return "SubModule_01_02 Required"