#include "ArrayAndStr.h"

void test()
{

}

void mergeSortedVector(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    // 逆序遍历，3个指针，两个数组中的较小者与遍历指针交换
    int i = nums1.size() - 1;
    m--;
    n--;

    while(n >= 0)
    {
        // 只有m还有，并且更大的时候一直自身交换，直到m没了或是n更大
        while(m >= 0 && nums1[m] > nums2[n])
        {
            swap(nums1[m--], nums1[i--]);
        }   
        // m没了但n还有，交换n；m还有但是n更大
        swap(nums2[n--], nums1[i--]);
    }

}

int removeElement(vector<int>& nums, int val) 
{
    int iBegin = 0;
    int iEnd = nums.size() - 1;

    while(iBegin <= iEnd)
    {
        // 左边找到第一个val
        while(iBegin <= iEnd && nums[iBegin] != val)
        {
            iBegin++;
        }
        
        while(iBegin <= iEnd && nums[iEnd] == val)
        {
            iEnd--;
        }

        if(iBegin <= iEnd)
        {
            nums[iBegin] = nums[iEnd];
            iBegin++;
            iEnd--;
        }
    }

    return iBegin;
}

int removeDuplicates(vector<int>& nums) 
{
    int32_t i = 0;
    int32_t j = 0;
    int32_t iLen = nums.size();

    while(j < iLen)
    {
        while(j < iLen && nums[i] == nums[j])
        {
            ++j;
        }

        if(j < iLen)
        {
            i++;
            nums[i] = nums[j];
        }
    }      

    return i + 1;  
}

int removeDuplicates2(vector<int>& nums) 
{ 
    int i = 2;
    int j = 2;
    int ilen = nums.size(); 

    if(ilen <= 2)
    {
        return ilen;
    }

    for(j = 2; j < ilen; j++)
    {
        // i-当前被替换位置 j-下一个新元素
        // i-2 == j 时表示中间的都是相同元素，直接跳过
        if(nums[i-2] != nums[j])
        {
            nums[i] = nums[j];
            i++;
        }
    }

    return i;
}

int majorityElement(vector<int>& nums) 
{
    int iLen = nums.size();
    if(iLen <= 0)
    {
        return -1;
    }

    int maxNum = nums[0];
    int count = 1;

    for(int i = 1; i < iLen; i++)
    {
        if(nums[i] == maxNum)
        {
            count++;
        }
        else
        {
            count--;
        }

        if(count <= 0)
        {
            maxNum = nums[i];
            count = 1;
        }
    }

    return maxNum;
}

void rotate(vector<int>& nums, int k) 
{
    auto reverse = [&](int i, int j)
    {
        while (i < j)
        {
            swap(nums[i++], nums[j--]);
        }
    };

    int size = nums.size();
    k %= size;
    
    reverse(0, size-1);
    reverse(0, k-1);
    reverse(k, size-1);
}

int maxProfit(vector<int>& prices)
{
    int iMinPrice = INT_MAX;
    int iMaxRange = 0;

    for(int price : prices)
    {
        iMinPrice = min(iMinPrice, price);
        iMaxRange = max(iMaxRange,(price - iMinPrice));
    }

    return iMaxRange; 
}

int maxProfitSum(vector<int>& prices) 
{
    int iTodayRange = 0;
    int sum = 0;
    int size = prices.size();

    if(size <= 1)
    {
        return 0;
    }

    for(int i = 1; i < size; i++)
    {
        iTodayRange = prices[i] - prices[i-1];
        if(iTodayRange > 0)
        {
            sum += iTodayRange;
        }
    }

    return sum;
}

bool canJump(vector<int>& nums) 
{
    int size = nums.size();
    int iRoad = 0;

    for(int i = 0; i < size; i++)
    {
        if(iRoad < i) return false;     // 当前的路已经追不上人了

        iRoad = max(iRoad, i + nums[i]);
    }

    // 全部遍历完说明走到最后
    return true;
}

int jumpMinTimes(vector<int>& nums) 
{
    int iMax = 0;
    int iTmpEnd = 0;
    int iTimes = 0;
    int sizeIndex = nums.size() - 1;

    for(int i = 0;i <= sizeIndex; i++)
    {       
        // 走到本轮结束位置每次先+1 因此本轮能到终点至退出就好
        if(iTmpEnd >= sizeIndex) break;

        // 到达当前位置时次数才+1
        iMax = max(iMax, i + nums[i]);
        if(i == iTmpEnd)
        {
            iTimes++;
            iTmpEnd = iMax;
        }
    }

    return iTimes;
}

