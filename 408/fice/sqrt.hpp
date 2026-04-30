#pragma once

#include<iostream>

namespace fice{
    class sqrt{
    private:
        size_t base;
        size_t root_val;    // 开方结果 (向下取整的整数根)
        bool perfect_flag;  // 是否为完全平方数

        // 核心计算逻辑：纯整数逐位构造法 (无浮点，无除法)
        void calculate() {
            // 如果是 0，直接出结果
            if (base == 0) {
                root_val = 0;
                perfect_flag = true;
                return;
            }

            size_t temp = base;
            size_t r = 0;
            // 找到最高位的起始点
            size_t bit = size_t(1) << (sizeof(size_t) * 8 - 2);

            while (bit > temp) {
                bit >>= 2;
            }

            // 逐位逼近求整数平方根
            while (bit != 0) {
                if (temp >= r + bit) {
                    temp -= r + bit;
                    r = (r >> 1) + bit;
                } else {
                    r >>= 1;
                }
                bit >>= 2;
            }

            root_val = r;
            // 如果 temp 最后被减到了 0，说明它是完全平方数
            perfect_flag = (temp == 0); 
        }
    public:
        // 构造函数：在对象创建时一次性计算完毕并存储所有结果
        explicit sqrt(size_t n) : base(n), root_val(0), perfect_flag(false) {
            calculate();
        }

        // 获取被开方数 (原数)
        size_t get_base() const { 
            return base; 
        }

        // 获取开方结果 (向下取整的值，例如 sqrt(26) 返回 5)
        size_t get_root() const { 
            return root_val; 
        }

        // 判断原数是否可以完美开平方
        bool is_perfect() const { 
            return perfect_flag; 
        }
    };
}