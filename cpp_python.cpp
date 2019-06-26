#include <pybind11/pybind11.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

namespace py = pybind11;
std::vector<int> values;

void push(std::string name, py::args args)
{
    std::cout << "name: " << name << '\n';
    std::transform(args.begin(), args.end(), std::back_inserter(values), [](const auto &arg) {
        return arg.template cast<int>();
    });
    std::cout << "current values: ";
    std::copy(values.begin(), values.end(), std::ostream_iterator<int>(std::cout, ", "));
    std::cout << '\n';
}

PYBIND11_MODULE(cpp_python, m) {
    m.def("push", push);
}