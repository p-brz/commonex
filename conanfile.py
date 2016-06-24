#!/usr/bin/env python
# -*- coding: utf-8 -*-

from conans import ConanFile, CMake, ConfigureEnvironment
import os
from os import path

class CommonEx(ConanFile):
    name = "commonex"
    version = "1.0.0"
    license = "MIT"
    url     = "https://github.com/paulobrizolara/commonex"
    exports = ("*.h", "*.hpp", "*wscript", "waf")

    #Header only
    settings = None
    options = {
        # Build tests or not
        "tests": [True, False]
    }
    default_options = "tests=False"

    requires = tuple()

    test_requires = (
        "catch/1.5.0@TyRoXx/stable",
        "WafGenerator/0.0.1@paulobrizolara/experimental"
    )

    def config(self):
        if self.options.tests:
            for r in self.test_requires:
                self.requires.add(r)

            self.generators.append("Waf")

    def build(self):
        if self.options.tests:
            os.chdir(self.conanfile_directory)
            waf = os.path.join(self.conanfile_directory, 'waf')
            self.run('%s configure build' % waf)

            self.run(os.path.join("build", "src", "tests", "tests"))

    def package(self):
        src = path.join(".", "src", "commonex")
        self.copy("*", dst=path.join("include", "commonex"), src=src)
