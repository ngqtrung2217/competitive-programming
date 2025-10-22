#include <bits/stdc++.h>
using namespace std;

int longestValid(const string &s)
{
    int n = s.size(), ans = 0;
    vector<int> st;
    st.reserve(n + 1);
    st.push_back(-1);

    auto is_open = [&](char c)
    {
        return c == '(' || c == '[' || c == '{' || c == '<';
    };
    auto match = [&](char open, char close)
    {
        return (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '{' && close == '}') || (open == '<' && close == '>');
    };

    for (int i = 0; i < n; i++)
    {
        char c = s[i];
        if (is_open(c))
        {
            st.push_back(i);
        }
        else
        {
            if (st.size() > 1 && match(s[st.back()], c))
            {
                st.pop_back();
                ans = max(ans, i - st.back());
            }
            else
            {
                st.clear();
                st.push_back(i);
            }
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << longestValid(s) << "\n";
    return 0;
}
