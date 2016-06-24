# CommonEx

[![badge](https://img.shields.io/badge/conan.io-commonex%2F1.0.0-green.svg?logo=data:image/png;base64%2CiVBORw0KGgoAAAANSUhEUgAAAA4AAAAOCAMAAAAolt3jAAAA1VBMVEUAAABhlctjlstkl8tlmMtlmMxlmcxmmcxnmsxpnMxpnM1qnc1sn85voM91oM11oc1xotB2oc56pNF6pNJ2ptJ8ptJ8ptN9ptN8p9N5qNJ9p9N9p9R8qtOBqdSAqtOAqtR%2BrNSCrNJ/rdWDrNWCsNWCsNaJs9eLs9iRvNuVvdyVv9yXwd2Zwt6axN6dxt%2Bfx%2BChyeGiyuGjyuCjyuGly%2BGlzOKmzOGozuKoz%2BKqz%2BOq0OOv1OWw1OWw1eWx1eWy1uay1%2Baz1%2Baz1%2Bez2Oe02Oe12ee22ujUGwH3AAAAAXRSTlMAQObYZgAAAAFiS0dEAIgFHUgAAAAJcEhZcwAACxMAAAsTAQCanBgAAAAHdElNRQfgBQkREyOxFIh/AAAAiklEQVQI12NgAAMbOwY4sLZ2NtQ1coVKWNvoc/Eq8XDr2wB5Ig62ekza9vaOqpK2TpoMzOxaFtwqZua2Bm4makIM7OzMAjoaCqYuxooSUqJALjs7o4yVpbowvzSUy87KqSwmxQfnsrPISyFzWeWAXCkpMaBVIC4bmCsOdgiUKwh3JojLgAQ4ZCE0AMm2D29tZwe6AAAAAElFTkSuQmCC)](http://www.conan.io/source/commonex/1.0.0/paulobrizolara/stable)

C++ header-only library to easy the creation of exception types and provide a set of frequently used ones.

This library was created initially as part of the [CalmPhotoFrame](https://bitbucket.org/pairg-ufrn/calmphotoframe-core)
project within the [PAIRG research group](http://www.pairg.dimap.ufrn.br) in
[UFRN](http://www.ufrn.br) (Federal University of Rio Grande do Norte).
The code was extracted to allow the reuse by other projects.

## Features

* Header-only (just include the header files)
* Create new exception types with just one line
        Ex.: EXCEPTION_CLASS(MyAwesomeException);
* Allows easy creation of exception hierarchies, to enable capture related exceptions without losing meaningful names.
        Ex.:
        EXCEPTION_CLASS(ClientError);
        EXCEPTION_SUBCLASS(NotFoundEntity, ClientError);
        EXCEPTION_SUBCLASS(UnauthorizedError, ClientError);
* Includes the class name and (optionally) the cause of error on exception messages to help identify what kind of error was thrown
        Ex.:
            throw IOException("Could not read file");

    Produces the message:
        "IOException:   Could not read file"
* Some useful macros (see macros.h) for checking exception conditions.

        Ex.: CHECK_NOTNULL, CHECK_BOUNDS and CHECK_ASSERTION

    Define 'COMMONEX_MACRO_CLASH' before including the library header if these macros are clashing with other names.

## How to use

You can just copy the **src/commonex** dir into your project or you can use it with **[conan](https://www.conan.io/)** (a package manager for c/c++ projects).

The [conan docs](http://docs.conan.io/en/latest/index.html) has detailed instructions in how to use it.

### Quickstart with Conan

1) Install conan:

    #You may need run this command as sudo
    pip install conan

2) Create a conanfile.txt in your project, like:

    [requires]
    ...
    commonex/1.0.0@paulobrizolara/stable

or (if you prefer) use a conanfile.py:

    from conans import ConanFile

    class YourConanFileClass(ConanFile):
        ...

        requires = (
            ... ,
            "commonex/1.0.0@paulobrizolara/stable"
        )

3) Install dependencies

    conan install

4) Integrate it into your build

See conan [integrations](http://docs.conan.io/en/latest/integrations.html) to learn how to integrate conan into your build.

5) Start using!

Example:

    ...
    #include commonex/commenex.h

    EXCEPTION_CLASS(InvalidArgsException);

    void run(int argc, char ** argv){
        Obj * myObj = getObj();
        CHECK_NOTNULL(myObj);

        if(!myObj->init(argc, argv)){
            throw InvalidArgsException("Could not initialize with given arguments");
        }
    }

    int main(int argc, char ** argv){
        try{
            run(argc, argv);
        }
        catch(std::exception & ex){
            std::cout << ex.what() << std::endl;
        }

        return 0;
    }

## License and Contributions

The project is released under the MIT license (see LICENSE.txt).

If you see something wrong, ugly or incomplete you can make a pull request or open an issue.
