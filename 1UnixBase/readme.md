__attribute__((noreturn)) 函数属性：通知编译器这个函数没有返回值，编译器可以优化的时候去除那些永远不会达到的语句。
使用的时候，可以减少没有返回值函数调用的开销，例如exit(),最好的例子就是存在死循环的时候去除

fflush(stdout),把缓冲区的内容输出到界面上。
fflush(stdin),把输入中的数据丢弃。这个做法常见在scanf中，遇到了非法输入之后，对于之后的输入丢弃。详见：http://blog.xuite.net/mb1016.flying/linux/28543400-fflush%28stdout%29   http://c.biancheng.net/cpp/html/2506.html
