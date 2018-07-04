# C++ London Uni

## assorted exercises 10th class (toptable)

### Build process (VC++ 2017)

```
git clone git@github.com:CPPLondonUniClassroom/assorted-exercises-10th-class-toptable.git
cd exercise1
mkdir -p Build
cd Build
cmake ..
cmake --build . --clean-first

cd ../../

cd exercise2
mkdir -p Build
cd Build
cmake ..
cmake --build . --clean-first

cd ../../

cd exercise3
mkdir -p Build
cd Build
cmake ..
cmake --build . --clean-first
```

### Test running process (didn't work in clion or Visual Studio)

```
echo "# Running exercise1 tests\n"

exercise1/Debug/test_is_even.exe
exercise1/Debug/test_count_odd.exe
exercise1/Debug/test_even_sum.exe
exercise1/Debug/test_copy_if_divisible_by.exe
exercise1/Debug/test_largest_div_by_three.exe
exercise1/Debug/test_is_sorted.exe


echo "# Running exercise2 tests\n"

exercise2/Debug/test_shift_char.exe
exercise2/Debug/test_rot13.exe
exercise2/Debug/test_encode.exe
exercise2/Debug/test_decode.exe

echo "# Running exercise3 tests\n"

exercise3/Debug/test_split.exe
exercise3/Debug/test_quoted_split.exe
exercise3/Debug/test_parse_csv.exe
```

## Known / Obvious problems

### Exercise 3

* CSV cannot contain quoted newline characters
  * simple fix is to defer parsing until a later point, similar to `in_dblquotes`
