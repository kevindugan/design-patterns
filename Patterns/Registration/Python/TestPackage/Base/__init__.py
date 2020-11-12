import os, sys
from glob import glob
from pkgutil import iter_modules
from importlib import import_module
from .ComponentBase import ComponentBase

def import_objective_components(directory=None, packageName=None):
    # Collect all packages
    pkgs = __collect_packages(root=directory)
    if len(pkgs) == 0:
        pkgs.extend([directory])

    # Traverse all subpackages
    for package in pkgs:
        package_root = __package_path(path=package, root=directory)
        print("PKG Root: "+package_root)

        # Check if each module in subpackage is derived from Base, otherwise unload it
        for (_, module_name, _) in iter_modules([package]):
            module = import_module(f"{package_root}.{module_name}", packageName)
            if str(ComponentBase.__name__) not in dir(module):
                del sys.modules[module.__name__]

# Collect all subpackages from root
def __collect_packages(root=None):
    modules = [f for f in glob(os.path.join(root, "*")) if os.path.isdir(f) and not os.path.basename(f).startswith("__")]
    for mod in modules:
        modules.extend( __collect_packages(root=mod) )
    return list(set(modules))

# Evaluate Package Path [Find relative path from root and replace seperator with]
def __package_path(path=None, root=None):
    pkg_path = os.path.relpath(path, root)
    # Special case for path == root
    if pkg_path == ".":
        result = ""
    else:
        result = "."+pkg_path.replace(os.sep, ".")
    return result