echo "================================================="
echo "=================COMP2160 A3Q1==================="
echo "================================================="
echo 

####  Run this script to automatically make and run this
####  table program, and test from provided script.

####  How to use this test shell:
####  insert (int): insert an integer into table
####  remove (int): remove an integer into table
####  search (int): search for the presence of an integer
####  clear: clear the whole table
####  first: print the first item in the table
####  next:  print the next item in the table
####  print: print the whole table

echo "excuting make"
make

echo 
echo "================================================="
echo 

echo "testing table program"
for script in ./test_script/*
do
    ./bin/table $script
done

echo 
echo "================================================="
echo 

echo "cleaning"
make clean