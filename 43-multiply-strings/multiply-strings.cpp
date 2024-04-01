class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        string result = "";

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';

            carry = sum / 10;
            sum %= 10;
            result = to_string(sum) + result;
        }

        return result;
    }

    string subtractStrings(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, borrow = 0;
        string result = "";

        while (i >= 0 || j >= 0) {
            int diff = (i >= 0 ? num1[i--] - '0' : 0) - borrow - (j >= 0 ? num2[j--] - '0' : 0);
            borrow = diff < 0;
            diff += borrow * 10;
            result = to_string(diff) + result;
        }

        result.erase(0, min(result.find_first_not_of('0'), result.size() - 1));

        return result;
    }

    string karatsuba(string num1, string num2) {
        int n = max(num1.size(), num2.size());

        if (n == 1) return to_string((num1[0] - '0') * (num2[0] - '0'));

        while (num1.size() < n) num1 = "0" + num1;
        while (num2.size() < n) num2 = "0" + num2;

        string a = num1.substr(0, n / 2);
        string b = num1.substr(n / 2);
        string c = num2.substr(0, n / 2);
        string d = num2.substr(n / 2);

        string ac = karatsuba(a, c);
        string bd = karatsuba(b, d);
        string ad_bc = subtractStrings(subtractStrings(karatsuba(addStrings(a, b), addStrings(c, d)), ac), bd);

        for (int i = 0; i < 2 * (n - n / 2); ++i) ac += "0";
        for (int i = 0; i < n - n / 2; ++i) ad_bc += "0";

        return addStrings(addStrings(ac, ad_bc), bd);
    }
    string multiply(string num1, string num2) {
        string ans = karatsuba(num1,num2);
        while(ans.length()>1 && ans[0]=='0'){
            ans=ans.substr(1);
        }
        return ans;
    }
};