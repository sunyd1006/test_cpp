import os

def getBuildTargetName(targetName, build_dir="build"):
    return os.path.join(build_dir, targetName)

env = Environment(CXXFLAGS="-std=c++11")


# gcc 不同文件夹下的源文件编译
# https://www.cnblogs.com/lihello/p/14435941.html

common_obj_li = Object(Glob('util/*.cpp'))
exsingleItemDemoLi = ["exSingleObjDemo.cpp"]
exsingleItemDemoLi += common_obj_li
env.Program(getBuildTargetName("exsingleItemDemo"), exsingleItemDemoLi, CPPPATH='../util')