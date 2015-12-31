# CommonExceptions

C++ library to easy the creation of exception types and provide a set of frequently used ones.

This library was created as part of the [CalmPhotoFrame](https://bitbucket.org/pairg-ufrn/calmphotoframe-core) project within the [PAIRG research group](http://www.pairg.dimap.ufrn.br) in [UFRN](http://www.ufrn.br) (Federal University of Rio Grande do Norte). The code was extracted to allow the reuse by other projects.

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

## How to use

You can just copy the **src** dir into your project.

Alternatively, you can use **[npm](https://www.npmjs.com/)!** to add the library on your project. Yes, npm is the **node** package manager, but on real it just can install *anything* (see the third item on [this link](http://blog.izs.me/post/1675072029/10-cool-things-you-probably-didnt-realize-npm)).

To use npm just create a package.json on your project (you can use *npm init*). Then references the git url on *package.json* dependencies field.

        Ex.: package.json
        {
            ...
            dependencies :{
                ...
                commonexceptions: https://github.com/paulobrizolara/CommonExceptions.git
            }
        }
Then you can include the directory on *node_modules* dir (after running *npm install*).

    Ex.: $CXX ... -I./node_modules/commonexceptions/src
