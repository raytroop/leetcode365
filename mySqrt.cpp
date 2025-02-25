// https://leetcode.com/problems/sqrtx/

// https://zxi.mytechroad.com/blog/math/leetcode-69-sqrtx/


// Newton’s method
double mySqrt(int num){
    constexpr double eps = 1e-3;
    double ans = static_cast<double>(num);
    while(ans * ans - num > eps){
        ans = (ans + num / ans) / 2;
    }

    return ans;
}