int hIndex(vector<int>& citations) 
{
    int iRet = 0;
    int size = citations.size();
    std::sort(citations.begin(), citations.end());

    for(int i = 0; i < size; i++)
    {
        if(citations[i] >= (size - i))
        {
            return size - i;
        }
    }

    return iRet;
}

vector<int> productExceptSelf(vector<int>& nums) 
{
    int size = nums.size();
    vector<int> vec(size);
    vector<int> vecLeft(size);
    vector<int> vecRight(size);
    int num = 1;

    if(size <= 1)
    {
        return vec;
    }

    for(int i = 0; i < size; i++)
    {
        num *= nums[i];
        vecLeft[i] = num;
    }

    num = 1;
    for(int i = size-1; i >= 0; i--)
    {
        num *= nums[i];
        vecRight[i] = num;
    }

    for(int i = 1; i < size - 1; i++)
    {
        vec[i] = vecLeft[i-1] * vecRight[i+1];
    }
    vec[0] = vecRight[1];
    vec[size-1] = vecLeft[size-2];

    return vec;
}

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
{
    int size = gas.size();
    int sum = 0;
    int minSum = INT_MAX;
    int minIndex = 0;

    for(int i = 0; i < size; i++)
    {
        sum += gas[i] - cost[i];
        if(sum < minSum)
        {
            minSum = sum;
            minIndex = i;
        }
    }

    // 亏最严重的一定放在后面
    return sum <= 0 ? -1 : (minIndex+1)%size;
}

int candy(vector<int>& ratings) 
{
    int size = ratings.size();

    if(size <= 1)
    {
        return 1;
    }

    vector<int> vecLeft(size, 1);
    vector<int> vecRight(size, 1);

    // 左遍历
    for(int i = 1; i < size; i++)
    {
        if(ratings[i] > ratings[i-1])
        {
            vecLeft[i] = vecLeft[i-1] + 1;
        }
    }

    int sum = vecLeft[size-1];
    for(int i = size-2; i >= 0; i--)
    {
        if(ratings[i] > ratings[i+1])
        {
            vecRight[i] = vecRight[i+1] + 1;
        }

        // 取最大值
        sum += max(vecLeft[i], vecRight[i]);
    }

    return sum;
}

int lengthOfLastWord(string s) 
{
    int j = s.size() - 1;

    // 去除末尾空格
    while(s.at(j) == ' ')
    {
        j--;
    }

    int i = j-1;
    while (i >= 0 && s.at(i) != ' ')
    {
        i--;
    }

    return j - i;
}

string longestCommonPrefix(vector<string>& strs) 
{
    string& s = strs[0];

    // 公共长度
    for(int j = 0; j <s.size(); j++)
    {
        // 遍历每个字符串
        for(string& str : strs)
        {
            // 退出条件：有一个字符串不相等或者有一个字符串长度结束
            if(str[j] != s[j] || j == str.size())
            {
                return s.substr(0, j);
            }
        }
    }

    return s;
}

string reverseWords(string s) 
{
    int i = s.size() - 1;
    string ret;

    while (i >= 0)
    {
        int cnt = 0;

        // 去除空格
        while(i >= 0 && s[i] == ' ') i--;
        while(i >= 0 && s[i] != ' ')
        {
            i--;
            cnt++;
        }

        if(cnt > 0)
        {
            ret += s.substr(i+1, cnt) + " "; 
        }
    }
    
    // 去除最后一个空格
    return ret.substr(0, ret.size()-1);
}

// 维护递减栈
int trap(vector<int>& height) 
{
    int ret = 0;
    stack<int> st;
    int size = height.size();

    // 遍历每个高度（找左右边界）
    for(int iRight = 0; iRight < size; iRight++)
    {
        // 栈非空 && 当前元素大于栈顶元素（右边界）
        while (!st.empty() && height[iRight] >= height[st.top()])
        {
            // 栈顶元素（低点）
            int bottom_h = height[st.top()];
            st.pop();

            // 找左边界 没有的话不计算
            if(st.empty())
            {
                break;
            }

            int iLeft = st.top();   // 左侧下一个更高的
            int h = min(height[iLeft], height[iRight]) - bottom_h;
            ret += (iRight - iLeft - 1) * h;
        }
        
        // 全部出栈更小元素后，这个数据入栈
        st.push(iRight);
    }

    return ret;
}

