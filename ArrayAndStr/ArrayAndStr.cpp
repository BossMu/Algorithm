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

    // 窗口右端一直右移，大于目标值后窗口左端开始收缩，像一只毛毛虫一样蠕动
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
            // char cTmp = dic[c] - 10;
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
    // int num = 0;

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

// vector<int> rightSideView(TreeNode* root)
// {
//     vector<int> ret;

//     // this auto&& dfs  递归调用自己
//     auto dfs = [&](this auto&& dfs, TreeNode* root, int depth) -> void
//     {
//         if(root == nullptr) return;

//         // 这一层首次遍历到，一定是最右边的
//         if(depth == ret.size())
//         {
//             ret.push_back(root->val);
//         }

//         dfs(root->right, depth+1);
//         dfs(root->left, depth+1);
//     };

//     dfs(root, 0);
//     return ret;
// }

vector<double> averageOfLevels(TreeNode* root)
{
    vector<double> ret;
    queue<TreeNode* > queue;
    if(root)
    {
        queue.push(root);
    }

    // 每一层都要取这一层的个数总和
    while (!queue.empty())
    {
        double sum = 0;
        int size = queue.size();
        for(int i =0;i < size ; i++)
        {
            TreeNode* node = queue.front();
            queue.pop();
            sum += node->val;
            if(node->left) queue.push((node->left));
            if(node->right) queue.push((node->right));
        }
        ret.push_back(sum/size);
    }
    
    return ret;
}

vector<vector<int>> levelOrder(TreeNode* root)
{
    vector<vector<int>> ret;
    queue<TreeNode*> que;

    if(root) que.push(root);

    while (!que.empty())
    {
        vector<int> vec;
        int size = que.size();
        for(int i = 0; i < size; i++)
        {
            TreeNode* node = que.front();
            que.pop();
            vec.push_back(node->val);
            if(node->left) que.push((node->left));
            if(node->right) que.push((node->right));
        }
        ret.push_back(vec);
    }
    
    return ret;
}

vector<vector<int>> zigzagLevelOrder(TreeNode* root)
{
    vector<vector<int>> ret;
    queue<TreeNode*> que;

    if(root) que.push(root);

    while (!que.empty())
    {
        // 奇数
        vector<int> tmp;
        int size = que.size();
        for(int i = size; i > 0; i--)
        {
            TreeNode* node = que.front();
            que.pop();
            tmp.push_back(node->val);
            if(node->left) que.push((node->left));
            if(node->right) que.push((node->right));
        }

        if(ret.size() % 2 == 1) reverse(tmp.begin(), tmp.end());
        ret.push_back(tmp);
    }
    
    return ret;
}

int getMinimumDifference(TreeNode* root)
{
    int iMin = INT_MAX;
    TreeNode* lpPre = nullptr;

    std::function<void(TreeNode*)> inorder = [&](TreeNode* node)  
    {
        if(node == nullptr) return;
        inorder(node->left);
        if(lpPre)
        {
            iMin = min(iMin, abs(node->val-lpPre->val));
        }
        lpPre = node;
        inorder(node->right);
    };

    inorder(root);

    return iMin;
}

bool isValidBST(TreeNode* root)
{
    TreeNode* lpPre = nullptr;

    std::function<bool(TreeNode*)> inorder = [&](TreeNode* node)
    {
        if(node == nullptr) return true;

        if(!inorder(node->left)) return false;
        if(lpPre)
        {
            if(lpPre->val >= node->val) return false;
        }

        lpPre = node;

        return inorder(node->right);
    };

    return inorder(root);
}

int kthSmallest(TreeNode* root, int k)
{
    int i = 0;
    int ret = 0;
    std::function<void(TreeNode*)> dfs = [&](TreeNode* node) -> void
    {
        if(node == nullptr) return;

        dfs(node->left);

        i++;
        if(i == k)
        {
            ret = node->val;
            return;
        }

        dfs(node->right);
    };

    dfs(root);
    return ret;
}

