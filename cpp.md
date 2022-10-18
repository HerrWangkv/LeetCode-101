1. 函数默认参数：
    ```cpp
    void display(int a = 0, int b = 0){
       cout << a << b;
    }
    display(b = 5);
    ```
    在CPP中会因为b未定义而报错，但是在Python中可以实现类似操作
    ```python
    def display(a = 0, b = 0):
        print(a, end="")
        print(b)

    display(b=5)
    ```
2. STL中容器的size函数的一个"bug":size函数输出一个**无符号数**，在size与负数进行比较时 `-1 < vec.size()`可能会输出`false`， 需要提前将size转化为有符号数`-1 < int(vec.size())`
3. cpp中子字符串：`str.substr(i, sz)`.其中i为初始字符索引，sz为子字符串长度。注意i必须在规定范围内，否则输出一个out_of_range错误。
4. cpp中的优先队列默认优先输出大值：`priority_queue<int>`相当于`priority_queue<int, vector<int>, less<int>>`。第二项表示容器类型(必须基于数组)。第三项表示稍后pop的项所满足的条件， 可以为标准库定义的函数或函数类型，如 `priority_queue<int, vector<int>, decltype(&cmp)> q(cmp)`其中 q 为优先队列名，cmp为函数。
5. cpp中如果`a`是一个array，那么`a`指的是指向首元素的指针，而`&a`类似于表示整个数组的指针,但两者包含的地址均为首元素地址。因此`a+1`指的是该数组第二个元素的地址，而`&a+1`相当于这个数组的尾后地址，但`&a+1`类型是数组指针，而不是元素指针，故设计成该指针的值与地址实际相同。因此在将array赋值给一个vector时，可以`vector<int>(a, *(&a + 1))`
6. cpp中的`std::find`只是一个迭代器的for循环。
7. cpp中的`max`函数中如果仅有一个参数存在(另一个溢出等)，则会直接返回这个参数。(慎用，如果另一个参数调用了可能提出异常的函数，如`stk.top()`，则依旧会出问题)
8. cpp中可以使用加号来连接两个字符串。
9. cpp中对定义但未初始化的vector：
   1.  `vec.resize(length, 0);`：初始化为length长度的全0 vector
   2.  `vec.assign(nums.begin(), nums.end());`：做一个`nums`的备份
10. vector去重：
   1.  `vec.assign(nums.begin(), nums.end());`：做一个`nums`的备份
   2.  `sort(vec.begin(), vec.end());`
   3.  `auto tmp = unique(vec.begin(), vec.end());`：`unique`函数将所有非unique的相邻重复元素移至vec末尾。返回值指向unique元素vector的尾后元素(第一个重复元素或end)
   4.  `vec.erase(tmp, vec.end());`
11. `vector`的`push_back`操作会调用成员类型的**拷贝构造函数**对其参数进行**拷贝**。
12. cpp会对map中不存在的key进行默认初始化，故不需要先检查该元素是否存在。
13. int和string之间相互转换分别为`std::stoi()`和`std::to_string()`