string convertZ(string s, int numRows)
{
    if(numRows < 2)
    {
        return s;
    }

    vector<string> rows(numRows);
    int iRow = 0;
    int iFlag = -1;
    string sRet;
    
    for(char c : s)
    {
        rows[iRow].push_back(c);
        // 边界反向
        if(iRow == 0 || iRow == numRows-1)
        {
            iFlag = -iFlag;
        }
        iRow += iFlag;
    }

    for(const string& s : rows)
    {
        sRet += s;
    }

    return sRet;
}

int strStr(string haystack, string needle) 
{
    int iRet = -1;

    int strSize = haystack.size();
    int subStrSize = needle.size();
    int iEnd = strSize - subStrSize;

    for(int i = 0; i <= iEnd; i++)
    {
        if(haystack.substr(i, subStrSize) == needle)
        {
            iRet = i;
            break;
        }
    }

    return iRet;
}

string DiffAve(vector<string> strVec, int width)
{
    int iSumWide = 0;
    int size = strVec.size();

    for(const string& str : strVec)
    {
        iSumWide += str.size();
    }
    iSumWide += size - 1;

    if(iSumWide > width)
    {
        return "";
    }

    int diff = width - iSumWide;
    int a = diff / (size - 1);      // 前num-2个元素后面跟a个空格
    int b = diff % (size - 1);      // 倒数第2个元素后面跟b个空格

    stringstream ss;
    if(size == 1)
    {
        ss << string(a, ' ');
        ss << strVec[0];
        ss << string(b, ' ');
    }
    else
    {
        for(int i = 0 ; i < size-2; i++)
        {
            ss << strVec[i];
            ss << string(a, ' ');
        }

        // 最后2个
        ss << strVec[size-2];
        ss << string(b, ' ');
        ss << strVec[size-1];
    }

    return ss.str();
}

bool isPalindrome(string s)
{
    bool bRet = true;
    int size = s.size();
    int i = 0;
    int j = size - 1 ;
    if(size <= 1)
    {
        return bRet;
    }

    while(i <= j)
    {
        while(i < j && !isdigit(s[i]) && !isalpha(s[i]))
        {
            i++;
        }

        while(i < j && !isdigit(s[j]) && !isalpha(s[j]))
        {
            j--;
        }

        if(i <= j && tolower(s[i]) == tolower(s[j]) )
        {
            i++;
            j--;
            continue;
        }
        else
        {
            bRet = false;
            break;
        }
    }

    return bRet;
}

bool isSubsequence(string s, string t) 
{
    int sSize = s.size();
    int tSize = t.size();

    if(sSize == 0)
    {
        return true;
    }

    int i = 0;
    int j = 0;
    while (j < tSize)
    {
        if(s[i] == t[j]) 
        {
            i++;
            if(i == sSize)
            {
                return true;
            }
        }
        j++;
    }

    return false; 
}

vector<int> twoSum(vector<int>& numbers, int target) 
{
    int i = 0;
    int j = numbers.size()-1;

    while(i < j)
    {
        if(numbers[i] + numbers[j] < target) i++;
        else if(numbers[i] + numbers[j] > target) j--;
        else return vector<int>{i+1, j+1};
    }

    return vector<int>{-1, -1};
}

int maxArea(vector<int>& height) 
{
    int i =0;
    int j = height.size()-1;
    int ret = 0;

    while(i < j)
    {
        if(height[i] < height[j]) 
        {
            ret = max(ret, (j-i) * height[i]);
            i++;
        }
        else 
        {
            ret = max(ret, (j-i) * height[j]);
            j--;
        }
    }

    return ret;
}

// [-4,-1,-1,0,1,2]
vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> ret;
    sort(nums.begin(), nums.end());
    int size = nums.size();
    int a = 0;
    while(a <= nums.size() - 2)
    {
        if(nums[a] > 0) break;

        int b = a+1;
        int c = size-1;

        // 固定a，双指针找b和c
        while(b < c)
        {
            if(nums[a] + nums[b] + nums[c] < 0) b++;
            else if(nums[a] + nums[b] + nums[c] > 0) c--;
            else 
            {
                ret.push_back(vector<int>{nums[a], nums[b], nums[c]});
                b++;
                c--;
            }

            // 去重
            while(b > a+1 && b < size-1 && nums[b] == nums[b-1]) b++; 
            while(c >= 1 && c < size-1 && nums[c] == nums[c+1]) c--;
        }

        // a去重
        a++;
        while(a >=1 && a < size-2 && nums[a] == nums[a-1]) a++; 
    }

    return ret;
}