int numIslands(vector<vector<char>>& grid)
{
    int iRow = grid.size();
    int iCol = grid[0].size();
    int iCount = 0;

    std::function<void(vector<vector<char>>&, int, int)> dfs = [&](vector<vector<char>>& grid, int i, int j) -> void
    {
        if(i < 0 || j < 0 || i >= iRow || j >= iCol) return;
        if(grid[i][j] != '0') return;

        grid[i][j] = '#';
        dfs(grid, i-1, j);
        dfs(grid, i+1, j);
        dfs(grid, i, j-1);
        dfs(grid, i, j+1);
    };

    for(int i = 0; i < iRow; i++)
    {
        for(int j = 0; j < iCol; j++)
        {
            if(grid[i][j] == '1')
            {
                dfs(grid, i, j);
                iCount++;
            }
        }
    }

    return iCount;
}

void solve(vector<vector<char>>& board)
{
    int iRow = board.size();
    int iCol = board[0].size();

    std::function<void(vector<vector<char>>&, int, int)> dfs = [&](vector<vector<char>>& board, int i, int j) -> void
    {
        if(i < 0 || j < 0 || i >= iRow || j >= iCol) return;
        if(board[i][j] != 'O') return;

        board[i][j] = '#';
        dfs(board, i-1, j);
        dfs(board, i+1, j);
        dfs(board, i, j-1);
        dfs(board, i, j+1);
    };

    // 把边缘临时处理
    for(int i = 0; i < iRow; i++)
    {
        if(board[i][0] == 'O') dfs(board, i, 0);
        if(board[i][iCol-1] == 'O') dfs(board, i, iCol-1);
    }
    for(int j = 0; j < iCol; j++)
    {
        if(board[0][j] == 'O') dfs(board, 0, j);
        if(board[iRow-1][j] == 'O') dfs(board, iRow-1, j);
    }

    // 全遍历一次 重新上色
    for(int i = 0; i < iRow; i++)
    {
        for(int j = 0; j < iCol; j++)
        {
            if(board[i][j] == 'O') board[i][j] = 'X';
            if(board[i][j] == '#') board[i][j] = 'O';
        }
    }
}


bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
    // 每个点分3个状态 0-未访问 1-正在访问该环 2-访问完
    vector<vector<int>> g(numCourses);
    for(auto& p : prerequisites)
    {
        g[p[1]].push_back(p[0]);
    }

    vector<int> colors(numCourses);
    std::function<bool(int)> dfs = [&](int x) -> bool
    {
        colors[x] = 1;
        for(int y : g[x])
        {
            if(colors[y] == 1 || (colors[y] == 0 && dfs(y)) )
            {
                return true;
            }
        }
        colors[x] = 2;
        return false;
    };

    for(int i = 0; i < numCourses; i++)
    {
        // 未访问过并且有环
        if(colors[i] == 0 && dfs(i))
        {
            return false;
        }
    }
    return true;
}

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
{
    vector<vector<int>> g(numCourses);
    vector<int> indegree(numCourses, 0);
    for(auto& p : prerequisites)
    {
        g[p[1]].push_back(p[0]);    //学完1后可以学2、3、4
        indegree[p[0]]++;           // 学2之前需要学一门
    } 

    // 入度为0的先学（课程都是从0开始的，因此下标就是编号主键）
    vector<int> queue;
    for(int i = 0; i < numCourses; i++)
    {
        if(indegree[i] == 0) queue.push_back(i);
    }

    // 拓扑
    vector<int> ret;
    while(!queue.empty())
    {
        int node = queue.back();
        queue.pop_back();
        ret.push_back(node);

        // 找他的所有邻居节点
        for(int nb : g[node])
        {
            indegree[nb]--;
            if(indegree[nb] == 0) queue.push_back(nb);  // 遍历中入度为0的表示没有前置依赖课程
        }
    }

    if(ret.size() >= numCourses) return ret;
    return {};
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    std::function<TreeNode*(int, int)> dfs = [&](int left, int right) ->  TreeNode*
    {
        if(left == right) return nullptr;
        int m = (left+right) / 2;

        return new TreeNode(nums[m], dfs(left, m), dfs(m+1, right));
    };

    // 注意这里，right是size，因为右侧分治时是+1
    return dfs(0, nums.size());
}
class Node4
{
    class Node 
    {
    public:
        bool val;
        bool isLeaf;
        Node* topLeft;
        Node* topRight;
        Node* bottomLeft;
        Node* bottomRight;
        
