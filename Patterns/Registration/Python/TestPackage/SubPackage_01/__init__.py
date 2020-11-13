from ..Base import import_objective_components
import os

# Discover all components of Package
import_objective_components(directory=os.path.dirname(__file__),
                            packageName=__package__)