int minSubArrayLen(int target, vector<int>& nums) 
{
    int iMinLen = INT_MAX;
    int sum = 0;
    int i = 0;

    // 窗口一直右移
    for(int j = 0; j < nums.size(); j++)
    {
        sum += nums[j];
        // 和大于等于sum时窗口左边右移一位,一只移动到不满足
        while(sum >= target)
        {
            iMinLen = min(iMinLen, (j-i+1));
            sum -= nums[i++];
        }
    }

    return iMinLen == INT_MAX ? 0 : iMinLen;
}

int lengthOfLongestSubstring(string s) 
{
    int i = -1; //只有一个字符时可以输出1
    int ret = 0;
    int len = s.length();
    unordered_map<char, int> map;   // value是最后出现下标

    for(int j = 0; j < len; j++ )
    {
        auto iter = map.find(s[j]);
        if(iter != map.end() )
        {
            // 更新窗口左侧,上一次出现的位置
            i = max(i, iter->second);
        }
        map[s[j]] = j;
        ret = max(ret, (j-i) );
    }

    return ret;
}


string minWindow(string s, string t) 
{
    int m = s.size();
    int n = t.size();
    if(m < n) return "";

    unordered_map<char, int> cnt_s,cnt_t;   // 两个记录字母和数量的map
    for(char ch : t) cnt_t[ch]++;   // 拆解子串t
    int ret_l = -1, ret_r = m;
    string ret;

    // 这个函数判断cnt_s全包含cnt_t
    function<bool()> check = [&]()
    {
        for(const pair<char, int>& p : cnt_t)
        {
            if(cnt_s.find(p.first) == cnt_s.end()) return false; // s中没有字母
            if(p.second > cnt_s.at(p.first )) return false;     // 该字母次数满足
        }
        return true;
    };

    // 每次右端点右移一位
    for(int l = 0, r = 0; r < m; r++)
    {
        cnt_s[s[r]]++; //s的右端点加入
        // 左端点一直右移到最小
        while(check())
        {
            if(r-l < ret_r-ret_l)
            {
                ret_l = l;
                ret_r = r;
            }
            cnt_s[s[l++]]--;    //左端点右移
        }
    }

    return ret_l == -1 ? "" : s.substr(ret_l,ret_r - ret_l + 1);
}

bool canConstruct(string ransomNote, string magazine) 
{
    std::unordered_map<char, int> map;

    for(char c : magazine)
    {
        map[c]++;
    }

    for(char c : ransomNote)
    {
        if(map[c] == 0)
        {
            return false;
        }
        map[c]--;
    }

    return true;
}

bool isIsomorphic(string s, string t)
{
    int sizeS = s.size();
    int sizeT = t.size();
    if(sizeS != sizeT) return false;

    std::unordered_map<char, int> sMap;
    std::unordered_map<char, int> TMap;

    for(int i = 0; i < sizeS; i++)
    {
        if(sMap[s[i]] != TMap[t[i]])
        {
            return false;
        }

        // 记录上一次出现的下标，防止默认位置是0
        sMap[s[i]] = i + 1;
        TMap[t[i]] = i + 1;
    }

    return true;
}

bool wordPattern(string pattern, string s)
{
    int size1 = pattern.size();

    // ------分隔字符串------
    int size = s.size();
    vector<string> vec;
    int wordStart = 0;  // 单词的起点索引
    int wordEnd = 0;    // 单词的终点索引（边界或指向空格），不包含
    while(wordEnd < size)
    {
        while (wordEnd < size && s[wordEnd] == ' ') wordEnd++;  // 跳过连续的空格
        wordStart = wordEnd;  // 设置下一个单词的起点
        while (wordEnd < size && s[wordEnd] != ' ') wordEnd++; // 找这次的字符串直到分隔符
        if (wordStart < wordEnd) 
        {
            vec.push_back(s.substr(wordStart, wordEnd - wordStart));
        }
    }

    int size2 = vec.size();
    if(size1 != size2) return false;

    std::unordered_map<char, int> map1;
    std::unordered_map<string, int> map2;

    for(int i = 0; i < size1; i++)
    {
        if(map1[pattern[i]] != map2[vec[i]] )
        {
            return false;
        }

        // 记录上一次出现的下标，防止默认位置是0
        map1[pattern[i]] = i + 1;
        map2[vec[i]] = i + 1;
    }

    return true;
}