        Node() {
            val = false;
            isLeaf = false;
            topLeft = NULL;
            topRight = NULL;
            bottomLeft = NULL;
            bottomRight = NULL;
        }
        
        Node(bool _val, bool _isLeaf) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = NULL;
            topRight = NULL;
            bottomLeft = NULL;
            bottomRight = NULL;
        }
        
        Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
            val = _val;
            isLeaf = _isLeaf;
            topLeft = _topLeft;
            topRight = _topRight;
            bottomLeft = _bottomLeft;
            bottomRight = _bottomRight;
        } 
    };

    Node* construct(vector<vector<int>>& grid) 
    {
        int s = grid.size();
        return inner_construct(grid,0,0,s-1,s-1);
    }
    Node* inner_construct(vector<vector<int>>& grid, int lur, int luc, int rdr, int rdc)
    {
        int area = (rdc - luc + 1) * (rdr - lur + 1);
        // 最小递归单元
        if(area == 1)
        {
            return new Node(grid[lur][luc], true);
        }

        int mid_r = lur + (rdr - lur + 1) / 2;
        int mid_c = luc + (rdc - luc + 1) / 2;
        Node* node_left_up = inner_construct(grid, lur, luc, mid_r-1, mid_c-1);
        Node* node_right_up = inner_construct(grid, lur, mid_c, mid_r-1, rdc);
        Node* node_left_down = inner_construct(grid, mid_r, luc, rdr, mid_c-1);
        Node* node_right_down = inner_construct(grid, mid_r, mid_c, rdr, rdc);
        if(node_left_up->isLeaf && node_right_up->isLeaf && node_left_down->isLeaf && node_right_down->isLeaf &&
        (node_left_up->val == node_right_up->val && node_left_up->val == node_left_down->val && node_left_up->val == node_right_down->val))
        {
            return new Node(node_left_up->val, true);
        }
        else
        {
            return new Node(0, false, node_left_up, node_right_up, node_left_down, node_right_down);
        }
    } 
};

string simplifyPath(string path)
{
    istringstream ss(path);
    string s;
    vector<string> vec; // 栈+队列一起用

    // 处理字符串到数组中
    while (getline(ss, s,'/'))
    {
        // 空串或者当前路径跳过
        if(s.empty() || s == ".")
        {
            continue;
        }

        if(s != "..")
        {
            vec.push_back(s);
        }
        else
        {
            if(!vec.empty())
            {
                vec.pop_back();
            }
        }
    }
    
    string sRet;
    for(auto& s : vec)
    {
        sRet += "/";
        sRet += s;
    }

    return sRet.empty() ? "/" : sRet;
}

// [链表]深拷贝随机链表
RandomNode::Node* RandomNode::copyRandomList(RandomNode::Node* head)
{
    if(head == nullptr)
    {
        return head;
    }

    Node* lpCur = head;
    unordered_map<Node*, Node*> map;

    // 第一次遍历，创建新节点、插入map
    while (lpCur != nullptr)
    {
        map[lpCur] = new Node(lpCur->val);
        lpCur = lpCur->next;
    }
    
    // 第二次遍历，维护指针关系
    lpCur = head;
    while (lpCur != nullptr)
    {
        map[lpCur]->next = map[lpCur->next];
        map[lpCur]->random = map[lpCur->random];
        lpCur = lpCur->next;
    }
    
    return map[head];
}

