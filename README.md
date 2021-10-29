# ProxyDLLExample

A simple DLL for Windows that can be used to demonstrate a DLL Proxy Attack.

This project uses GCC through MinGW was tested on Ubuntu Linux. 

## Files

- proxy.c - src for the proxy dll
- hello.c - src for the target dll
- hello.def - exports for the hello.dll
- get_exports.py - script will read the exports from a dll and format into a .def file 

## Demo as a proxy

Compile proxy.dll

```
x86_64-w64-mingw32-gcc -m64 -c -Os  proxy.c -Wall -shared -masm=intel
x86_64-w64-mingw32-dllwrap -m64 --def proxy.def  proxy.o -o proxy.dll
```

Compile hello.dll

```
x86_64-w64-mingw32-gcc -m64 -c -Os hello.c -Wall -shared -masm=intel
x86_64-w64-mingw32-dllwrap -m64 --def hello.def hello.o -o hello.dll
```

You can user rundll32.exe as an example target application.

- Compile proxy.dll
- Compile hello.dll
- rename hello.dll to original.dll
- rename proxy.dll to hello.dll

Use rundll32.exe to demo the proxy


```
rundll32 hello.dll, hello
```

- Rundll32 will load hello.dll and call the hello function
- The hello function if forwarded to original.dll where it is executed
- The hello.dll will run the 'malicous' payload