bool isAnagram(string s, string t)
{
    int size1 = s.size();
    int size2 = t.size();
    if(size1 != size2) return false;

    std::unordered_map<char, int> map1,map2;

    for(int i = 0; i < size1; i++)
    {
        map1[s[i]]++;
        map2[t[i]]++;
    }

    // 两个map如果完全相等的话，那么key和value一定一样，只要找到一个不一样就退出
    for(auto iter = map1.begin(); iter != map1.end(); iter++)
    {
        if(iter->second != map2[iter->first])
        {
            return false;
        }
    }

    return true;
}

vector<vector<string>> groupAnagrams(vector<string>& strs)
{
    std::unordered_map<string, std::vector<string> > map;
    for(auto& s : strs)
    {
        string sTmp = s;
        std::sort(sTmp.begin(), sTmp.end());
        map[sTmp].push_back(s);     // key是排序好的字符串，value是一堆原始字符串
    }

    vector<vector<string> > retVec;
    retVec.reserve(map.size());

    // _是占位符，即map的key不关注
    for(auto& [_, tmpVec] : map)
    {
        retVec.push_back(tmpVec);
    }

    return retVec;
}

bool isHappy(int n)
{
    auto getNum = [](int n)
    {
        int sum = 0;
        while(n)
        {
            sum += (n%10)*(n%10);
            n /= 10;
        }
        return sum;
    };

    std::unordered_set<int> set;
    while(n != 1)
    {
        n = getNum(n);
        if(set.count(n)) return false;
        else set.insert(n);
    }

    return true;


}

bool containsNearbyDuplicate(vector<int>& nums, int k)
{
    int size = nums.size();
    std::unordered_map<int, int> map;

    for(int i = 0; i < size; i++)
    {
        if(map.count(nums[i]))
        {
            int iLast = map[nums[i]];
            if(i - iLast <= k)
            {
                return true;
            }
        }
        map[nums[i]] = i;
    }

    return false;
}

int longestConsecutive(vector<int>& nums)
{
    int size = nums.size();
    int maxLen = 1;
    int nowLen = 1;
    int pre = 0;

    std::sort(nums.begin(), nums.end() );
    if(size == 0) return 0;

    for(int j = 1; j < size ;j++)
    {
        pre = j-1;
        while(j < size && nums[j] == nums[j-1]) j++;    // 跳过重复元素

        if(j < size)
        {
            if(nums[j] == nums[pre] + 1 )
            {
                nowLen++;
                maxLen = max(maxLen, nowLen );
            } 
            else
            {
                nowLen = 1;
            }
        }
    }

    return maxLen;
}

vector<string> summaryRanges(vector<int>& nums)
{
    std::vector<string> ret;
    int size = nums.size();

    for(int i = 0,j; i < size ; i++)
    {
        j = i + 1;
        while(j < size && nums[j] - nums[j-1] == 1 ) j++;
        
        string str = "";
        if(j == i + 1 )
        {
            str += to_string(nums[i]);
        }
        else
        {
            str += to_string(nums[i]) + "->" + to_string(nums[j-1]);
        }

        ret.push_back(str);

        i = j-1;
    }

    return ret;
}

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
    std::sort(intervals.begin(), intervals.end() );
    vector<vector<int>> ret;
    int size = intervals.size();

    for(int i = 0; i < size; )
    {
        int t = intervals[i][1];    // 区间右侧
        int j = i + 1;

        while (j < size && intervals[j][0] <= t)    //区间左侧在区间内，拓展区间右侧
        {
            t = max(t, intervals[j][1] );
            j++;
        }

        ret.push_back(vector<int>{intervals[i][0], t} );
        i = j;  // i 重新赋值ß
    }

    return ret;
}

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
{
    intervals.push_back(newInterval);

    return merge(intervals);
}

int findMinArrowShots(vector<vector<int>>& points)
{
    int size = points.size();
    std::sort(points.begin(), points.end() );
    int ret = 0;
    int l = points[0][0];
    int r = points[0][1];

    for(int i = 1; i < size; i++)
    {
        // 左端点在最小区间内 表示有交集
        if(points[i][0] <= r)
        {
            l = max(l, points[i][0]);
            r = min(r, points[i][1]);
        }
        else
        {
            ret++;
            l = points[i][0];
            r = points[i][1];   //新区间
        }
    }

    return ret+1;

}

