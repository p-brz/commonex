#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os
from os import path

top='.'
out='build'

def loadtools(ctx):
    ctx.load('compiler_c compiler_cxx')

def options(ctx):
    loadtools(ctx)
    ctx.add_option('--staticlib', action='store_true', default=True, help='If true, build static library')

def configure(ctx):
    loadtools(ctx)

def build(ctx):
    features = 'cxx ' + "cxxstlib" if ctx.options.staticlib else "cxxshlib";
    ctx(target="CommonExceptions"
        , features  = features
        , source    = ctx.path.ant_glob('src/**/*.cpp', src=True,dir=False)
        , includes  = ['src']
        , export_includes = ['src']
    )
