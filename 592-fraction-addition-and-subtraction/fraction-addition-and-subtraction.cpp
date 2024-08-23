class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int getNum(int &i, const string &expression) {
        string temp = "";
        while (expression[i] != '/') {
            temp += expression[i];
            i++;
        }
        return stoi(temp);
    }

    int getDen(int &i, const string &expression) {
        string temp = "";
        while (i < expression.size() && expression[i] != '+' && expression[i] != '-') {
            temp += expression[i];
            i++;
        }
        return stoi(temp);
    }

    string fractionAddition(string expression) {
        int s1 = 1, i = 0;

        if (expression[i] == '-') {
            s1 = -1;
            i++;
        }

        int num1 = getNum(i, expression);
        i++;
        int den1 = getDen(i, expression);

        while (i < expression.size()) {
            int s2 = expression[i] == '-' ? -1 : 1;
            i++;

            int num2 = getNum(i, expression);
            i++;
            int den2 = getDen(i, expression);

            int lcm = (den2 * den1) / gcd(den1, den2);
            num1 = s1 * num1 * (lcm / den1) + s2 * num2 * (lcm / den2);
            den1 = lcm;

            s1 = (num1 < 0) ? -1 : 1;
            if (num1 < 0) num1 *= -1;
        }

        int gc = gcd(num1, den1);
        if (gc > 1) {
            num1 /= gc;
            den1 /= gc;
        }

        return (s1 == -1 ? "-" : "") + to_string(num1) + "/" + to_string(den1);
    }
};