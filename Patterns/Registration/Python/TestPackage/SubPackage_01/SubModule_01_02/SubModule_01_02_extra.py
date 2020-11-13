from ...Base.ComponentBase import ComponentBase
from ...Base.ComponentRegistration import ComponentRegistration

@ComponentRegistration.register('SubModule_01_02_extra')
class SubModule_01_02_extra(ComponentBase):
    def required(self):
        return "SubModule_01_02_extra Required"