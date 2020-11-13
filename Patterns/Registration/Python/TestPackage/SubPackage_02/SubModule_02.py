from ..Base.ComponentBase import ComponentBase
from ..Base.ComponentRegistration import ComponentRegistration

@ComponentRegistration.register('SubModule_02')
class SubModule_02(ComponentBase):
    def required(self):
        return "SubModule_02 Required"