vector<string> letterCombinations(string digits)
{
    if(digits.empty())
    {
        return {};
    }

    unordered_map<char, string> map
    {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
        {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    
    vector<string> res;
    string path;
    const int len = digits.length();

    // 方法一：auto 
    /* 
    auto traceback = [&](auto&& self, int i) -> void
    {
        // 长度一致退出
        if(i == len)
        {
            res.push_back(path);
            return;
        }

        for(char ch : map[digits[i]])
        {
            path.push_back(ch);
            // 递归下一位
            self(self, i+1);
            // 回溯
            path.pop_back();    // 删除字符串最后一个字符
        }
    };
    */

    // 方法二：std:function
    std::function<void(int)> traceback = [&](int i) -> void
    {
        // 终止条件：遍历完所有数字
        if (i == digits.length()) {
            res.push_back(path);
            return;
        }

        // 遍历当前数字对应的所有字母
        for (char ch : map[digits[i]]) {
            path.push_back(ch);   // 做选择
            traceback(i + 1);     // 递归调用（直接写traceback，无需传self）
            path.pop_back();      // 撤销选择
        }
    };

    // traceback(traceback, 0); // 方法一
    traceback(0);   // 方法二

    return res;
}

// [回溯]组合
vector<vector<int>> combine(int n, int k)
{
    vector<vector<int>> res;
    vector<int> path;

    std::function<void(int)> func = [&](int start)
    {
        // 退出条件,本轮完成，插入
        if(path.size() == k)
        {
            res.push_back(path);
            return; 
        }

        // 剪枝
        int need = k - path.size();
        int end = n - need + 1;

        // 回溯 eg(4,4)  121-4 后，把1退出，变成1221
        for(auto i = start; i <= end; i++)
        {
            path.push_back(i);
            func(i+1);
            path.pop_back();
        }
    };

    func(1);

    return res;
}

// 
vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> res;
    vector<int> tmp;
    int size = candidates.size();

    std::function<void(int,int)> func = [&](int start, int sum)
    {
        // 退出条件
        if(sum == target)
        {
            res.push_back(tmp);
            return;
        }

        // 剪枝
        if(sum > target)
        {
            return;
        }

        // 递归回溯
        for(int i = start; i < size; i++)
        {
            tmp.push_back(candidates[i]);
            func(i, sum+candidates[i]);
            tmp.pop_back();
        }
    };

    func(0, 0);
    return res;
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string tmp;

    std::function<void(int, int)> func = [&](int leftNum, int rightNum)
    {
        // 总数量2n表示结束
        if(tmp.size() == 2*n)
        {
            res.push_back(tmp);
            return;
        }

        // 只要左括号数量小于n既可以添加
        if(leftNum < n)
        {
            tmp.push_back('(');
            func(leftNum+1, rightNum);
            tmp.pop_back();
        }

        // 只要右括号数量小于左括号就可以添加
        if(rightNum < leftNum)
        {
            tmp.push_back(')');
            func(leftNum, rightNum+1);
            tmp.pop_back();
        }
    };

    func(0, 0);
    return res;
}

bool exist(vector<vector<char>>& board, string word) 
{
    int m = board.size();
    int n = board[0].size();

    std::function<bool(int,int,int)> func = [&](int i, int j, int index)
    {
        // 退出
        if(index == word.size())
        {
            return true;
        }

        if(i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index])
        {
            return false;
        }

        // 标记
        char tmp = board[i][j];
        board[i][j] = '\0'; //不允许重复

        bool b = false;
        if(!b) b = func(i-1,j,index+1);
        if(!b) b = func(i+1,j,index+1);
        if(!b) b = func(i,j-1,index+1);
        if(!b) b = func(i,j+1,index+1);

        // 回退
        board[i][j] =tmp;
        return b;
    };

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(func(i, j, 0)) 
            {
                return true;
            }
        }
    }

    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target)
{
    int m = matrix.size();
    int n = matrix[0].size();

    int l = -1;
    int r = m*n;

    while (l+1 < r)
    {
        int mid = l + (r-l)/2;
        int x = matrix[mid/n][mid%n];
        if(x == target)
        {
            return true;
        }

        if(x < target)
        {
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    
    return false;
}

int findPeakElement(vector<int>& nums)
{
    int l = 0, r = nums.size() - 1;

    while (l + 1 < r)
    {
        int mid = l + (r-l)/2;
        if(nums[mid] > nums[mid+1])
        {
            r = mid;
        }
        else
        {
            l = mid;
        }
    }
    
    return nums[l] > nums[r] ? l : r;
}

string addBinary(string a, string b)
{
    int i = a.size()-1;
    int j = b.size()-1;
    int carry = 0;
    string res;

    while(i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';

        res.push_back((sum%2)+'0');
        carry = sum / 2;
    }

    reverse(res.begin(), res.end());
    return res;
}

int reverseBits(int n)
{
    int res = 0;

    for(int i = 0; i < 32; i++)
    {
        // 每次取n的最低位，依次放在res右侧实现逆转
        res = (res << 1) | (n & 1);
        n = n >> 1;
    }

    return res;
}

int hammingWeight(int n)
{
    int num = 0;
    while(n)
    {
        num += n & 1;
        n = n >> 1;
    }
    
    return num;
}

int singleNumber(vector<int>& nums)
{
    int tmp = 0;

    for(int i : nums)
    {
        // 运算操作自动转二进制
        tmp ^= i;
    }

    return tmp;
}

int singleNumber2(vector<int>& nums)
{
    int one = 0,two = 0;

    for(int i : nums)
    {
        two |= one & i;
        one ^= i;
        // 出现3次清空
        int mask = ~(one & two);
        one &= mask;
        two &= mask;
    }

    return one;
}

int rangeBitwiseAnd(int left, int right)
{
    // 只要 left != right，区间内必然存在至少一个数会把某一位从 1 翻到 0，导致该位及更低位的按位与结果为 0。

    int n = 0;
    while (left != right)
    {
        left >>= 1;
        right >>= 1;
        n++; 
    }
    
    return left << n;
}

int climbStairs(int n)
{
    // a b sum
    // 走到当前的方式只有两种，f(n-2)+2  或者  f(n-1)+1,因此只需要两个数记录就好了
    if(n == 1) return 1;
    if(n == 2) return 2;
    int a = 1,  b = 1;
    int sum = 0;
    for(int i = 2; i <= n; i++)
    {
        sum = a + b;
        a = b;
        b = sum;
    }

    return sum;
}

int rob(vector<int>& nums)
{
    // 方法1：dp数组
    // 定义一个数组，记录到本位置最大收益
    /*
    int n = nums.size();
    if(n == 0) return 0; 
    if(n == 1) return nums[0];

    vector<int> dp(n);
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);

    for(int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
    }
    return dp.back();
    */

    // 方法2：优化空间，两个变量
    int n = nums.size();
    if(n == 0) return 0; 
    if(n == 1) return nums[0];

    int n1 = nums[0];
    int n2 = max(nums[0], nums[1]);
    int cur = n2;
    for(int i = 2; i < n; i++)
    {
        cur = max(n2, n1 + nums[i]);
        n1 = n2;
        n2 = cur;
    }

    return n2;
}

bool wordBreak(string s, vector<string>& wordDict)
{
    // 思想：创建一个dp数组，表示s中岛本位置可以被拼出
    unordered_set<string> wordSet(wordDict.begin(),wordDict.end()); //方便查找子字符串
    int n = s.size();
    vector<bool> dp(n+1,false); // 0占位，因此N+1
    dp[0] = true;

    for(int i = 0; i < n+1; i++)
    {
        // 只查找子字符串
        for(string str : wordSet)
        {
            int sLen = str.size();
            // 当前长度大于子串，并且子串前位置可拼，并且子串相等
            if(i >= sLen && dp[i-sLen] && (s.substr(i-sLen, sLen) == str))
            {
                dp[i] = true;
                break;
            }
        }
    }

    return dp.back();
}

int coinChange(vector<int>& coins, int amount)
{
    // 完全背包问题
    // dp[i] 表示凑成金额 i 所需的最少硬币数
    // 对于每个硬币corn，要遍历金额i,min(dp[i],dp[i-corn]+1)
    vector<int> dp(amount+1, INT_MAX-1);
    dp[0] = 0; // 凑齐0元需要0个硬币

    for(int i = 1; i <= amount; i++)
    {
        for(int j = 0; j < coins.size(); j++)
        {
            // 只有当前金额 >= 硬币面额时，才能使用这个硬币
            if(i >= coins[j])
            {
                // 取小的
                dp[i] = min(dp[i], dp[i-coins[j]] + 1);
            }
        }
    }

    return dp[amount] == (INT_MAX-1) ? -1 : dp[amount];
}

int lengthOfLIS(vector<int>& nums)
{
    // dp[i]表示到当前位置的最长长度几个
    // 状态转移：从某个位置到本位置是不是递增，比较这两个数
    int n = nums.size();
    if(n == 0) return 0;
    vector<int> dp(n, 1);
    int ret = 1;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(nums[j] < nums[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
                if(dp[i] > ret) ret = dp[i];
            }
        }
    }

    return ret;
}

int minimumTotal(vector<vector<int>>& triangle)
{
    // dp[i][j]表示到当前行的最小和
    // 状态转移：自底而上，不用考虑边界，每个上层元素只能来源于下面的两个，取小即可
    int row = triangle.size();

    // 原地修改，不用dp
    for(int i = row-2; i >= 0 ; i--)
    {
        for(int j = 0; j < triangle[i].size();j++)
        {
            triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
        }
    }

    return triangle[0][0];
}

int minPathSum(vector<vector<int>>& grid)
{
    // 方法一：二维dp
    int row = grid.size();
    int col = grid[0].size();
    vector<vector<int>> dp(row, vector<int>(col,0));
    dp[0][0] = grid[0][0];
    // 初始化第一行,只能左边移动过来
    for(int j = 1;j < col;j++)
    {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for(int i = 1; i < row; i++)
    {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }

    for(int i = 1; i < row; i++)
    {
        for(int j = 1; j < col; j++)
        {
            dp[i][j] = min(dp[i-1][j] + grid[i][j], dp[i][j-1] + grid[i][j]);
        }
    }

    return dp[row-1][col-1];

    // ==============================================
    // 2. 一维DP优化版（空间O(n)，推荐）
    // 因为只需要用到上一行和左侧即可
    // vector<int> dp(n, 0);
    // dp[0] = grid[0][0];
    // // 初始化第一行
    // for (int j = 1; j < n; j++) {
    //     dp[j] = dp[j-1] + grid[0][j];
    // }
    // // 遍历剩余行
    // for (int i = 1; i < m; i++) {
    //     // 更新当前行第一个元素（只能从上一行下来）
    //     dp[0] = dp[0] + grid[i][0];
    //     for (int j = 1; j < n; j++) {
    //         dp[j] = min(dp[j], dp[j-1]) + grid[i][j];
    //     }
    // }
    // return dp[n-1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{
    // dp表示到达这个位置的路线数量。障碍物的为0
    // 初始化第一行第一列，若有一个障碍物后面的都是0
    // 转移方程：(dp[i-1][j] + dp[i][j-1])
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));

    if(obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1) return 0;

    // 初始化
    int flag = 0;
    for(int j = 0; j < n; j++)
    {
        if(obstacleGrid[0][j] == 1 )
        {
            flag = 1; 
        }
        if(flag == 1)
        {
            dp[0][j] = 0;
        }
        else
        {
            dp[0][j] = 1;
        }
    }

    int flag2 = 0;
    for(int i = 0; i < m; i++)
    {
        if(obstacleGrid[i][0] == 1 )
        {
            flag2 = 1; 
        }
        if(flag2 == 1)
        {
            dp[i][0] = 0;
        }
        else
        {
            dp[i][0] = 1;
        }
    }

    for(int i = 1; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(obstacleGrid[i][j] == 1)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }

    return dp[m-1][n-1];
}

