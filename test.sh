#!/bin/bash

assert() {
  expected="$1"
  input="$2"

  build/bin/chibicpp "$input" > tmp.s || exit
  clang++ --target=riscv64-unknown-elf --gcc-toolchain=${HOME}/bin/riscv/newlib -march=rv64gc -static -o tmp tmp.s
  qemu-riscv64 ./tmp
  actual="$?"

  if [ "$actual" = "$expected" ]; then
    echo "$input => $actual"
  else
    echo "$input => $expected expected, but got $actual"
    exit 1
  fi
}

assert 0 0
assert 42 42

echo OK
