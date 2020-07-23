# Setting up Competitive Programming on Local Machine :

#### Content

- [Benefits](#Benefits)

- [SetUp](#Setting-up-env)

- [Snippets](#Snippets)


<br> <hr> <br>


## Benefits


#### It is always a good practice to set up your coding environment right on your pc as :

* It helps in faster code execution.

* Independent of the load on IDE's during the contest.

* Various Code Snippets can be used.

* Interaction with command line and terminal.

* Less chances of your code getting leaked.



<br> <hr> <br>



## Setting up env:

So below are some good setups which you may like and may modify as well as per your choice.

Also, you can set up your environment as you like if you have basic knowledge and read any of the blogs below. Just set up the compiler and a text editor or ide. Remember to add the path of your compiler to environment variable.

p.s. Should read about precompiling the headers if you use C++ for faster build.

[Codeforces blog for some editor preferences](https://codeforces.com/blog/entry/356)

<br>

### VSCode and C++ :
* [Setting up VS Code for CP - Rachit Jain - Youtube](https://www.youtube.com/watch?v=Y-_3rXgrRAY)

<br>

### Sublime and C++ :
* [Codingblocks Blog](https://blog.codingblocks.com/2019/setting-up-a-c-competitive-programming-environment/)
* [Codingblocks - Youtube](https://www.youtube.com/watch?v=Mt6Jb8u9XBk)
* [Blog - the-hyp0cr1t3](https://github.com/the-hyp0cr1t3/CC/blob/master/Setting%20up%20Sublime.md)

<br>

### C++ in Ubuntu :
* [GeeksforGeeks Blog](https://www.geeksforgeeks.org/setting-up-a-c-competitive-programming-environment/)

<br>

### Linux Setup with Geany :
* [Linux Setup with Geany - Errichto - Youtube](https://www.youtube.com/watch?v=ePZEkbbf3fc)

<br>

### Precompiling C++ headers :

It is always important to precompile the C++ header files to save your precious time in compilation. You can search for the same on the internet if you run into error.

All you have to do is to find your stdc++.h file in your compiler path and then compile it like normal file with the flags you use to run.

`g++ [your-flags] stdc++.h`

* [Codeforces blog for windows](https://codeforces.com/blog/entry/66809)

* [Codeforces blog for linux distro](https://codeforces.com/blog/entry/53909?)

* [Another Codeforces blog](https://codeforces.com/blog/entry/79026)

<br>

### VSCode and Python3 :

I prefer Python and VSCode setup. Here's how you can set it up :

* Download and install Python3 and VSCode.

* Add path to environment variable. 

* Install CodeRunner Extension on VSCode.

* Open your settings.json file on VSCode and modify the coderunner command for any python file as `python -u <input.txt> output.txt` to take input from input.txt and write to output.txt. Then you can easily run your file with <kbd> ctrl + alt + n </kbd>

<br>

### Bonus 

[CP Editor](https://cpeditor.org/)

This editor is purposely designed for CP and Codeforces. Easy to use and many interesting features. It greatly improves typing speed as one of my friends who is a big fan of this editor suggests.

<br> <hr> <br>

## Snippets

Snippets are the cool features offered by the text editors through which you can add a bunch of code just by a few taps. 

- [CP Snippets by Atom.io](https://atom.io/packages/cpp-competitive-programming-snippets)

<br> 
You can add your own snippets as for loading your template, adding a bfs code or for anything you want. Just look for how to add custom snippets in your text editor.

- [VSCode Guide - Blog](https://code.visualstudio.com/docs/editor/userdefinedsnippets)

- [Sublime Text 3 - Video & Blog](https://devdojo.com/episode/how-to-create-sublime-text-snippets)

<br> <br>

> Now you're all set to solve the [problems](https://github.com/luctivud/All-Of-Competitive-Programming/tree/master/01-Material).

> I've mentioned all the popular setups. If you're facing an error in setting up it is easy to google it and find solution on stackoverflow. 