# Synpsis
The goal of this exercise is to setup the development environment, so you can work with the project we will be using in the next several classes.

By the end, you should be able to build the `solved` branch with make, run the executable and see the following output:
~~~~
+--------+----------------------------------------+----------+----------+
|       5|Super Mob                               |     12.90|     64.50|
+--------+----------------------------------------+----------+----------+
|      12|Tea Cup                                 |      5.30|     63.60|
+--------+----------------------------------------+----------+----------+
|       8|Red Wine Glass                          |      8.60|     68.80|
+--------+----------------------------------------+----------+----------+
                                                     Subtotal|    196.90|
                                                             +----------+
                                                        Taxes|     19.69|
                                                             +----------+
                                                        TOTAL|    216.59|
                                                             +----------+
~~~~

## Installation
### Linux
If you would like to try out Linux, but you own a Windows 10 PC, the best way is __Windows Subsystem for Linux__: https://docs.microsoft.com/en-us/windows/wsl/install-win10

You can then open a Terminal directly inside your Ubuntu subsystem and start hacking. Tip: VS Code (installed on your Windows) has a very nice integration with WSL: https://code.visualstudio.com/docs/remote/wsl

Once you are in your Linux Shell:
```
apt-get install g++ git cmake make
```
That's it!

### Windows
If you decide to go with Windows directly, there are a couple of more steps:
1. Install Git (https://git-scm.com/downloads)
2. Install MinGW (http://www.mingw.org/wiki/Getting_Started/) Use default location (`C:\MinGW`)
3. Install CMake (https://github.com/Kitware/CMake/releases/download/v3.17.0-rc3/cmake-3.17.0-rc3-win64-x64.msi). *Make sure you add cmake to your PATH environment variable. 
4. Make sure `C:\MinGW\bin` is in your PATH environment variable
5. Install VS Code: https://code.visualstudio.com/download

*If you are not sure how to edit your environment variables, see https://www.architectryan.com/2018/03/17/add-to-the-path-on-windows-10/

To test the installation, you can open a CMD terminal and enter the following commands. They will show errors, but you should not see `unrecognied command`:
```
git
g++
mingw32-make
cmake
```

You are all set. Next, we start using the tooling to work on the project.

## Get the code
You first need to get the code. You do this by cloing the Git repository on your local machine.
1. Open a terminal
2. You are in your home directory. You can navigate to another place (`cd` command) or keep it here.
  * For linux, this is `/home/<user>` 
  * For Windows, this is `C:/Users/<user>`
4. Clone the repo `git clone https://github.com/kvuchkov/citb205-2020`. This will create a `citb205-2020` folder in your directory of choice (probably Home dir)
5. Navigate inside the repo: `cd citb205-2020`

## Using git
Git is a source control management. It keeps track of all versions of all files that are considered part of the project. It is a big topic, for now you need to know only a few concepts:
* __Clone__ - Git allows you to clone a project with its entire history (every version of every file ever made). This is how you get the code to work on
* __Commit__ - When you do changes, git will detect that the files on your machine are different than what is *committed* in the source control, i.e. you have made changes. 
To preserve changes in Git, you need not just save your files, but to commit them as well. I will share a few steps below.
* ___Branch__ - You can organize your versions in branches. Each branch is a separate branch of history, i.e. a series of changes of all files in the repository. In this repository, we have two branches:
  * `master` - this is the default and primary branch of every repo. In our case, this is where the where you will do your work. When you clone the repository, you are on this branch.
  * `solved` - this is the branch where you can see the solutions of every lab. Only for lab1 the solved branch contains the entire solution, not just the part for the lab.

Going forward, you will need to do the following steps when working with the project:
1. Change something. Open the README.md file in the root of the repository and add some test, e.g. "OK" at the end.
2. Run `git status` - you will that git reports the file README.md as being changed. 
3. Run `git add .` - this will stage all changes you've made, i.e. it will prepare them for commit.
4. Run `git commit -n "getting started"`. The `getting started` part is an example - when you working on the project later in the class, put meaningful short messages that indicate what you have changed.
5. Run `git status` again - git will say you are up-to-date

You need to be in this state (i.e. `up-to-date`) where you don't have uncommited changes to be able to update the projects with changes from github (changes I have made, e.g. adding a new lab exercise.). 
To update your project you need to run `git pull` - this will update your copy (i.e. clone) of the project with whatever changes I have made in Github.

Last but not least, when you have commited everything, you can peek at the `solved` branch for inspiration. Run `git checkout solved` to change all your files to their solved version. 
Then (without making any changes) get back to the `master` branch to continue working by running `git checkout master`. 

That's it. You know Git.

## Build the project
1. Generate the `Makefile`. This is a special file with instructions that is generated by `cmake` which we installed earlier. __This needs to be done only once__.
  * For Linux/Mac, run: `cmake .`
  * For Windows, run: `cmake . -G "MinGW Makefiles"`
2. After the previous step is successful, you can build the project any number of times (whenever you make a change). Before doing this, checkout the solved branch by running `git checkout solved`.
  * On Windows, run: `mingw32-make`
  * On Linux/Mac, run: `make`

You should see progress reported of the different steps. If you are on the solved branch, the build will be successful. You should see something like:
```
$ make
Scanning dependencies of target lab1
[ 16%] Building CXX object CMakeFiles/lab1.dir/src/main.cpp.o
[ 33%] Building CXX object CMakeFiles/lab1.dir/src/product.cpp.o
[ 50%] Building CXX object CMakeFiles/lab1.dir/src/item.cpp.o
[ 66%] Building CXX object CMakeFiles/lab1.dir/src/invoice.cpp.o
[ 83%] Building CXX object CMakeFiles/lab1.dir/src/textprinter.cpp.o
[100%] Linking CXX executable lab1
[100%] Built target lab1
```
3. Now, let's see how does this look like if the compilation is not successful. Checkout the master branch `git checkout master` and build the project again (see step #2). 
Things should look like a bit different now:
```
$ make
Scanning dependencies of target lab1
[ 16%] Building CXX object CMakeFiles/lab1.dir/src/main.cpp.o
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/main.cpp:7:13: error: no matching constructor for initialization of 'Product'
    Product superMob("Super Mob", 12.90);
            ^        ~~~~~~~~~~~~~~~~~~
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/product.h:8:7: note: candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 2 were provided
class Product {
      ^
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/product.h:8:7: note: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 2 were provided
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/product.h:8:7: note: candidate constructor (the implicit default constructor) not viable: requires 0 arguments, but 2 were provided
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/main.cpp:8:13: error: no matching constructor for initialization of 'Product'
    Product teaCup("Tea Cup", 5.30);
            ^      ~~~~~~~~~~~~~~~
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/product.h:8:7: note: candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 2 were provided
class Product {
      ^
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/product.h:8:7: note: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 2 were provided
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/product.h:8:7: note: candidate constructor (the implicit default constructor) not viable: requires 0 arguments, but 2 were provided
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/main.cpp:9:13: error: no matching constructor for initialization of 'Product'
    Product redWineGlass("Red Wine Glass", 8.60);
            ^            ~~~~~~~~~~~~~~~~~~~~~~
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/product.h:8:7: note: candidate constructor (the implicit copy constructor) not viable: requires 1 argument, but 2 were provided
class Product {
      ^
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/product.h:8:7: note: candidate constructor (the implicit move constructor) not viable: requires 1 argument, but 2 were provided
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/product.h:8:7: note: candidate constructor (the implicit default constructor) not viable: requires 0 arguments, but 2 were provided
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/main.cpp:11:13: error: no member named 'add' in 'Invoice'
    invoice.add(superMob, 5);
    ~~~~~~~ ^
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/main.cpp:12:13: error: no member named 'add' in 'Invoice'
    invoice.add(teaCup, 12);
    ~~~~~~~ ^
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/main.cpp:13:13: error: no member named 'add' in 'Invoice'
    invoice.add(redWineGlass, 8);
    ~~~~~~~ ^
/Users/kiril.vuchkov/uni/CITB205-2020/lab1/src/main.cpp:16:13: error: no member named 'print' in 'TextPrinter'
    printer.print(std::cout, invoice);
    ~~~~~~~ ^
7 errors generated.
make[2]: *** [CMakeFiles/lab1.dir/src/main.cpp.o] Error 1
make[1]: *** [CMakeFiles/lab1.dir/all] Error 2
make: *** [all] Error 2
```

# The end

This is it. Stay on the master branch and continue to Lab 2.
