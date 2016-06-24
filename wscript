#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
from os import path

top='.'
out='build'

def loadtools(ctx):
    ctx.load('compiler_c compiler_cxx')
    ctx.load('conanbuildinfo_waf', tooldir=".");


def options(ctx):
    loadtools(ctx)
    ctx.add_option('--tests', action='store', default=True, help='Compile or not tests')

def configure(ctx):
    loadtools(ctx)

def build(ctx):
    ctx(name            = "commonex",
        includes        = 'src',
        export_includes = 'src')

    if ctx.options.tests:
        ctx.recurse(path.join('src', 'tests'))
