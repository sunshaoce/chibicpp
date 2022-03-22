# chibicpp

本项目旨在移植 [chibicc](https://github.com/rui314/chibicc) 项目到C++，并且以RISC-V为后端，CMake作为版本控制工具。同时以中文作为注释语言。

## 环境要求
- git:                 2.25+
- cmake:               3.20+
- ninja:               1.10+
- clang++:             13.0+
- riscv-gnu-toolchain: 11.1+
- qemu-riscv64:        6.2+

## 编译
```
mkdir build
cd build
cmake -GNinja ..
ninja
```

## 测试
【注意】请自行替换掉`test.sh`中的`--gcc-toolchain=${HOME}/bin/riscv/newlib`中riscv newlib库的路径。
```
./test.sh
```