// 最长回文子串
string longestPalindrome(string s)
{
    // 方法一：中心扩展
    // 遍历一遍，每次以i为奇数中心向两边扩展 或 以i和i+1为偶数中心向两边扩展

    // 方法二：动态规划
    // dp[i][j] 表示i到j是回文串
    // 转义方程 dp[i][j] = (s[i] == s[j]) && (j-i <= 1 || dp[i+1][j-1])

    int n = s.size();
    int maxlen = 1;
    int begin = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // 初始化对角线
    for(int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }

    // 按照子串长度遍历
    for(int l = 2; l <= n; l++)
    {
        for(int i = 0; i < n ; i++)
        {
            int j = i + l - 1;
            if(j >= n) break;

            if(s[i] != s[j])
            {
                dp[i][j] = false;
            }
            else
            {
                if(l == 2)
                {
                    dp[i][j] = true;
                }
                else
                {
                    dp[i][j] = (s[i] == s[j]) && (j-i <= 1 || dp[i+1][j-1]);
                }
            }

            if(dp[i][j] && l > maxlen)
            {
                maxlen = l;
                begin = i;
            }
        }
    }
    return s.substr(begin, maxlen);
}

// 交错字符串
bool isInterleave(string s1, string s2, string s3)
{
    // 首先，s1的+s2的长度一定要等于s3的长度
    // 1、dp[i][j]表示s1的前i和s2的前j个能拼出s3的前i+j个
    // 2、初始化： 第一行表示全部由s1拼出来 dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1]
    // 3、转移方程：dp[i][j] = (dp[i-1][j] && s1[i-1] == s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1])
    int m = s1.size(), n = s2.size(), t = s3.size();
    if(m+n != t) return false;

    // +1，因为前0个占用了1位,那后续遍历的时候就要包括m、n
    vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    // 初始化
    dp[0][0] = true;
    for(int i = 1; i <= m;i++)
    {
        dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
    }
    for(int j = 1; j <= n; j++)
    {
        dp[0][j] = dp[0][j-1] && s2[j-1] == s3[j-1];
    }

    // 遍历转移方程
    for(int i = 1; i <= m; i++ )
    {
        for(int j = 1; j <= n; j++)
        {
            // 当前位置是s1的i或者当前位置是s2的j
            dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
        }
    }

    return dp[m][n];
}

