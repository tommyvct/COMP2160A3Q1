echo "================================================="
echo "=================COMP2160 A3Q1==================="
echo "================================================="
echo 

####  Run this script to automatically make and run 
####  this table program, and test from provided 
####  script.

####  How to use this test shell:
####  insert (int): insert an integer into table
####  remove (int): remove an integer into table


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