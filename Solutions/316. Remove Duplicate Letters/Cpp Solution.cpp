#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <limits>
#include <set>
#include <unordered_set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <numeric>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <functional>
using namespace std;

#define ll long long
#define MOD 1000000007
#define INF LLONG_MAX
#define PI 3.14159265358979323846

#define pb push_back
#define pop pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORR(i, a, b) for (int i = (a); i > (b); --i)

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef unordered_set<int> usi;

class Solution
{
public:
    /**
     * Remove duplicate letters from the input string.
     *
     * @param s the input string
     *
     * @return the string with duplicate letters removed
     *
     * @throws None
     */
    string removeDuplicateLetters(string s)
    {
        set<char> seen;
        string res = "";

        // Store the count of each character in the input string.
        vector<int> count(26, 0);
        for (char c : s)
        {
            count[c - 'a']++;
        }

        for (char c : s)
        {
            // Decrement the count of the current character.
            count[c - 'a']--;

            // If the character is already in the result, skip it.
            if (seen.count(c) > 0)
            {
                continue;
            }

            // Pop characters from the back of the result string while:
            // 1. They are greater than the current character.
            // 2. There are still more occurrences of them in the input.
            while (!res.empty() && c < res.back() && count[res.back() - 'a'] > 0)
            {
                seen.erase(res.back());
                res.pop();
            }

            // Add the current character to the result and mark it as seen.
            res += c;
            seen.insert(c);
        }

        return res;
    }
};