// 最小转换次数（编辑距离）
int minDistance(string word1, string word2) 
{
    // dp[i][j]表示word1的i转换成word2的j的最小次数
    // 转移方程：增删改三种操作
    // 修改：dp[i-1][j-1] + 1
    // 新增:dp[i][j-1] + 1
    // 删除：dp[i-1][j] + 1
    // 初始化 dp[i][0] = i 将前i个转成空字符 
    // 初始化 dp[0][j] = j
    int m = word1.size();
    int n = word2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    // 初始化
    for(int i = 0 ; i <= m; i++)
    {
        dp[i][0] = i;
    }
    for(int j = 0; j <= n; j++)
    {
        dp[0][j] = j;
    }

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n;j++)
        {
            // 字符相等就不用操作
            if(word1[i-1] == word2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            // 字符不相等 增删改的一种
            else
            {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
            }
        }
    }

    return dp[m][n];
}

//----- 买卖股票
// 只允许买卖一次 - 贪心算法
int maxProfit_one(vector<int>& prices)
{
    // 定义一个最小的买入价，最大的收益，循环更新
    int min_p = INT_MIN;
    int res = 0;

    for(int p : prices)
    {
        min_p = min(min_p, p);
        res = max(res, p - min_p);
    }

    return res;
}

// 无限次交易(>一半元素个数) - 贪心
int maxProfit_max(vector<int>& prices)
{
    // 只要有利润就加上,可以认为是提前买入或者一直持仓吃利润
    int res = 0;

    for(int i = 1; i < prices.size(); i++)
    {
        if(prices[i] - prices[i-1] > 0)
        {
            res += prices[i] - prices[i-1];
        }
    }

    return res;
}

