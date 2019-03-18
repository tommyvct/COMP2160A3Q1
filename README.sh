echo "================================================="
echo "=================COMP2160 A3Q1==================="
echo "================================================="
echo "==============Wu Tommy (7852291)================="
echo "================================================="
echo
echo

####  Run this script to automatically make and run this
####  table program, and test from provided script.

####  How to use this test shell:
####    ./bin/table for interactive shell, OR
####    ./bin/table script.file to use as a scripter

####  Supported operations:
####  insert (int): insert an integer into table
####  remove (int): remove an integer into table
####  search (int): search for the presence of an integer
####  clear: clear the whole table
####  first: print the first item in the table
####  next:  print the next item in the table
####  print: print the whole table


echo "================================================="
echo "=================excuting make==================="
echo "================================================="
echo 

make

echo
echo

echo "================================================="
echo "=============testing table program==============="
echo "================================================="

for script in ./test_script/*
do
    echo
    ./bin/table $script
    echo
done

echo
echo "================================================="
echo "===========Test complete, cleaning==============="
echo "================================================="
echo 

make clean
