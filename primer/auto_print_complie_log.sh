#!/bin/bash

######################################################################
# 使用说明：直接在CLion中执行，即可先打印日志
######################################################################
# 检测的文件是否变化： https://blog.csdn.net/diyiday/article/details/93077288
log_name=./sun_compile_1005_husun.log
main_name="main"

function read_file() {
  while IFS= read -r line;
  do
    # todo 因为没有找到 printf的颜色打印，就草草实现了
    # 不会忽略空格，而echo 会
    is_error_line=$(echo $line | grep -cE "error|warning" | awk '{print $1}')
    if [ $is_error_line -gt 0 ]; then
        echo $line | perl -pe 's/(fatal)/\e[0;41;37m$1\e[0m/g; s/(error)/\e[1;31m$1\e[0m/g; s/(warning)/\e[1;33m$1\e[0m/g; s/(info)/\e[1;32m$1\e[0m/g; s/(debug)/\e[1;34m$1\e[0m/g; s/(wechat)/\e[1;35m$1\e[0m/g'
    else
        printf '%s\n' "$line"
    fi
  done < $1
}

run_compile=$(g++ -std=c++14 ex12.cpp ex12main.cpp -o $main_name 2>$log_name)

# 判断文件是否存在
if [ ! -f $log_name ] ; then
    echo "------------------------------------------- 不存在$log_name"
    exit
else
    how_many_error=$(grep -cE "error" $log_name | awk '{print $1}')
    if [ $how_many_error -gt 0 ] ; then
        read_file $log_name
        echo -e "\n----------------------------------------------------------------------------------"

        # perl 高亮关键字用的
        error_content=$(grep -E "error|warning" $log_name | awk '{print}' | perl -pe 's/(fatal)/\e[0;41;37m$1\e[0m/g; s/(error)/\e[1;31m$1\e[0m/g; s/(warning)/\e[1;33m$1\e[0m/g; s/(info)/\e[1;32m$1\e[0m/g; s/(debug)/\e[1;34m$1\e[0m/g; s/(wechat)/\e[1;35m$1\e[0m/g')
        echo "$error_content"
    else
        abs_path_to_exe_file=$(cd $(dirname $0);pwd)"/"$main_name
        echo "当前文件目录： "$abs_path_to_exe_file
        #        add_ch=$(chmod +x $abs_path_to_exe_file)

        #        https://blog.csdn.net/toby54king/article/details/103376514
        #        http://www.361way.com/shell-process/1126.html
        # 调用可执行文件
        ./$main_name
    fi
fi

rm_file=$(rm -rf $log_name)

# 计算日志的 md5
#old_log_md5=$(md5sum -b $log_name | awk '{print $1}'| sed 's/ //g')