// 无限次交易，卖出手续费 - 状态机&贪心（只有买卖两种状态）
int maxProfit_max_fee(vector<int>& prices, int fee)
{
    // 注意和2次买卖的区别，可以达到的状态初始化为0（一开始空仓），一开始达不到的状态初始化为最小值（第一次不可能卖出）
    int n = prices.size();
    int hold = -prices[0];
    int empty = 0;

    for(int i = 1; i < n; i++)
    {
        // 临时变量，因为状态转移是基于上一日
        int hold_tmp = max(hold, empty - prices[i]);
        int empty_tmp = max(empty, hold + prices[i] - fee);

        hold = hold_tmp;
        empty = empty_tmp;
    }

    return empty;
}

// 2次买卖股票 - 状态机+贪心
int maxProfit_2(vector<int>& prices)
{
    // 思路：状态机，上一步执行完下一步才有意义 ，否则值不会变
    // 只有最多4次操作，因此用变量记录即可

    int m = prices.size();
    if(m < 2) return 0;

    int buy1 = -prices[0];  // 第一天买入后的钱
    int sell1 = -999999;
    int buy2 = -999999;
    int sell2 = -999999;

    for(int i = 1; i < m; i++)
    {
        // 以更低的价格买入
        int buy1_tmp = max(buy1, -prices[i]);
        // 依赖buy1，以更高的价格卖出
        int sell1_tmp = max(sell1, buy1 + prices[i]);
        // 依赖sell1
        int buy2_tmp = max(buy2, sell1 - prices[i]);
        // 依赖buy2
        int sell2_tmp = max(sell2, buy2 + prices[i]);

        buy1 = buy1_tmp;
        sell1 = sell1_tmp;
        buy2 = buy2_tmp;
        sell2 = sell2_tmp;
    }

    return max(max(sell1, sell2), 0);
}

