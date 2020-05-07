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