bool isValid(string s)
{
    std::unordered_map<char, int> dic = { {'(', 1} , {'[', 2} , {'{', 3}, 
                                          {')', 11}, {']', 12}, {'}', 13}};
    std::stack<int> stack;
            
    for(char c : s)
    {
        if(dic[c] < 10)
        {
            stack.push(dic[c]);
        }
        else
        {
            if(stack.empty())
            {
                return false;
            } 
            char cTmp = dic[c] - 10;
            if(stack.top() == dic[c] - 10)
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
    }

    // 是否全部配对
    if(!stack.empty())
    {
        return false;
    }

    return true;
}

int evalRPN(vector<string>& tokens)
{
    std::stack<int> stack;
    int i,j = 0;
    for(auto& c : tokens)
    {
        if(c != "+" && c != "-" && c != "*" && c != "/")
        {
            stack.push(stoi(c));
        }
        else
        {
            // 每次取两个数运算
            i = stack.top();
            stack.pop();
            j = stack.top();
            stack.pop();

            if(c == "+") stack.push(j + i); 
            else if(c == "-") stack.push(j - i); 
            else if(c == "*") stack.push(j * i); 
            else if(c == "/") stack.push(j / i); 
        }
    }

    return stack.top();
}

int calculate(string s) 
{
    stack<int> sign;
    sign.push(1);
    int num = 0;
    int op = 1;
    int res = 0;

    for(char ch : s)
    {
        if(isdigit(ch))
        {
            num = num * 10 + (ch - '0');
            continue;
        }
        
        res += op * num;
        num = 0;

        if (ch == '+') op = sign.top(); // 与括号外面符号结合起来
        else if (ch == '-') op = -sign.top(); // 与括号外面符号结合起来
        else if (ch == '(') sign.push(op);  //进入左括号，把左括号之前的符号置于栈顶
        else if (ch == ')') sign.pop();     //退出括号，弹出栈顶符号
    }
    res += op * num;

    return res;
}

bool hasCycle(ListNode *head) 
{
    ListNode* fast = head;
    ListNode* slow = head;
    
    while(fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;    
        // 指针判断 即使为空也无所谓
        if(slow == fast)
        {
            return true;
        }
    }

    return false;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
{
    ListNode* lpHead = nullptr;
    ListNode* lpTail = nullptr;
    int32_t carry = 0;

    while(l1 || l2)
    {
        int n1 = l1 ? l1->val : 0;
        int n2 = l2 ? l2->val : 0;
        int sum = n1 + n2 + carry;

        if(!lpHead)
        {
            lpHead = lpTail = new ListNode(sum % 10);
        }
        else
        {
            lpTail->next = new ListNode(sum % 10);
            lpTail = lpTail->next;
        }

        carry = sum / 10;

        if(l1)
        {
            l1 = l1->next;
        } 
        if(l2) 
        {
            l2 = l2->next;   
        }
    }
    
    // 多出一位
    if(carry > 0)
    {
        lpTail->next = new ListNode(carry);
    }

    return lpHead;
}

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2)
{
    ListNode* lpHead = new ListNode(-1);
    ListNode* lpRet = lpHead;

    while (list1 && list2)
    {
        if(list1->val < list2->val)
        {
            lpRet->next = new ListNode(list1->val);
            list1 = list1->next;
        }
        else
        {
            lpRet->next = new ListNode(list2->val);
            list2 = list2->next;
        }

        lpRet = lpRet->next;
    }
    
    lpRet->next = list1 == nullptr ? list2 : list1;

    return lpHead->next;
}

ListNode* reverseBetween(ListNode* head, int left, int right) 
{
    ListNode* lpHead = new ListNode(0, head);
    ListNode* rePre = lpHead;
    int iCount = 1;

    // 找到翻转开始前一个节点
    while(iCount < left)
    {
        rePre = rePre->next;
        iCount++;
    }

    ListNode* reHead = rePre->next;

    // 翻转
    ListNode* cur = reHead;
    ListNode* next;
    ListNode* last;
    // 3个指针，cur每次后移，把cur的next赋值成last
    while(iCount <= right)
    {
        iCount++;
        next = cur->next;
        cur->next = last;
        last = cur;
        cur = next;
    }

    // 拼接
    rePre->next = last;  // 头的下一个是区间的尾
    reHead->next = cur;  // 区间头的下一个是尾 

    return lpHead->next;
}

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode* newList = new ListNode(0, head);
    ListNode* l = newList;
    ListNode* r = newList;

    for(int i = 0; i < n; i++)
    {
        r = r->next;
    }

    while(r->next)
    {
        l = l->next;
        r = r->next;
    }

    ListNode* lNext = l->next;
    l->next = lNext->next;

    return newList->next;
}