// 无限次交易+冷静期 - 状态机+动态规划
int maxProfit_cooltime(vector<int>& prices)
{
    // 三状态流转：持有 → 卖出 → 冷却 → 可买入。
    int n = prices.size();
    if(n < 2) return 0;
    int hold = -prices[0];
    int empty = 0;
    int cool = 0;

    for(int i = 1; i < n; i++)
    {
        int hold_tmp = max(hold, cool - prices[i]);
        int empty_tmp = max(empty, hold + prices[i]);
        int cool_tmp = empty;

        hold = hold_tmp;
        empty = empty_tmp;
        cool = cool_tmp;
    }

    // 最后卖完最赚钱
    return max(empty, cool);
}

// 多次买卖股票 - 状态机+动态规划（数组代替变量）
int maxProfit_k(int k, vector<int>& prices)
{
    int size = prices.size();
    if(size < 2 || k <=0 ) return 0;

    // 初始化
    vector<int> buy(k+1, -999999);  // 后续状态不可达
    vector<int> sell(k+1, -999999);
    buy[1] = -prices[0];  // 第一个位置
    sell[0] = 0;    // buy1依赖sell0

    for(int i = 1; i < size; i ++)
    {
        vector<int> buy_tmp = buy;
        vector<int> sell_tmp = sell;

        for(int j = 1; j <= k; j++)
        {
            // j次买入依赖j-1次卖出；j次卖出依赖j次买入
            buy_tmp[j] = max(buy[j], sell[j-1] - prices[i]);
            sell_tmp[j] = max(sell[j], buy[j] + prices[i]);
        }

        buy = buy_tmp;
        sell = sell_tmp;
    }

    int res = 0;
    for (int j = 1; j <= k; j++) 
    {
        res = max(res, sell[j]);
    }
    return res;
    // 固定次数的可以return sell[2]中前几个最大的
}