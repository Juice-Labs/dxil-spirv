#!/usr/bin/env python3

#
# Copyright 2020 Hans-Kristian Arntzen for Valve Corporation
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301, USA
#

import sys
import os
import argparse
import shutil
import hashlib

def hashstr(path):
    with open(path, 'rb') as f:
        bytes = f.read()
        if len(bytes) == 0:
            return None
        result = hashlib.sha1(bytes).hexdigest()
    return result

def copy_reference_shader(output_dir, input_path):
    name = hashstr(input_path)
    if name is not None:
        shutil.copy(input_path, os.path.join(output_dir, name + '.dxil'))

def main():
    parser = argparse.ArgumentParser(description = 'Script for copying VKD3D shader dumps to regression suite.')
    parser.add_argument('--dxil', required = True, help = 'Folder containing a bunch of .dxil shaders.')
    parser.add_argument('--output', required = True, help = 'Output directory.')

    args = parser.parse_args()

    for root, dirs, files in os.walk(args.dxil):
        for file in files:
            if os.path.splitext(file)[1] == '.dxil':
                print('Copying DXIL reference file:', file)
                copy_reference_shader(args.output, os.path.join(args.dxil, file))

if __name__ == '__main__':
    main()

