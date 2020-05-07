// 本算法由于在Brian Kernighan与Dennis Ritchie的《The C Programming Language》一书被展示而得名
// 是一种简单快捷的hash算法。
// 也是Java目前采用的字符串的Hash算法（累乘因子为31）。
// 此哈希函数用的最多
template<class T>
size_t BKDRHash(const T *str)
{
	register size_t hash = 0;
	while (size_t ch = (size_t)*str++)
	{		
		hash = hash * 131 + ch;   // 也可以乘以31、131、1313、13131、131313..
		// 可将乘法分解为位运算及加减法可以提高效率
		// 如将上式表达为：hash = hash << 7 + hash << 1 + hash + ch;
	}
	return hash;
}

// Arash Partow发明的一种hash算法 
// 比较优秀的一种哈希算法
unsigned int APhash(char *str)
{
    unsigned int val = 0;
    int i = 0;
    for (i = 0; *str; i++) 
        if ((i & 1) == 0)
            val ^= ((val << 7)^(*str++)^(val>>3));
        else
            val ^= (~((val << 11)^(*str++)^(val>>5)));

    return (val & 0x7FFFFFFF);	
}

// Unix system系统中使用的一种著名hash算法，后来微软也在其hash_map中实现。
template<class T>
size_t FNVHash(const T* str)
{
	if(!*str)
		return 0;
	register size_t hash = 2166136261;
	while (size_t ch = (size_t)*str++)
	{
		hash *= 16777619;
		hash ^= ch;
	}
	return hash;
}