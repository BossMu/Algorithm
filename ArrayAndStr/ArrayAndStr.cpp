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