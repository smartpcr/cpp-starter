
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
2. On linux

    ```bash
    git clone https://github.com/microsoft/vcpkg.git vcpkg && cd vcpkg && ./bootstrap-vcpkg.sh
    export VCPKG_ROOT=$PWD
    echo "export VCPKG_ROOT=$PWD" >> ~/.zshrc
    ```
3. create presets for windows and linux, see example in `CMakePresets.json`
4. install packages, this should update `vcpkg.json` file

    ```bash
    vcpkg install fmt
    vcpkg install spdlog
    vcpkg install gtest
    vcpkg install cpp-httplib # https://github.com/yhirose/cpp-httplib
    vcpkg install nlohmann-json # https://github.com/nlohmann/json
    vcpkg install jwt-cpp # https://github.com/Thalhammer/jwt-cpp
    ```
