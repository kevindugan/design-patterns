from abc import ABC, abstractmethod

class ComponentBase(ABC):
    @abstractmethod
    def required(self):
        pass