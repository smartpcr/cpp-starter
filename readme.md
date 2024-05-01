
## Using cmake

### Linux

1. tools

```bash
sudo apt-get install build-essential g++ gdb cmake ninja-build
```

### Windows

1. tools
    - [Visual Studio](https://visualstudio.microsoft.com/ko/vs/)
    - [CMake](https://cmake.org/download/)
    - [Ninja](https://ninja-build.org/)
    - [VS Code](https://code.visualstudio.com/)
    - [clion](https://www.jetbrains.com/clion/)

## Dependency Management via vcpkg

### install vcpkg

1. On windows
    
    ```cmd
    E:
    cd \
    git clone https://github.com/microsoft/vcpkg.git vcpkg && cd vcpkg && bootstrap-vcpkg.bat
    setx VCPKG_ROOT "E:\vcpkg"
    setx PATH "%PATH%;E:\vcpkg"
    ```
    