ListNode* deleteDuplicates(ListNode* head) 
{
    ListNode* lpHead = new ListNode(0, head);
    ListNode* cur = lpHead;

    // 从当前位置往后看，存在还存在两个，就可能相同
    while (cur->next && cur->next->next)
    {
        int32_t val = cur->next->val;

        // 重复的数字直接全去掉
        if(cur->next->next->val == val)
        {
            while (cur->next && cur->next->val == val)
            {
                cur->next = cur->next->next;
            }
        }
        else
        {
            cur = cur->next;
        }
    }
    
    return lpHead->next;
}

ListNode* rotateRight(ListNode* head, int k) 
{
    if (k == 0 || head == nullptr || head->next == nullptr) 
    {
        return head;
    } 

    int32_t iNum = 1;
    ListNode* iterEnd = head;
    // 统计链表个数
    while (iterEnd->next)
    {
        iNum++;
        iterEnd = iterEnd->next;
    }
    
    int32_t iDiff = iNum - k % iNum;
    if(iDiff == iNum || iDiff == 0)
    {
        return head;
    }

    // 找到分界处 重新拼接
    int32_t iTmpNum = 1;
    ListNode* iter = head;
    while(iTmpNum < iDiff)
    {
        iTmpNum++;
        iter = iter->next;
    }
    ListNode* lpNewHead = iter->next;
    iter->next = nullptr;
    iterEnd->next = head;

    return lpNewHead;
}

