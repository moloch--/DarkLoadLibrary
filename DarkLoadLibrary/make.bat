@echo off
SET OBF_FLAGS=-mllvm -bcf -mllvm -bcf_prob=20 -mllvm -bcf_loop=2 -mllvm -sub -mllvm -sub_loop=3 -mllvm -fla -mllvm -split_num=3 -mllvm -aesSeed=DEADBEEFDEADCODEDEADBEEFDEADCODE

IF EXIST dark.exe del dark.exe

@echo on
clang.exe -static -std=c11 %OBF_FLAGS% -o dark.exe -I .\include\ -v ^
    src\darkloadlibrary.c ^
    src\resolve.c ^
    src\ldrutils.c ^
    src\pebutils.c ^
    src\syscalls.c ^
    src\syscallsstubs.c ^
    src\main.c
