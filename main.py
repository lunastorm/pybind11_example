import sys
sys.path.append("build")

import cpp_python

values = [1, 2, 3]
cpp_python.push("test", *values)

values = [4, 5, 6]
cpp_python.push("foo", *values)