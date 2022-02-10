#!/usr/bin/env python3
import os
from re import sub
import subprocess


def parse_file(file, file_extensions):
    elements = []

    def get_indent(line):
        return len(l) - len(l.lstrip())

    minimum_indent = None

    content = None
    with open(file, 'r') as f:
        content = f.readlines()

    assert(content is not None)

    for l in content:
        indent = get_indent(l)
        # print(indent)
        if indent > 0:
            if minimum_indent is None:
                minimum_indent = indent
            else:
                minimum_indent = min(minimum_indent, indent)

    if minimum_indent is None:
        minimum_indent = 1

    for i, l in enumerate(content):
        indent = get_indent(l)
        if indent > 0 and indent % minimum_indent != 0:
            raise ValueError("Unexpected indentation in line " + str(i+1))

    levels = []
    for i, l in enumerate(content):
        indent = get_indent(l)
        c = l.strip()
        level = int(indent / minimum_indent)

        extension = os.path.splitext(c)
        is_dir = extension[1] not in file_extensions

        if is_dir:
            if level > len(levels) + 1:
                raise ValueError("Unexpected indentation in line " + str(i+1))
        else:
            if level != len(levels):
                raise ValueError("Unexpected indentation in line " + str(i+1))

        while level < len(levels):
            levels.pop()

        if is_dir:
            levels.append(c)
        else:
            elements.append(os.path.join(os.sep.join(levels), c))

    return elements


class substition:
    def __init__(self, path, ext, fill_with):
        self._path = path
        self._ext = ext
        self._fill_with = fill_with


def substitude_elements(elements, substitutions):
    for e in elements:
        ext = os.path.splitext(e)[1]
        if not ext in substitutions:
            continue

        for s in substitutions[ext]:
            p = e.replace(ext, s._ext)
            out_path = os.path.join(s._path, p)
            if not os.path.exists(out_path):
                os.makedirs(os.path.dirname(out_path), exist_ok=True)
                content = s._fill_with(p)
                with open(out_path, 'w') as f:
                    f.write('\n'.join(content))

            s, o = subprocess.getstatusoutput("clang-format -i " + out_path)
            if o:
                print(s)


def fill_cpp(path):
    out = []
    out.append('#include "' + path.replace('.cpp', '.hpp') + '"')
    out.append('')
    out.append('namespace jhm {')
    c = os.path.basename(path)
    c = os.path.splitext(c)[0]
    out.append(c + '::' + c + '() = default;')
    out.append(c + '::~' + c + '() = default;')
    out.append('}  // namespace jhm.')
    return out


def fill_hpp(path):
    out = []
    out.append('#pragma once')
    out.append('')
    out.append('namespace jhm {')
    c = os.path.basename(path)
    c = os.path.splitext(c)[0]
    out.append('class ' + c + ' {')
    out.append('public:')
    out.append(c + '();')
    out.append('~' + c + '();')
    out.append('};')
    out.append('}  // namespace jhm.')
    return out


if __name__ == '__main__':
    elements = parse_file("testfile.txt", [".<ext>"])
    for e in elements:
        print(e)

    substitutions = {
        ".<ext>": [substition("src", ".cpp", fill_cpp), substition("include", ".hpp", fill_hpp)]
    }

    substitude_elements(elements, substitutions)
