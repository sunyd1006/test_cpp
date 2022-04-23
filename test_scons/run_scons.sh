
function print_center() {
    str="========================="
    echo -e "\n"$str" "$1" "$str"\n"
}


scons -Q


print_center "run start"


./ex_lib_target

print_center "run done"

./ex7_main
print_center "run done"


rm -rf  *.o *.out *.os 


# rm -rf *.a *.so 