int maxDepth(TreeNode* root) 
{
    if(1)
    {
        // 方法1 DFS 递归或者栈
        if(root == nullptr)
        {
            return 0;
        }
    
        return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
    else
    {
        // 方法2 BFS 层次遍历
        if(root == nullptr)
        {
            return 0;
        }

        std::queue<TreeNode*> queue;
        queue.push(root);
        int i = 0;
        while (!queue.empty())
        {
            // 把这一层都遍历完
            int size = queue.size();
            for(int i = 0; i < size; i++)
            {
                TreeNode* curNode = queue.front();
                queue.pop();

                if(curNode->left)
                {
                    queue.push(curNode->left);
                }
                if(curNode->right)
                {
                    queue.push(curNode->right);
                }
            }

            i++;
        }
        
        return i;
    }
}

bool isSameTree(TreeNode* p, TreeNode* q) 
{
    if(p == nullptr || q == nullptr)
    {
        return p == q;
    }

    return (p->val == q->val) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

TreeNode* invertTree(TreeNode* root) 
{
    // 空节点递归结束
    if(root == nullptr) return nullptr;

    TreeNode* tmp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(tmp);

    return root; 
}

bool isSymmetric(TreeNode* root)
{
    // 函数入参只有一个节点，无法直接递归调用，因此要新函数
    if(root == nullptr)
    {   
        return true;
    }

    std::function<bool(TreeNode*, TreeNode*)> is_symmetric = [&](TreeNode* left, TreeNode* right)->bool
    {
        if(left == nullptr && right == nullptr) return true;
        if(left == nullptr || right == nullptr || left->val != right->val) return false;
    
        return (is_symmetric(left->left, right->right) && is_symmetric(left->right, right->left));
    };

    return is_symmetric(root->left, root->right);
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    // 只能处理无重复元素的二叉树
    unordered_map<int, int> dic;
    // 记录中序元素的值和位置关系(用中序去拆分)
    for(int i = 0; i < inorder.size(); i++)
    {
        dic[inorder[i]] = i;
    }

    // root-根节点在前序位置 left左节点中序位置
    std::function<TreeNode*(int, int, int)> innerFunc = [&](int root, int left, int right)->TreeNode*
    {
        if(left > right) return nullptr;
        TreeNode* node = new TreeNode(preorder[root]);  // 前序中建立根节点
        int idx = dic[preorder[root]];  // 找到根节点值对应的中序中的位置
        // 左子树 
        // 前序：根节点在前序的后一个
        // 中序：左是left，右是idx根的左边
        node->left = innerFunc(root+1, left, idx-1);     
        // 右子树
        // 前序：根root往后偏移左子树的数量(idx-left),再偏移1
        // 中序：左是idx根的右边，右是right
        node->right = innerFunc(root+(idx-left)+1, idx+1, right);
        return node;
    };

    //前序中的根0，中序的左0，右size-1
    return innerFunc(0, 0, inorder.size()-1);
}

TreeNode* buildTree2(vector<int>& inorder, vector<int>& postorder)
{
    // 只能处理无重复元素的二叉树
    unordered_map<int, int> dic;
    // 记录中序元素的值和位置关系(用中序去拆分)
    for(int i = 0; i < inorder.size(); i++)
    {
        dic[inorder[i]] = i;
    }

    // root-根节点在后序位置 left左节点中序位置
    std::function<TreeNode*(int, int, int)> innerFunc = [&](int root, int left, int right)->TreeNode*
    {
        if(left > right) return nullptr;
        TreeNode* node = new TreeNode(postorder[root]);  // 前序中建立根节点
        int idx = dic[postorder[root]];  // 找到根节点值对应的中序中的位置
        // 左子树 
        // 后序：根节点往前偏移右子树的数量(right-idx),再偏移1
        // 中序：左是left，右是idx根的左边
        node->left = innerFunc(root-(right-idx)-1, left, idx-1);     
        // 右子树
        // 后序：根节点的前一个
        // 中序：左是idx根的右边，右是right
        node->right = innerFunc(root-1, idx+1, right);
        return node;
    };

    //后序中的根0，中序的左0，右size-1
    return innerFunc(postorder.size()-1, 0, inorder.size()-1);
}

bool hasPathSum(TreeNode* root, int targetSum)
{
    if(root == nullptr) return false;

    targetSum -= root->val;
    if(root->left == nullptr && root->right == nullptr)
    {
        return targetSum == 0;
    }

    return hasPathSum(root->left, targetSum) || hasPathSum(root->right, targetSum);
}

int countNodes(TreeNode* root)
{
    int num = 0;

    if(root == nullptr)
    {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

Node* connect(Node* root)
{
    if(root == nullptr) return nullptr;

    vector<Node*> vec = {root};
    while (!vec.empty())
    {
        int size = vec.size();
        for(int i = 0; i < size; i++)
        {
            Node* tmp = vec[i];
            if(i > 0)
            {
                vec[i-1]->next = tmp;
            }
            if(tmp->left) vec.push_back(tmp->left);
            if(tmp->right) vec.push_back(tmp->right);
        }

        // vec去除前size个元素
        vec.erase(vec.begin(), vec.begin()+size);
    }

    return root;
}

void flatten(TreeNode* root)
{
    std::function<TreeNode*(TreeNode*)> dfs = [&](TreeNode* root) -> TreeNode*
    {
        if(root == nullptr) return nullptr;

        TreeNode* leftTail = dfs(root->left);
        TreeNode* rightTail = dfs(root->right);

        // 左子树存在，把左子树右下角的next链接为右子树
        // 构建返回的链表:根的左null，根的右是根原先的左
        if(leftTail)
        {   
            leftTail->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }

        // 依次返回右子树、左子树、根
        return rightTail ? rightTail : (leftTail ? leftTail : root);
    };

    dfs(root);
}

int sumNumbers(TreeNode* root)
{
    int ret = 0;
    
    std::function<void(TreeNode*, int)> dfs = [&](TreeNode* root, int num) -> void
    {
        if(root == nullptr)
        {
            return;
        }

        num = num*10 + root->val;
        // 叶子节点 返回值累加这条路径的数值
        if(root->left == nullptr && root->right == nullptr)
        {
            ret += num;
            return;
        }
        
        dfs(root->left, num);
        dfs(root->right, num);
    };
    
    dfs(root, 0);
    return ret;
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if (!root || root == p || root == q) return root;
    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;
    return left ? left : right;
}

int maxPathSum(TreeNode* root)
{
    std::function<int(TreeNode* , int&)> maxPathSum = [&](TreeNode* root, int &val) -> int
    {
        if (root == nullptr) return 0;
	int left = maxPathSum(root->left, val);
	int right = maxPathSum(root->right, val);
	int lmr = root->val + max(0, left) + max(0, right);
    // ret是这个节点作为一条分支，和别人拼接的最大值，因此只能与左或者右的一个
	int ret = root->val + max(0, max(left, right));
    // val是这个节点最为根
	val = max(val, max(lmr, ret));
	return ret;
    };

    int val = INT_MIN;
    maxPathSum(root, val);
    return val;
}