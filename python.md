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
2. `dict`和`collections.Counter()`的区别：`dict`类似cpp中的map，如果使用`update`进行更新，会自动覆盖原来的value，但`Counter()`是用来计数的，使用`update`进行更新时，只会在原有value基础上进行附加。且`dict`的`update`参数也是`dict`，但`Counter()`的`update`参数是`list`。当然`Counter()`也可以如同`dict`进行操作。
3. python不允许字符相减，但可以使用`ord()`函数返回ascii码，再相减。
4. 注意`[[0]*9]*9`中**每行**所代表的列表的地址实际相同。如果想要生成一个每行之间互不相关的9x9矩阵，需要`[[0]*9 for _ in range(9)]`
5. 对于26个字母的计数问题，python中用dictionary比用长度为26的list快
6. 队列相关操作：
    - `from queue import Queue`
    - `q = Queue()`
    - `while(not q.empty())`
    - `sz = q.qsize()`
    - `q.put(x)`
    - `x = q.get()`
7. `reverse`仅能对完整list进行inplace翻转，如果对一个list进行切片，会得到一个源list的复制，故无法对源list的部分进行翻转。这种情况应该`lst[:k] = lst[k-1::-1]`
8. python中的`max`函数的参数必须都存在，不能做到cpp中那样。