# stg_ex
A small std::string based library for common string getters, hashing and a few file based functions.

Simply include this in your project and make calls via the stg_ex namespace.

Code Example ( main.cpp):

```cpp


#include "stg_ex.h"


//Make sure to include SDL2 into your compiler/build system for this to work.

int main( int argc, char* args[] )
{
    std::string hello_world = "Hello World, the sky is blue, the ocean is too!";
    
    hello_world = stx_ex::string_replace_all( hello_world,"ocean", "my tears when coding");

    return 1;
}

```

Donate to make stg_ex greater
=========================================
Work on open source projects like this is not possible without funding. The amount of time it takes to update the codebases, create examples, tutorials and more is quite expensive. Please consider either a one-time or monthly donation to keep this engine going and more frequently updated. 

We have a [Patron Page](https://www.patreon.com/pawbyte?ty=h) that you can help fund future open source projects and the updates to this one.

There is also a [PayPal](http://gamepencil.pawbyte.com/donate/) one time donation method as well. 

I appreciate your generousity and moving this project forward. 



Discord Chat
======
Come and  [join our discord server](https://discord.gg/aNX3Fcx)!  Bounce ideas off each other, hangout and discord open source,gaming, etc.

Forums
======
Become a member on our [forum](http://community.pawbyte.com/)!  Here, you can find help and talk directly with the developers of this project!

Developers
----------
[theweirdn8](https://github.com/theweirdn8)
![](https://avatars0.githubusercontent.com/u/3193947?v=4&s=100)
