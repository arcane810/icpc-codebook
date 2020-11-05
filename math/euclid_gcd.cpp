//FIND GCD of a and b AND GIVE A SOLUTION FOR ax + by = gcd(a, b)
//a and b ASSUMED TO BE NON NEGATIVE HERE
//CANNOT HANDLE THE CASE WHERE BOTH a AND b ARE ZERO
int extended_gcd(int a, int b, int &x, int &y)
{
    if(b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    int result = extended_gcd(b, a % b, x, y);
    int x_new = y, y_new = x - (a / b) * y;
    x = x_new;
    y = y_new;
    return result;
}

//FIND A SOLUTION FOR ax + bx = c, RETURN TRUE IF A SOLUTION EXISTS, FALSE IF NONE EXISTS
//CANNOT HANDLE THE CASE WHERE BOTH a AND b ARE ZERO
bool find_any_solution(int a, int b, int c, int &x, int &y, int &g)
{
    g = extended_gcd(abs(a), abs(b), x, y);
    if(abs(c) % g)
        return false;
    x *= c / g;
    y *= c / g;
    if(a < 0)
        x *= -1;
    if(b < 0)
        y *= -1;
    return true;
}

//SHIFT THE SOLUTION BY cnt, gcd(a, b) ASSUMED TO BE 1
void shift_solution(int a, int b, int &x, int &y, int cnt)
{
    x += b * cnt;
    y -= a * cnt;
}

//COUNT NUMBER OF SOLUTIONS FOR ax + by = c, GIVEN RANGE OF VALUES x and y CAN TAKE
//NEITHER a NOR b CAN BE ZERO
int count_solutions(int a, int b, int c, int lx, int rx, int ly, int ry)
{
    int x, y, g, sign_a, sign_b, lx1, rx1, lx2, rx2;
    if(!find_any_solution(a, b, c, x, y, g))
        return 0;
    a /= g;
    b /= g;
    sign_a = (a > 0) ? 1 : -1;
    sign_b = (b > 0) ? 1 : -1;

    shift_solution(a, b, x, y, (lx - x) / b);
    if(x < lx)
        shift_solution(a, b, x, y, sign_b);
    lx1 = x;

    shift_solution(a, b, x, y, (rx - x) / b);
    if(x > rx)
        shift_solution(a, b, x, y, -sign_b);
    rx1 = x;

    shift_solution(a, b, x, y, -(ly - y) / a);
    if(y < ly)
        shift_solution(a, b, x, y, -sign_a);
    lx2 = x;

    shift_solution(a, b, x, y, -(ry - y) / a);
    if(y > ry)
        shift_solution(a, b, x, y, sign_a);
    rx2 = x;

    if(sign_a == sign_b)
        swap(lx2, rx2);

    int fx = max(lx1, lx2), fy = min(rx1, rx2);
    if(fx > fy)
        return 0;
    return (fy - fx) / abs(b) + 1;
}